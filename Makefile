CC = gcc
CFLAGS = -Wall -Wextra -std=c11
GTK_FLAGS = `pkg-config --cflags --libs gtk+-3.0`

SRC = src/scheduler.c src/algorithms.c src/metrics.c src/report.c
GUI_SRC = src/gui_gtk.c
HEADERS = include/scheduler.h include/algorithms.h include/metrics.h
TARGET = scheduler_simulator

all: $(TARGET)

$(TARGET): $(SRC) $(GUI_SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(GUI_SRC) $(SRC) -o $@ $(GTK_FLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
