/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "linenoise-wrapper.h"

#include "linenoise.hpp"

#include <stdexcept>
#include <vector>

#if defined(_WIN32)
#  include <windows.h>
#elif defined(__APPLE__)
#  include <mach-o/dyld.h>
#  include <limits.h>
#  include <cstdlib>
#elif defined(__linux__)
#  include <climits>
#  include <unistd.h>
#elif defined(__FreeBSD__)
#  include <sys/types.h>
#  include <sys/sysctl.h>
#  include <unistd.h>
#else
#  error "Unsupported platform: add a branch for your OS"
#endif

void enable_multiline() {
  linenoise::SetMultiLine(true);
}

void set_continuation_prompt(const char* prompt) {
  linenoise::SetContinuationPrompt(prompt);
}

bool read_line(const char* prompt, std::string& line) {
  return !linenoise::Readline(prompt, line);
}

void add_history(const std::string& line) {
  linenoise::AddHistory(line.c_str());
}

bool load_history(const char* path) {
  linenoise::SetHistoryMaxLen(124);
  return linenoise::LoadHistory(path);
}

bool save_history(const char* path) {
  return linenoise::SaveHistory(path);
}

std::string get_executable_path() {
  #if defined(_WIN32)
  // Windows: GetModuleFileName, growing the buffer until it fits.
  std::vector<char> buf(MAX_PATH);
  for (;;) {
    DWORD len {GetModuleFileNameA(nullptr, buf.data(), static_cast<DWORD>(buf.size()))};
    if (len == 0) throw std::runtime_error("GetModuleFileNameA failed");
    if (len < buf.size())
      return std::string(buf.data(), len);
    buf.resize(buf.size() * 2); // Buffer too small, try again.
  }

  #elif defined(__APPLE__)
  // macOS: _NSGetExecutablePath gives a path that may contain symlinks, so resolve it with realpath.
  uint32_t size = 0;
  _NSGetExecutablePath(nullptr, &size); // First call just fills required size.
  std::vector<char> buf(size);
  if (_NSGetExecutablePath(buf.data(), &size) != 0) throw std::runtime_error("_NSGetExecutablePath failed");
  char resolved[PATH_MAX];
  if (realpath(buf.data(), resolved) == nullptr) throw std::runtime_error("realpath failed");
  return std::string(resolved);

  #elif defined(__linux__)
  // Linux: /proc/self/exe is a symlink to the executable.
  std::vector<char> buf(PATH_MAX);
  for (;;) {
    const ssize_t len {readlink("/proc/self/exe", buf.data(), buf.size())};
    if (len < 0) throw std::runtime_error("readlink(/proc/self/exe) failed");
    if (static_cast<size_t>(len) < buf.size())
      return std::string(buf.data(), len);
    buf.resize(buf.size() * 2); // Truncated, try a bigger buffer.
  }

  #elif defined(__FreeBSD__)
  // FreeBSD: sysctl with the KERN_PROC_PATHNAME mib.
  int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
  size_t size {0};
  if (sysctl(mib, 4, nullptr, &size, nullptr, 0) != 0)
    throw std::runtime_error("sysctl (size query) failed");
  std::vector<char> buf(size);
  if (sysctl(mib, 4, buf.data(), &size, nullptr, 0) != 0)
    throw std::runtime_error("sysctl (path query) failed");
  return std::string(buf.data());

  #endif
}
