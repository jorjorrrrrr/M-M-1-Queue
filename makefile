CC = g++
#INSTDIR =
#INCLUDE = .
CFLAGS = -g -Wall
#LIBS +=

main: main.o myDLL.o queueServer.o PKTArrivalEventGenerator.o EventList.o exponentialRand.o
	$(CC) -o main main.o myDLL.o queueServer.o PKTArrivalEventGenerator.o EventList.o exponentialRand.o && ./main | tee log.txt
main.o: main.cpp myDLL.cpp myDLL.h exponentialRand.cpp exponentialRand.h
	$(CC) $(CFLAGS) -c main.cpp
queueServer.o: queueServer.cpp queueServer.h
	$(CC) $(CFLAGS) -c queueServer.cpp
PKTArrivalEventGenerator.o: PKTArrivalEventGenerator.cpp PKTArrivalEventGenerator.h
	$(CC) $(CFLAGS) -c PKTArrivalEventGenerator.cpp
myDLL.o: myDLL.cpp myDLL.h
	$(CC) $(CFLAGS) -c myDLL.cpp
EventList.o: EventList.cpp EventList.h
	$(CC) $(CFLAGS) -c EventList.cpp
exponentialRand.o: exponentialRand.cpp exponentialRand.h
	$(CC) $(CFLAGS) -c exponentialRand.cpp
clean:
	rm -f main *.o log.txt
