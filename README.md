# CS50x_2023_Harvard
This course teaches you how to think algorithmically and solve problems efficiently. Topics include abstraction, algorithms, data structures, encapsulation, resource management, security, software engineering, and web development. Languages include C, Python, SQL, and JavaScript plus CSS and HTML. Problem sets inspired by real-world domains of biology, cryptography, finance, forensics, and gaming. Designed for concentrators and non-concentrators alike, with or without prior programming experience. 68% of CS50 students have never taken CS before.

Enroll here: [CS50x](https://cs50.harvard.edu/x/2023/)
Instructor: [David J. Malan](https://cs.harvard.edu/malan/) 

# Notes📝 & Project🚀

## ⛳[Week-0 project]()  `[Theme: Basics of Programming]`

## Project: 

  - [Scratch Project](https://scratch.mit.edu/projects/)
>  Computer science is not so much about programming as it is about problem solving
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
[slides](chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/https://cdn.cs50.net/2017/fall/shorts/conditional_statements/conditional_statements.pdf)

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

## ⛳[Week-1]([lecture_1](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_1)) `[Theme: Basics of C, Greedy Algorithm, Cryptography]`

## Project: 

  - Lab
    - [Hello](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_1/Submission /hello)
    - [Population]()
    
  - Problem set
    - Mario
      - [Less comfortable](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_1/Submission /mario-less)
      - [More comfortable](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_1/Submission /mario-more)
    - [Cash](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_1/Submission%20/cash)
    - [Credit](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_1/Submission /credit)

⛳[Week-2](https://github.com/vrv501/CS50x-2021/blob/main/pset2) `[Theme: Arrays, Cryptography, Encryption]`
     
- Lab
  - [Scrabble]([scrabble](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_2/Submission/scrabble))
- Problem set
  - [Readability]([readability](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_2/Submission/readability))
  - [Substitution]([substitution](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_2/Submission/substitution))

⛳[Week-3](https://github.com/vrv501/CS50x-2021/blob/main/pset3) `[Theme: Algorithms, Graph Theory Basics]`

  - Lab
    - [Sort](https://github.com/vrv501/CS50x-2021/blob/main/pset3/sort)
  - Problem set
    - [Plurality](https://github.com/vrv501/CS50x-2021/blob/main/pset3/plurality)
    - [Runoff](https://github.com/vrv501/CS50x-2021/blob/main/pset3/runoff)
    - [Tideman](https://github.com/vrv501/CS50x-2021/blob/main/pset3/tideman)(Recursive approach)💥

⛳[Week-4](https://github.com/vrv501/CS50x-2021/blob/main/pset4) `[Theme: Memory organization, Pointers⚠, Image filters, File manipulation & Data Recovery]`

  - Lab

    - [Volume](https://github.com/vrv501/CS50x-2021/blob/main/pset4/volume)

  - Problem set

    - Filter💥

      - [Less comfortable](https://github.com/vrv501/CS50x-2021/blob/main/pset4/filter/less)
      - [More comfortable](https://github.com/vrv501/CS50x-2021/blob/main/pset4/filter/more)
      
    - [Recover](https://github.com/vrv501/CS50x-2021/blob/main/pset4/recover)

⛳[Week-5](https://github.com/vrv501/CS50x-2021/blob/main/pset5) `[Theme: Data Structures⚠]`

  - Lab
    - [Inheritance](https://github.com/vrv501/CS50x-2021/blob/main/pset5/inheritance)
  - Problem set
    - [Speller](https://github.com/vrv501/CS50x-2021/blob/main/pset5/speller)(Using Tries)💥

⛳[Week-6](https://github.com/vrv501/CS50x-2021/blob/main/pset6) `[Theme: Basics of Python, Forensics, Probability]`

  - Lab
    - [World Cup](https://github.com/vrv501/CS50x-2021/blob/main/pset6/worldcup)
  - Problem set
    - [Hello](https://github.com/vrv501/CS50x-2021/blob/main/pset6/hello)
    - Mario
      - [Less comfortable](https://github.com/vrv501/CS50x-2021/blob/main/pset6/mario/less)
      - [More comfortable](https://github.com/vrv501/CS50x-2021/blob/main/pset6/mario/more)
    - [Cash](https://github.com/vrv501/CS50x-2021/blob/main/pset6/cash)
    - [Credit](https://github.com/vrv501/CS50x-2021/blob/main/pset6/credit)
    - [Readability](https://github.com/vrv501/CS50x-2021/blob/main/pset6/readability)
    - [DNA](https://github.com/vrv501/CS50x-2021/blob/main/pset6/dna)

⛳[Week-7](https://github.com/vrv501/CS50x-2021/blob/main/pset7) `[Theme: SQLite, Database querying, Crime Investigation]`

  - Lab
    - [Songs](https://github.com/vrv501/CS50x-2021/blob/main/pset7/songs)
  - Problem set
    - [Movies](https://github.com/vrv501/CS50x-2021/blob/main/pset7/movies)
    - [Fiftyville](https://github.com/vrv501/CS50x-2021/blob/main/pset7/fiftyville)💥

⛳[Week-8](https://github.com/vrv501/CS50x-2021/blob/main/pset8) `[Theme: Basics of HTML, CSS, Javascript, DOM]`

  - Lab
    - [Trivia](https://github.com/vrv501/CS50x-2021/blob/main/pset8/trivia)
  - Problem set
    - [Homepage](https://github.com/vrv501/CS50x-2021/blob/main/pset8/homepage)
      View the website [here](https://skyfall01.github.io/CS50x-2021/) !!!

⛳[Week-9](https://github.com/vrv501/CS50x-2021/blob/main/pset9) `[Theme: Flask, Python revisited, Jinja, Equity Markets(Stocks)]`

  - Lab
    - [Birthdays](https://github.com/vrv501/CS50x-2021/blob/main/pset9/birthdays)
  - Problem set
    - [Finance](https://github.com/vrv501/CS50x-2021/blob/main/pset9/finance)💥

# 
