ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

help:
	@echo -e "Test a package development branch during an issue or a pull-request.\n"
	@echo -e "clone:\tClone the package repository in current directory."
	@echo -e "run:\tRun Emacs using a minimal working example."

clone:
	git clone https://github.com/mmitch/ox-bb $(ROOT_DIR)/ox-bb
	cd $(ROOT_DIR)/ox-bb && git checkout link-with-id

run:
	emacs --init-directory=$(ROOT_DIR) mwe.org
