### **README.md for Simple Shell**

---

# **Simple Shell**

## **Introduction**
`Simple Shell` est une interpréteur de ligne de commande minimaliste conçu pour imiter certains aspects d'un shell Unix standard. Ce projet a été développé dans le cadre du programme Holberton School pour renforcer les compétences en C et comprendre le fonctionnement interne des shells.

---

## **Fonctionnalités**
- Affichage d'un prompt en attente de commandes utilisateur.
- Exécution des commandes avec ou sans chemin complet (ex: `ls` ou `/bin/ls`).
- Gestion des arguments passés aux commandes (ex: `ls -l`).
- Gestion des commandes internes comme :
  - `exit` : Quitter le shell.
  - `env` : Afficher les variables d'environnement.
- Gestion des erreurs (ex: commande introuvable).
- Lecture et tokenisation des commandes.
- Prise en charge des commandes du PATH.

---

## **Compilation**
Pour compiler le programme, utilisez la commande suivante :
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## **Utilisation**
### **Mode interactif**
Exécutez le shell en mode interactif pour entrer des commandes directement dans le terminal :
```bash
./hsh
$ ls
$ pwd
$ exit
```

### **Mode non-interactif**
Le shell peut également fonctionner en mode non-interactif en lisant des commandes depuis un fichier ou un pipe :
```bash
echo "ls -l" | ./hsh
```

---

## **Exemples**
### **Exécution normale**
```bash
$ ./hsh
$ ls
AUTHORS  main.c  shell.c
$ pwd
/home/user/simple_shell
$ exit
```

### **Commande introuvable**
```bash
$ ./hsh
$ invalid_command
Commande introuvable
$ exit
```

---

## **Fichiers principaux**
### **Code source**
- `main.c` : Point d'entrée principal du shell.
- `traiter_ligne.c` : Lecture et traitement des entrées utilisateur.
- `tknelize.c` : Tokenisation des chaînes de caractères.
- `chercher_commande.c` : Recherche des commandes dans le PATH.
- `creer_processus.c` : Création et gestion des processus pour exécuter les commandes.
- `executer_env.c` : Commande interne `env`.

### **Utilitaires**
- `tools.c` : Fonctions utilitaires (_strdup, _strlen, etc.).
- `shell.h` : Fichier d'en-tête contenant les définitions et prototypes.

### **Fichiers annexes**
- `AUTHORS` : Liste des contributeurs.
- `README.md` : Documentation du projet.
- `man_1_simple_shell` : Manuel pour le shell.

---

## **Fonctionnalités à venir**
- Gestion avancée des redirections (`>`, `>>`, `<`, etc.).
- Implémentation de commandes comme `cd`.
- Gestion des alias et historiques de commandes.

---

## **Dépendances**
Le programme utilise uniquement des fonctions autorisées dans le cadre du projet :
- `execve`, `fork`, `malloc`, `free`, `read`, `write`, `perror`, etc.
- Bibliothèques standard : `<stdio.h>`, `<stdlib.h>`, `<unistd.h>`, `<string.h>`.

---

## **Exécution avec Valgrind**
Pour vérifier l'absence de fuites mémoire :
```bash
valgrind --leak-check=full --track-origins=yes ./hsh
```

---

## **Contributeurs**
- **Ahmed Salem** - <yyahmedsalm@gmail.com>
- **Noumane Bouqetyb
---

## **Manuel**
Un manuel est disponible pour expliquer l'utilisation du shell. Consultez-le avec :
```bash
man ./man_1_simple_shell
```

---
