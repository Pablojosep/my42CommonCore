# Common Core

Repository with my **Common Core** (42) projects. Libft, printf, and get_next_line — some folders have more than one version because I kept iterating until everything passed the tests.

## What's in here

- **libft** — C reimplementation of libc functions (strings, memory, linked lists). It's the base you use for the rest of the curriculum.
- **ft_printf** — My own version of `printf` with the formats required by the project.
- **get_next_line** — Read a file descriptor (file, stdin, etc.) line by line with a configurable buffer.

All plain C, compiled with `-Wall -Wextra -Werror`.

## How to build

Each project has its own `Makefile`. For libft (the version I use as reference is `libft_0`):

```bash
cd Rank0/libft/libft_0
make
```

That produces `libft.a`. For printf and get_next_line, just `cd` into the project folder and run `make` the same way.

## Structure

```
Rank0/
├── libft/       # several versions (libft_0 is the one I keep)
├── printf/
└── get_next_line/
```

---

If something doesn't build or you want to use a specific version, check that folder's `Makefile` — the include path or header name sometimes changes between versions.
