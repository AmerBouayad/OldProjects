#!/bin/bash

echo -e "\E[32m\n Création du fichier fileLim...\n\E[0m"

touch fileLim

echo -e "\E[32m\n Taille occupé par le fichier vide fileLim...\n\E[0m"

du -h fileLim

echo -e "\E[32m\n Attribution d'ACL en boucle sur le fichier fileLim...\n\E[0m"

for i in {1..508} ; do
    group="group$i"
    if grep -q $group /etc/group ; then
    echo "$group exist"
    else
        sudo groupadd $group
        setfacl -m g:$group:rwx fileLim
    fi
done

echo -e "\E[32m Appuyez enter pour voir le nombre d'ACL attribué au fichier fileLim\E[0m"
read -p " "

getfacl fileLim | grep -v \# | tr -s \\n  | wc -l

echo -e "\E[32m\n Taille occupé par le fichier fileLim après AttributionACL..\n\E[0m"

du -h fileLim

echo -e "\E[32m\n On peut voir que les ACL occupe un bloc physique entier.\n\E[0m"
