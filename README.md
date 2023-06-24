# get_next_line
Reading from a file descriptor and understanding the use of static variables.
## About the project

The get_next_line is a project at Hive Helsinki (42 School) that helps to learn how to read from a file descriptor and understand the concept of static variables.

The "get_next_line" function retrieves one line at a time from a specified file. If you call this function in a loop, it will gradually return the entire contents of the file, one line at a time, until it reaches the end of the file. You can customize the buffer size used by the function when you compile it, allowing you to adapt it to different situations.

What makes this function interesting is its ability to remember the state of the data it has read between consecutive calls. This means that it can pick up where it left off in the previous call and continue reading from there, ensuring that each line is retrieved properly.

The main advantage of this implementation is that it can handle files of any size because it reads and returns data incrementally, rather than loading the entire file into memory all at once. This approach is memory-efficient and particularly useful when dealing with large files that may exceed the available memory.

By working on the "get_next_line" project, you will gain practical experience in file input/output operations, understand how static variables work, and learn about memory management techniques. Additionally, you will develop a deeper understanding of reading data line by line, which is a common task in many programming scenarios.

## Bonus
The get_next_line bonus, has the same functionality of the initial project but can handle multiple file descriptors at the same time. Also, if the mandatory part wasn't written with only one static variable, the bonus should use only one.

## Using this get_next_line function
The functions are written in C language and thus needs the **`gcc` compiler**. This is not a program, therefore, it needs another file to be compiled with. For example, you can add this main function for it to work.

```C
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    char *line;
    int  fd;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd)
    return (0);
}
```
The bonus main:
```C
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("file.txt", O_RDONLY);
	fd2 = open("file1.txt", O_RDONLY);
	fd3 = open("file2.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd2);
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd3);
		printf("%s\n", line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
```
**Note**
The files should exist for the program to work properly!

**1. Clone  the git repository into your computer:**
```shell
git clone https://github.com/dardangerguri/get_next_line.git get_next_line
cd get_next_line
```
**2. Compiling the library**

After adding the main file, to compile the program, run:
```shell
gcc main.c get_next_line.c get_next_line_utils.c
```
or, for the bonus
```shell
gcc main.c get_next_line_bonus.c get_next_line_utils_bonus.c
```
or, if you want to specify the BUFFER_SIZE in the compilation run this:
```bash
gcc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```
**3. Execution:**
```bash
./a.out
```
## Testing
### Third-party tester
I tested the library with this third-party tester: 
* [gnlTester](https://github.com/Tripouille/gnlTester.git)
