#ifndef INC_02OCMITKLASSENV2_FELD_H
#define INC_02OCMITKLASSENV2_FELD_H

#include "spieler.h"

typedef enum { leer = 0, gefahr, brunnen, relikt } artDesFelds;

class Feld {
    bool p_betreten = false;
    artDesFelds p_art = setFeldart();

public:
    // C O N S T R U C T O R S:
    Feld ();
    Feld(bool betreten, artDesFelds art);

    // S E T T E R   &   G E T T E R   M E T H O D S:
    artDesFelds setFeldart(artDesFelds art);
    artDesFelds setFeldart();
    artDesFelds getArt();
    bool setIsBetreten(bool betreten);
    bool getIsBetreten() const;
};

#endif //INC_02OCMITKLASSENV2_FELD_H
