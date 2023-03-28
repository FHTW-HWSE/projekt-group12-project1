# Sitzordnung und Contact Tracing Software

## Funktionale Requirements:

* #### Anlegen/Speichern von Räumen
* #### Eintragen von Studierenden/Schülerkennung
* #### Eintragen von Infiziertenstatus
* #### Rekonstruirbarkeit der Daten: File -> Programm -> File


## Nichtfunktionale Requirements:

* #### Der User soll möglichst durch den ganzen Prozess durchgeleitet werden, ohne komplett neustarten zu müssen
* #### Die Daten sollen in CSV-Files gespeichert werden
* #### Das Verzeichnis der CSV-Files soll gelesen werden können und dem User ermöglicht werden, über einfache Eingaben ein File zu suchen und zu wählen
* #### Die CSV-Files sollen Zeitstempel im Namen tragen, um die Navigation zu erleichtern
* #### Die TXT-Files sollen auch Zeitstempel im Namen haben und zusätzlich, nach welchem Kriterium die Lister der Namen erstellt wurde


## Constrains:

* #### Zeitintensivität

# Programmstruktur für die Sitznachbar-Anwendung
## Hauptprogramm


1. Erstellung eines neuen Hörsaals mit den angegebenen Eigenschaften
2. Generierung des ausgewählten Belegungsmusters im Hörsaal
3. Erstellung einer leeren Liste von Studierenden
4. Schleife zur Eingabe von Studierenden-IDs und Sitzplatz-Nummern
    - Überprüfung der Gültigkeit des Sitzplatzes
    - Hinzufügen des neuen Studierenden zum Hörsaal und zur Liste der Studierenden
    - Aktualisierung der direkten Nachbarn-Liste von jedem betroffenen Studierenden
    - Aktualisierung der indirekten Nachbarn-Liste von jedem betroffenen Studierenden
5. Schleife zur Abfrage von direkten und indirekten Nachbarn
    - Überprüfung der Gültigkeit der Studierenden-ID
    - Anzeige der direkten und indirekten Nachbarn von dem angegebenen Studierenden

## Funktionen

- Überprüfung der Gültigkeit des Sitzplatzes: Überprüfung, ob der angegebene Sitzplatz im Hörsaal vorhanden und nicht belegt ist
- Aktualisierung der direkten Nachbarn-Liste: Hinzufügen von Studierenden, die sich links, rechts, vorne und hinten von einem bestimmten Sitzplatz befinden, zur Liste der direkten Nachbarn dieses Studierenden
- Aktualisierung der indirekten Nachbarn-Liste: Hinzufügen von Studierenden, die von einem der direkten Nachbarn dieses Studierenden umgeben sind, zur Liste der indirekten Nachbarn dieses Studierenden




 <br>  

#### User Story: 
#### Organisator will einen neuen Raum (mit Reihen, Spalten, Belegungsmuster) anlegen können um den Sitzplan zu erstellen

| **Ausgangssituation**: | User ist im Menu                                                                                         |
|------------------------|----------------------------------------------------------------------------------------------------------|
| **Wenn**:              | der User die Erstellung eines Raumes beginnt                                                             |
| **Dann**:              | fordere den User auf, Werte für Reihen und Spalten zu wählen und speichere diese Werte in INT Variablen  |

| **Ausgangssituation**: | der User wird aufgefordert die Reihen und Spalten Anzahl  einzugeben |
|------------------------|----------------------------------------------------------------------|
| **Wenn**:              | wenn der user werte <= 0 eingibt                  |
| **Dann**:              | benachrichtige den user, dass die eingabe falsch war und wiederholt werden muss |

| **Ausgangssituation**: | der user wird aufgefodert die reihen und spalten zahl                            |
|------------------------|----------------------------------------------------------------------------------|
| **Wenn**:              | wenn der user werte <= 0 eingibt                                                 |
| **Dann**:              | benachrichtige den user, dass die eingabe falsch war und wiederholt werden muss  |

| **Ausgangssituation**:  | der user wird aufgefordert die reihen und spalten zahl einzugeben |
|-------------------------|-------------------------------------------------------------------|
| **Wenn**:               | eine gültige eingabe erfolgt ist                                  |
| **Dann**:               | fordere den user auf einen belegungsplan zu wählen                |

| **Ausgangssituation**:  | es wurde gültige werte für reihen/spalten/belegungsplan gewählt                                          |
|-------------------------|----------------------------------------------------------------------------------------------------------|
| **Wenn**:               | der raum nicht erstellt werden konnte                                                                    |
| **Dann**:               | benachrichtige den user, dass die erstellung des neuen raums fehlgeschalgen ist und beende das programm  |

| **Ausgangssituation**:  | es wurde gültige werte für reihen/spalten/belegungsplan gewählt |
|-------------------------|-----------------------------------------------------------------|
| **Wenn**:               | der raum erstellt werden konnte                                 |
| **Dann**:               | lade das file mit dem gerade erstellten raum                    |

#### User Story:
#### Organisator will mehrere Belegungsmuster zur Auswahl haben, um gesetzeskonform zu bleiben

| **Ausgangssituation**:  | der user hat einen neuen raum erstellt                              |
|-------------------------|---------------------------------------------------------------------|
| **Wenn**:               | der User aufgefordert wird ein Belegungsmuster zu wählen            |
| **Dann**:               | werden dem User folgende Muster zur Auswahl gegeben: 25%, 50%, 100% |

| **Ausgangssituation**:  | der User wird aufgefodert eines der erlaubten Muster zu wählen                   |
|-------------------------|----------------------------------------------------------------------------------|
| **Wenn**:               | eine ungültige Wahl erfolgt ist                                                  |
| **Dann**:               | benachrichtige den User und fordere ihn erneut auf ein gültiges Muster zu wählen |

| **Ausgangssituation**:  | der User wird aufgefordert eines der erlaubten Muster zu wählen              |
|-------------------------|------------------------------------------------------------------------------|
| **Wenn**:               | eine gültige wahl erfolgt ist                                                |
| **Dann**:               | erstelle eine matrix mit mit den gewünschten maßen und nullen befüllt |

| **Ausgangssituation**:  | der User wird aufgefodert eines der erlaubten Muster zu wählen und eine richtige Auswahl ist erfolgt |
|-------------------------|------------------------------------------------------------------------------------------------------|
| **Wenn**:               | 100% gewählt wurde                                                                                   |
| **Dann**:               | setze alle Plätze auf 1                                                                              |

| **Ausgangssituation**:  | der User wird aufgefodert eines der erlaubten Muster zu wählen und eine richtige Auswahl ist erfolgt |
|-------------------------|------------------------------------------------------------------------------------------------------|
| **Wenn**:               | 50% gewählt wurde                                                                                    |
| **Dann**:               | setze die Plätze so auf 1, das die Nachbarn oben, unten, links und rechts immer 0 sind              |

| **Ausgangssituation**:  | der User wird aufgefodert eines der erlaubten Muster zu wählen und eine richtige Auswahl ist erfolgt |
|-------------------------|------------------------------------------------------------------------------------------------------|
| **Wenn**:               | 25% gewählt wurde                                                                                    |
| **Dann**:               | setze die Plätze so auf 1, das alle direkten Nachbarn (also inkl. diagonale) immer 0 sind            |

| **Ausgangssituation**:  | ein gültiges Muster wurde gewählt           |
|-------------------------|---------------------------------------------|
| **Wenn**:               | das Muster auf die Matrix angewandt wurde |
| **Dann**:               | dann erstelle ein neues File                |

| **Ausgangssituation**:  | ein gültiges muster wurde gewählt und das muster wurde auf die matrix angewandt                |
|-------------------------|---------------------------------------------------------------------------------------------------|
| **Wenn**:               | das File nicht erstellt werden konnte                                                             |
| **Dann**:               | Benachrichtige den User, dass die Erstellung des Raum fehlgeschlagen ist und beende das Programm  |

| **Ausgangssituation**:  | ein gültiges muster wurde gewählt und das muster wurde auf die matrix angewandt                                                                     |
|-------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Wenn**:               | das File erfolgreich angelegt wurde                                                                                                                    |
| **Dann**:               | schreibe die Matrix eindeutig rekonstruierbar in das eben angelegte File, so dass jeder erlaubte Platz einer Schülerkennung zugeordnet werden kann  |

| **Ausgangssituation**:  | das neue Raum-File wurde erfolgreich angelegt                                                      |
|-------------------------|----------------------------------------------------------------------------------------------------|
| **Wenn**:               | der Sitzplan nicht in das File geschrieben werden konnte                                           |
| **Dann**:               | benachrichtige den User, dass die Erstellung des Raumes fehlgeschlagen ist und beende das Programm |


#### User Story:
#### Organisator will an Hand der Schülerkennung (indirekte) Nachbarn abfragen, um zu benachrichtigende Personen zu ermitteln

| **Ausgangssituation**:  | ein Sitzplan wurde entsprechend eines Belegungsmusters erstellt und Studenten-Kennnummern eingetragen |
|-------------------------|-------------------------------------------------------------------------------------------------------|
| **Wenn**:               | der Organisator einen Studenten als Coronafall einträgt                                               |
| **Dann**:               | gibt das Programm eine Liste zurück die die direkten und indirekten Nachbarn enthält                  |


#### User Story:
#### Organisator will existierende Räume laden können, um später Nachbarn abfragen zu können

| **Ausgangssituation**:  | es existieren verschiedene Räume |
|-------------------------|----------------------------------|
| **Wenn**:               | einer geladen wird               |
| **Dann**:               | wird das File gelesen            |

| **Ausgangssituation**:  | das File wurde gelesen                                                                                        |
|-------------------------|---------------------------------------------------------------------------------------------------------------|
| **Wenn**:               | Schülerkennungen gefunden wurden                                                                              |
| **Dann**:               | wird eine  Matrix erstellt und mit Namen gefüllt, entsprechend dem Belegungsmuster (also inkl leere Plätze) |

| **Ausgangssituation**:  | die Matrix existiert                                                      |
|-------------------------|---------------------------------------------------------------------------|
| **Wenn**:               | der Organisator eine Schülerkennung als infiziert meldet                  |
| **Dann**:               | soll das Programm diesen Eintrag in der Matrix als infiziert kennzeichnen |

| **Ausgangssituation**:  | Schüler ist gekennzeichnet                                                                    |
|-------------------------|-----------------------------------------------------------------------------------------------|
| **Wenn**:               | Nachbarn zu informieren sind (laut Verordnung)                                                |
| **Dann**:               | sollen diese an Hand der Eingabe direkte/indirekte Nachbarn ermittelt werden, über die Matrix |

| **Ausgangssituation**:  | Nachbarn sind zu informieren                                                                                                          |
|-------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **Wenn**:               | der Organisator die Eingabe bestätigt                                                                                                 |
| **Dann**:               | sollen die Nachbarn rekonstruierbar in dem File gekennzeichnet werden, und eine Text-Datei mit Schülerkennungen/Namen erstellt werden |


#### User Story:
#### Organisator will anhand der Studierendenkennung einen Sitzplan speichern können, um Sitzplatz dauerhaft speichern zu können

| **Ausgangssituation**:  | Die Studierendenkennung wird eingeben                               |
|-------------------------|---------------------------------------------------------------------|
| **Wenn**:               | Die Studierendenkennung noch nicht in der Matrix ist                |
| **Dann**:               | dann speichere die Studierendenkennung entsprechend Belegungsmuster |

| **Ausgangssituation**:  | Die Studierendenkennung wird eingeben                                                     |
|-------------------------|-------------------------------------------------------------------------------------------|
| **Wenn**:               | Die Studierendenkennung schon in der Matrix ist                                           |
| **Dann**:               | dann speichere die Studierendenkennung nicht, informiere User und kehre zu Eingabe zurück |
