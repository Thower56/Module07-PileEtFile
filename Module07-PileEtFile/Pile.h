#pragma once
#include <stdexcept>
#include <ostream>
#include "Liste.h"

template <class TypeElement>
class Pile{
public:
	Pile() 
	{
		std::cout << "Ctor Pile par Default" << std::endl;
	}

	Pile(const Pile& p_PileACopier)
		: m_Liste(nullptr)
	{
		std::cout << "Ctor par Copie Pile" << std::endl;
		this->m_Liste = new TypeElement[p_PileACopier.m_Liste.capacite()];
		for (size_t i = 0; i < p_PileACopier.m_Liste.nombreElements(); i++)
		{
			this->m_Liste[i] = p_PileACopier.m_Liste[i];
		}
	}

	Pile(Pile&& p_PileADeplacer)
		:m_Liste(p_PileADeplacer.m_Liste)
	{
		std::cout << "Ctor par Deplacement Pile" << std::endl;
		p_PileADeplacer.m_Liste = nullptr;
	}

	~Pile()
	{
		
	}

	Liste<TypeElement> pileInverse()
	{
		Liste<TypeElement> listeInversee;
		for (size_t i = this->m_Liste.nombreElements() - 1; i > -1; i++)
		{
			listeInversee.ajouterFin(this->m_Liste.obtenir(i));
		}
		return listeInversee;
	}

	 void empiler(TypeElement p_element) 
	{
		 this->m_Liste.ajouterFin(p_element);
	}

	TypeElement depiler() 
	{
		if (this->m_Liste.nombreElements == 0)
		{
			std::invalid_argument("Pile vide");
		}
		int index = this->m_Liste.nombreElements -1;
		TypeElement elementRecent = m_Liste[index];
		this->m_Liste.supprimerFin();
		return elementRecent;
	}

	TypeElement sommet() 
	{
		if (this->m_Liste.nombreElements == 0)
		{
			std::invalid_argument("Pile vide");
		}
		int index = this->m_Liste.nombreElements - 1;
		return m_Liste.obtenir(index);
	}

	bool estPileVide()
	{
		if (this->m_Liste.nombreElements == 0)
		{
			return true;
		}
		return false;
	}
	int taille()
	{
		return this->m_Liste.nombreElements;
	}


	template <class TypeElement> friend Pile<TypeElement> operator+(const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2);
	template <class TypeElement> friend Pile<TypeElement> operator+(const Pile<TypeElement>& p_pile, const TypeElement& p_TypeElement);
	template <class TypeElement> friend Pile<TypeElement>& operator+=(const Pile<TypeElement>& p_pile, const TypeElement& p_TypeElement);
	template <class TypeElement> friend Pile<TypeElement>& operator+=(const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2);
	template <class TypeElement> friend std::ostream& operator<<(std::ostream& p_ostream, const Pile<TypeElement>& p_pile);

private:
	Liste<TypeElement> m_Liste;
};