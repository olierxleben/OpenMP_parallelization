PLATFORM := $(shell uname)
PWD := $(shell pwd)
OMP := -fopenmp
SINGLE := 1

ifdef SINGLE
	$(OMP) := -fopenmp
endif
all: prepare helloworld envvars

helloworld: prepare
	gcc -c $(OMP) hello_world/hello_world.c -o build/helloworld
	
	@echo finished building helloworld.

envvars: prepare
	gcc -c $(OMP) envvars_libfuncs/envvars_libfuncs.c -o build/envvars_libfuncs
	
	@echo finished building envvars_libfuncs

prepare:
	@echo start building...
	
clean: 
	rm -rf hello_world/helloworld.o 
	rm -rf build/*
	
	