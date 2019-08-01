TARGET= a.out
OBJECTS=main.o include/coureur.o include/liste.o
TOBJECTS=test.o include/coureur.o include/liste.o
CFLAGS= -Wall

default : main

all : main

run: main
	echo "Starting Program Execution..."
	./$(TARGET)
	make clean
	
clean :
	rm -f *.o
	rm -f $(TARGET)

main :
	g++ -Wall -c -fmessage-length=0 -o main.o main.cpp 
	g++ -o $(TARGET) main.o -lglu32 -lopengl32 -lfreeglut
