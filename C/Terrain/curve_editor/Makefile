IDIR =.
ODIR=obj
CC=g++
CFLAGS=-I$(IDIR) -Wall -g3 -lglut -lGL -lGLU  -std=c++17
TARGET=NoiseGen.exe

_DEPS = CurveEditor.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o CurveEditor.o
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
