SRC = $(wildcard src/*.cpp test/*.cpp)

OBJS = $(SRC:.cpp=.o)

CXXFLAGS = -std=c++14

LIBS = -pthread libgtest.a

INC = -I googletest/googletest \
      -I googletest/googletest/include \
      -I googlemock/googlemock \
      -I googlemock/googlemock/include \
      -I src \
      -I test

EXE = calc.exe

all: $(OBJS)
	cp -f $(OBJS) .
	g++ -o $(EXE) $(CXXFLAGS) $(OBJS) $(LIBS) $(INC)
	rm -f $(OBJS)

%.o: %.cpp
	g++ -c $(CXXFLAGS) $(INC) $< -o $@

.PHONY: clean

clean:
	rm -f *.o *.exe
