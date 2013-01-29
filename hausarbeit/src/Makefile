PLATFORM := $(shell uname)
PWD := $(shell pwd)
OMP := -fopenmp

all: prepare helloworld envvars sections tasks

helloworld: prepare
	gcc -c $(OMP) helloworld/hello_world.c -o build/helloworld
	
	@echo finished building helloworld.

envvars: prepare
	gcc -c $(OMP) envvars_libfuncs/envvars_libfuncs.c -o build/envvars_libfuncs
	
	@echo finished building envvars_libfuncs

sections: prepare
	gcc -c $(OMP) sections/sections.c -o build/sections
	
	@echo finished building sections
	
prepare:
	@echo start building...
	
tasks: prepare
	gcc -c $(OMP) tasks/fib.c -o build/tasks
	
	@echo finished building sections

clean: 
	rm -rf hello_world/helloworld.o 
	rm -rf sections/sections.o
	rm -rf build/*