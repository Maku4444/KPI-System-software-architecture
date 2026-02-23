CC = gcc
TARGET = app

all:

run_all: clean step1 step2 step3 step4 step5

step1:
	$(CC) zvd2_2.c -o $(TARGET)_s1
	@echo "\n--- КРОК 1: Базовий Hello World ---"
	@ls -l $(TARGET)_s1 && size $(TARGET)_s1

step2:
	$(CC) -DSTEP2 zvd2_2.c -o $(TARGET)_s2
	@echo "\n--- КРОК 2: Глобальний масив (BSS) ---"
	@ls -l $(TARGET)_s2 && size $(TARGET)_s2

step3:
	$(CC) -DSTEP3 zvd2_2.c -o $(TARGET)_s3
	@echo "\n--- КРОК 3: Ініціалізований масив (DATA) ---"
	@ls -l $(TARGET)_s3 && size $(TARGET)_s3

step4:
	$(CC) -DSTEP4 zvd2_2.c -o $(TARGET)_s4
	@echo "\n--- КРОК 4: Локальні масиви (STACK) ---"
	@ls -l $(TARGET)_s4 && size $(TARGET)_s4

step5:
	$(CC) -g zvd2_2.c -o $(TARGET)_debug
	$(CC) -O3 zvd2_2.c -o $(TARGET)_opt
	@echo "\n--- КРОК 5: Debug (-g) vs Opt (-O3) ---"
	@echo "Debug:" && ls -l $(TARGET)_debug && size $(TARGET)_debug
	@echo "Opt:" && ls -l $(TARGET)_opt && size $(TARGET)_opt

clean:
	rm -f app_*

.PHONY: all step1 step2 step3 step4 step5 clean run_all
