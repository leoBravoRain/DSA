CC = g++
CFLAGS=-Wall -std=c++11
BINS= linked_lists

all: clean compile

compile:
	$(CC) $(CFLAGS) -o $(BINS) $(BINS).cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
