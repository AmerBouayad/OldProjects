#!/bin/bash
echo "echo "coucou moi je peux exécuter et pas toi"" > file1

echo -e "\E[32m Creation d'un fichier test nommé file1\n\E[0m"

getfacl file1
echo -e "\E[32mPermet de voir les ACL par défaut du fichier file1\n\E[0m"

sudo useradd yassin
echo -e "\E[32mCreation d'un user Yassin\n\E[0m"

sudo useradd amer
echo -e "\E[32mCreation d'un user Amer\n\E[0m"

sudo groupadd esigroup
echo -e "\E[32mCreation d'un group esiGroup\n\E[0m"

sudo usermod -a -G esigroup amer
echo -e "\E[32mOn attribut l'utilisateur Amer au groupe esiGroup\n\E[0m"

echo -e "\E[32mAppuyez sur enter pour lancer <setfacl -m u:yassin:rwx,g:esiGroup:r--,o::--- file1>\n\E[0m"
read -p " "
setfacl -m u:yassin:rwx,g:esigroup:rw-,o::--- file1

echo -e "\E[32mDroit attribue à file1\n\E[0m"
getfacl file1

echo -e "\E[32mAppuyez pour executer file1 en tant que Yassin\n\E[0m"
read -p " "
sudo su yassin << 'finYassin'
./file1
finYassin

echo -e "\E[32mAppuyez pour essayez d'éxécuter file1 en tant que Amer\n\E[0m"
read -p " "
sudo su amer << 'finAmer'
./file1
finAmer

rm file1


sudo userdel -fr yassin 2>/dev/null
sudo userdel -fr amer 2>/dev/null
sudo groupdel esigroup


