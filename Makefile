CC     := gcc
CFLAGS := -Werror -std=gnu99 -g -Og


OBJS := bitfloat.o ptr.o array.o clab_test.o

all: clab_test

clab_test: $(OBJS)
	gcc $^ -o $@ 

%.o : %.c
	gcc $(CFLAGS) -c ${<}


clean :
	rm -f $(OBJS) clab_test
