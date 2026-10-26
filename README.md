_This project has been created as part of the 42 curriculum by darmarti_

# get_next_line

## Description

`get_next_line` is a C function that reads and returns one line at a time from
a file descriptor. It keeps unread data between calls, handles lines with or
without a trailing newline, and supports reading from multiple file
descriptors.

The function returns the line including its `\n` character when one is
present. It returns `NULL` when the end of the file is reached or when an
error occurs.

## Function prototype

```c
char *get_next_line(int fd);
```

## Files

- `get_next_line.c` — main line-reading logic and persistent buffers.
- `get_next_line.h` — function declarations, includes, and `BUFFER_SIZE`.
- `get_next_line_utils.c` — memory and string helper functions.
- `main_get_next_line.c` — local test program.
- `tests/` — sample files used for manual testing.

## Compilation and usage

Compile the implementation with a chosen buffer size:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line.c get_next_line_utils.c main_get_next_line.c \
   -o get_next_line
```

Run the test program from the project directory:

```bash
./get_next_line
```

`BUFFER_SIZE` controls how many bytes are read in each system call. If it is
not defined during compilation, the header uses `1` as the default value.

To use the function in another program, compile `get_next_line.c` and
`get_next_line_utils.c`, include `get_next_line.h`, and call
`get_next_line(fd)` repeatedly. The returned strings are dynamically
allocated and must be freed by the caller.

## Testing

The files in `tests/` cover common edge cases, including:

- empty files;
- one-character files;
- files containing only newlines;
- a final line without a trailing newline;
- regular multi-line input.

## Resources

- `read(2)` — reading bytes from a file descriptor.
- `open(2)` — opening files for testing.
- `malloc(3)` and `free(3)` — dynamic memory management.

