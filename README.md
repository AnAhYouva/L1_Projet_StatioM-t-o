🌦️ Station Météo avec ESP32, Python et Tkinter
🔧 Présentation du projet
Ce projet a pour but de réaliser une station météo capable de mesurer trois paramètres environnementaux : la température, l’humidité et la lumière. Pour cela, on utilise une carte ESP32 (UCA Education Board) reliée à plusieurs capteurs. Les données collectées sont envoyées en temps réel à un ordinateur via une liaison série USB, puis traitées et affichées dans une interface graphique développée en Python avec Tkinter. Ce projet s’inscrit dans le cadre du module CSF 2024-2025.

Il vise à mettre en pratique l’interfaçage de capteurs, la communication série entre microcontrôleur et PC, ainsi que la création d’interfaces utilisateur simples en Python.



⚙️ Fonctionnement du système
Lecture des capteurs
La carte ESP32 est connectée à des capteurs permettant de mesurer :

la température et l’humidité (capteur SI7021),

la luminosité ambiante (capteur analogique).

Transmission des données
Les valeurs mesurées sont envoyées à l’ordinateur via le port série USB, selon un format simple (par exemple, séparé par des virgules ou des retours à la ligne).

Traitement en Python
Un script Python lit en continu les données reçues via le port série grâce à la bibliothèque pyserial. Il extrait les valeurs numériques et les prépare pour l’affichage.

Affichage avec Tkinter
Les données sont affichées en direct dans une fenêtre graphique Tkinter. L’interface est conçue pour être lisible, avec des champs mis à jour en temps réel.

(Optionnel) Des extensions peuvent être ajoutées, comme :

l’enregistrement automatique des mesures dans un fichier CSV,

l’affichage graphique en temps réel avec Matplotlib,

ou l’envoi des données à distance via LoRaWAN.
