#!/usr/bin/make -f

cfiles=$(wildcard *.c)
# $<表示依赖
all: choice_strcpy.c
	$(CC) $<

test:
	# to test anything i don`t understand
	@echo ${cfiles}

clean:
	-$(RM) a.out

.PHONY: clean
