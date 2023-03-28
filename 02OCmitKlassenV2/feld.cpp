#include "feld.h"

// C O N S T R U C T O R S:
Feld::Feld (){
    bool p_betreten = false;
    artDesFelds p_art = setFeldart();
}
Feld::Feld(bool betreten, artDesFelds art){
    p_betreten = betreten;
    p_art = art;
}

// S E T T E R   &   G E T T E R   M E T H O D S:
artDesFelds Feld::setFeldart(artDesFelds art){
    p_art = art;
    return p_art;
}
artDesFelds Feld::setFeldart() {
    int ws = rand() % 10 + 1;
    if (ws <= 5) {
        return leer;
    } else if (ws <= 5) {
        return gefahr;
    } else if (ws == 8) {
        return brunnen;
    } else {
        return relikt;
    }
}
artDesFelds Feld::getArt(){
    return p_art;
}
bool Feld::setIsBetreten(bool betreten){
    p_betreten = betreten;
    return p_betreten;
}
bool Feld::getIsBetreten() const{
    return p_betreten;
}