REPORT=report
LATEX_CC=pdflatex
LATEX_ARGS=-shell-escape -interaction nonstopmode

.PHONY: all clean mrproper install help

all: $(REPORT).pdf

$(REPORT).pdf: $(REPORT).tex
	$(LATEX_CC) $(LATEX_ARGS) -draftmode $(REPORT).tex
	makeindex $(REPORT).idx
	makeglossaries $(REPORT)
	biber $(REPORT)
	$(LATEX_CC) $(LATEX_ARGS) -draftmode $(REPORT).tex
	$(LATEX_CC) $(LATEX_ARGS) $(REPORT).tex
	echo -e "\nCompilation success!\n"

$(REPORT).tex: $(REPORT).org
	emacs --batch -l $(REPORT).el --visit $(REPORT).org --eval '(org-babel-tangle-file "$(REPORT).org")' -f org-latex-export-to-latex --kill
	echo -e "\nTangle and weave success!\n"

clean:
	rm -rf \
	    $(REPORT).aux $(REPORT).log $(REPORT).out $(REPORT).toc     \
	    $(REPORT).lof $(REPORT).loc $(REPORT).lot $(REPORT).lol     \
	    $(REPORT).idx $(REPORT).ilg $(REPORT).ind $(REPORT).loa     \
	    $(REPORT).glg $(REPORT).glo $(REPORT).gls $(REPORT).glsdefs \
	    $(REPORT).ist $(REPORT).acr $(REPORT).acn $(REPORT).alg     \
	    $(REPORT).bbl $(REPORT).bcf $(REPORT).blg $(REPORT).run.xml \
	    _minted-report

mrproper: clean
	rm -rf $(REPORT).pdf $(REPORT).bib $(REPORT).tex

install:
	sudo apt-get install emacs
	emacs --batch -l $(REPORT).el --eval '(message "Emacs initialization success!")' --kill
	sudo apt-get install texlive texlive-science texlive-latex-extra texlive-fonts-extra texlive-luatex texlive-xetex biber python3-pygments
	echo -e "\nInstallation success!\n"

help:
	@echo "Use 'make install' to install needed Emacs packages and TexLive packages."
	@echo "Use 'make $(REPORT).tex' to extract LaTeX code from the Emacs Org-mode source file."
	@echo "Use 'make $(REPORT).pdf' to compile LaTeX code to the final PDF file."
	@echo "Use 'make' to perform both of these steps at once."
	@echo "If an error occurs during LaTeX compilation, try either:"
	@echo "1. Use 'make LATEX_CC=xelatex' or 'make LATEX_CC=lualatex' to use another LaTeX compiler (preferred one)."
	@echo "2. Use 'make -i' to ignore errors (last resort)."
