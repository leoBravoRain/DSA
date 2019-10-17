CC = g++
CFLAGS=-Wall -std=c++11
BINS= work2

all: clean compile puntos

compile:
	$(CC) $(CFLAGS) -o $(BINS) $(BINS).cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
