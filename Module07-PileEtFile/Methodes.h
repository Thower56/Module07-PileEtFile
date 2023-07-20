#pragma once
#include "Pile.h"
#include "File.h"

bool CorrectementImbriquee(std::string p_expression)
{
    char debutParetheses = '(';
    char finParetheses = ')';
    char debutCrochets = '[';
    char finCrochets = ']';
    char debutAccolades = '{';
    char finAccolades = '}';
    Pile<char> compteur;
    bool correctementImbriquee = true;

    for (size_t i = 0; i < p_expression.length() && correctementImbriquee; i++)
    {
        if (p_expression[i] == debutAccolades || p_expression[i] == debutCrochets || p_expression[i] == debutParetheses)
        {
            compteur.empiler(p_expression[i]);
        }
        else if (p_expression[i] == finAccolades)
        {
            if (compteur.sommet() == debutAccolades)
            {
                compteur.depiler();
            } 
            else
            {
                correctementImbriquee = false;
            }
        }
        else if (p_expression[i] == finCrochets)
        {
            if (compteur.sommet() == debutCrochets)
            {
                compteur.depiler();
            }
            else
            {
                correctementImbriquee = false;
            }
        }
        else if (p_expression[i] == finParetheses)
        {
            if (compteur.sommet() == debutParetheses)
            {
                compteur.depiler();
            }
            else
            {
                correctementImbriquee = false;
            }
        }
        
    }

    return correctementImbriquee;
}

Pile<char> expressionPostfixe(std::string p_expression)
{
    Pile<char> operateur;
    Pile<char> postFixe;
    
    for (size_t i = 0; i < p_expression.length(); i++)
    {
        if (std::isdigit(p_expression[i]))
        {
            postFixe.empiler(p_expression[i]);
        }
        else if (p_expression[i] == ' ')
        {
            ;
        }
        else
        {
            if (operateur.estPileVide())
            {
                operateur.empiler(p_expression[i]);
            }
            else 
            {
                if (operateur.sommet() == '+' || operateur.sommet() == '-')
                {
                    operateur.empiler(p_expression[i]);
                }
                else if (p_expression[i] == '*' || p_expression[i] == '/')
                {
                    operateur.empiler(p_expression[i]);
                }
                else
                {
                    while(operateur.sommet() == '+' || operateur.sommet() == '-')
                    {
                        postFixe.empiler(operateur.depiler());
                    }
                    operateur.empiler(p_expression[i]);
                }
            }
        }
    }
    while (!operateur.estPileVide())
    {
        postFixe.empiler(operateur.depiler());
    }
    return postFixe;
}
