CFLAGS=-Wall
GCC=gcc

#
# Compile and run the test suite.
#
tests:
	$(GCC) tests.c -I. -o tests.out && \
	./tests.out

#
# Compile the source files.
#
compile:
	$(GCC) $(CFLAGS) linked_list.c -o linked_list.out	

#
# Remove all executables.
#
clean:
	rm *.out

.PHONY: clean
.PHONY: compile
.PHONY: tests
