// UT El Paso EE 4374 Assignment 3
// Multi-threaded Prime Number Search
// Author: ???
//
#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include "mafravi_prime.h" //@modified Mahdokht Afravi on 04.06 R
#include <stdlib.h> //@modified Mahdokht Afravi on 04.06 R

/* Global variables that are shared */
sPRIME_THREAD primeThreadData[MAX_THREADS];
int numThreads;
//@modified Mahdokht Afravi on 04.06 R
#define BUFF_SIZE 1000000
unsigned char buff[BUFF_SIZE+1];

void *prime_search(void *param) {
  //@modified Mahdokht Afravi on 04.06 R
  sPRIME_THREAD *p = (struct sPRIME_THREAD *) param;
  //open the file to read/write to it
  FILE *f;
  //write(1,p->num,10);
  if ( p->num==1 ) f = fopen("primes1","a");
  else f = fopen("primes2","a");
  if ( f!=NULL ) { //file opened successfully
    for ( (p->current)=(p->low) ; (p->current)<=(p->high) ; p->current++ )
      if ( test_prime((p->current)) )
	fprintf(f,"%d\n",p->current); //write the prime to the file in a new line
    fclose(f);
  }
}

void *mini_shell(void *param) {
  //@modified Mahdokht Afravi on 04.06 R
  int inputSize, i;
  int threadNum;
  char buff[128];		// Character buffer

  while(1) {
    // Request a line of input
    write(1, " -> ", 4);
    // Read the line
    inputSize = read(0, buff, 128);
    // Strip off carriage return
    buff[inputSize-1] = '\0';
		
    if((buff[0] >= '1') && (buff[0] <= '9')) {
      // An integer was entered
      threadNum = buff[0] - '0';
      if(threadNum <= numThreads) {
	printf("Thread %d progress: %d\n", threadNum, primeThreadData[threadNum-1].current);
      } else {
	printf("Thread %d does not exist\n", threadNum);
      }		
    } else {		
      if(buff[0] == 'a') {
	// Print status for all threads
	for(i = 0; i < numThreads; i++) {
	  printf("Thread %d progress: %d\n", i+1, primeThreadData[i].current);
	}
      } else {
	printf("Unrecognized input\n");
      }
    }
    printf("\n");
    fflush(NULL);
  }
  pthread_exit(0);
}

//@modified Mahdokht Afravi, 80483123 on 04.04 T
int test_prime(int n) {
  //2 is prime
  if ( n==2 )
    return 1;
  //n/2 has no remainder, not prime
  if ( (n%2)==0 )
    return 0;
  //from 3->sqrt(n)
  for ( int i=3 ; i*i<=n ; i+=2 )
    if ( (n%i)==0 )
      return 0;
  return 1;
}
