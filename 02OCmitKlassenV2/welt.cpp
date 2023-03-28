#include "welt.h"

// C O N S T R U C T O R S:
Welt::Welt(){
    p_x = 5;
    p_y = 5;

    world = new Feld*[p_x];
    for (int i = 0; i < p_x; i++) {
        world[i] = new Feld[p_y];
    }
}
Welt::Welt(int x, int y){
    p_x = x;
    p_y = y;

    world = new Feld*[p_y];
    for (int i = 0; i < p_y; i++) {
        world[i] = new Feld[p_x];
    }
}

// D E C O N S T R U C T O R:
Welt::~Welt() {
    for (int i = 0; i < p_y; i++) {
        delete[] world[i];
    }
    delete[] world;
}

// S E T T E R   &   G E T T E R   M E T H O D S:
int Welt::setX(int x){
    p_x = x;
    return p_x;
}
int Welt::getX() const{
    return p_x;
}
int Welt::setY(int y){
    p_y = y;
    return p_y;
}
int Welt::getY() const{
    return p_y;
}

// M E T H O D S   R E L E V A N T   F O R   C L A S S   W E L T:
void Welt::feldGenerieren(){
    for (int y = 0; y < p_y; ++y) {
        for (int x = 0; x < p_x; ++x) {
            world[y][x].setIsBetreten(false);
            world[y][x].setFeldart(); // ruft fkt feldart() ab, die dann einen random wert generiert und entsprechend eine Feldart zurückgibt
        }
    }
}
void Welt::printFeld(Spieler& charakter, Spieler& gegner){
    std::cout << std::endl;
    for (int y = 0; y < p_y; ++y) {
        for (int x = 0; x < p_x; ++x) {
            if(x == gegner.getX() && y == gegner.getY() && x == charakter.getX() && y == charakter.getY()){
                std::cout << "⚔";
            } else if(x == gegner.getX() && y == gegner.getY()){
                std::cout << "ඞ";
            } else if (x == charakter.getX() && y == charakter.getY()){
                std::cout << "웃";
            } else if(world[y][x].getIsBetreten()){
                std::cout << "_";
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
int Welt::anzahlRelikte(){
    int relikte = 0;
    for (int y = 0; y < p_y; ++y) {
        for (int x = 0; x < p_x; ++x) {
            if(world[y][x].getArt() == relikt) {
                relikte++;
            }
        }
    }
    return relikte;
}
void Welt::printAnleitung(int relikte){
    std::cout << std::endl
              << "----------------------   W I L L K O M M E N   ----------------------" << std::endl << std::endl
              << "Erforsche die Felder, bis du alle Relikte findest." << std::endl
              << "Pass auf! Bei Gefahren könntest du ein Leben verlieren :(" << std::endl
              << "Bei Brunnen kannst du dich erholen und ein extra Leben gewinnen :)" << std::endl
              << "Zusätzlich kannst du bei bestimmten Brunnen- und Reliktfelder Diamanten finden." << std::endl
              << "Sammelst du 3 Diamanten, so kannst du dich von Gefahren schützen." << std::endl << std::endl
              << "Verwende 'w' ↑,'a' ←,'s' →,'d' ↓ um dich im Feld zu bewegen." << std::endl << std::endl
              << "----------------------   V I E L   S P A S S   ----------------------" << std::endl << std::endl
              << "In diesem Spiel gibt es " << relikte << " Relikte. Finde sie alle um zu gewinnen!" << std::endl << std::endl;

}
void Welt::aktuellesFeldBearbeiten(Spieler& spieler1, Spieler& gegner){
    if (spieler1.getX() == gegner.getX() && spieler1.getY() == gegner.getY()){
        std::cout << std::endl << "Erwischt ⚔ -1 Leben!" << std::endl;
        spieler1.setLebenspunkte(spieler1.getLebenspunkte()-1);
        spieler1.setGegTreffen(spieler1.getGegnerTreffen()+1);
    }

    int ws = rand() % 10 + 1;
    switch (world[spieler1.getY()][spieler1.getX()].getArt()) {

        case relikt:
            std::cout << std::endl << "Relikt gefunden!" << std::endl;
            spieler1.setReliktpunkte(spieler1.getReliktpunkte()+1);
            if(ws <= 7){
                std::cout << std::endl << "Du hast einen Diamanten gefunden!" << std::endl;
                spieler1.setDiamanten(spieler1.getDiamanten()+1);
            }
            break;

        case brunnen:
            std::cout << std::endl << "Brunnenfeld :) +1 Leben!" << std::endl;
            spieler1.setLebenspunkte(spieler1.getLebenspunkte()+1);
            spieler1.setHeilungen(spieler1.getHeilungen()+1);
            if(ws <= 7){
                std::cout << std::endl << "Du hast einen Diamanten gefunden!" << std::endl;
                spieler1.setDiamanten(spieler1.getDiamanten()+1);
            }
            break;

        case gefahr:
            if(spieler1.getDiamanten() >= 3){
                world[spieler1.getY()][spieler1.getX()].setFeldart(leer);
            } else if(!numberGuesser()) {
                std::cout << std::endl << "Gefahren Test nicht bestanden! :( -1 Leben!" << std::endl;
                spieler1.setLebenspunkte(spieler1.getLebenspunkte()-1);
                spieler1.setSchaden(spieler1.getSchaden()+1);
            }
            break;
        default:
            break;
    }

    world[spieler1.getY()][spieler1.getX()].setIsBetreten(true);
    world[spieler1.getY()][spieler1.getX()].setFeldart(leer);
}
void Welt::printGameStats(Spieler& spieler1, int relikte){
    if(relikte == spieler1.getReliktpunkte()) {
        std::cout << std::endl
                  << "***************************************************" << std::endl
                  << "*  SPIEL GEWONNEN! DU HAST ALLE RELIKTE GEFUNDEN! *" << std::endl
                  << "***************************************************" << std::endl << std::endl;
    } else {
        std::cout << std::endl
                  << "*********************************************" << std::endl
                  << "*  SPIEL VERLOREN! DU HAST KEIN LEBEN MEHR! *" << std::endl
                  << "*********************************************" << std::endl << std::endl;
    }
    std::cout
            << "-------------------  G A M E  S T A T S  -------------------" << std::endl << std::endl
            << "Du hast insgesamt:" << std::endl
            << "- " << spieler1.getReliktpunkte() << " Relikte gefunden," << std::endl
            << "- " << spieler1.getSchaden() << " Schaden erlitten," << std::endl
            << "- " << spieler1.getHeilungen() << " Schaden geheilt," << std::endl
            << "- " << spieler1.getGegnerTreffen() << " Mal mit Gegnern gekämpft" << std::endl << std::endl
            << "-----------------------   E N D E   ------------------------" << std::endl << std::endl;
}
bool Welt::numberGuesser(){
    int num, guess, tries = 0;
    srand(time(0)); //seed random number generator
    num = rand() % 10 + 1; // random number between 1 and 100
    std::cout << "Du hast ein Gefahrenfeld erwischt! Um kein Leben zu verlieren, hast du 3 Versuche," << std::endl
    << "die Zahl zu finden, an der ich denke. Findest du die Zahl nicht, so verlierst du 1 Leben. " << std::endl
    << "Hast du kein Leben mehr, so verlierst du das Spiel!"  << std::endl  << std::endl;

    do
    {
        std::cout << "Gib einen Schätzwert zwischen 1 und 10 ein:  ";
        std::cin >> guess;

        if(std::cin.fail()) {
            std::cout << "Eingabe muss eine Zahl sein!" << std::endl << std::endl;
            std::cin.clear(); // clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore remaining input
        } else
        if(guess > 0 && guess <= 10) {
            tries++;
            if (guess > num)
                std::cout << "Zu hoch!" << std::endl << std::endl;
            else if (guess < num)
                std::cout << "Zu niedrig!" << std::endl << std::endl;
            else
                std::cout << "\nRichtig! Du hast es dieses Mal bestanden... " << std::endl;
        } else {
            std::cout << "Eingabe ausserhalb des erlaubten Bereichs!" << std::endl << std::endl;
        }
    } while (guess != num && tries < 3);

    if (guess == num){
        return true;
    } else {
        return false;
    }
}

void Welt::resizeWorld(int x, int y)
{
    // create new matrix
    Feld** newWorld = new Feld*[x];
    for (int i = 0; i < x; i++) {
        newWorld[i] = new Feld[y];
    }

    // copy elements from old matrix to new matrix
    int rows = p_x;
    int cols = p_y;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newWorld[i][j] = world[i][j];
        }
    }

    // free memory of old matrix
    for (int i = 0; i < p_x; i++) {
        delete[] world[i];
    }
    delete[] world;

    // set new matrix and dimensions
    world = newWorld;
    p_x = x;
    p_y = y;
}
