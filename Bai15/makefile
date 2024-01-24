CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = output

OBJS = student.o main.o 
#CPPS = student.cpp main.cpp 

#all: $(TARGET)
#	./$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	
student.o: student.cpp student.h
	$(CC) $(CFLAGS) -c $< -o $@
main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#g++ -o out main.cpp
clean:
	del $(OBJS)

