#NOM    : Makefile
#CLASSE : IPC - LaboIPC
#OBJET  : Laboratoire I.P.C. 2ème année
#HOWTO	: make; make clean
#AUTEUR	: J.C. Jaumain, 07/2011

Init:	Affichage
	touch LaboIPC.tex

Affichage: LaboIPC.pdf
	evince LaboIPC.pdf

LaboIPC.pdf: LaboIPC.tex
	pdflatex LaboIPC.tex
	pdflatex LaboIPC.tex	# 2x pour la T.O.C.
	rm -f *.aux *.dvi *.ps *.log *.toc *~

clean:
	find . -name *~ -exec rm -f '{}' \;


