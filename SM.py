import serial

# === Paramètres série ===
PORT = "COM5"      # ⚠️ Remplace par ton vrai port série (ex: COM3, COM6...)
BAUDRATE = 115200  # Même que dans ton code Arduino

try:
    ser = serial.Serial(PORT, BAUDRATE, timeout=2)
    print(f"🟢 Connecté à {PORT} — Lecture en cours...\n")

    while True:
        line = ser.readline().decode('utf-8').strip()
        if line.startswith("T=") and "H=" in line and "L=" in line:
            # Exemple reçu : T=23;H=56;L=342
            try:
                valeurs = line.split(";")
                temp = valeurs[0].split("=")[1]
                hum = valeurs[1].split("=")[1]
                lux = valeurs[2].split("=")[1]

                print(f"🌡 Température : {temp} °C | 💧 Humidité : {hum} % | 💡 Luminosité : {lux} lux")
            except:
                print("⛔ Format de ligne incorrect :", line)
        else:
            print("⏳ Attente de données valides...")
except serial.SerialException:
    print(f"❌ Impossible d’ouvrir le port {PORT}")
except KeyboardInterrupt:
    print("\n🔴 Arrêt manuel du script")
finally:
    if 'ser' in locals() and ser.is_open:
        ser.close()
        print("🔌 Port série fermé")
