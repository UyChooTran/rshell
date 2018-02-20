# rshell

This is a command shell called rshell written in C++. Our command shell prints out a prompt ("$") and reads in a command written on one line by the user. One command can have 3 components: executable program, (e.g. echo, ls, exit) a list of arguments and connectors.

The connectors which can be used are || (or), && (and), and ; (semi-colon):
If a command is followed ;, then the next command is always executed.
If a command is followed by &&, then the next command is executed only if the first one fails.
If a command is followed by ||, then the next command is executed only if the first one fails.

There is no limit to the number of commands that can be chained together.

Everything after a "#" is considered a comment.

Our commands are executed using the C++ system calls: fork(), execvp() and wait().

List of known bugs:

Doesn't output the current user or working directory on prompt.

The cd command does not execute

Does not handle quoted strings yet

Does not support all operators yet
   
