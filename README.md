# C Data Structures
C implementations of various data structures and their operations. Each data structure has it's own set of tests, which can be run, and has been tested for memory leaks, which can also be run. 

## Running Tests

Before running the tests, you must first open a terminal and clone the repo:

`git clone https://github.com/Tomkay94/c-datastructures.git`

##### For A _Specific_ Data Structure
To run the *correctness* tests for a certain data structure:
 - `cd` to the specific data structure's folder.
 - run `make tests`.
 
To run the *memory leak detection* tests for a certain data structure:
- `cd` to the specific data structure's folder.
- run `make leakcheck`.
  
##### For _All_ Data Structures
To run all correctness tests for _all_ data structures:
  - `cd` to the root of the repo folder.
  - run `./makeTests.sh`.
