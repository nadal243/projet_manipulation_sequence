# TP6 - Manipulation de sequences ADN

## Presentation

Ce projet de programmation en C manipule des individus et compare des sequences ADN. Il utilise le fichier `ADN.txt` comme base de donnees. Chaque individu est decrit par trois champs separes par des espaces ou des retours a la ligne : son nom, son prenom, puis sa sequence ADN.

## Contenu du projet

- **P1** (`mainP1.c`) : lit des individus depuis `ADN.txt`, les stocke, les affiche dans l'ordre inverse, puis libere la memoire allouee.
- **P2** (`mainP2.c`) : demande deux sequences, calcule leur score avec `Needleman` et affiche un pourcentage de similarite.
- **P3** (`mainP3.c`) : demande une sequence de comparaison, parcourt les individus du fichier et affiche leur similarite ainsi que l'individu ayant le meilleur resultat.
- **`individu.c` / `individu.h`** : definissent la structure `t_indiv` et les fonctions de lecture, d'affichage, de liberation et de calcul de similarite.
- **`score.c` / `score.h`** : contiennent les fonctions de comparaison des sequences.

Les bases ADN utilisees sont `A`, `C`, `G` et `T`. Le caractere `-` peut representer un nucleotide indetermine.

## Compilation et execution

Le Makefile compile la partie P3 :

```sh
make
./mainP3.out
```

Pour compiler les autres parties manuellement :

```sh
gcc -Wall -o mainP1.out mainP1.c individu.c score.c -lm
gcc -Wall -o mainP2.out mainP2.c score.c -lm
```

L'option `-lm` lie la bibliotheque mathematique utilisee par `score.c`. Les commandes doivent etre lancees depuis le dossier contenant `ADN.txt`.
