.SILENT: test tidy
.PHONY: all clean compile test tidy

SHELL := /bin/bash
FILES=word line up list length concat search kendall subtract
CC=clang
LDLIBS=-lm -lcs1010
CFLAGS=@compile_flags.txt
CPPFLAGS=

all: compile tidy test 

length: length.c
	$(CC) $(CFLAGS)    $^ $@-main.c $(LDLIBS) -o $@

concat: concat.c length.c
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
