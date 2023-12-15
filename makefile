CC = g++
#INSTDIR =
#INCLUDE = .
CFLAGS = -g -Wall
#LIBS +=

main: main.o myDLL.o PKTArrivalEventGenerator.o EventList.o exponentialRand.o
	$(CC) -o main main.o myDLL.o PKTArrivalEventGenerator.o EventList.o exponentialRand.o && ./main
main.o: main.cpp myDLL.cpp myDLL.h exponentialRand.cpp exponentialRand.h
	$(CC) $(CFLAGS) -c main.cpp
PKTArrivalEventGenerator.o: PKTArrivalEventGenerator.cpp PKTArrivalEventGenerator.h
	$(CC) $(CFLAGS) -c PKTArrivalEventGenerator.cpp
myDLL.o: myDLL.cpp myDLL.h
	$(CC) $(CFLAGS) -c myDLL.cpp
EventList.o: EventList.cpp EventList.h
	$(CC) $(CFLAGS) -c EventList.cpp
exponentialRand.o: exponentialRand.cpp exponentialRand.h
	$(CC) $(CFLAGS) -c exponentialRand.cpp
clean:
	rm -f main *.o
