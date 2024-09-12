BINARY = exo6
CC = g++

run: $(BINARY)
	./$<

%: %.cpp %.h
	$(CC) -Wall -g $< -o $@

clean:
	rm -f $(BINARY) *.o
