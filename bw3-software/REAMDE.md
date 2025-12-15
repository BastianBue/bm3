# BM3 Supercar - Dokumentation (BM3 = Bastian, Marius, Markus, Max)

Diese Anleitung erklärt, wie du dieses Repository mit PlatformIO und dem CLion-Plugin auf einen unterstützten Mikrocontroller in einem gewünschten Profil installierst, baust und hochlädst.

## Voraussetzungen

- **CLion** (aktuelle Version empfohlen)
- **PlatformIO IDE Plugin** für CLion ([Installationsanleitung](https://docs.platformio.org/en/latest/integration/ide/clion.html))
- **PlatformIO CLI** ([Installationsanleitung](https://docs.platformio.org/en/latest/core/installation.html))
- **Python 3** (wird von PlatformIO benötigt)
- **Unterstütztes Mikrocontroller-Board** (z.B. ESP32-C3 DevKitM-1)
- **USB-Kabel** zum Verbinden des Boards

## Schritt-für-Schritt-Anleitung

1. **Repository klonen**
   ```sh
   git clone <dieses-repository-url>
   cd <repo-ordner>
   ```

2. **Projekt in CLion öffnen**
   - Starte CLion.
   - Wähle `Open` und öffne den Projektordner.
   - CLion erkennt das PlatformIO-Projekt und initialisiert die Umgebung.

3. **Profil auswählen**
   - Profile sind in der `platformio.ini` als Environments definiert (z.B. `development`, `production`).
   - Wähle das gewünschte Profil unten in der PlatformIO-Toolbar in CLion (z.B. `env:development` oder `env:production`).
   - **Hinweis:** Die verschiedenen Profile sind bereits als Run Configurations in IntelliJ/CLion hinterlegt und mit diesem Repository mitgeliefert. Du findest sie im `.idea/runConfigurations`-Verzeichnis und kannst sie direkt verwenden.

4. **Mikrocontroller anschließen**
   - Verbinde dein Board per USB mit dem Computer.
   - Stelle sicher, dass der richtige serielle Port in PlatformIO ausgewählt ist (falls nötig).

5. **Projekt bauen**
   - Klicke auf das PlatformIO-Build-Symbol (Haken) in der CLion-Toolbar oder führe aus:
     ```sh
     pio run -e development   # oder -e production
     ```

6. **Firmware hochladen**
   - Klicke auf das PlatformIO-Upload-Symbol (Pfeil) oder führe aus:
     ```sh
     pio run -e development -t upload
     ```
   - Die Firmware wird auf den Mikrocontroller geflasht.

7. **Serielle Ausgabe überwachen (optional)**
   - Nutze den PlatformIO Serial Monitor (Stecker-Symbol) oder führe aus:
     ```sh
     pio device monitor -e development
     ```

## Diagramme

- [Klassendiagramm (structure.mermaid)](docs/structure.mermaid)
- [State Machine Diagramm (state_machine.mmd)](docs/state_machine.mmd)

## Hinweise
- Um das aktive Profil zu wechseln, einfach ein anderes Environment in der PlatformIO-Toolbar wählen, die entsprechende Run Configuration nutzen oder den `-e`-Parameter bei `pio`-Befehlen verwenden.
- Entwicklungs-spezifische Logs und Features sind nur im `development`-Profil aktiv.
- Weitere Details findest du in der [PlatformIO-Dokumentation](https://docs.platformio.org/).
