C		 = gcc
EXEC	 = snake
CFLAGS = -Wall 
OBJ 	 = terminal.o main.o 

ifdef DEBUG
CFLAGS += -D DEBUG
DEBUG : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c terminal.h
	$(CC) $(CFLAGS) main.c -c

terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c



clean:
	rm -f $(EXEC) $(OBJ)


