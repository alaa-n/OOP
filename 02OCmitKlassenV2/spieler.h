#ifndef INC_02OCMITKLASSENV2_SPIELER_H
#define INC_02OCMITKLASSENV2_SPIELER_H

#include <iostream>

class Spieler {
    int p_lebenspunkte = 5;
    int p_reliktpunkte = 0;
    int p_diamanten = 0;
    int p_x = 0;
    int p_y = 0;
    int p_schaden = 0;
    int p_heilungen = 0;
    int p_gegnerTreffen = 0;

public:
    // C O N S T R U C T O R S:
    Spieler();
    Spieler(int leben, int relikte, int x, int y);
    Spieler(int x, int y);

    // M E T H O D S   R E L E V A N T   F O R   C L A S S   S P I E L R:
    void spielerBewegen();
    void printSpielerStats() const;
    void gegnerBewegen(Spieler& spieler1);

    // S E T T E R   &   G E T T E R   M E T H O D S:
    int setLebenspunkte(int lebenPkte);
    int getLebenspunkte() const;
    int setReliktpunkte(int reliktPkte);
    int getReliktpunkte() const;
    int setDiamanten(int diamanten);
    int getDiamanten() const;
    int setX(int x);
    int getX() const;
    int setY(int y);
    int getY() const;
    int setSchaden(int schaden);
    int getSchaden() const;
    int setHeilungen(int heilung);
    int getHeilungen() const;
    int setGegTreffen(int gegTreff);
    int getGegnerTreffen() const;
};

#endif //INC_02OCMITKLASSENV2_SPIELER_H
