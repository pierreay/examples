# Package name.
PKG_NAME=mypkg

# * Running

# Run the package main function as a module and exit.
run:
	python -c "from $(PKG_NAME) import main; main.main()"

# Run the package main function as a module and gives interactive REPL.
run-repl:
	python -i -c "from $(PKG_NAME) import main; main.main()"

# Run the package main function as a script.
run-script:
	$(PKG_NAME)/main.py

# * Building

# Build the Python distribution of our project.
build:
	python -m build

# * Installing to root

# Install the project system-wide using static installation method (copying files).
install-root-dist:
	sudo pip install --break-system-packages .

# Install the project system-wide using dynamic installation method (symlinking files).
install-root-dev:
	sudo pip install --break-system-packages --editable .

# Uninstall the project system-wide.
uninstall-root:
	sudo pip uninstall --break-system-packages $(PKG_NAME)

# * Installing to user

# Install the project user-wide using static installation method (copying files).
install-user-dist:
	pip install --break-system-packages --user .

# Install the project user-wide using dynamic installation method (symlinking files).
install-user-dev:
	pip install --break-system-packages --user --editable .

# Uninstall the project user-wide.
uninstall-user:
	pip uninstall --break-system-packages $(PKG_NAME)

# * Cleaning

clean:
	sudo rm -rf build
	sudo rm -rf $(PKG_NAME).egg-info
	sudo rm -rf $(PKG_NAME)/__pycache__
