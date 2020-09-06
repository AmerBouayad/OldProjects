#NOM    : Makefile
#CLASSE : Process - LaboProcess
#OBJET  : Laboratoire Process 2ème année
#HOWTO	: make; make clean
#AUTEUR	: J.C. Jaumain, 07/2011

Init:	Affichage
	touch LaboProcess.tex

Affichage: LaboProcess.pdf
	evince LaboProcess.pdf

LaboProcess.pdf: LaboProcess.tex
	pdflatex LaboProcess.tex
	pdflatex LaboProcess.tex	# 2x pour la T.O.C.
	rm -f *.aux *.dvi *.ps *.log *.toc *~

clean:
	find . -name *~ -exec rm -f '{}' \;

