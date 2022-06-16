# A Simple Shell Program Using C

Write a simple UNIX command interpreter.

---

## Compilation

Your shell will be compiled this way:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## Testing

Your shell should work like this in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## TASKS

---

0. Betty would be proud
Write a beautiful code that passes the Betty checks

1. Simple shell 0.1











## Issues

> Report issues/bug here: [Issues](https://github.com/oolufolabii/simple_shell/issues)

---

## Contributors

+ **Ademola Sikiru** - [ade2002](https://github.com/Ade2002/)
+ **Olufolabi Otitoola** - [oolufolabii](github.com/oolufolabii/)

chmod u+x as_inbuilts.c && git add --chmod=+x as_inbuilts.c && git commit -m 'as_inbuilts.c' && git push
git add . && git commit -m 'created readme'
