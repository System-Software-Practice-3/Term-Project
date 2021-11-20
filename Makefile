CC = g++
CXXFLAGS = -std=c++11 -g -O2 -Wall
OBJS = TextRec.o Knn.o Ensemble.o test.o
SRCS = TextRec/TextRec.cc Knn/Knn.cc Ensemble/Ensemble.cc test.cc
LIB = -L ~/Kiwi/build -lkiwi
TARGET = Test.out

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJS) $(LIB)

$(OBJS) : $(SRCS)
	$(CC) $(CXXFLAGS) -c $(SRCS)

clean:
	rm -f *.o *.out
