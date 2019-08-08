IDIR =include
CC=g++
CFLAGS=-I -g3 -lglut -lGL -lGLU
TARGET=a.out

DEPS = NoiseMap.h Mesh.h Terrain.h PerlinNoise.h
OBJ = main.o NoiseMap.o Mesh.o Terrain.o PerlinNoise.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o $(TARGET) $^ $(CFLAGS)
	
clean :
	rm *.o
	rm $(TARGET)
