CC = g++
CFLAGS=-Wall -std=c++11
BINS= read_points

all: clean compile

compile:
	$(CC) $(CFLAGS) -o $(BINS) $(BINS).cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
