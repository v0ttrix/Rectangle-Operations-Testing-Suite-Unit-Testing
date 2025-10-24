CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
DEBUGFLAGS = -Wall -Wextra -std=c99 -g -DDEBUG
TARGET = rectangle_calc
SRCDIR = BCSRec
SOURCES = $(SRCDIR)/main.c

.PHONY: all clean debug run

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

debug: $(SOURCES)
	$(CC) $(DEBUGFLAGS) $(SOURCES) -o $(TARGET)_debug

clean:
	rm -f $(TARGET) $(TARGET)_debug

run: $(TARGET)
	./$(TARGET)

test:
	@echo "Run unit tests through Visual Studio Test Explorer"
	@echo "Or use: vstest.console.exe BCSRecTesting.dll"
