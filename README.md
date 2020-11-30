# My Own Shell Application

This is my own shell applicaiton made with C. This project has its own commands, response and error outputs. 
In Linux shell is a c program, so I made this project with C.

## How does this project work?

The project consists of 5 programs. These are myshell, tekrar(repeat), islem, topla(add), cikar(substract).

Myshell is a program that runs continuously. This program works with parameters like shell commands.
It continues to run until the exit command entered. Myshell program distinguishes incoming commands.
If the command entered is ‘clear‘, it clears the terminal. If the command entered is ‘cat‘, 
it performs the file reading operation. Multiple commands can be entered in the program at the same time. 
To distinguish them the '|' character is used.

2 more parameters besides the repeat word for repeat processing must be entered. 
The first of these is the word to be repeated. The other should be repeat number.

To add and subtract 3 units next to the operation command parameter is entered. 
The first of these is to indicate the action to be taken. 
The first parameter can only be 'cikar' and 'topla'. Second and third parameters must be numbers to be processed.

The program will give a warning for incorrectly entered parameters.

## Running the tests

Download files ,compile and run myshell

## Screenshots

![Image](https://mertiq.github.io/my-own-shell-application/1.png)
![Image](https://mertiq.github.io/my-own-shell-application/2.png)

## Built With

* [C]() - Used to code all things.

## Acknowledgments

* [Mertiq](https://github.com/Mertiq)
* [Geeks for Geeks](https://www.geeksforgeeks.org/making-linux-shell-c/)
