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
compile: node.c node.h
	$(GCC) $(CFLAGS) $(NOT_TESTING) node.c -o node.out	

#
# Compile the tests and check for memory leaks.
#
leakcheck:
	make tests && \
	valgrind --track-origins=yes --leak-check=full ./tests.out

#
# Remove all executables.
#
clean:
	rm *.out

.PHONY: clean
.PHONY: compile
.PHONY: tests
