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

	~Pile()
	{
		for (size_t i = this->m_Liste.nombreElements() / 2; i > -1; i++)
		{
			int indexFin = this->m_Liste.nombreElements() - i;
			TypeElement temp = this->m_Liste.obtenir(i);
			this->m_Liste.definir(i, this->m_Liste.obtenir(indexFin));
			this->m_Liste.definir(indexFin, temp);
		}
	}

	TypeElement obtenir(int p_index) const
	{
		return m_Liste.obtenir(p_index);
	}

	Liste<TypeElement> InversePile()
	{
		
		Liste<TypeElement> listeInversee;
		for (size_t i = 0 ; i < this->m_Liste.nombreElements(); i++)
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
		if (m_Liste.nombreElements() == 0)
		{
			std::invalid_argument("Pile vide");
		}
		int index = this->m_Liste.nombreElements() - 1;
		TypeElement elementRecent = m_Liste.obtenir(index);
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
		return this->m_Liste.nombreElements() == 0;
	}
	int taille()
	{
		return this->m_Liste.nombreElements();
	}

	template <class TypeElement> friend Pile<TypeElement> operator+(const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2);
	template <class TypeElement> friend Pile<TypeElement> operator+(const Pile<TypeElement>& p_pile, const TypeElement& p_TypeElement);
	template <class TypeElement> friend Pile<TypeElement>& operator+=(Pile<TypeElement>& p_pile, const TypeElement& p_TypeElement);
	template <class TypeElement> friend Pile<TypeElement>& operator+=(Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2);
	template <class TypeElement> friend bool operator==(const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2);
	template <class TypeElement> friend bool operator!=(const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2);
	template <class TypeElement> friend Pile<TypeElement> operator~(const Pile<TypeElement>& p_pile1);
	template <class TypeElement> friend std::ostream& operator<<(std::ostream& p_ostream, const Pile<TypeElement>& p_pile);

private:
	Liste<TypeElement> m_Liste;
};