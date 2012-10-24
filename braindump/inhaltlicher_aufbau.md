## Inhaltlicher Aufbau: Ideen

* **Einleitung** (1 S.)

  Warum ist Parallelprogrammierung so wichtig, blablabla
  Warum ausgerechnet OpenMP

* OpenMP in der Theorie (2 S.)

  * Konzepte
    
    Wie funktioniert das ganze?
    Was kann OpenMP?
    Was braucht man, um OpenMP benutzen zu können (-> spezielle Unterstützung durch Compiler, usf.)

  * OpenMP vs. [MPI|TBB|...]?

    Was macht OpenMP anders als MPI (Nachrichtenaustausch vs. Shared Memory)?
    Was macht OpenMP anders als TBB (Bibliothek vs. Compiler-Feature)?

* Implementierung Algorithmus X (2 S.)

  * Beschreibung des Algorithmus

    Nur kurz, wie funtioniert der Algorithmus?

  * Wie umgesetzt?

  * Laufzeituntersuchung

    Laufzeit tatsächlich mal messen. Verhält sich die Laufzeit wie erwartet?
    Wie verhält sie sich in Abhängigkeit von der Prozessoranzahl?

* Implementierung Algorithmus Y (2 S.)
  * Wie oben
* Fazit (1 S.)
	* Auswertung, Vergleich Laufzeiten der Algorithmen mit TBB evtl ??? 

