# CS50x_2023_Harvard
This course teaches you how to think algorithmically and solve problems efficiently. Topics include abstraction, algorithms, data structures, encapsulation, resource management, security, software engineering, and web development. Languages include C, Python, SQL, and JavaScript plus CSS and HTML. Problem sets inspired by real-world domains of biology, cryptography, finance, forensics, and gaming. Designed for concentrators and non-concentrators alike, with or without prior programming experience. 68% of CS50 students have never taken CS before.

Enroll here: [CS50x](https://cs50.harvard.edu/x/2023/)
Instructor: [David J. Malan](https://cs.harvard.edu/malan/) 

# Notes📝 & Project🚀

# ⛳[Week-0 project]()  `[Theme: Basics of Programming]`

## Project: 

  - [Scratch Project](https://scratch.mit.edu/projects/)
>  Computer science is not so much about programming as it is about problem solving
# ⛳[Week-1]([lecture_1](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_1)) `[Theme: Basics of C, Greedy Algorithm, Cryptography]`

## Project: 

  - Lab
    - [cash]()
    - [Population]()
  - Problem set
    - Mario
      - [Mario-less]()
      - [Mario-more]()
    - [cash]()
    - [credit](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_1/Submission%20/credit)

## C basic

There are a few guiding lights when writing code: correctness, design, style.

```c
#include <stdio.h>

int main(void)
{
  printf("hello, world");
}
```

> You need to type `make hello` to compile your code and `./hello` to run it.

## The Command Line

The command line lets you run commands without the need for a GUI.

cd, for changing our current directory (folder)
cp, for copying files and directories
ls, for listing files in a directory
mkdir, for making a directory
mv, for moving (renaming) files and directories
rm, for removing (deleting) files
rmdir, for removing (deleting) directories

## Data Types and Variables

In C you have access to many data types: bool, char, double, float, int, long, string.Each of these data types only have a finite number of bits.

*Integers only use 32 bits*. This can support 4 billion total values and lets you count from -2 billion to 2 billion. To work with larger numbers you'd need a long.

When working with formatted strings, you can use the following format codes:

- %c - single character
- %f - floating point value
- %i - integer
- %li - long
- %s - string

> C supports a number of mathmatical operators: +, -, \*, /, %.

## Conditionals

> Conditional expressions allow your programs to make decisions and take different forks in the road, depending on the values of variables or user input.
> [slides](chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/https://cdn.cs50.net/2017/fall/shorts/conditional_statements/conditional_statements.pdf)

## Loops

[slides](chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/https://cdn.cs50.net/2017/fall/shorts/loops/loops.pdf)

> Loops allow your programs to execute lines of code repeatedly, saving you from needing to copy and paste or otherwise repeat lines of code.

- while (true) { } • This is what we call an infinite loop. The lines of code between the curly braces will execute repeatedly from top to bottom, until and unless we break out of it (as with a break; statement) or otherwise kill our program.
- while (boolean-expr) { } • If the boolean-expr evaluates to true, all lines of code between the curly braces will execute repeatedly, in order from top-to-bottom, until boolean-expr evaluates to false. • Somewhat confusingly, the behavior of the Scratch block is reversed, but it is the closest analog.
- do { } while (boolean-expr); • This loop will execute all lines of code between the curly braces once, and then, if the boolean-expr evaluates to true, will go back and repeat that process until booleanexpr evaluates to false.
- for (int i = 0; i < 10; i++) { } • Syntactically unattractive, but for loops are used to repeat the body of a loop a specified number of times, in this example 10. • The process undertaken in a for loop is: • The counter variable(s) (here, i) is set • The Boolean expression is checked. • If it evaluates to true, the body of the loop executes. • If it evaluates to false, the body of the loop does not execute. • The counter variable is incremented, and then the Boolean expression is checked again, etc.
- for (start; expr; increment) { } • Syntactically unattractive, but for loops are used to repeat the body of a loop a specified number of times, in this example 10. • The process undertaken in a for loop is: • The statement(s) in start are executed • The expris checked. • If it evaluates to true, the body of the loop executes. • If it evaluates to false, the body of the loop does not execute. • The statement(s) in increment are executed, and then the expr is checked again, etc.
- while 
  - Use when you want a loop to repeat an unknown number of times, and possibly not at all. 
- do-while 
  - for Use when you want a loop to repeat an unknown number of times, but at least once. 
- for
  - Use when you want a loop to repeat a discrete number of times, though you may not know the number at the moment the program is compiled.

## Operators

[sides](chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/https://cdn.cs50.net/2017/fall/shorts/operators/operators.pdf)

- Arithmetic Operators
- Boolean Expressions  

# 

# ⛳[Week-2](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_2)`[Theme: Arrays, Cryptography, Encryption]`

##      project

- Lab
  - [scrabble](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_2/Submission/scrabble)
- Problem set
  - [readability](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_2/Submission/readability)
  - [substitution](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_2/Submission/substitution)

## Compiling

A compiler is a programme that converts source code to machine code. Clang is a popular compiler for C.

When all programmes had to be compiled, the default file produced was `a.out` for assembly output.

Clang can be configured with command line arguments but these can become long and verbose. Eventually you will want to automate the steps.

Sometimes when using a library it's not sufficient to include the header file at the top of your code, you need to explicitly tell the computer where to find the file.

When you comile your code there are a few steps involved:

- precompiling
- compiling
- assembling
- linking

First the computer preprocesses your code, looking for any lines starting with `#` and copying the contents of the referenced file into your own code.

To compile your code means to convert it from source code to another kind of source code, assembly code.

To assemble your code means to convert your code from assembly to machine code, 0s and 1s.

Finally the 0s and 1s of your code need to be linked to the 0s and 1s of any library you are using.

## Memory

On a typical computer each data type in C is defined as taking up a fixed amount of space. This varies, but for example:

- bool - 1 byte
- char - 1 byte
- double - 8 bytes
- float - 4 bytes
- int - 4 bytes
- long - 8 bytes
- string - ? bytes

It's in memory (RAM) that programmes are stored while running and files are stored while open.

RAM is much faster than solid state storage but it's also volatile, it requires electricity to maintain it.

Imagine your computer's memory as a grid of bytes. An int would take up 4 spaces. In those 4 spaces would be a pattern of 0s and 1s representing the int.

## Arrays

An array is a sequence of values stored in memory back to back.

In C you need to specify how many values you want to store in the array when you declare it. The exception is when you are passing an array to a custom function, because you don't know in advance.

```c
int scores[3];

scores[0] = 72;
scores[1] = 73;
scores[2] = 33;
```

A constant is a variable whose value cannot change.

```c
const int TOTAL = 3;
```

## Strings

If you cast a character to an int, you can access its ASCII value.

Each char is stored in a single byte.

By default, C does not have a string datatype.

A string is an array of characters.

So the string `"HI!"` is equivalent to the array `['H', 'I', '!']`.

You can access the individual characters of a string using [] notation.

The computer's memory knows when strings begin and end because, under the hood, the string uses one extra byte, `\0` or `NUL`, to represent the end of the string. For example, the string `HI!` uses 4 bytes, not 3.

```c
string s = "HI!"
printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
// 72 73 33 0
```

One dangerous aspect of C is that you can access values from other parts of memory. If you accessed `s[4]` you would get whatever value is in this adjacent spot in memory.

If you want to loop to the end of a string and then stop, you could set your loop to break when it reaches `\0` or use the `strlen()` function from `<string.h>`.

```c
int main(void)
{
  string s = get_string("Input: ");
  printf("Output: ");
  for (int i = 0, n = strlen(s); i < n; i++)
  {
    printf("%c", s[i]);
  }
  printf("\n");
}

```

## Arrays of Strings

You can have an array of strings. And since a string is itself an array, this is an array of arrays.

```c
string words[2];
words[0] = "HI!";
words[1] = "BYE!";
```

You can use multiple [] to access values from nested arrays.

```c
words[0][0]
// 'H'
words[1][1]
// 'Y'
```

The ASCII values of uppercase and lowercase letters are always 32 apart. You could uppercase a lowercase letter by subtracting 32 from it. Or you could just use the `toupper()` function from `<ctype.h>`. `toupper()` expects a character as input; you cannot pass a word to it. To make a string uppercase you would need to loop over every character in the string.

## Command-line Arguments

Just as custom functions can take inputs, so can main.

```c
int main(int argc, string argv[])
{

}
```

This means that this `main` takes an int and an array of strings as its input.

`argc` stands for argument count, the number of words you expect your user to type at the prompt. This includes the name of your programme.

`argv` stands for argument vector, an array of the strings typed by the user.

## Exit Status

Programmes often return an int to show what has happened. 0 indicates that nothing as gone wrong. This is why in C you set up `main` to return an int.

```c
int main(int argc, string argv[])
{
  if (argc != 2)
  {
    printf("missing command-line argument\n");
    return 1;
  }
  printf("hello, %s\n", argv[1]);
  return 0;
}
```

## Cryptography

Cryptography is the art of scrambling information in order to hide it.

If that information is text, you can convert the plaintext to ciphertext.

A cipher is an algorithm that scrambles its input so as to produce an output that a third party can't understand. That algorithm is a reversible process so that you can decipher the text and read it.

Ciphers use a key to determine how to encrypt and decrypt the input.

# ⛳[Week-3]() `[Theme: Algorithms, Graph Theory Basics]`

## Project

  - Lab
    - [Sort]( )
  - Problem set
    - [Plurality]( )
    - [Runoff]( )
    - [Tideman]()(Recursive approach)💥

## [Running Time](https://cs50.harvard.edu/x/2023/notes/3/#running-time)

>  *running time* involves an analysis using *big O* notation. Take a look at the following graph:

- It’s the shape of the curve that shows the efficiency of an algorithm. Some common running times we may see are:
  - O(n2)
  - O(nlog⁡n)
  - O(n)
  - O(log⁡n)
  - O(1)

- Of the running times above, O(n2) is considered the worst running time, O(1) is the fastest.
- Linear search was of order O(n) because it could take *n* steps in the worst case to run.
- Binary search was of order O(log⁡n) because it would take fewer and fewer steps to run even in the worst case.
- Programmers are interested in both the worst case, or *upper bound*, and the best case, or *lower bound*.
- The Ω symbol is used to denote the best case of an algorithm, such as Ω(log⁡n).
- The Θ symbol is used to denote where the upper bound and lower bound are the same, where the best case and the worst case running times are the same.

## [Linear and Binary Search](https://cs50.harvard.edu/x/2023/notes/3/#linear-and-binary-search)

### Linear search 

Linear search sequentially checks every item in a list.

This has a time complexity of O(n) and Ω(1).

```c
int main(void)
{
  int numbers[] = {4,6,8,2,7,5,0};

  for (int i = 0; i < 7; i++)
  {
    if (numbers[i] == 0)
    {
      printf("Found\n");
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}
```

### Binary Search

Binary search repeatedly divides in half the part of a list that could contain an item, until the possible locations is narrowed down to just one.

This has a time complexity of O(log n) and Ω(1).



## Structs

Using `typefed` and the `struct` keyword, C can create a datatype that is combination of other datatypes. This could be useful for storing key value pairs.

```c
typedef struct
{
  string name;
  string number;
}
person;
```

Phone numbers should be represented using strings not ints since they can have non-numeric characters in them.

```c
typedef struct
{
  string name;
  string number;
}
person;

int main(void)
{
  person people[2];

  people[0].name = "Brian";
  people[0].number = "+1-617-495-1000";

  people[1].name = "David";
  people[1].number = "+1-949-468-2750";

  for (int i = 0; i < 2; i++)
  {
    if (strcmp(names[i].name, "David") == 0)
    {
      printf("Found %s\n", people[i].number);
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}
```



##   [Sorting](https://cs50.harvard.edu/x/2023/notes/3/#sorting)

- *sorting* is the act of taking an unsorted list of values and transforming this list into a sorted one.

- When a list is sorted, searching that list is far less taxing on the computer. Recall that we can use binary search on a sorted list, but not on an unsorted one.

- It turns out that there are many different types of sort algorithms.

- *Selection sort* is one such search algorithm.
### Merge Sort 

  - In merge sort, the idea of the algorithm is to sort smaller arrays and then combine those arrays together (merge them) in sorted order. 
  
  - Merge sort leverages something called recursion touch on in more detail in a future video. In pseudocode: 
  - In pseudocode: 
    -  Sort the left half of the array (assuming n >1)
    - Sort the right half of the array (assuming n>1)
    -  Merge the two halves together

### Selection Sort

Selection sort loops over a list, finding the smallest unsorted item and swapping it with the leftmost unsorted item until all items have been sorted. It is relatively inefficient.

It has a time complexity of O(n2) and Ω(n2).

### Bubble Sort

Bubble sort loops over a list, compares two adjacent elements and swaps them if they are in the wrong order. The loop is repeated until the list is sorted. The largest values bubble up to the end of the list.

It has a time complexity of O(n2) and Ω(n).  

## [Recursion](https://cs50.harvard.edu/x/2023/notes/3/#recursion)

# ⛳[Week-4]() `[Theme: Memory organization, Pointers⚠, Image filters, File manipulation & Data Recovery]`

  - Lab

    - 

  - Problem set

    - 💥

      
      

# ⛳[Week-5]( ) `[Theme: Data Structures⚠]`

  - Lab
    - 
  - Problem set
    - 💥

# ⛳[Week-6]( ) `[Theme: Basics of Python, Forensics, Probability]`

  - Lab
    - 
  - Problem set
    - 
    - 
      - 
      - 
    - 

# ⛳[Week-7]() `[Theme: SQLite, Database querying, Crime Investigation]`

  - Lab
    - 
  - Problem set
    - 
    - 💥

# ⛳[Week-8]() `[Theme: Basics of HTML, CSS, Javascript, DOM]`

  - Lab
    - 
  - Problem set
    - 

# ⛳[Week-9]() `[Theme: Flask, Python revisited, Jinja, Equity Markets(Stocks)]`

  - Lab
    - 
  - Problem set
    - 
