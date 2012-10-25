CXXFLAGS = -O2 -g -Wall -fmessage-length=0 -ltbb
OBJS = warmup1-main.o
LIBS =
TARGET = warmup1

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
