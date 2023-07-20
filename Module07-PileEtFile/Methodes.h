#pragma once
#include "Pile.h"
#include "File.h"

bool CorrectementImbriquiee(Pile<char>& p_pileChar)
{
    char debutParetheses = '(';
    char finParetheses = ')';
    char debutCrochets = '[';
    char finCrochets = ']';
    char debutAccolades = '{';
    char finAccolades = '}';
    Pile<char> compteurParetheses;
    Pile<char> compteurCrochets;
    Pile<char> compteurAccolades;

    for (size_t i = 0; i < p_pileChar.taille(); i++)
    {
        if (p_pileChar.obtenir(i) == debutParetheses)
        {
            compteurParetheses.empiler(p_pileChar.obtenir(i));
        }
        if (p_pileChar.obtenir(i) == finParetheses)
        {
            if (compteurParetheses.taille() == 0)
            {
                return false;
            }
            compteurParetheses.depiler();
        }

        if (p_pileChar.obtenir(i) == debutCrochets)
        {
            compteurCrochets.empiler(p_pileChar.obtenir(i));
        }
        if (p_pileChar.obtenir(i) == finCrochets)
        {
            if (compteurCrochets.taille() == 0)
            {
                return false;
            }
            compteurCrochets.depiler();
        }

        if (p_pileChar.obtenir(i) == debutAccolades)
        {
            compteurAccolades.empiler(p_pileChar.obtenir(i));
        }
        if (p_pileChar.obtenir(i) == finAccolades)
        {
            if (compteurAccolades.taille() == 0)
            {
                return false;
            }
            compteurAccolades.depiler();
        }

    }

    return compteurAccolades.taille() == compteurCrochets.taille() == compteurParetheses.taille() == 0;
}

Pile<char> expressionPostfixe(Pile<char> p_expression)
{

}