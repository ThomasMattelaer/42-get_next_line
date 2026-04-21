*This project has been created as part of the 42 curriculum by Tmattela*


# Get Next Line

## Description

The **Get Next Line (GNL)** project is a fundamental exercise in C programming that focuses on file I/O, memory management, and static variables.

The goal of this project is to implement a function:

```c
char *get_next_line(int fd);
```

This function reads from a file descriptor and returns **one line at a time**, including the newline character (`\n`). Each call to the function should return the next line until the end of the file is reached.

This project introduces key concepts such as:

* Persistent state using static variables
* Dynamic memory allocation and deallocation
* Buffer management
* Efficient string manipulation
* Handling edge cases like EOF and partial reads


## Instructions

### Compilation

Compile the project using:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c
```

If you want to change the number of character that you need to read

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

### Usage in the main function

1. Open a file using `open()`
2. Call `get_next_line(fd)` in a loop
3. Free each returned line after use
4. Close the file with `close()`

Example:

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

### Notes

* The function returns `NULL` when there is nothing left to read.
* The caller is responsible for freeing the returned string.
* The function works with any file descriptor (files, stdin, etc.).

---

## Algorithm Explanation

The implementation is based on a **persistent buffer strategy** using a static variable.

### Core Idea

The function maintains a static string (`buffer`) that stores leftover (after the '\n') between function calls. This allows the function to "remember" what was read but not yet returned.

### Steps

1. **Initialization**

   * A static variable stores leftover data from previous reads.
   * A temporary buffer is allocated for reading from the file descriptor.

2. **Reading Loop**

   * Data is read in chunks using `read()`.
   * Each chunk is appended to a temporary string.

3. **Line Detection**

   * The function searches for a newline character (`\n`).
   * If found:

     * The part before the newline is extracted and returned.
     * The remaining part is stored in the static variable for the next call.

4. **End of File Handling**

   * If `read()` returns 0 (EOF):

     * If leftover data exists, it is returned as the last line.
     * Otherwise, `NULL` is returned.

### Justification

This approach ensures:

* Efficient reading without re-reading data
* Correct handling of lines split across multiple reads
* Minimal memory usage by reusing stored data
* Compliance with the requirement of returning one line per call

---

## Technical Choices

* **Static Variable**: Used to persist leftover data across function calls.
* **Dynamic Allocation**: Ensures flexibility in handling variable-length lines.
* **Custom String Functions**: (`ft_strjoin`, `ft_substr`, `ft_strdup`, etc.)
* **Buffer Size**: Defined via `BUFFER_SIZE` macro to allow flexible read sizes.

---

## Resources

### Documentation & References

* The GNU C Library documentation (`read`, `malloc`, `free`)
* Geeks for Geeks - Dynamic Memory Allocation in C 
* Manual pages:

  ```bash
  man 2 read
  man 3 malloc
  ```
* 42 intra resources and subject PDF
* Stack Overflow discussions on file reading strategies in C

### Tutorials & Ressources

* https://www.codecademy.com/resources/docs/c/static-variables
* https://www.rapidtables.com/code/linux/gcc/gcc-d.html
* https://www.codequoi.com/variables-locales-globales-statiques-en-c/
* https://medium.com/@lannur-s/gnl-c3cff1ee552b
* https://raw.githubusercontent.com/mxw/grmr/master/src/finaltests/bible.txt
* https://www.youtube.com/playlist?list=PLc4DnsRQbs6ZTJ-CxxtYlec3KyfIU1tQD
*

### AI Usage

AI tools (such as ChatGPT) were used for:

* Conceptual understanding of static variables
* Debugging strategies and reasoning about memory issues
* Generating the README.md
* Clarifying edge cases (EOF handling, buffer behavior)

AI was **not used to generate the final implementation**, but rather as a support tool to better understand the underlying concepts and improve code correctness.

---

