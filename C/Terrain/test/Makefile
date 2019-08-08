IDIR =include
ODIR=obj
CC=g++
CFLAGS=-I -g3 -lglut -lGL -lGLU
TARGET=a.out

DEPS = NoiseMap.h Mesh.h Terrain.h PerlinNoise.h
#DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

OBJ = main.o NoiseMap.o Mesh.o Terrain.o PerlinNoise.o
#OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o $(TARGET) $^ $(CFLAGS)
	
clean :
	rm $(ODIR)/*.o
	rm $(TARGET)
