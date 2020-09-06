#!/bin/bash

echo -e "\E[32m\n Suppression des ACL attribuées à fileLim et des groupes crées...\n\E[0m"


for i in {1..508} ; do
    group="group$i"
    if grep -q $group /etc/group ; then
        sudo groupdel $group
        setfacl -b fileLim
    else
        echo "$group exist not"
    fi
done

echo -e "\E[32m\n Vérification des ACL du fichier fileLim...\n\E[0m"
getfacl fileLim

echo -e "\E[32m\n Suppression du fichier fileLim \n\E[0m"
rm fileLim



