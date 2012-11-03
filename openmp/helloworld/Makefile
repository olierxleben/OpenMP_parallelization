SRCS=helloOpenMP.cpp
OBJS=$(SRCS:.cpp=.o)
EXEC=helloOpenMp
CC = g++
CPPFLAGS = -fopenmp -Wall

all: $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(EXEC)

$(OBJS):
	$(CC) $(CPPFLAGS) -c $(@:.o=.cpp)

clean:
	rm $(OBJS)