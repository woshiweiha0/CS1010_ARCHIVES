.SILENT: test tidy
.PHONY: all clean compile test tidy

SHELL := /bin/bash
FILES=counter dot unit largest days id max padovan 
CC=clang
LDLIBS=-lm -lcs1010
CFLAGS=@compile_flags.txt

all: compile tidy test

max: max.c
	$(CC) $(CFLAGS)    $^ $@-main.c $(LDLIBS) -o $@

largest: largest.c
	$(CC) $(CFLAGS)    $^ $@-main.c $(LDLIBS) -o $@

compile: $(FILES)

test: $(FILES)
	for question in $(FILES); do ./test.sh $$question; done

format:
	clang-format -i *.c 2> /dev/null

tidy:
	clang-tidy -quiet *.c 2> /dev/null

clean:
	rm $(FILES)
# vim:noexpandtab
