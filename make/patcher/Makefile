# * Variables

# Find the absolute path of the directory containing the Makefile, whatever the
# working directory of the call is.
ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

# URL of the PoC.
REPO_URL:=https://github.com/user/project
# Path of the PoC.
REPO_PATH:=/tmp/project
# Commit to use.
REPO_COMMIT=deadbef

# * Recipes

# Allows to add a description after each target name starting with '\#\#'.
# Remember that targets can have multiple entries (e.g. for long target specifications).
# Source: https://gist.github.com/prwhite/8168133
help:			## Show this help.
help:
	@grep -F -h "##" $(MAKEFILE_LIST) | grep -F -v grep | sed -e 's/\\$$//' | sed -e 's/##//'

clone:			## Clone the PoC repository.
clone: $(REPO_PATH)

$(REPO_PATH):
	git clone $(REPO_URL) $(REPO_PATH)

clean:			## Clean the filesystem from PoC repository.
clean:
	rm -rf $(REPO_PATH)

prepare:		## Clean the PoC repository to prepare it for patching.
prepare:
	cd $(REPO_PATH) && git restore .
	cd $(REPO_PATH) && git checkout $(REPO_COMMIT)

patch-xxx:		## Patch the PoC for XXX.
patch-xxx: prepare
	cd $(REPO_PATH) && patch -p1 -i $(ROOT_DIR)/xxx.patch

run:			## Run the PoC with previously applied patch.
run: clone
	cd $(REPO_PATH) && ./run
