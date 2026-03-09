# Common Core

Repositorio con mis proyectos del **Common Core** (42). Aquí está la libft, printf y get_next_line que fui haciendo — en algunas carpetas hay más de una versión porque fui iterando hasta que pasaba los tests.

## Qué hay dentro

- **libft** — Reimplementación en C de funciones de la libc (strings, memoria, listas enlazadas). Es la base que usas en el resto del curriculum.
- **ft_printf** — Versión propia de `printf` con los formatos que pide el proyecto.
- **get_next_line** — Lectura línea a línea de un fd (archivo, stdin, etc.) con buffer configurable.

Todo está en C puro, compilado con `-Wall -Wextra -Werror`.

## Cómo compilar

Cada proyecto tiene su propio `Makefile`. Por ejemplo, para libft (la versión que uso como referencia es la de `libft_0`):

```bash
cd Rank0/libft/libft_0
make
```

Genera `libft.a`. Para printf y get_next_line, entra en la carpeta del proyecto que quieras y `make` igual.

## Estructura

```
Rank0/
├── libft/       # varias versiones (libft_0 es la que mantengo)
├── printf/
└── get_next_line/
```

---

Si algo no compila o quieres usar una versión concreta, revisa el `Makefile` de esa carpeta; a veces la ruta del `include` o el nombre del header cambia entre versiones.
