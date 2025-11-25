CC = gcc
CFLAGS = -Wall -Wextra -std=c11
GTK_FLAGS = `pkg-config --cflags --libs gtk+-3.0`

SRC = src/scheduler.c src/algorithms.c src/metrics.c src/gui_gtk.c src/report.c
HEADERS = include/scheduler.h include/algorithms.h include/metrics.h
TARGET = scheduler_simulator

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $^ -o $@ $(GTK_FLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
