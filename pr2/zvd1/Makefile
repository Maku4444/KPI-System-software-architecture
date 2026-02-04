CC = gcc
CFLAGS = -Wall
TARGET = zvd1_analysis

all: $(TARGET) analyze

$(TARGET): zvd1.o
	$(CC) -o $(TARGET) zvd1.o

zvd1.o: zvd1.c
	$(CC) $(CFLAGS) -c zvd1.c

analyze: $(TARGET)
	@echo "\n--- Розміри сегментів (size) ---"
	size $(TARGET)
	@echo "\n--- Деталі секцій (objdump) ---"
	objdump -h $(TARGET) | grep -E "text|data|bss"

clean:
	rm -f *.o $(TARGET)

.PHONY: all analyze clean
