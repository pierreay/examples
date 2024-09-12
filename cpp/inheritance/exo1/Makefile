BINARY = exo1
CC = g++

run: $(BINARY)
	./$<

%: %.cpp %.h
	$(CC) -Wall -g $< -o $@

clean:
	rm -f $(BINARY) *.o

tags: $(BINARY).cpp
	ctags -R
