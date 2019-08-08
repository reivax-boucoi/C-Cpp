IDIR =.include
ODIR=obj
CC=g++
CFLAGS=-I -g3 -lglut -lGL -lGLU
TARGET=a.out

_DEPS = NoiseMap.h Mesh.h Terrain.h PerlinNoise.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o NoiseMap.o Mesh.o Terrain.o PerlinNoise.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o $(TARGET) $^ $(CFLAGS)
	
run :
	make all
	./$(TARGET)
	make clean
clean :
	rm -f $(ODIR)/*.o
	rm $(TARGET)
