

CC = gcc
SRCS = main.c print.c
OBJS = $(SRCS:%.c=%.o)
TARGET = main
DBG_FLAGS = -g -O0

.SUFFIXES : .c .o

all : $(TARGET)

.c.o:
	@echo "================================"
	@echo "=Compiling $@ "
	@echo "================================"
	$(CC) $(DBG_FLAGS) -c $< -o $@

$(TARGET) : $(OBJS)
	$(CC) $(DBG_FLAGS) -o $(TARGET) $(OBJS)

depend :
	gccmakedep $(SRCS)


clean : 
	rm -f $(OBJS) $(TARGET)



