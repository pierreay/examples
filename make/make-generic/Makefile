# Find the absolute path of the directory containing the Makefile, whatever the
# working directory of the call is.
ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

pwd:
	@echo Try to call the Makefile from another directory:
	@echo \`make -f \$$\MAKEFILE_PATH pwd\`
	@echo "pwd:"
	@pwd
	@echo "\$$(ROOT_DIR):"
	@echo $(ROOT_DIR)
