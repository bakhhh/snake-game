CC      = gcc
EXEC    = snake
CFLAGS  = -Wall 
OBJ     = terminal.o main.o 

ifdef DEBUG
CFLAGS += -D DEBUG
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c terminal.h 
	$(CC) $(CFLAGS) -c main.c

terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) -c terminal.c


clean:
	rm -f $(EXEC) $(OBJ)


