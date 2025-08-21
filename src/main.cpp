#include <iostream>

void repl() {
  std::string line {"a"};
  // Not the cleanest syntax, but this comma expression works to print the "~ >" prompt.
  while (std::cout << "~ > ", std::getline(std::cin >> std::ws, line)) {
    std::cout << "you typed " << line << '\n';
  }

  // Clear the prompt characters from the last line.
  std::cout << "\b\b\b\b";
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    repl();
  } else if (argc == 2) {
    // Hmmm
  } else {
    std::cout << "Usage: flicker [path]\n";
    return 64;
  }

  return 0;
}
