CC=gcc
CFLAGS = -Wall

src = $(wildcard *.c)
obj = $(src:.c=.o)

algos.a: $(obj)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f $(obj) algos.a
