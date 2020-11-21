FLTKCONFIG=/usr/local/src/fltk-1.4.x-git/fltk-config
LD=g++

CXXFLAGS=-g -Wall `$(FLTKCONFIG) --cxxflags`
LDFLAGS=`$(FLTKCONFIG) --ldstaticflags --use-images`
LDLIBS=
LIBS=

SRC=test1.cxx TableBox.cxx
OBJ=$(SRC:.cxx=.o)
EXE=test1
.SUFFIXES: .cxx .h .H .o

all: $(SRC) $(EXE)
	
$(EXE): $(OBJ)
	$(LD) $(OBJ) -o $(EXE) $(LDFLAGS) $(LIBS) $(LDLIBS)

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXE)
