UNAME = $(shell uname)

SYMTARGET = sudoku-tbb

ifeq ($(UNAME), Darwin) 
LIBS =
TARGET = $(SYMTARGET)-osx
else
LIBS = ../tbb-4.1-linux/libtbb.so.2
TARGET = $(SYMTARGET)-tbb-linux
endif

CXXFLAGS = -I include/ -O2 -g -Wall -fmessage-length=0 
OBJS = src/tbbsudoku-main.o src/sudoku.o src/sudokusolver.o

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -ltbb -o $(TARGET) $(OBJS) $(LIBS)
	ln -fs $(TARGET) $(SYMTARGET)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
