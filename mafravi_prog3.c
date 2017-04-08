// UT El Paso EE 4374 Assignment 3
// Multi-threaded Prime Number Search
// Author: ???
//
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h> //@modified mafravi on 04.01 S
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include "mafravi_prime.h" //@modified mafravi on 04.01 S

#define BUFFER_SIZE	1000000

unsigned char buffer[BUFFER_SIZE+1];
unsigned char fileName[100];
FILE *primeFile;
FILE *primeThreadFile;


int main(int argc, char *argv[])
{
  int i, bytesRead, bytesWritten;
  pthread_t tid[MAX_THREADS]; 
  pthread_t tidshell;
  pthread_attr_t attr;
  time_t before, after;

  /* Record time at start */
  before = time(NULL);

  /* Setup threads to find prime numbers */
  pthread_attr_init(&attr);
  numThreads = 2;

  //@modified Mahdokht Afravi on 04.06 R
  //create the two threads
  sPRIME_THREAD ptd[MAX_THREADS];
  ptd[0].num = 1;
  ptd[0].low = 1;
  ptd[0].high = 2500000;
  pthread_create(&(tid[0]),&attr,prime_search,&(ptd[0]));
  ptd[1].num = 2;
  ptd[1].low = 2500001;
  ptd[1].high = 5000000;
  pthread_create(&(tid[1]),&attr,prime_search,&(ptd[1]));

  /* Setup a mini shell thread to provide interactivity with the user */
  pthread_create(&tidshell,&attr,mini_shell,NULL);
  
#if 0

  /* Create primes output file */
  primeFile = fopen("primest","w");
  fclose(primeFile);

  /* Wait for the prime search threads to complete and combine their data */
  for(i = 0; i < numThreads; i++)
    {
      /* Wait for the next thread to complete */
      pthread_join(tid[i],NULL);
      /* On thread completion, write its data to "primest" */
      fileName[0] = '\0';
      sprintf(fileName, "primes%d", i+1);                 // Open the thread's data file
      if((primeThreadFile = fopen(fileName,"r")) == NULL)
	{
	  printf("Failed to open file: %s\n", fileName);
	}
      else
	{
	  if((primeFile = fopen("primest","a")) == NULL)	// Open "primest"
	    {
	      printf("Failed to open file: primest\n");
	    }
	  else
	    {
	      while(feof(primeThreadFile) == 0)
		{
		  /* Read from the thread's data file */
		  bytesRead = fread(buffer,1,BUFFER_SIZE,primeThreadFile);
		  /* Write to the combined file */
		  bytesWritten = fwrite(buffer,1,bytesRead,primeFile);
    		}
	      fclose(primeFile);
	    }
	  fclose(primeThreadFile);
	}
    }
  
  /* Record execution time */
  after = time(NULL);
  printf("\nPrime search done after %ld seconds\n", after-before);
#endif

  sleep(20);
  
  /* Lastly, kill the interaction thread */
  pthread_kill(tidshell, SIGKILL);

  return 0;

}

