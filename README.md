# Craps in C

This repo demos a simple implementation of [Craps](https://en.wikipedia.org/wiki/Craps) in C.

## System Requirement

* A recent C compiler.
* `make(1)`

We tested the program on recent Visual C++, GCC, and Clang.

For Windows users, you may get a `make` port at [GnuWin32](http://gnuwin32.sourceforge.net/).

## Usage

`craps` default to *pass* bet:

```
$ ./craps
Come-out roll: 6 + 4 = 10
Got 5 + 6 = 11. Try again...
Got 2 + 6 = 8. Try again...
Got 3 + 5 = 8. Try again...
Got 4 + 5 = 9. Try again...
Got 5 + 6 = 11. Try again...
Got 2 + 1 = 3. Try again...
Got 1 + 2 = 3. Try again...
Got 6 + 3 = 9. Try again...
Hit: 4 + 6 = 10
The player wins
```

Players may bet on *no pass* as well:

```
$ ./craps wrong
Come-out roll: 2 + 6 = 8
Got 3 + 2 = 5. Try again...
Got 6 + 4 = 10. Try again...
Seven-out: 1 + 6 = 7
The player wins
```

`craps` also runs in quiet mode:

```
$ ./craps -q
lose
```

Run `craps -h` for more usage.

## Copyright

Copyright (c) 2018 Michelle Chen. Licensed under MIT
