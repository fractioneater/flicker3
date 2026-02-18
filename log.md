## July 7, 2025

This was when I decided Flicker's compiler needed a rewrite and feature overhaul.
I began to plan what my end goal would be.

## July – November 2025

I'd decided that although C is nice, I didn't want to use it for Flicker 3.
So I learned C++, using the wonderful tutorials on [learncpp].
My plan was to finish before the beginning of December so I could do the Advent of Code in C++ then begin working on Flicker in the spring.

## December 2025

I was not done with the [learncpp] tutorials. But I knew enough to do Advent of Code anyway.
Because there were only 12 days of AoC, I had more time at the end of the month.
I did the occasional C++ lesson, but still made little progress.

## January 27, 2026

It was a snowy day. I was bored. And what better to do when you're bored than start writing tests for a language you're designing?

I got CMake hooked up with Google Test, ready to get going. There wasn't much to test, so it wasn't as satsifying as actual language design.
But testing is important.

## January 28 – 30, 2026

Lexers. Aren't they beautiful? They're also really fun to write.
In my case, it was more rewriting than writing, because Flicker 2 had a very functional lexer that translated easily from C to C++.

Well, that was my expectation, and it was mostly true,
but I did notice the occasional bug in the old code that should've _completely prevented Flicker 2 from working_.
Needless to say, those bugs did not get ported to F3.

I was unfamiliar with GTest and not quite bored enough to go in-depth learning it, so I asked Claude (the LLM) to create a little example test that I could
examine to familiarize myself with the framework.
It wrote an entire test suite for my lexer. The tests were not rigorous—they didn't cover any of the
edge cases I needed to look out for—but there were at about 120 of them.

## January 31, 2026

I was curious how parsers worked. I tried to learn what the different varieties were, but didn't come away with much.
It seemed like a recursive descent parser (the same type Flicker 2 had) was a good idea for F3 as well,
mainly for quality (helpfulness) of error messages. That's a priority for me.

I needed a good language grammar to write a consistent recursive descent parser with a clear structure. I used the one I'd started writing for the Flicker
IntelliJ Plugin (forgot to mention that short-lived project). I wanted to test Junie, the JetBrains AI agent, so I asked it to write a lexer adapter to turn
my handwritten lexer's tokens into ones ANTLR 4 could read. It did pretty well, and by the end of the day I could write Flicker code in a file and have the
computer lex and parse it.

Note that ANTLR is only temporary. It (and all the AI-written code accompanying it) will be permanently removed once my grammar is stable.

----

## February 3, 2026

The day I created this log file. You can see I've switched to present tense.

For the past couple of days, I've been modifying Flicker's grammar. Today I wrote the outline for classes.
I still haven't finished the [learncpp] tutorials, by the way.

## February 9, 2026

The repository is now public, licensed under the MPL 2.0.
I've done two main things since the last entry:

* Lots of tokens have been shuffled around, and I've added new helpful ones like `?:` (Elvis or Nil Coalescing Operator), `++`, `--`, and all the modifying 
  assignment operators (`+=`, `/=`, `^=`, and the rest).

* Error recovery in the lexer. Now, instead of stopping at the first error, it will print a list of all that it finds. It won't continue to parse after 
  finding a lexer error, so I don't need too sophisticated error recovery, but I do still need to consume the right number of characters to continue lexing 
  after an error.

`CMakePresets.json` now stores two presets: debug and release. A build guide is in the README.

[learncpp]: https://learncpp.com