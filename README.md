Simple Shell (simple_shell)
Description
simple_shell est un interpréteur de commandes UNIX simple, écrit en C, qui implémente les fonctionnalités de base d'un shell. Ce shell affiche un prompt, permet à l'utilisateur de saisir une commande, et exécute la commande correspondante en utilisant execve. Il gère également certaines commandes intégrées, telles que exit pour quitter le shell et env pour afficher les variables d'environnement.

Fonctionnalités
Le shell fournit les fonctionnalités suivantes :

Prompt interactif :

Affiche un prompt "$ " pour inviter l'utilisateur à entrer une commande.
Gestion des commandes :

Attend l'entrée d'une commande par l'utilisateur.
Exécute les commandes externes en recherchant leur chemin d'exécution dans le répertoire courant ou dans le PATH.
Commandes intégrées :

exit : Quitte le shell.
env : Affiche les variables d'environnement actuelles.
Gestion des erreurs :

Si la commande n'est pas trouvée, un message d'erreur est affiché.
Le shell continue à s'exécuter après chaque commande.
Gestion de la condition de fin de fichier (Ctrl+D) :

Si l'utilisateur appuie sur Ctrl+D, le shell se termine proprement.
Installation
Prérequis
Système UNIX/Linux.
Compilateur gcc pour compiler le programme.
Une version de C conforme à la norme gnu89.
Compilation
Clonez le projet, puis compilez-le avec la commande suivante :

bash
Copier le code
git clone https://github.com/votre_utilisateur/simple_shell.git
cd simple_shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 shell_03.c -o simple_shell
Exécution
Une fois compilé, vous pouvez lancer le shell avec :

bash
Copier le code
./simple_shell
Cela affichera un prompt "$ " et vous pourrez entrer des commandes.

Commandes disponibles
exit
La commande exit permet de quitter le shell. Vous pouvez entrer :

bash
Copier le code
$ exit
Le shell se fermera immédiatement.

env
La commande env affiche toutes les variables d'environnement actuelles.

bash
Copier le code
$ env
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
HOME=/home/user
LANG=en_US.UTF-8
...
Architecture
Le projet est structuré comme suit :

bash
Copier le code
simple_shell/
├── shell_03.c      # Code principal du shell
└── README.md        # Ce fichier
Explication du code
main
La fonction main est la fonction principale qui gère la boucle du shell. Elle affiche un prompt, lit la commande entrée par l'utilisateur, et vérifie si la commande est exit ou env. Si c'est le cas, elle appelle les fonctions correspondantes. Si la commande est une commande externe, elle recherche le chemin de l'exécutable et l'exécute en utilisant execve.

display_prompt
Cette fonction affiche le prompt "$ " pour inviter l'utilisateur à entrer une commande.

read_command
Cette fonction lit une ligne de commande entrée par l'utilisateur et la renvoie. Elle gère également la condition de fin de fichier (Ctrl+D).

parse_command
Cette fonction sépare la commande et ses arguments, et renvoie un tableau de chaînes de caractères.

get_command_path
Cette fonction recherche le chemin complet de la commande entrée par l'utilisateur, en vérifiant d'abord si elle est située dans le répertoire courant ou dans les répertoires définis dans la variable d'environnement PATH.

execute_command
Cette fonction exécute la commande entrée en utilisant execve, en passant le chemin de la commande, ses arguments, et les variables d'environnement. Si la commande n'existe pas, un message d'erreur est affiché.

is_exit_command
Cette fonction vérifie si la commande entrée est exit.

is_env_command
Cette fonction vérifie si la commande entrée est env.

print_env
Cette fonction affiche toutes les variables d'environnement en parcourant la variable globale environ.

Exemples d'utilisation
Exemple 1 : Exécution d'une commande simple
bash
Copier le code
$ ls
bin  etc  home  lib  usr
Exemple 2 : Utilisation de la commande env
bash
Copier le code
$ env
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
HOME=/home/user
LANG=en_US.UTF-8
...
Exemple 3 : Utilisation de la commande exit
bash
Copier le code
$ exit
Le shell se ferme et vous revenez à l'invite de commande du terminal.

Gestion des erreurs
Le shell gère plusieurs erreurs courantes :

Si une commande entrée n'existe pas, un message d'erreur est affiché :
bash
Copier le code
$ unknown_command
unknown_command: command not found
Si execve échoue, un message d'erreur est affiché et le shell continue.
Avertissement
Ce shell est un projet éducatif conçu pour vous aider à comprendre comment fonctionne un interpréteur de commandes de base. Il n'implémente pas de fonctionnalités avancées comme les redirections, les tubes (pipes), ou les arguments complexes. Il se concentre sur les bases de l'exécution de commandes et de la gestion des erreurs.

Contribuer
Les contributions au projet sont les bienvenues ! Si vous souhaitez améliorer ce shell, veuillez suivre les étapes ci-dessous :

Fork le projet.
Créez une branche pour votre fonctionnalité (git checkout -b feature/your-feature).
Commitez vos modifications (git commit -am 'Ajout d’une nouvelle fonctionnalité').
Poussez la branche sur votre fork (git push origin feature/your-feature).
Créez une pull request pour discuter de vos modifications.
Licence
Ce projet est sous licence MIT. Voir le fichier LICENSE pour plus d'informations.
