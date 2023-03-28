#ifndef INC_02OCMITKLASSENV2_WELT_H
#define INC_02OCMITKLASSENV2_WELT_H

#include <cstdlib>
#include <ctime>
#include "feld.h"

class Welt {

    Feld** world;

public:
    int p_x;
    int p_y;
    // C O N S T R U C T O R S:
    Welt();
    Welt(int x, int y);

    // D E C O N S T R U C T O R:
    ~Welt();    // doesnt need to be called in main, already automatically destructs once created in the class.

    // S E T T E R   &   G E T T E R   M E T H O D S:
    int setX(int x);
    int getX() const;
    int setY(int y);
    int getY() const;

    // M E T H O D S   R E L E V A N T   F O R   C L A S S   W E L T:
    void feldGenerieren();
    void printFeld(Spieler& charakter, Spieler& gegner);
    int anzahlRelikte();
    void printAnleitung(int relikte);
    void aktuellesFeldBearbeiten(Spieler& spieler1, Spieler& gegner);
    void printGameStats(Spieler& spieler1, int relikte);
    bool numberGuesser();

    void resizeWorld(int x, int y);
};

#endif //INC_02OCMITKLASSENV2_WELT_H
