TARGET = main
OBJS = main.o GameInfo.o 

CC = c++
CFLAGS = -c -g -W -Wall -Wno-write-strings
LD = c++
LDFLAGS = -o $(TARGET)
LIBS = -lcurses

all : $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $<

clean:
	rm *.o
	rm $(TARGET)