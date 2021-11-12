CC = g++

CFLAGS = -std=c++11 -g 

TARGET = Knn_test.out
OBJS = Knn_test.o Knn.o

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

Knn_test.o : Knn_test.cc
	$(CC) $(CFLAGS) -c $<

Knn.o : Knn.cc
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f *.o Knn_test.out

