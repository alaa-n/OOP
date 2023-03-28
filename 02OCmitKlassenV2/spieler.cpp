#include "spieler.h"
#include "welt.h"

// C O N S T R U C T O R S:
Spieler::Spieler(){
    p_lebenspunkte = 5;
    p_reliktpunkte = 0;
    int p_diamanten = 0;
    p_x = 0;
    p_y = 0;
    p_schaden = 0;
    p_heilungen = 0;
    p_gegnerTreffen = 0;
}
Spieler::Spieler(int leben, int relikte, int x, int y){
    p_lebenspunkte = leben;
    p_reliktpunkte = relikte;
    int p_diamanten = 0;
    p_x = x;
    p_y = y;
    p_schaden = 0;
    p_heilungen = 0;
    p_gegnerTreffen = 0;
}
Spieler::Spieler(int x, int y){
    p_x = x;
    p_y = y;
}

// M E T H O D S   R E L E V A N T   F O R   C L A S S   S P I E L R:
void Spieler::spielerBewegen(){
    char bewegung;
    std::cin >> bewegung;

    switch (bewegung) {
        case 'w':
            if (p_y != 0) {
                p_y--;
            } else {
                std::cout << "Bewegung nicht moeglich!" << std::endl;
            }
            break;
        case 's':
            if (p_y != 4) {
                p_y++;
            } else {
                std::cout << "Bewegung nicht moeglich!" << std::endl;
            }
            break;
        case 'a':
            if (p_x != 0) {
                p_x--;
            } else {
                std::cout << "Bewegung nicht moeglich!" << std::endl;
            }
            break;
        case 'd':
            if (p_x != 4) {
                p_x++;
            } else {
                std::cout << "Bewegung nicht moeglich!" << std::endl;
            }
            break;
        default:
            std::cout << "Bewegung nicht moeglich!" << std::endl;
            break;
    }
}
void Spieler::printSpielerStats() const{
    std::cout << "Leben: " << p_lebenspunkte << " | Relikte: " << p_reliktpunkte << " | Diamanten: " << p_diamanten
              << " | Position: (" << p_x << "/" << p_y << ")" << std::endl << std::endl;
    if(p_diamanten == 3){
        std::cout << "Du hast jetzt 3 Diamanten und bist von Gefahrenfeldern geschützt!" << std::endl << std::endl;
    }
}
void Spieler::gegnerBewegen(Spieler& spieler1){
    int randomAxis = rand() %2;
    switch (randomAxis) {
        case 0:
            if(spieler1.p_x > this->p_x){
                this->p_x++;
            } else if(spieler1.p_x < this->p_x){
                this->p_x--;
            }
            break;
        case 1:
            if(spieler1.p_y > this->p_y){
                this->p_y++;
            } else if(spieler1.p_y < this->p_y){
                this->p_y--;
            }
            break;
        default:
            break;
    }

}

// S E T T E R   &   G E T T E R   M E T H O D S:
int Spieler::setLebenspunkte(int lebenPkte){
    p_lebenspunkte = lebenPkte;
    return p_lebenspunkte;
}
int Spieler::getLebenspunkte() const{
    return p_lebenspunkte;
}
int Spieler::setReliktpunkte(int reliktPkte){
    p_reliktpunkte = reliktPkte;
    return p_lebenspunkte;
}
int Spieler::getReliktpunkte() const{
    return p_reliktpunkte;
}
int Spieler::setDiamanten(int diamanten){
    p_diamanten = diamanten;
    return p_diamanten;
}
int Spieler::getDiamanten() const{
    return p_diamanten;
}
int Spieler::setX(int x){
    p_x = x;
    return p_x;
}
int Spieler::getX() const{
    return p_x;
}
int Spieler::setY(int y){
    p_y = y;
    return p_y;
}
int Spieler::getY() const{
    return p_y;
}
int Spieler::setSchaden(int schaden){
    p_schaden = schaden;
    return p_schaden;
}
int Spieler::getSchaden() const{
    return p_schaden;
}
int Spieler::setHeilungen(int heilung){
    p_heilungen = heilung;
    return p_heilungen;
}
int Spieler::getHeilungen() const{
    return p_heilungen;
}
int Spieler::setGegTreffen(int gegTreff){
    p_gegnerTreffen = gegTreff;
    return p_gegnerTreffen;
}
int Spieler::getGegnerTreffen() const{
    return p_gegnerTreffen;
}