#NOM    : Makefile
#CLASSE : Intro - LaboIntro
#OBJET  : Laboratoire F.S. 2ème année
#HOWTO	: make; make clean
#AUTEUR	: MBA 08/2016

Affichage: LaboIntro.pdf
	evince -f LaboIntro.pdf&

LaboIntro.pdf : LaboIntro.tex
	pdflatex LaboIntro.tex
	pdflatex LaboIntro.tex	# 2x pour la T.O.C.

clean:
	rm -f *.aux *.dvi *.idx *.log *.toc *~ 
	find . -name *~ -exec rm -f '{}' \;
	find . -name *.o -exec rm -f '{}' \;
	find . -name *.bak -exec rm -f '{}' \;
