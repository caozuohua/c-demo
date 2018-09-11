#!/usr/bin/make -f

all: link-node.c
	$(CC) $<

clean:
	@echo $(RM)
	-$(RM) a.out

.PHONY: clean
