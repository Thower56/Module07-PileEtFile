 
#include <iostream>
#include "File.h"
#include "Liste.h"
#include "OperateurUtile.h"
#include "Pile.h"

int main()
{

    Liste<int> liste;
    liste.ajouterFin(1);
    liste.ajouterFin(2);
    liste.ajouterFin(3);
    liste += 4;
    std::cout << liste << std::endl;

    Pile<double> liste2;
    liste2.empiler(1);
    liste2.empiler(2);
    liste2.empiler(3);
    std::cout << liste2 << std::endl;

    File<int> liste3;
    liste3.enfiler(1);
    liste3.enfiler(2);
    liste3.enfiler(3);
    std::cout << liste3 << std::endl;

    return 0;
}
