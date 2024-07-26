# * Variables

# Find the absolute path of the directory containing the Makefile, whatever the
# working directory of the call is.
ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

# * Recipes

# Allows to add a description after each target name starting with '\#\#'.
# Remember that targets can have multiple entries (e.g. for long target specifications).
# Source: https://gist.github.com/prwhite/8168133
help:     ## Show this help.
help:
	@grep -F -h "##" $(MAKEFILE_LIST) | grep -F -v grep | sed -e 's/\\$$//' | sed -e 's/##//'

show-pwd: ## Show the available directories in variables.
show-pwd:
	@echo Try to call the Makefile from another directory:
	@echo \`make -f \$$\MAKEFILE_PATH pwd\`
	@echo "pwd:"
	@pwd
	@echo "\$$(ROOT_DIR):"
	@echo $(ROOT_DIR)

