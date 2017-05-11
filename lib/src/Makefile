
.PHONY: help lib main

help:
	@echo "Please use \`make <target>' where <target> is one of"
	@echo "  lib       to compile and build the demo as static library"
	@echo "  main      to build the demo main program"


lib:
	gcc -c demo.c -iquote ../include -fPIC
	ar cr ../lib64/libdemo.a demo.o

main:
	gcc main.c demo.c -o main -iquote ../include


