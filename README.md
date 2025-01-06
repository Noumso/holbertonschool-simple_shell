### **README.md**
![Diagramme de flux](images/flowchart.png)
```markdown
# Simple Shell

## Description
Le **Simple Shell** est un projet réalisé dans le cadre de la formation à Holberton School. Ce programme implémente un interpréteur de commandes Unix minimaliste en C. Il a pour objectif d'approfondir les concepts de programmation système et la gestion des processus en utilisant des fonctions Unix natives.

---

## Fonctionnalités
- **Mode interactif** :
  - Affiche une invite (`$`) et attend les commandes utilisateur.
- **Mode non interactif** :
  - Exécute des commandes depuis une redirection ou un fichier.
- **Gestion des commandes** :
  - `exit` : Quitte le shell.
  - `env` : Affiche les variables d'environnement.
- **Gestion des erreurs** :
  - Affiche un message clair si une commande est introuvable.
- **Support des chemins relatifs et absolus pour les commandes.**

---

## Fonctionnement
Voici un flowchart décrivant le fonctionnement du shell :

```mermaid
graph TD;
    A[Utilisateur entre une commande] -->|Commande saisie| B[Lecture de l'entrée utilisateur];
    B --> C[Parsing et tokenisation de la commande];
    C --> D[Recherche du chemin dans PATH];
    D -->|Commande trouvée| E[Création d'un processus enfant];
    E --> F[Exécution de la commande];
    D -->|Commande introuvable| G[Afficher 'Commande introuvable'];
    F --> H[Retour au prompt];
    G --> H;
```
---

## Compilation
Pour compiler le programme, utilisez la commande suivante :
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## Utilisation
### Mode interactif
Lancez le shell directement :
```bash
./hsh
```
Une invite (`$`) s'affichera. Entrez vos commandes, telles que `ls`, `pwd`, ou `env`.

### Mode non interactif
Passez des commandes via un fichier ou une redirection :
```bash
echo "/bin/ls" | ./hsh
cat commands.txt | ./hsh
```

---

## Exemples
### Mode interactif
```bash
$ ls
file1  file2  file3
$ pwd
/home/user
$ exit
```

### Mode non interactif
```bash
$ echo "/bin/ls" | ./hsh
file1  file2  file3
```

---

## Ressources utiles
Voici quelques ressources pour approfondir les concepts abordés dans ce projet :
- **[Manuels Unix](https://man7.org/linux/man-pages/)** : Documentation des appels système et commandes Unix.
- **[GeeksforGeeks - System Programming](https://www.geeksforgeeks.org/system-programming/)** : Articles pédagogiques sur la programmation système.
- **[Learn C Programming](https://www.learn-c.org/)** : Guide interactif pour apprendre le langage C.

---

## Auteurs
- **Ahmed Salem H’meyd**
  - Email : yyahmedsalm@gmail.com

---
