## Flicker 3

Flicker 1 was written in Kotlin. It used an AST and an interpreter. It was painfully slow and wasn't even finished.

[Flicker 2] was written in C. It used bytecode in a VM. It was nice and fast, and it had lots of useful features.

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
2. Make sure you have CMake (at least 4.0) and Ninja installed.
3. Make sure you have a C++ compiler capable of using the **C++20 standard**.
4. **One-time setup:** run `cmake -S . -B build` to configure CMake's build directory.
5. Run `cmake --build --target flicker_3 --preset release` (use `--preset debug` if you prefer).
6. The executable will be in `build/flicker_3`. Give it execute permissions if necessary, then run it by itself for a REPL, or with a file path as an argument.
7. Chances are, you'll want to mess around with debug flags in `h/common.h`. For example, if you'd rather just print tokens instead of exporting as a DOT
   tree for GraphViz. Change whatever, but remember to rebuild.

Of course, you can build with `clang++` or `g++` if you prefer.
CMake can make your life easier, but it can also be bothersome to set up.

## FAQ

Curated by none other than _Someone_.

### Why is the language called Flicker?

It is currently unknown why this language is called Flicker. This question has sparked many debates in the hypothetical online forum. At the moment, there are a
few circulating fan theories (it is important that I clarify **these are only rumors**):

1. The Developer enjoys candles.
2. The language is intended to be easy to write. Merriam-Webster, the Developer's favorite dictionary and thesaurus (citation needed), lists the following as an
   example sentence for the word _Flicker:_ "Thoughts _flickered_ through his mind."  
   The intent of Flicker is to allow the user to capture their thoughts in code... **as quickly as they _flicker_ through the user's mind.**
3. The Developer chose a random two-syllable word that was not taken.
4. A flicker is a bird (_Colaptes auratus_). The Developer has been documented reading _Crafting Interpreters_ by Bob Nystrom. Bob Nystrom occasionally names
   his programming languages after birds (Wren, Magpie, Finch, and Lark). Okay, I admit this is a stretch.

[Flicker 2]: https://github.com/fractioneater/flicker