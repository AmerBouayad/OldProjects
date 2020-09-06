# Access Control List (ACL)

Une ACL est une liste d’Access Control donnant ou supprimant des droits d'accès à une personne ou un groupe.
Pour plus de détail, voir le rapport.

## Prérequis

```if grep "CONFIG_FS_POSIX_ACL=y" /boot/config-*; then echo OK; else echo apt-get install acl; fi```		

Si votre noyau ne supporte pas encore ACL, celui-ci sera installé.

## Script

L'intégralité des scripts se trouvent dans le dossier Script, on y trouve 4 scripts:

-scriptAcl.sh: Démonstration du principe d'ACL avec l'utilisation d'utilisateurs et d'un groupe
-heritageACL.sh: Démonstration du principe d'ACL par défaut, héritage d'ACL d'un dossier à son contenu
-scriptMasque.sh: Démonstration du principe de masque
-scriptLocalisation.sh: Permet de d'afficher la localisation physique les ACL
-scriptLimiteAcl.sh: Permet de montrer la limite d'ACL d'un fichier
-suppressionGroupes.sh: Supprime les groupes et leurs ACL crées après l'exécution du script scriptLimiteAcl

Ces scripts sont déjà éxécutables, il suffit d'utiliser la commande ./nomscript afin d'éxécuter le script.

## Rapport

Le rapport est là pour apporter des explications concernant les différents principes 
d'ACL présentés dans les scripts.

Le rapport possède sa version PDF, ainsi que sa version latex se trouvant dans le dossier ACLAzdadBouayadRapport. 

Afin de générer le PDF du rapport, il faut se rendre dans le dossier /ACLAzdadBouayadRapport et d'utiliser la commande "pdflatex ACLAzdadBouayadRapport.tex".

## Auteurs

42392 - Bouayad Amer
42193 - Azdad Yassin



