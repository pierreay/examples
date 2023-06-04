INPUT = paper.tex

help:
	@echo make compile
	@echo make clean
	@echo make mrproper

compile:
	pdflatex -shell-escape -interaction nonstopmode $(INPUT)
	pdflatex -shell-escape -interaction nonstopmode $(INPUT)
	#pdflatex -shell-escape -interaction nonstopmode $(INPUT)

clean:
	rm -rf _minted*
	rm -rf *.tex
	rm -rf *.log
	rm -rf *.toc
	rm -rf *.out
	rm -rf *.aux

mrproper: clean
	rm -rf *.pdf
