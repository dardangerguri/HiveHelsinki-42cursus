# pipex

Understand pipes and shell redirections by replicating the functionality of a shell command using the C programming language.

## About the project

The Pipex project is a part of the Hive (42 school) curriculum, designed to provide a practical understanding of pipes and shell redirections in Unix-like systems. The main goal is to emulate the functionality of a shell command pipeline using the C programming language.

The project starts with an input file. A command is applied to this file, and the output from this command is redirected to another command. This second command generates the final output and stores it in an output file.

```bash
< input cmd1 | cmd2 > output
```

### Bonus features

The first bonus stage of the project broadens its scope. Rather than just handling two commands, the program should be capable of managing multiple commands.

```bash
< input cmd1 | cmd2 | cmd3 ...| cmdn > output
```
The second bonus stage introduces the concept of a here_doc (a temporary file that holds multiple lines of text until a delimiter is entered) as the initial parameter. A command is applied to the "here_doc" file and it is piped from one command to the next. Additionally, the final command appends the result to the end of the output file, rather than replacing its content.

```bash
cmd1 << LIMITER | cmd1 | cmd2 .... | cmdn >> output
```

## Running the project

To run the project, first clone the repository and navigate into the project directory. Then, use the  `make` command to compile the project.

It can handle to commands:

```bash
./pipex input_file cmd1 cmd2 output_file
```

`make bonus` for the bonus part to compile!

First bonus part is similar to mandatory part, however it handels multiple pipes:

```bash
./pipex input_file cmd1 cmd2 ... cmdn output_file
```

The second part of the bonus handels here_doc:

```bash
./pipex here_doc LIMITER cmd1 cmd2 ... cmdn output_file
```
The LIMITER can be any word you choose!
