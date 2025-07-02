# get_next_line 📄

A project that aims to implement a function to read a line from a file descriptor. This project focuses on file I/O, dynamic memory allocation, and managing buffers to read data efficiently.

## Features 🚀
- **Reading a line**: Reads a line from a file descriptor until a newline (`\n`) or end-of-file (EOF) is encountered.
- **Handling buffers**: Efficiently manages buffers to read data in chunks, ensuring minimal memory usage.
- **Memory management**: Allocates memory dynamically for each line read and frees it when necessary.
- **Multi-platform compatibility**: The function works across platforms with a POSIX-compliant environment.
- **Edge cases**: Handles various edge cases like reading multiple lines, empty lines, or handling files with no newline.

## Installation & Usage 💻

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/Ali-Fayad/get_next_line.git
    cd get_next_line
    ```

2. **Compile the Library**:
    ```bash
    make
    ```

3. **Test the Implementation**:
    After compiling, you can use the `get_next_line` function in your own C code. Example:
    ```c
    #include "get_next_line.h"
    #include <fcntl.h>
    #include <stdio.h>

    int main() {
        int fd = open("file.txt", O_RDONLY);
        char *line;

        while (get_next_line(fd, &line)) {
            printf("%s\n", line);
            free(line);  // Don't forget to free the line!
        }
        close(fd);
        return 0;
    }
    ```

4. **Run with Valgrind** (to check for memory leaks):
    ```bash
    make v
    ```

## How to Use 📌

- **Basic Example**:
    ```c
    char *line;
    while (get_next_line(fd, &line)) {
        // Do something with the line
        printf("Line: %s\n", line);
        free(line);  // Free the memory after use
    }
    ```

- **Supported Features**:
    - Reads a line until `\n` or EOF.
    - Handles files of varying sizes efficiently.
    - Works with any file descriptor, including standard input (`stdin`).

## Built With 🛠️
- **C**: Standard C library functions.
- **File I/O**: Uses `read()` to read from file descriptors.
- **Dynamic Memory**: Manages buffers and memory allocation efficiently.
- **Norminette Compliant**: The code adheres to 42’s strict coding standards.

## Authors ✨
- **Ali-Fayad** (GitHub: [Ali-Fayad](https://github.com/Ali-Fayad))

## License 📜
This project is for educational purposes and follows 42 School's guidelines. All rights reserved.

🚀 **get_next_line**: Efficiently reading lines from file descriptors in C!
