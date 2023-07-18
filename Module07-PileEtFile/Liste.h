#pragma once
#include <iostream>
#include <stdexcept>


template <class TypeElement>
class Liste
{
public:
	Liste()
		:m_valeurs(new TypeElement[1]), m_capacite(1), m_NbDElements(0)
	{
		std::cout << "List Generique ctor par default" << std::endl;
	}

	Liste(const Liste<TypeElement>& p_listACopier)
		:m_valeurs(nullptr),
		m_capacite(p_listACopier.m_capacite),
		m_NbDElements(p_listACopier.m_NbDElements)
	{
		this->m_valeurs = new TypeElement[this->m_capacite];
		for (size_t i = 0; i < p_listACopier.nombreElements(); i++)
		{
			this->m_valeurs[i] = p_listACopier.m_valeurs[i];
		}
		std::cout << "List Generique ctor par Copie" << std::endl;
	}

	Liste(Liste<TypeElement>&& p_listADeplacer)
		:m_valeurs(p_listADeplacer.m_valeurs),
		m_capacite(p_listADeplacer.m_capacite),
		m_NbDElements(p_listADeplacer.m_NbDElements)
	{
		p_listADeplacer.m_valeurs = nullptr;
		p_listADeplacer.m_capacite = 0;
		p_listADeplacer.m_NbDElements = 0;
	}
	~Liste()
	{
		if (this->m_valeurs)
		{
			delete[] this->m_valeurs;
			this->m_valeurs = nullptr;
		}
	}

	TypeElement obtenir(const int& p_indice) const
	{
		if (p_indice >= this->m_NbDElements || p_indice < 0)
		{
			throw std::invalid_argument("L'indice n'est pas valide");
		}
		return this->m_valeurs[p_indice];
	}

	int nombreElements() const
	{
		return this->m_NbDElements;
	}

	int capacite() const
	{
		return this->m_capacite;
	}

	void ajouterFin(const TypeElement& p_valeur)
	{
		if (this->m_NbDElements == this->m_capacite)
		{
			int futurCapacite = this->m_capacite * 2;
			TypeElement* futurTableau = new TypeElement[futurCapacite];
			for (size_t i = 0; i < this->m_NbDElements; i++)
			{
				futurTableau[i] = this->m_valeurs[i];
			}

			delete[] this->m_valeurs;
			this->m_valeurs = futurTableau;
			this->m_capacite = futurCapacite;
		}
		this->m_valeurs[this->m_NbDElements++] = p_valeur;
	}

	void ajouterDebut(const TypeElement& p_valeur)
	{
		if (this->m_NbDElements == this->m_capacite)
		{
			this->m_NbDElements++;
			int futurCapacite = this->m_capacite * 2;
			TypeElement* futurTableau = new TypeElement[futurCapacite];
			futurTableau[0] = p_valeur;
			for (size_t i = 1; i < this->m_NbDElements; i++)
			{
				futurTableau[i] = this->m_valeurs[i-1];
			}

			delete[] this->m_valeurs;
			this->m_valeurs = futurTableau;
			this->m_capacite = futurCapacite;
		}
		else
		{
			this->m_NbDElements++;
			TypeElement* futurTableau = new TypeElement[this->m_capacite];
			futurTableau[0] = p_valeur;
			for (size_t i = 1; i < this->m_NbDElements; i++)
			{
				futurTableau[i] = this->m_valeurs[i-1];
			}

			delete[] this->m_valeurs;
			this->m_valeurs = futurTableau;
		}
	}

	void definir(int p_index, TypeElement p_element)
	{
		if (p_index > this->m_NbDElements || p_index < 0)
		{
			std::invalid_argument("Index invalid");
		}
		this->m_valeurs[p_index] = p_element;
	}

	void supprimerFin()
	{
		if (this->m_NbDElements == 0)
		{
			throw std::invalid_argument("");
		}
		--this->m_NbDElements;
	}


	Liste<TypeElement> operator=(const Liste<TypeElement>& p_listeACopier)
	{
		if (this != &p_listeACopier)
		{
			if (this->m_capacite < p_listeACopier.m_capacite)
			{
				TypeElement* futurListe = new TypeElement[p_listeACopier.m_capacite];
				delete[] this->m_valeurs;
				this->m_valeurs = futurListe;
				this->m_capacite = p_listeACopier.m_capacite;
			}

			for (size_t i = 0; i < p_listeACopier.m_NbDElements; i++)
			{
				this->m_valeurs[i] = p_listeACopier.m_valeurs[i];
			}

		}
		return *this;
	}

	template <class TypeElement> friend Liste<TypeElement> operator+(const Liste<TypeElement>& p_Liste1, const Liste<TypeElement>& p_Liste2);
	template <class TypeElement> friend Liste<TypeElement> operator+(const Liste<TypeElement>& p_Liste, const TypeElement& p_TypeDeLaListe);
	template <class TypeElement> friend Liste<TypeElement>& operator+=(Liste<TypeElement>& p_Liste, const TypeElement& p_TypeDeLaListe);
	template <class TypeElement> friend Liste<TypeElement>& operator+=(Liste<TypeElement>& p_Liste1, const Liste<TypeElement>& p_Liste2);
	template <class TypeElement> friend bool operator==(const Liste<TypeElement>& p_Liste1, const Liste<TypeElement>& p_Liste2);
	template <class TypeElement> friend bool operator!=(const Liste<TypeElement>& p_Liste1, const Liste<TypeElement>& p_Liste2);
	template <class TypeElement> friend std::ostream& operator<<(std::ostream& p_ostream, const Liste<TypeElement>& p_liste);

private:
	int m_capacite;
	TypeElement* m_valeurs;
	int m_NbDElements;
};