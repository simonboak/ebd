CC      = cc
CFLAGS  = -Wall -Wextra -O2 -std=c99
TARGET  = ebd
PREFIX  = /usr/local

$(TARGET): ebd.c
	$(CC) $(CFLAGS) -o $(TARGET) ebd.c

install: $(TARGET)
	install -m 755 $(TARGET) $(PREFIX)/bin/

clean:
	rm -f $(TARGET)

.PHONY: install clean
