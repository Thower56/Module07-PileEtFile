 
#include <iostream>
#include "File.h"
#include "Liste.h"
#include "OperateurUtile.h"
#include "Pile.h"

int main()
{
    std::cout << "***************[Liste]********************" << std::endl;
    Liste<int> liste;
    liste.ajouterFin(1);
    liste.ajouterFin(2);
    liste.ajouterFin(3);
    liste.ajouterDebut(0);
    liste.ajouterDebut(-1);
    std::cout << liste << std::endl;

    Liste<int> liste2;
    liste2.ajouterFin(5);
    liste2.ajouterFin(6);
    liste2.ajouterFin(7);
    std::cout << liste2 << std::endl;
    liste += liste2;
    std::cout << liste << "Test" << std::endl;

    std::cout << "***************[Pile]********************" << std::endl;
    Pile<double> liste3;
    liste3.empiler(1);
    liste3.empiler(2);
    liste3.empiler(3);
    std::cout << liste3 << std::endl;

    Pile<double> liste33;
    liste33.empiler(4);
    liste33.empiler(5);
    liste33.empiler(6);
    std::cout << liste33 << std::endl;

    Pile<double> liste333 = liste3 + liste33;
    std::cout << "Pile = Pile2 + Pile3 : " << liste333 << std::endl;

    liste3 += liste33;
    std::cout <<"Pile += Pile2 : " << liste3 << std::endl;

    std::cout << "***************[File]********************" << std::endl;
    File<int> liste4;
    liste4.enfiler(1);
    liste4.enfiler(2);
    liste4.enfiler(3);
    std::cout << liste4 << std::endl;

    File<int> liste5;
    liste5.enfiler(6);
    liste5.enfiler(5);
    liste5.enfiler(4);
    std::cout << liste5 << std::endl;

    File<int> liste6 = liste4 + liste5;
    std::cout << "File = File2 + File3 : " << liste6 << std::endl;

    liste4 += liste5;
    std::cout <<"File += File2 : " << liste4 << std::endl;

    if (liste4 == liste6)
    {
        std::cout << "File Pareil" << std::endl;
    }
    File<int> liste7 = ~liste4;
    std::cout << liste7 << std::endl;
    return 0;
}
