CC = g++

CFLAGS = -std=c++11 -g 

TARGET = Tag2Vec_test.out
OBJS = Tag2Vec_test.o Tag2Vec.o Knn.o

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

Tag2Vec_test.o : Tag2Vec_test.cc
	$(CC) $(CFLAGS) -c $<

Tag2Vec.o : Tag2Vec.cc
	$(CC) $(CFLAGS) -c $<

Knn.o : ../Knn/Knn.cc
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f *.o Tag2Vec_test.out

