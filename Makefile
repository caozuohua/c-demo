#!/usr/bin/make -f

cfiles := $(wildcard *.c)
# $<表示第一个依赖
# $^表示所有依赖
TARGET := $(patsubst %.c, %, $(cfiles))

all: $(TARGET)

$(TARGET): $(cfiles)
	$(CC) -o $@ $^

test:
	# to test anything i don`t understand
	@echo ${cfiles}

clean:
	-$(RM) a.out

.PHONY: clean
