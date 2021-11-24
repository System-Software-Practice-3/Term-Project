CC = g++
CXXFLAGS = -std=c++11 -g -O2 -Wall
OBJS = TextRec.o Knn.o TextRec_Test.o
SRCS = TextRec.cc TextRec_Test.cc ../Knn/Knn.cc 
LIB = -L ~/Kiwi/build -lkiwi
TARGET = TextRec_Text.out

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJS) $(LIB)

$(OBJS) : $(SRCS)
	$(CC) $(CXXFLAGS) -c $(SRCS)

clean:
	rm -f *.o *.out
