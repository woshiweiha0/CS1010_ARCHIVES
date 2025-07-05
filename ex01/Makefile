.SILENT: test tidy
.PHONY: all clean compile test tidy

SHELL := /bin/bash
FILES=odd sum candy triangle leap multiple date pressure gcd digits power suffix taxi
CC=clang
LDLIBS=-lm -lcs1010
CFLAGS=@compile_flags.txt

all: compile test

candy: candy.c
	$(CC) $(CFLAGS)    $^ $@-main.c $(LDLIBS) -o $@

compile: $(FILES) 

test: $(FILES) tidy
	for question in $(FILES); do ./test.sh $$question; done

format:
	clang-format -i *.c 2> /dev/null

tidy:
	clang-tidy -quiet *.c 2> /dev/null

clean:
	rm $(FILES)
# vim:noexpandtab
