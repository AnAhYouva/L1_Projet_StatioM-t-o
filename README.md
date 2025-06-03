🌦️ Station Météo avec ESP32, Python et Tkinter
🔧 Présentation du projet
Ce projet consiste à réaliser une station météo simple capable de mesurer la température, l’humidité et la luminosité. Les données sont collectées à l’aide de capteurs connectés à une carte ESP32 (UCA Education Board), puis transmises en série USB à un ordinateur.

Un script Python lit ces données en temps réel, les affiche dans une interface graphique Tkinter et propose diverses fonctionnalités supplémentaires.



⚙️ Fonctionnement général
Les capteurs mesurent la température, l’humidité et la lumière ambiante.

L’ESP32 envoie les données via le port série USB.

Un script Python lit les données et les affiche dans une fenêtre Tkinter.

L’interface permet une lecture claire et en direct des mesures.



🛠️ Problèmes rencontrés
Détection difficile du port COM sous Windows.

Valeurs parfois erronées du capteur SI7021.

Problèmes de synchronisation entre Arduino et Python.

Nécessité d’ajouter manuellement certaines bibliothèques Python sur Windows.



🚀 Améliorations possibles
Ajout d’un graphique en temps réel avec Matplotlib.

Sauvegarde automatique des données dans un fichier CSV.

Envoi des données via LoRaWAN vers The Things Network.

Création d’un affichage web local grâce à un mini-serveur hébergé sur l’ESP32.
