## Push_swap mit dem Quicksort-Algorithmus

### Push_swap-Aufgabe

Die Push_swap-Aufgabe besteht darin, eine Liste von Zahlen auf zwei Stacks, A und B, zu sortieren. Es stehen verschiedene Operationen zur Verfügung, wie das Vertauschen, Verschieben und Rotieren von Elementen auf den Stacks. Das Ziel ist es, die Liste auf Stack A in aufsteigender Reihenfolge zu sortieren, wobei die effizienteste Anzahl von Operationen angestrebt wird.

Mit dieser Methode erreichte ich die volle Punktzahl 100/100%.

### Modifizierter Quicksort-Algorithmus

In diesem Projekt habe ich mich entschieden, den Quicksort-Algorithmus zu modifizieren, um die spezifischen Anforderungen von Push_swap zu erfüllen. Hier ist eine Übersicht der modifizierten Funktionen:


#### `sort_to_b`-Funktion

1. Überprüfung auf Aufsteigende Sortierung:

Bevor mit der eigentlichen Sortierung begonnen wird, erfolgt eine Überprüfung, ob der Stack A bereits aufsteigend sortiert ist. Diese Überlegung basiert auf der Erkenntnis, dass eine bereits sortierte Liste keine weiteren Sortieroperationen erfordert. In diesem Fall kann die Funktion frühzeitig abbrechen, da das Ziel bereits erreicht ist.


2. Sortierung der Liste im spezial Fall:

Für Listen mit einer geringen Anzahl von Elementen, nämlich drei oder weniger, wird eine spezielle Sortierungsfunktion (`sort_three_a`) aufgerufen. 
Dieser Ansatz beruht auf dem Fakt das es bei einer Listengröße von maximal 3 Zahlen nur 5 mögliche if else bedingungen braucht um diese auf effizientesten Weg zu sortieren.


3. Berechnung des Medians:

Der Median der aktuellen Liste auf Stack A wird berechnet, um als Orientierungspunkt für die Aufteilung der Liste zu dienen. Die Wahl des Medians ermöglicht eine ausgewogene Verteilung der Elemente auf die beiden Stacks, was zu einer effizienteren Sortierung beiträgt.
Dabei habe ich mich für eine temporäre Vorsortierung entschieden und nehme mir dann die Zahl aus meinem Array aus dem Index max_länge / 2.
Dadurch erhalten wir den perfekte Median und können dadurch die höchste Punktzahl erreichen.
Anschließend wird diese Vorsortierte Liste wieder verworfen und nicht weiter genutzt.


4. Verschieben und Rotieren:

Die Entscheidung, ob ein Element auf Stack B verschoben oder Stack A rotiert wird, hängt von seiner Position im Verhältnis zum Median ab. Diese Entscheidung gründet sich darauf, ob das Element kleiner oder größer als der Median ist. Der Prozess des Verschiebens und Rotierens spielt eine entscheidende Rolle bei der korrekten Anordnung der Elemente in beiden Stacks. Während des Sortiervorgangs von Stack A zu Stack B wird überprüft, ob ein Element kleiner als der Median ist. Falls dies zutrifft, wird das Element zu Stack B verschoben. Andernfalls erfolgt eine Rotation, bis die Bedingung erneut erfüllt ist und wir die maximale Anzahl an pushs durchgeführt haben (Aktuelle Stack A Size / 2 + %2).

5. Rekursive Aufrufe:

Die rekursiven Aufrufe sind ein wesentlicher Bestandteil des Sortierprozesses und tragen dazu bei, die Teilisten auf beiden Stacks effektiv zu sortieren. Nach der Verschiebung oder Rotation der Elemente in den vorherigen Schritten wird die Funktion rekursiv aufgerufen, um den verbleibenden Teil der Liste sowohl auf Stack B als auch auf Stack A zu sortieren. Diese wiederholten rekursiven Aufrufe gewährleisten, dass die Sortierung bis zur vollständigen Anordnung der Elemente fortgesetzt wird. Dieser iterative Ansatz ermöglicht eine effiziente und präzise Sortierung der gesamten Liste auf beiden Stacks.

In der `sort_to_b`-Funktion rufe ich `sort_to_a` auf, wenn die Liste auf Stack A erfolgreich in die Teilisten auf Stack B verschoben wurde. Dies geschieht, nachdem die Elemente gemäß dem Median auf Stack B verschoben oder auf Stack A rotiert wurden. Dann wird die `sort_to_a`-Funktion rekursiv aufgerufen, um den verbleibenden Teil der Liste auf Stack A zu sortieren.

In der `sort_to_a`-Funktion hingegen rufe ich `sort_to_b` auf, wenn die Liste auf Stack B erfolgreich in die Teilisten auf Stack A verschoben wurde. Dies geschieht, nachdem die Elemente gemäß dem Median auf Stack A verschoben oder auf Stack B rotiert wurden. Danach wird die `sort_to_b`-Funktion rekursiv aufgerufen, um den verbleibenden Teil der Liste auf Stack B zu sortieren.

Diese alternierenden rekursiven Aufrufe sorgen dafür, dass die Sortierung der Liste sowohl auf Stack A als auch auf Stack B in einer effizienten und abwechselnden Weise durchgeführt wird, bis die gesamte Liste auf beiden Stacks vollständig sortiert ist.

#### `sort_to_a`-Funktion

Diese Funktion verhält sich sehr ähnlich zu der oben beschriebenen `sort_to_b`-Funktion.
Der einzige gravierende Unterschied liegt dabei das wir nun in Stack B eine sehr grobe in Absteigender Form Sortierte Liste vorfinden und dadurch noch die überprüfung mit der Zahl und des Medians umkehren.
Nun suchen wir nach einer Zahl die größer gleich des Medians entspricht und pushen diese Aahl un Absteigender Form zurück zu Stack A.

### Besonderheiten und Funktionsweise

- **Effiziente Sortierung:**
  - Der Algorithmus versucht, die effizienteste Anzahl von Operationen zu verwenden, indem er den Median als Orientierungspunkt nutzt.

- **Rekursive Strategie:**
  - Die rekursiven Aufrufe ermöglichen die schrittweise Sortierung kleinerer Teillisten auf den beiden Stacks.

- **Spezielle Sortierung für Kleine Teilisten:**
  - Für Teilisten mit drei oder weniger Elementen wird eine optimierte Sortierungsfunktion aufgerufen.

- **Abbruchbedingungen:**
  - Der Algorithmus bricht ab, wenn die Liste bereits sortiert ist oder wenn die Teilliste klein genug ist.

Diese Modifikationen ermöglichen eine effiziente Anpassung des Quicksort-Algorithmus an die spezifischen Anforderungen von Push_swap.
