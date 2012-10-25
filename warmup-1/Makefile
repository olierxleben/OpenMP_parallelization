UNAME = $(shell uname)

ifeq ($(UNAME), Darwin)
LIBS = ../tbb-4.1-osx/libtbb.so
TARGET = warmup1-osx
else
LIBS = ../tbb-4.1-linux/libtbb.so
TARGET = warmup1-linux
endif

CXXFLAGS = -O2 -g -Wall -fmessage-length=0 -ltbb
OBJS = warmup1-main.o

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
