CC=gcc
GTK_CFLAGS = $(shell pkg-config --libs --cflags gtk+-2.0)
EXEC=ocr

all: $(EXEC)

$(EXEC): ocr_ui.c
	$(CC) $(GTK_CFLAGS) ocr_ui.c -o $(EXEC)
