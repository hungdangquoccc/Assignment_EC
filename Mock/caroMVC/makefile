CC = g++
CFLAGS = -Wall -g

SRS = *.cpp
OBJS = *.o

TARGET = main.exe

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(SRS) $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJS): $(SRS)
	$(CC) $(CFLAGS) -c $(SRS)

clean:
	del $(TARGET) $(OBJS)

