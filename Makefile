# Complete this rule
mafravi_prog3: mafravi_prime.o mafravi_prog3.c
	gcc -pthread -o $@ $^ -lm

# Replace with correct file names
mafravi_prime.o: mafravi_prime.c mafravi_prime.h
	gcc -c mafravi_prime.c

clean:
	rm *.o; rm mafravi_prog3 ; rm *~ #del *.o; del mafravi_prog3; del *~
