### A propos
Le Makefile fourni permet de compiler tous les codes de l'interro en même temps, 
et de stocker le résultat de chaque compilation et exécution dans des 
fichiers "*_results.txt" séparés.
Ceci dit, il fait des choses pas très catholiques pour essayer d'obtenir des résultats
plus lisibles et éviter de mettre sur git des fichiers trop gros (résultants d'une 
boucle infinie par exemple).

Si un fichier de résultat n'est pas disponible sur git, c'est probablement que le code
contenait une boucle infinie, et générait donc un fichier de résultat trop grand.


### "Fausses erreurs" dans le code
Les erreurs qui empêchaient la compilation mais qui ne correspondaient pas à
l'erreur qu'il fallait trouver dans l'exercice ont été corrigées (par exemple:
le prof a oublié un include ou une déclaration, mais ce n'est pas la réponse
qu'il attend => je l'ai en général corrigé dans le .cpp).

Faites attention au fait que dans l'énoncé de l'interro, il est précisé que l'option
`-fpermissive` est passée à gcc, donc des codes qui ne compileraient pas sans cette option 
peuvent compiler en indiquant un warning au lieu d'une erreur.
Il se peut donc qu'un code qui n'est pas autorisé par le langage compile sans erreur !

Notez qu'à l'interro ni les warnings de compilation ni les codes d'erreurs 
lors de l'exécution ne sont donnés !

### Pour regénérer les résultats:
```
make clean
make
```
ou utilisez le script regen_results.sh fourni.
Veuillez noter que le Makefile utilise Valgrind pour produire un résultat intégrant
les fuites de mémoire éventuelles, et donc regénérer les résultat peux prendre du temps.

Si un résultat vous semble bizarre et que vous voulez le vérifier en compilant/exécutant 
le code à la main, vous pouvez toujours le faire avec:
g++ -std=c++14 -Wextra -Wall -fpermissive -o code1 code1.cpp && ./code1

### Contact
Si vous constatez des comportements inattendus ou des erreurs, ouvrez un issue, ou envoyez moi un
mail: raphael.melotte -at- gmail.com 
