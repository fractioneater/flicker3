Flicker 1 was written in Kotlin. It used an AST and an interpreter. It was painfully slow and wasn't even finished.

[Flicker 2] was written in C. It used bytecode in a VM. It was nice and fast, and it had lots of useful features.

Flicker 3 will be...

- implemented in C++
- turned into an AST, then _optimized,_ converted into bytecode, and run in a VM
- **statically typed**
- (hopefully) faster in runtime
- and, above all, it will be...<details><summary>click to end the suspense...</summary><details><summary>sorry, I needed a bit more suspense...</summary>
  **It will be FUN! Both to implement and to use!**</details></details>

## Code Sample

```ruby
# In Flicker, the world does not exist. Instead, we use a bagel.
print "Hello, Bagel!"

# And because printing things is nice, I've made it an expression:
var a = print "Hello again, Bagel!"

#- Block comment -#

## Double-comments are the current hacky solution to skip a newline:
print 3 + ##
  a.length # I'm actually not sure whether this indentation will be accepted or not

# You can express yourself with expressions:
nil or true or false
44 / 4
4 < Random().byte() < 40  # Chained comparisons for the Python fans
4..2
variable ?: ""            # Nil coalescing operator (Elvis)
variable?.type            # Safe member access

# And when expressions get boring, you can have fun with functions:
fun double(num: Int) -> Int = num * 2

fun doubleAndPrint(num: Int) -> Int
  val doubled = num * 2
  print "=(num) doubled is =(doubled)"
  return doubled

fun add for A (x: A, y: A) -> A  # Type parameters (polymorphism)
  return x + y

add(3.2, 88.75)
add(6, 10)

fun callAndReturn for T (function: () -> T) -> T
  return function()

callAndReturn { print "lambdas are cool"; return [1, 2, 3]; }

# We've also got control flow. I assume you know the general idea, but take a look at this:
var string = ""
each item[index] in 78..93
  string += "#=(index): =(item)"
around
  # Ain't that neat?
  string += "\n"

print string

# Buuuuut... fractioneater, what if I prefer C-style for-loops?
# Those are here too!
for var i = 78; i <= 93; ++i
  print i

# And all three types of loop (while, each, for) can have an around clause like you saw above and an 'else' clause.
# But this isn't a Python 'else' clause. It only runs WHEN THE CODE IN THE MAIN BODY NEVER GETS A CHANCE TO RUN!
while false
  print "You shouldn't see this"
else
  print "Hello"

# Classes are very important in Flicker, but don't confuse it with Java. You can still have code outside of classes in Flicker.
class Test is WhateverItsSupertypeShouldBe
  namespace
    # This is essentially a 'companion object' in Kotlin. Except it's a namespace.
    var exampleNumber = 42  # Can be accessed with Test::exampleNumber

  init(name: String)
    super(name)  # If the superclass needs initialized

  fun method()
    pass

# And that's it, mostly. Namespaces can be defined by themselves (outside of a class) if you want, and there's also the 'using' keyword
# which can mean two things:
using "../constants.fl" for pi     # 1: Imports
using StringList = List of String  # 2: Type aliases

# Speaking of type aliases, I've made an interesting choice with generics. If you remember, my syntax is this:
#   fun/class for T     OR      fun/class of T
# For and of can be used interchangeably. For multiple type params, DO NOT use a comma: class Thing for T U.
# You might be thinking, wouldn't this cause some problems with nesting generics?
#   Pair of List of String Int
# Yes, that's weird. However, the parser won't let you write it. You'll have to do this instead:
#   Pair of StringList Int
# The parser is looking out for you. Keep your code readable, folks.

```

## Testing

You can't _use_ Flicker yet, in the full sense, but you can _test_ it. Here's what I'm implying by making this distinction: the language won't work how you
expect it to, but I'd appreciate reports of non-obvious bugs.

**At the moment, Flicker cannot run your code. It can parse it, and that's cool, but don't expect to see it run.**

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
