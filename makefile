main: main.o myDLL.o exponentialRand.o
	g++ -o main main.o myDLL.o exponentialRand.o && ./main
#main: main.o myDDL.o EventList.o exponentialRand.o
#    g++ -o main main.o myDLL.o EventList.o exponentialRand.o
main.o: main.cpp myDLL.cpp myDLL.h exponentialRand.cpp exponentialRand.h
	g++ -c main.cpp
myDLL.o: myDLL.cpp myDLL.h
	g++ -c myDLL.cpp
exponentialRand.o: exponentialRand.cpp exponentialRand.h
	g++ -c exponentialRand.cpp
clean:
	rm -f main *.o
