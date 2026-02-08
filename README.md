## Flicker 3

Flicker 1 was written in Kotlin. It used an AST and an interpreter. It was painfully slow, and wasn't even finished.

Flicker 2 was written in C. It used bytecode in a VM. It was nice and fast, and it had lots of nice features.

Flicker 3 will be...
- implemented in C++
- turned into an AST, then _optimized,_ converted into bytecode, and run in a VM
- **statically typed**
- (hopefully) faster in runtime
- and, above all, it will be...<details><summary>click to end the suspense...</summary><details><summary>sorry, I needed a bit more suspense...</summary>
  **It will be FUN! Both to implement and to use!**</details></details>

## Testing

You can't _use_ Flicker yet, in the full sense, but you can _test_ it. Here's what I'm implying by making this distinction: the language won't work how you 
expect it to, but I'd appreciate reports of non-obvious bugs.

To _test_ flicker:
1. Download or clone this repo.
2. Make sure you have CMake and Ninja installed.
3. Run `cmake --build --target flicker_3 --preset release` (use `--preset debug` if you prefer).
4. The executable will be in `cmake-build-release/flicker_3` (or `cmake-build-debug/`). Make it executable if necessary, then run it by itself for a REPL, or 
   with a file path as an argument.
5. Chances are, you'll want to mess around with debug flags in `h/common.h`. For example, if you'd rather just print tokens instead of exporting as a DOT 
   tree for GraphViz. Change whatever, but remember to rebuild.

Of course, you can build with `clang++` or `g++` if you prefer.
CMake can make your life easier, but if you don't have it installed already, it may be unnecessary.
