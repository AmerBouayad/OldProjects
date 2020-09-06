###
# [Raphaël Mélotte - raphael.melotte@gmail.com] (with ressources taken from the internet)
#
# This makefile compiles each .cpp file looking like codeX.cpp where 'X' is one or more numbers
# into one executable of the same name, without any extension.
# The output of the compilation along with the output of the execution (if compilation succeeded) 
# is stored in a file postfixed with "_results.txt"
#
# IT DOES SOME NASTY THINGS to try to have a fancier result file, to forcefully 
# stop endless loops and also to avoid commiting large files. 
# Please use it in a non-valuable environment, or don't use it at all.
#
# Required tools are: bash, gcc, valgrind, make
#
# Example: 
# code01.cpp will be compiled into code01, but code01_lib.cpp will NOT be compiled.
# (this is required as cpp files from the exams are often included directly into other files). 
# The results of the compilation will be stored in code01_results.txt.
# If compilation succeeded, the result of the execution will be appended.
# If execution failed at some point (segfault, ...), the beginning of the execution output might
# be printed to file, but an error message followed by the error code will be appended afterwards.
#
# The execution part uses a timeout to avoid running endless loops endlessly.
# If the program is stopped by the timeout, a specific message will be appended in the output.
# If you expect a program to NOT contain an endless loop but it times out, try increasing the
# TIMEOUT value.
#
###

SHELL=/bin/bash

EXEC="Résultat de l'exécution: "
EXEC_TIMEOUT="(ERREUR: timeout! Le programme met trop de temps à s'exécuter, peut-être contient-il une boucle infinie)"
TIMEOUT="10s"
EXEC_FAIL="(ERREUR: erreur d'exécution)!"
COMP="Résultat de la compilation: "
COMP_FAIL="(ERREUR: la compilation a échouée!)"
COMP_SUC="(la compilation a réussie)"


# we can't and don't need to compile codeX_*.cpp, only codeX.cpp:
SRC := $(shell ls | grep -E "code([0-9])+.cpp")

# The compiler we use:
CC = g++

# Flags to give to the compiler:
# remove the next line if you don't want extra warnings in the result file:
CFLAGS = -Wall -Wextra 
CFLAGS += -std=c++14
CFLAGS += -fpermissive # required by the wording

# the binaries will have the same name as the source file, without any extension:
BIN = $(patsubst %.cpp,%,$(SRC))
# files holding the results of both compilation and execution: 
RESULTS = $(patsubst %.cpp,%_results.txt,$(SRC))

progs: $(BIN)

%: %.cpp
# remove the @ symbol to have a more verbose output (make will list what it's doing):
	@- echo $(COMP) > $@_results.txt
	- $(CC) $(CFLAGS) -o $@ $< &>> $@_results.txt && echo $(COMP_SUC) >> $@_results.txt
	@- if [ -f $@ ]; then \
		echo $(EXEC) >> $@_results.txt ;\
		else echo $(COMP_FAIL) >> $@_results.txt;\
	fi
	@- if [ -f $@ ]; then \
		timeout $(TIMEOUT) valgrind -q ./$@ &>> $@_results.txt ;\
		RESULT=$$? ; \
		if [ $$RESULT -eq 124 ]; then \
	       		echo $(EXEC_TIMEOUT) >> $@_results.txt ;\
		fi; \
		if [ $$RESULT -ne 0 ]; then\
			echo $(EXEC_FAIL) "(errno: $$RESULT)" >> $@_results.txt ;\
		fi \
	fi
	$(shell echo "# This gitignore is automatically generated, DO NOT edit it by hand" > .gitignore)
	$(shell find . -size +5M | cat >> .gitignore)
clean:
	-rm -vf $(BIN)
	-rm -vf $(RESULTS)

# We have to tell make that some targets aren't filenames:
.PHONY: progs clean
