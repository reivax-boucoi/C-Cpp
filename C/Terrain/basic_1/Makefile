IDIR =.
ODIR=obj
CC=g++
CFLAGS=-I$(IDIR) -g3 -lglut -lGL -lGLU
TARGET=NoiseGen.exe

_DEPS = NoiseMap.h Mesh.h Terrain.h PerlinNoise.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o NoiseMap.o Mesh.o Terrain.o PerlinNoise.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

default : all

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
run : all
	./$(TARGET)
	
all: $(OBJ)
	$(CC) -o $(TARGET) $^ $(CFLAGS)
	

clean :
	rm -f $(ODIR)/*.o
	rm $(TARGET)
