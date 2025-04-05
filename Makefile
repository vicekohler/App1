CC=gcc
CFLAGS=-Wall -Wextra -g
LDFLAGS=-Wl,--subsystem,console
OBJ=main.o orders.o metrics.o  # Eliminamos utils.o de esta línea

app1: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o app1 $(LDFLAGS)

main.o: main.c orders.h metrics.h
orders.o: orders.c orders.h
metrics.o: metrics.c metrics.h orders.h

clean:
	del /Q *.o app1.exe 2>nul || true