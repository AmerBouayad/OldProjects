#!/bin/bash
# Ce script permet de regénérer tous les fichiers _results de chaque interro
for i in * ; do
	if [ -d "$i" ] ; then
		echo "génération des résultats pour $i"
		(cd "$i" ; make clean ; make)
	fi
done
