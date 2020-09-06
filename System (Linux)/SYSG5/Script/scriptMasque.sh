#!/bin/bash

touch testMask

pwd > testMask

sudo useradd test1

setfacl -m u:test1:rwx testMask
echo -e "\E[32mAppuyez sur Enter pour éxecuter cat testMask \n\E[0m"
read -p " "

#La ligne suivante permet de repasser en user test1 pour test1 le cat
sudo su test1 << 'fintest1'
cat testMask
fintest1


echo -e "\E[32mAppuyez sur Enter pour éxecuter getfacl \n\E[0m"
read -p " "
getfacl testMask

setfacl -m m::x testMask

echo -e "\E[32mAppuyez sur Enter pour éxecuter getfacl\n\E[0m"
read -p " "
getfacl testMask

echo -e "\E[32mAppuyez sur Enter pour éxecuter cat après masque\n\E[0m"
read -p " "

sudo su test1 << 'fintest1'
cat testMask
fintest1

sudo userdel test1 2>/dev/null
rm testMask
