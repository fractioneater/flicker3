/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <string>

/**
 * Enables multiline mode in Linenoise.
 */
void enable_multiline();
/**
 * Sets the continuation prompt for Linenoise. Used on multiline input.
 * @param prompt Prompt to display on a continuation line
 */
void set_continuation_prompt(const char* prompt);
/**
 * Reads a line with Linenoise :)
 * @param prompt Message to display before getting input
 * @param line Output ref to hold the line after reading it
 * @return False if the user asks to quit, true otherwise
 */
bool read_line(const char* prompt, std::string& line);
/**
 * Adds a line to Linenoise's history storage.
 * @param line Line to add to the history
 */
void add_history(const std::string& line);
/**
 * Loads history file into Linenoise's history.
 * @param path History file path
 * @return Not used
 */
bool load_history(const char* path);
/**
 * Saves Linenoise history to a file.
 * @param path History file path
 * @return
 */
bool save_history(const char* path);

/**
 * Gets the path of the currently running executable.
 * Used for REPL history.
 * @return Path to the executable
 */
std::string get_executable_path();
