CC = g++
CFLAGS = -Wall -g #Đây là các cờ biên dịch. -Wall bật thông báo lỗi cảnh báo chi tiết, 
#và -g thêm thông tin gỡ lỗi để có thể sử dụng trong quá trình debug.

TARGET = main
OBJS = *.o 	#danh sach cac file .o

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del -f $(OBJS) $(TARGET)

