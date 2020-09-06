#!/bin/bash

#Creation d'un dossier et de son default ACL

echo -e "\E[32m\n Héritage d'ACL par défaut démo\n\E[0m"

mkdir dossierACLDefault

echo -e "\E[32m\n Droit du dossier à la creation\n\E[0m"

getfacl dossierACLDefault

echo -e "\E[32m\n Voici les ACL par défaut du dossier créé\n\E[0m"

echo -e "\E[32m\n Appuyez enter pour éxécuter setfacl -dm u::rw-,g::---,o::--- dossierACLDefault\n\E[0m"
read -p " "
setfacl -dm u::rw-,g::---,o::--- dossierACLDefault

echo -e "\E[32m\n Voici les ACL du dossier dorénavant\n\E[0m"

getfacl dossierACLDefault

cd dossierACLDefault

echo -e "\E[32m\n Création du fichier file dans le dossier dossierACLDefault\n\E[0m"

touch file

echo -e "\E[32m\n Voici les ACL de ce fichier\E[0m"

getfacl file 

rm file

cd ..

rmdir dossierACLDefault

