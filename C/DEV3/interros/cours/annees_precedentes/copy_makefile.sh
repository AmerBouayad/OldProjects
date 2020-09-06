#!/bin/bash
# Ce script permet de regénérer tous les fichiers _results de chaque interro
for i in * ; do
	if [ -d "$i" ] ; then
		(cp -v Makefile $i/)
	fi
done
