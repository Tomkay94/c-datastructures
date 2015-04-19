CFLAGS=-Wall
GCC=gcc
NOT_TESTING=-D NOT_TESTING
#
# Compile and run the test suite.
#
tests: tests.c
	$(GCC) tests.c -I. -o tests.out && \
	./tests.out

#
# Compile the source files.
#
compile: stack.c stack.h
	$(GCC) $(CFLAGS) $(NOT_TESTING) stack.c -o stack.out	

#
# Remove all executables.
#
clean:
	rm *.out

.PHONY: clean
.PHONY: compile
.PHONY: tests
