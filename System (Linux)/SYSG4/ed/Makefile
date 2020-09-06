#NOM    : Makefile
#CLASSE : ED - LaboED
#OBJET  : Laboratoire E.D Bloc2
#HOWTO	: make; make clean
#AUTEUR	: J.C. Jaumain, 07/2011
#AUTEUR	: MBA, 08/2018

Init:	Affichage
	touch LaboED.tex

Affichage: LaboED.pdf
	evince -f LaboED.pdf&

LaboED.pdf: LaboED.tex 
	pdflatex LaboED.tex
	pdflatex LaboED.tex	# 2x pour la T.O.C.
	rm -f *.aux *.dvi *.ps *.log *.toc *~

clean:
	find . -name *~ -exec rm -f '{}' \;
