#include <iostream>
#include <cstdlib>                          // <cstdlib> needed for the rand() function!!!
#include <ctime>

#include "spieler.h"
#include "feld.h"
#include "welt.h"

int main() {
    srand(std::time(nullptr));
    Spieler spieler1(5,0,0,0);
    Spieler gegner(rand() %4 + 1, rand() %4 + 1);

    Welt welt;

    while(true) {
        int relikte = 0;

        while (relikte == 0) {
            welt.feldGenerieren();
            relikte = welt.anzahlRelikte();
        }

        welt.printAnleitung(relikte);
        spieler1.printSpielerStats();
        welt.printFeld(spieler1, gegner);

        while (spieler1.getLebenspunkte() > 0 && spieler1.getReliktpunkte() < relikte) {
            spieler1.spielerBewegen();
            gegner.gegnerBewegen(spieler1);

            welt.aktuellesFeldBearbeiten(spieler1, gegner);

            spieler1.printSpielerStats();
            welt.printFeld(spieler1, gegner);
        }

        welt.printGameStats(spieler1, relikte);

        welt.resizeWorld(welt.getX()+1, welt.getY()+1);

    }

    return 0;
}
