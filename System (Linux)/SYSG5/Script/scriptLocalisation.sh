#!/bin/bash

echo -e "\n\E[32mCréation d'un fichier file2...\E[0m"
touch file2
 
echo -e "\n\E[32mInsertion de texte dans file2...\E[0m"
pwd > file2
 
echo -e "\n\E[32mRécuperation des ACL par défaut de file2...\E[0m"
getfacl file2
 
echo -e "\n\E[32mCréation du group testGroup...\E[0m"
sudo groupadd testGroup
 
echo -e "\n\E[32mStockage du n° inode dans une variable i...\E[0m"
i=$(ls -li | grep file2 | cut -f1 -d ' ')

echo -e "\n\E[32mLe numéro d'inode de file2 est : \E[0m"
echo $i
 
echo -e "\n\E[32mStockage du n° de partition contenant /home dans une variable s...\E[0m"
s=$(lsblk | grep /home | cut -c3-7)

echo -e "\n\E[32mLe numéro d'inode de file2 est : \E[0m"
echo $s
 
echo -e "\n\E[32mPassage en mode debugger\E[0m"
sudo debugfs /dev/$s <<END
stat <$i>
q
END
 
echo -e "\n\E[32mAppuyez enter pour éxécuter setfacl -m g:testGroup:rwx, file2\E[0m"
read -p " "
setfacl -m g:testGroup:rwx, file2 

echo -e "\n\E[32mRécuperation des nouveau ACL par de file2...\n\E[0m"
getfacl file2

echo -e "\n\E[32mPassage en mode debugger\E[0m"
sudo debugfs /dev/$s << END
stat <$i>
q
END

sudo groupdel testGroup
rm file2

