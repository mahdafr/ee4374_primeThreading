# Assignment 3: Prime Number (Multi-Threading)

## Tasks
### 1. Unpack the Programming Assignment 3 package.
Nothing to write for this task.
### 2. Write a test_prime(1) function, with prototype (int test_prime(int n);) that returns a 0 if n is not prime or 1 if it is prime.
My solution to this is made to be more efficient than the linearly-checking method, as we are expected to test rather large numbers. My solution is modeled after that found in stackoverflow.com/questions/19608423/efficient-prime-number-function
### 3. Write a prime_search(1) function, with prototype (void* prime_search(void* param);) that serves as a start routine for the prime search threads. It will be given a range of integers and will determine which of those in the range are prime. Prime numbers will be written to "primesx", where x is the thread number. Each prime number will be on a separate line in the file.
For assistance in debugging this task, I found my solutions to the two bugs on casting the struct sPRIME_THREAD from a void * to gather the data from the method parameters in the prime_search(1) function. The next step is to open the file to create and write to it with the write(3) buffer.
### 4. Write a mini_shell(1) function, with prototype (void* mini_shell(void* param);) that serves as a start routine for the interactivity thread. This function will display a prompt and take commands from the user.
To do this task, I modified the mini_shell(1) method to be sure it accesses both the primeThreadData[0] and primeThreadData[1] structs to track either (or both) of their progress towards their high values.
### 5. Write the main() program so that two threads can find the prime numbers up to 5 million.
I uncommented the #if--#endif definitions in the mafravi_prog3.c main() function which allowed the threads to be not only created but also tracked in their calls to prime_search() and mini_shell().
### 6. Balance the search load to decrease the execution time as much as possible.
Since my machine seems to want to complete integers up to 5 million in under 2 seconds with every test, my strategy is to increase from 5 million to 7 million. I will keep increasing and testing to break the load evenly across both threads.