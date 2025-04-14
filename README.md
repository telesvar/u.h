# u.h

Provides common type aliases, safe macros, and utilities for convenient programming.

## Features

- **Type Aliases:**  
  Short names for fixed-width integers (`i8`, `u8`, etc.), `usize`, `isize`, and more.
- **Macros:**  
  - `nil` – portable null pointer (`nullptr` or `NULL`)
  - `PROC_NAME` – function name as a string
  - `INLINE` – portable inline keyword
  - `UNUSED` – silence unused variable warnings
  - `countof` – number of elements in a static array
  - `containerof` – get pointer to containing struct from member pointer
  - `likely`, `unlikely` – branch prediction hints
- **Portable `bool` support** for C and C++
- **No dynamic memory, I/O, or platform dependencies**

## Usage

**1. Add `u.h` to your project.**

**2. Always include `u.h` as the very first header in every source file:**

```c
#include <u.h>
...
#include "your_other_headers.h"
```

> [!NOTE]
> `u.h` must be included at the very top of every source file, before any other header.
> This ensures that its typedefs and macros are defined first, and helps avoid warnings or conflicts if other headers define similar names.

## Example

```c
#include "u.h"

#include <stdio.h>

struct Example {
    int x;
};

int main(void) {
    // countof:
    int arr[10] = {0};
    printf("Array has %zu elements\n", countof(arr));

    // containerof:
    struct Example ex = { .x = 123 };
    int *px = &ex.x;
    struct Example *pex = containerof(px, struct Example, x);
    printf("containerof: ex.x = %d, pex->x = %d\n", ex.x, pex->x);

    // PROC_NAME:
    printf("Current function: %s\n", PROC_NAME);

    // nil:
    int *p = nil;
    printf("nil pointer: %p\n", (void *)p);

    // UNUSED:
    int unused_var = 99;
    UNUSED(unused_var);

    return 0;
}
```

## Supported Compilers

- C89 or later, C++98 or later
- GCC, Clang, MSVC, and most embedded toolchains

## FAQ

**Q: Why must `u.h` be included first?**  
A: Including u.h first ensures its typedefs and macros are defined before any other header, which helps avoid warnings or conflicts if other headers define similar names.
In C11 and later, redefining a typedef to the same type is allowed; in earlier standards, it may produce a warning.

**Q: Is it safe for embedded systems?**  
A: For the most part: `u.h` uses only standard headers and features, and does not require dynamic memory or I/O.

**Q: Can I use it in C++?**  
A: Yes.

---

## License

[0BSD](LICENSE).

## Contributing

Issues and suggestions are welcome!  

If you find a portability issue, open an issue or PR.

## Credits

Inspired by Plan9, the Linux kernel, BSDs.
