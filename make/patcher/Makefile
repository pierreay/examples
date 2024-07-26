# * Variables

# Find the absolute path of the directory containing the Makefile, whatever the
# working directory of the call is.
ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

# URL of the PoC.
REPO_URL:=https://github.com/tiiuae/jamrf
# Path of the PoC.
REPO_PATH:=/tmp/jamrf
# Commit to use.
REPO_COMMIT=f69801f

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

patch-fm:		## Patch the PoC for FM jamming.
patch-fm: prepare
	cd $(REPO_PATH) && patch -p1 -i $(ROOT_DIR)/poc-constant-jammer-97_1-mhz-fm.patch

patch-wifi:		## Patch the PoC for Wi-Fi jamming.
patch-wifi: prepare
	cd $(REPO_PATH) && patch -p1 -i $(ROOT_DIR)/poc-reactive-jammer-5_3-ghz-wifi.patch

run:			## Run the PoC with previously applied patch.
run: clone
	cd $(REPO_PATH)/HackRF && python jamRF_v1.py
