# Libft
Implementing my own C library with commonly used C standard library functions and some additional functions
## About the project
Libft is the first project in the program of Hive Helsinki (42 School). The Libft project aims to introduce students to Standard C Library functions and some additional functions that will be useful in future projects. By completing this project, students become more familiar with how these functions work, how to implement them, and how to use them. 

## Content of the libft project
The libft project includes a [`Makefile`](Makefile), [`Header file`](libft.h) and the functions.
#### Makefile
| Command | Usage |
| --- | --- |
| `make` | creates .o files for each function of the mandatory part, as well as the main library file, libft.a |
| `make bonus` | creates .o files for each function of the bonus part, as well as the main library file, libft.a |
| `make libft.a` | same as make |
| `make clean` | removes the .o files used to create the library |
| `make fclean` | removes the .o files used to create the library, as well as the libft.a library file |
| `make re` | removes all compilation files and remakes them |

#### C Standard Library Functions

- **Memory** : [`ft_memset`](ft_memset.c) [`ft_bzero`](ft_bzero.c) [`ft_memcpy`](ft_memcpy.c)[`ft_memmove`](ft_memmove.c) [`ft_memchr`](ft_memchr.c) [`ft_memcmp`](ft_memcmp.c) [`ft_calloc`](ft_calloc.c)

- **String** : [`ft_strlen`](ft_strlen.c) [`ft_strlcpy`](ft_strlcpy.c) [`ft_strlcat`](ft_strlcat.c) [`ft_strchr`](ft_strchr) [`ft_strrchr`](ft_strrchr.c) [`ft_strnstr`](ft_strnstr.c) [`ft_strncmp`](ft_strncmp) [`ft_strdup`](ft_strdup.c) [`ft_atoi`](ft_atoi.c)

- **Type** : [`ft_isdigit`](ft_isdigit.c) [`ft_isalpha`](ft_isalpha.c) [`ft_isalnum`](ft_isalnum.c) [`ft_isprint`](ft_isprint.c) [`ft_toupper`](ft_toupper.c) [`ft_tolower`](ft_tolower.c)

#### Additional Functions

- **String** : [`ft_substr`](ft_substr.c) [`ft_strjoin`](ft_strjoin.c) [`ft_strtrim`](ft_strtrim.c) [`ft_split`](ft_split.c) [`ft_itoa`](ft_itoa.c) [`ft_strmapi`](ft_strmapi.c) [`ft_striteri`](ft_striteri.c)
- **Write** : [`ft_putchar_fd`](ft_putchar_fd.c) [`ft_putstr_fd`](ft_putstr_fd.c) [`ft_putendl_fd`](ft_putendl_fd.c) [`ft_putnbr_fd`](ft_putnbr_fd.c)

#### Bonus Part

- **Linked list** : [`ft_lstnew`](ft_lstnew.c) [`ft_lstadd_front`](ft_lstadd_front.c) [`ft_lstsize`](ft_lstsize.c) [`ft_lstlast`](ft_lstlast.c) [`ft_lstadd_back`](ft_lstadd_back.c) [`ft_lstdelone`](ft_lstdelone.c) [`ft_lstclear`](ft_lstclear.c) [`ft_lstiter`](ft_lstiter.c) [`ft_lstmap`](ft_lstmap.c)

## Using this library
The library is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

**1. Clone  the git repository into your computer:**
```shell
git clone https://github.com/dardangerguri/libft.git
cd libft
```
**2. Compiling the library**

To compile the library, run:
```shell
make && make bonus && make clean
```
**3. Using it in your code**

To use the library functions in your code, simply include its header:
```C
#include "libft.h"
```
and, when compiling your code, add the required flags:
```shell
-lft -L path/to/libft.a -I path/to/libft.h
```
## Testing
### Third-party Testers
I tested the library with three third-party testers: 
* [libftTester]([https://github.com/Tripouille/libftTesterlibf](https://github.com/Tripouille/libftTester))
* [libft-unit-test](https://github.com/alelievr/libft-unit-test)
* [libft-war-machine](https://github.com/0x050f/libft-war-machine)
## :exclamation: Notes
In a 42 School, projects must be written according to Norm rules.
Functions must not terminate unexpectedly apart from undefined behavior. For example, segmentation fault, bus error, double free, etc.
This library is compiled with GCC by specifying the -Wall -Wextra -Werror flags. And Makefiles should not be relinked.
Global variables cannot be used.
If you need sub-functions to write complex functions, you should define these sub-functions as static to avoid publishing them with the library.
