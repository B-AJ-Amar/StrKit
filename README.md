# strKit - A C String Library

## Overview
str.h is a comprehensive C library designed to simplify and enhance string manipulation in C programs. It provides a set of efficient and easy-to-use functions for working with C-style strings, offering developers a robust toolkit to streamline string operations.

## Usage Examples

### Input 
```c
#include <stdio.h>
#include "str.h"

int main() {
    // ? strings =================================================================
    str s = strCreate("Hello");
    strExtend(&s, " World");
    printf("%s\n", strGet(s));
    strInsert(&s, "Beautiful ", 6);
    printf("%s\n", strGet(s));
    strFree(&s);
    
    // ? Array of strings ========================================================
    strArray sa = strArrayCreate(5);
    
    strArraySet(&sa, 1, "World");
    strArraySet(&sa, 2, "Beautiful");
    strArraySet(&sa, 3, "Day");
    
    strArraySet(&sa, 3, "Today");

    strArrayAppend(&sa, "!");
    strArrayPush(&sa, "# ");
    strArrayInsert(&sa, "Hello ", 1);

    strArrayPrint(sa);

    return 0;
}

```
### Output
```bash
Hello World
Hello Beautiful World
['# ', 'Hello ', '', 'World', 'Beautiful', 'Today', '', '!', ]
```

## Installation

- Download the library:

    ```bash
    git clone https://github.com/B-AJ-Amar/StrKit.git
    ```

- Include the library header in your C source files:

    ```c
    #include <str.h>
    ```

- Link your project with the `str.h` library during compilation:

    ```bash
    gcc main.c str.c -o myapp 
    ```
# Documention
(comming soon)

# Contributing
strKit is an open-source project, and contributions are welcome!
