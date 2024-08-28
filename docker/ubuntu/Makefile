# Create the Docker container from the image.
build:
	docker build -t myubuntu-example .

# Execute a command in the Docker container and stop the container.
run:
	docker run --rm myubuntu-example /bin/bash -c "cd /examples && ls"

# Get a shell into the Docker container.
shell:
	docker run -it myubuntu-example /bin/bash

# Clean our Docker images and containers.
clean:
	docker rmi -f myubuntu-example
