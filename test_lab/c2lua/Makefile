

CC = gcc
AR = ar
CFLAGS = 

OBJS = $(SRCS:%.c=%.o)
LIB_OBJS = $(LIB_SRCS:%.c=%.o)
TARGET = 
LIB_NAME = mylib
LIB_FULL_NAME = lib$(LIB_NAME).a

SRCS = 
LIB_SRCS = main.c

.SUFFIXES : .c .o

all : lib

.c.o:
	@echo "====================="
	@echo "=	compiling $@ "
	@echo "====================="
	$(CC) $(CFLAGS) -c $< -o $@


lib : $(LIB_FULL_NAME)

$(LIB_FULL_NAME) : $(LIB_OBJS)
	$(AR) rcv $@ $(LIB_OBJS)


clean : 
	rm -f $(OBJS) $(LIB_OBJS) $(TARGET)
	
