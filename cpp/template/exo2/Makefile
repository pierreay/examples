BINARY = exo2
CC = g++

run: $(BINARY)
	./$<

%: %.cpp %.h
	$(CC) -Wall -g $< -o $@

clean:
	rm -f $(BINARY) *.o tags

tags: $(BINARY).cpp
	ctags -R

valgrind: $(BINARY)
	valgrind --leak-check=full ./$(BINARY)
