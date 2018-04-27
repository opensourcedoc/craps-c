ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')
endif

ifndef CC
	ifeq ($(detected_OS),Windows)
		CC=cl
	else ifeq ($(detected_OS),Darwin)
		CC=clang
	else
		CC=gcc
	endif
endif

ifndef CFLAGS
	ifeq ($(detected_OS),Windows)
		CFLAGS=
	else ifeq ($(detected_OS),Darwin)
		CFLAGS=-O1 -Wall -Wextra -g -std=c99 -fsanitize=address -fno-omit-frame-pointer
	else
		CFLAGS=-Wall -Wextra -g -std=c99
	endif
endif

MEM_CHECK=valgrind

ifeq ($(detected_OS),Windows)
	RM=del
endif

TARGET=craps

all: run

mem: compile
ifeq ($(detected_OS),Windows)
	echo "Not supported"
else
	$(MEM_CHECK) ./$(TARGET)
	echo $$?
endif

run: compile
ifeq ($(detected_OS),Windows)
	.\$(TARGET)
	echo %errorlevel%
else
	./$(TARGET)
	echo $$?
endif

compile:
ifeq ($(detected_OS),Windows)
	$(CC) $(CFLAGS) craps.c
else
	$(CC) $(CFLAGS) -o $(TARGET) craps.c
endif

clean:
	$(RM) $(TARGET)
