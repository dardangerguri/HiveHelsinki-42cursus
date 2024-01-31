# get_next_line

Understanding file descriptor reading and the application of static variables.

## About the project

The get_next_line project provides a practical approach to understanding file descriptor reading and the application of static variables.

The get_next_line function is designed to retrieve a single line from a specified file. When this function is called in a loop, it sequentially returns the entire file content, one line at a time, until it reaches the end of the file. The buffer size used by the function can be customized during compilation, allowing for adaptability to various scenarios.

A unique feature of this function is its ability to remember the state of the data it has read between consecutive calls. This allows it to resume reading from where it left off in the previous call, ensuring proper retrieval of each line.

The primary advantage of this implementation is its capacity to handle files of any size. It achieves this by incrementally reading and returning data, instead of loading the entire file into memory at once. This memory-efficient approach is particularly beneficial when dealing with large files that could potentially exceed available memory.


By working on the get_next_line project, you will gain practical experience in file I/O operations, gain a deeper understanding of static variables, and learn about memory management techniques. Furthermore, you will develop a comprehensive understanding of line-by-line data reading, a common task in various programming scenarios.

## Bonus Features

The get_next_line bonus version retains the functionality of the initial project but can handle multiple file descriptors simultaneously. If the mandatory part was not written with a single static variable, the bonus version should only use one.

## Running the project

The functions are written in the C programming language and require the `gcc` compiler. As this is not a standalone program, it needs to be compiled with another file. For instance, you can add the following main function for it to work:

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
    close(fd);
    return (0);
}
```

For the bonus version, use the following main function:

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
**Important**
Ensure the files exist for the program to function correctly!

**1. Clone the Git Repository:**

```shell
git clone https://github.com/dardangerguri/get_next_line.git get_next_line
cd get_next_line
```
**2. Compiling the library**

After adding the main file, compile the program as follows:

```shell
gcc main.c get_next_line.c get_next_line_utils.c
```

For the bonus version:

```shell
gcc main.c get_next_line_bonus.c get_next_line_utils_bonus.c
```

To specify the BUFFER_SIZE during compilation:

```bash
gcc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```
**3. Execution:**
```bash
./a.out
```
