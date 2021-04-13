main: heap.o heapFuncts.o heapFuncts.h
	g++ -g heap.o heapFuncts.o -o main

heap.o: heap.cpp heapFuncts.h
	g++ -c -g heap.cpp

heapFuncts.o: heapFuncts.cpp heapFuncts.h
	g++ -c -g heapFuncts.cpp

clean:
	rm *.o main