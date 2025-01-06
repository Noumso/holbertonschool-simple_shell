
---

### **README.md**

```markdown
# Simple Shell

## Description
Le **Simple Shell** est une implémentation d'un interpréteur de commandes Unix de base. Ce projet a été réalisé dans le cadre de la formation en développement à Holberton School. L'objectif principal est de comprendre et d'appliquer des concepts clés de programmation système en C.

---

## Fonctionnalités
- **Mode interactif** :
  - Le shell affiche une invite (`$`) et attend des commandes utilisateur.
- **Mode non interactif** :
  - Le shell exécute des commandes depuis un fichier ou une redirection.
- **Gestion des commandes classiques** :
  - `exit` : Quitte le shell.
  - `env` : Affiche les variables d'environnement.
- **Gestion des erreurs** :
  - Affiche un message lorsque la commande est introuvable.
- **Exécution des commandes avec chemins absolus et relatifs**.

---

## Compilation
Pour compiler le shell :
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## Utilisation
### Mode interactif
Lancez simplement le programme :
```bash
./hsh
```
Vous verrez une invite (`$`). Tapez des commandes comme `ls` ou `pwd` pour les exécuter.

### Mode non interactif
Utilisez une redirection ou un fichier contenant des commandes :
```bash
echo "/bin/ls" | ./hsh
```
ou
```bash
cat commands.txt | ./hsh
```

---

## Exemple de sortie
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

## Diagramme de flux
Voici un diagramme de flux illustrant le fonctionnement de votre shell :

![Diagramme de flux](flowchart.png)

---

## Structure du code
### Principales fonctions
- **`main`** : Gère la boucle principale du shell.
- **`lire_entree`** : Lit les commandes de l'utilisateur.
- **`traiter_ligne`** : Analyse et découpe une ligne de commande.
- **`chercher_commande`** : Recherche le chemin complet d'une commande.
- **`creer_processus`** : Crée un processus enfant pour exécuter la commande.
- **`executer_env`** : Affiche les variables d'environnement.

---

## Ressources utiles
Voici quelques sites qui peuvent vous aider à approfondir vos connaissances :
- [Manuels Unix](https://man7.org/linux/man-pages/)
- [GeeksforGeeks - System Programming](https://www.geeksforgeeks.org/system-programming/)
- [The Linux Programming Interface](http://man7.org/tlpi/) (livre de référence)
- [Learn C Programming](https://www.learn-c.org/)

---

## Auteurs
- **Ahmed Salem H’meyd**  
  [yyahmedsalm@gmail.com](mailto:yyahmedsalm@gmail.com)

---

## Licence
Ce projet est réalisé dans un cadre éducatif et est soumis aux règles académiques de Holberton School.
```

---

### **Diagramme de flux**
Je vais générer un diagramme de flux pour compléter le README.

Le diagramme de flux a été généré avec succès. Vous pouvez le télécharger et l'ajouter au README via ce lien :

[Diagramme de flux](sandbox:/mnt/data/flowchart.png)

Si vous avez besoin d'autres ajustements ou d'ajouts, faites-le-moi savoir !
