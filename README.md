# Assignment 3: Prime Number (Multi-Threading)

## Tasks
### 1. Unpack the Programming Assignment 3 package.
Nothing to write for this task.
### 2. Write a test_prime(1) function, with prototype (int test_prime(int n);) that returns a 0 if n is not prime or 1 if it is prime.
My solution to this is made to be more efficient than the linear checking method, as we are expected to test rather large numbers. My solution is modeled after that found in stackoverflow.com/questions/19608423/efficient-prime-number-function
### 3. Write a prime_search(1) function, with prototype (void* prime_search(void* param);) that serves as a start routine for the prime search threads.