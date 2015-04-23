GCC=gcc
CFLAGS=-Wall
NOT_TESTING=-D NOT_TESTING

#
# Compile and run the test suite.
#
tests: tests.c
	$(GCC) tests.c -I. -o tests.out && \
	./tests.out

#
# Remove all executables.
#
clean:
	rm *.out
