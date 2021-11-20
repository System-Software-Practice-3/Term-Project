CC = g++

CFLAGS = -std=c++11 -g 

TARGET = TagRec_test.out
OBJS = TagRec_test.o TagRec.o Knn.o

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

TagRec_test.o : TagRec_test.cc
	$(CC) $(CFLAGS) -c $<

TagRec.o : TagRec.cc
	$(CC) $(CFLAGS) -c $<

Knn.o : ../Knn/Knn.cc
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f *.o TagRec_test.out

