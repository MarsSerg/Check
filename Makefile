CC=g++
CFLAGS=-c -Wall -std=c++11 -g

All : DBGen

DBGen : main.o io.o matches.o
	$(CC) main.o io.o matches.o -o a.out
	
main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp
	

	
io.o : io.cpp
	$(CC) $(CFLAGS) io.cpp
	
matches.o : matches.cpp
	$(CC) $(CFLAGS) matches.cpp
	
clean : 
	rm -rf *.o a.out