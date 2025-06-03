🌦️ Station Météo avec ESP32, Python et Tkinter
🔧 Présentation du projet
Ce projet a pour but de réaliser une station météo capable de mesurer trois paramètres environnementaux : la température, l’humidité et la lumière. Pour cela, on utilise une carte ESP32 (UCA Education Board) reliée à plusieurs capteurs. Les données collectées sont envoyées en temps réel à un ordinateur via une liaison série USB, puis traitées et affichées dans une interface graphique développée en Python avec Tkinter. Ce projet s’inscrit dans le cadre du module CSF 2024-2025.

Il vise à mettre en pratique l’interfaçage de capteurs, la communication série entre microcontrôleur et PC, ainsi que la création d’interfaces utilisateur simples en Python.



⚙️ Fonctionnement du système

Voici les principales étapes suivies pour réaliser le projet :

1. Programmation de la carte ESP32 (UCA Board)

Deux codes Arduino ont été utilisés :

Un pour le capteur SI7021 afin de lire la température et l'humidité

Un autre pour le capteur LTR-303ALS pour mesurer la luminosité

Ces deux programmes ont été fusionnés pour envoyer les trois valeurs dans le port série au format :

T=25;H=60;L=432

2. Communication série

La carte envoie les données en boucle via le port COM (USB)

Le débit série est de 115200 bauds

3. Script Python

Un fichier station_meteo_tkinter.py lit les données du port série

Le script analyse les données reçues (séparées par ;)

Il met à jour dynamiquement les étiquettes de l'interface Tkinter

4. Interface Graphique (Tkinter)

Une fenêtre avec trois champs est affichée :

🌡 Température

💧 Humidité

💡 Luminosité

Un indicateur de statut montre si le port COM est connecté ou non

▶️ Utilisation

Connecter la carte UCA au PC

Flasher le code Arduino fusionné

Lancer le script Python avec :

python station_meteo_tkinter.py

Les valeurs s'affichent automatiquement dans la fenêtre Tkinter

🔄 Perspectives

Ajouter un graphique en temps réel (Matplotlib)

Export CSV des données

Interface Web ou envoi à distance via LoRaWAN
