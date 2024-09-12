BINARY = exo4
CC = g++

run: $(BINARY)
	./$<

%: %.cpp
	$(CC) $< -o $@

clean:
	rm -f $(BINARY) *.o
