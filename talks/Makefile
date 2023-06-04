ORG_NAME   = beamer
IMG_DIR    = imgs
FIND_BIN   = /usr/bin/find
DRAWIO_BIN = /usr/bin/drawio

clean:
	rm -rf _minted-$(ORG_NAME) $(ORG_NAME).tex

mrproper: clean
	rm -rf $(ORG_NAME).pdf $(IMG_DIR)/*.drawio.pdf

drawio:
	cd $(IMG_DIR) && $(FIND_BIN) . -name "*.drawio" -exec rm -f {}.pdf \; -exec $(DRAWIO_BIN) --crop -x -o {}.pdf 2>/dev/null {} \;
