#!/usr/bin/make -f

cfiles=$(wildcard *.c)

all: choice_strcpy.c
	$(CC) $<

test:
	# to test anything i don`t understand
	@echo ${cfiles}

clean:
	@echo $(RM)
	-$(RM) a.out

.PHONY: clean
