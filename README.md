# pipex
## About the project
The pipex project at Hive (42 school) serves as an exerccise that helps us to understand the pipes and shell redirections. The goal of the project is to replicate the functionality of a shell command by using C programming language.

Initially, you have an input file, and you apply a command to it. Then, you direct the output of this command to another command, which produces the final output and stores it in an output file.

```bash
< input cmd1 | cmd2 > output
```
In the first bonus section, the project expands its scope. Instead of handling just two commands, the program should manage to handle multiple commands.
```bash 
< input cmd1 | cmd2 | cmd3 ...| cmdn > output
```
The second bonus part introduces us the here_doc (a temporary file that stores multiple lines of text until the delimiter is typed) as the initial parameter. You apply a command to "here_doc" file and it is piped from one command to the next. Also, final command instead of replacing the content of the output file, it appends the result to the end of the output file.

```bash 
cmd1 << LIMITER | cmd1 | cmd2 .... | cmdn >> output
```

## Using get_next_line
`make` for it to compile the mandatory part! 

It can handle to commands:
```bash
./pipex input_file cmd1 cmd2 output_file
```

`make bonus` for it to compile the bonus part! 

First bonus part is similar to mandatory part, however it handels multiple pipes:
```bash
./pipex input_file cmd1 cmd2 ... cmdn output_file
```

The second part of the bonus handels here_doc:
```bash
./pipex here_doc LIMITER cmd1 cmd2 ... cmdn output_file
```
The LIMITER can be any word you choose!
