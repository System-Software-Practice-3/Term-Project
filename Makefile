CC = g++

CFLAGS = -std=c++11 -g 

TARGET = test.out
OBJS = test.o TagRec.o Knn.o

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

test.o : test.cc
	$(CC) $(CFLAGS) -c $<

TagRec.o : ./TagRec/TagRec.cc
	$(CC) $(CFLAGS) -c $<

Knn.o : ./Knn/Knn.cc
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f *.o test.out

