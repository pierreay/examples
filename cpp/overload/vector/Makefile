BINARY = exo2_list
CC = g++

run: $(BINARY)
	./$<

%: %.cpp %.h
	$(CC) -Wall -g $< -o $@

clean:
	rm -f $(BINARY) *.o
