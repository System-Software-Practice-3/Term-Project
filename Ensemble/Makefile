CC = g++
CXXFLAGS = -std=c++11 -g -O2 -Wall
OBJS = Ensemble.o Ensemble_Test.o
SRCS = Ensemble.cc Ensemble_Test.cc
TARGET = Ensemble_Test.out

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) $(CXXFLAGS) -c $(SRCS)

clean:
	rm -f *.o *.out
