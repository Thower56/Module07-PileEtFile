#pragma once
#include <ostream>
#include "Liste.h"
template <class TypeElement>
class File
{
public:
	File()
	{
		std::cout << "Ctor File par Default" << std::endl;
	}

	~File()
	{
		
	}


	void fileInverse()
	{
		
		for (size_t i = this->m_Liste.nombreElements() / 2; i > -1; i++)
		{
			int indexFin = this->m_Liste.nombreElements() - i;
			TypeElement temp = this->m_Liste.obtenir(i);
			this->m_Liste.definir(i, this->m_Liste.obtenir(indexFin));
			this->m_Liste.definir(indexFin, temp);
		}
	}

	void enfiler(TypeElement p_element)
	{
		this->m_Liste.ajouterDebut(p_element);
		
	}

	TypeElement defiler()
	{
		if (this->m_Liste.nombreElements == 0)
		{
			std::invalid_argument("File vide");
		}

		TypeElement element = this->m_Liste.obtenir(this->m_Liste.nombreElements() - 1);
		this->m_Liste.supprimerFin();
		return element;
	}

	TypeElement tete()
	{
		if (this->m_Liste.nombreElements == 0)
		{
			std::invalid_argument("File vide");
		}
		return this->m_Liste.obtenir(this->m_Liste.nombreElements() - 1);
	}

	bool estFileVide()
	{
		return this->m_Liste.nombreElements == 0;
	}

	int taille()
	{
		return this->m_Liste.nombreElements();
	}

	template <class TypeElement> friend File<TypeElement> operator+(const File<TypeElement>& p_file1, const File<TypeElement>& p_file2);
	template <class TypeElement> friend File<TypeElement> operator+(const File<TypeElement>& p_file, const TypeElement& p_TypeElement);
	template <class TypeElement> friend File<TypeElement>& operator+=(File<TypeElement>& p_file, const TypeElement& p_TypeElement);
	template <class TypeElement> friend File<TypeElement>& operator+=(File<TypeElement>& p_file1, const File<TypeElement>& p_file2);
	template <class TypeElement> friend bool operator==(const File<TypeElement>& p_file1, const File<TypeElement>& p_file2);
	template <class TypeElement> friend bool operator!=(const File<TypeElement>& p_file1, const File<TypeElement>& p_file2);
	template <class TypeElement> friend File<TypeElement> operator~(const File<TypeElement>& p_file1);
	template <class TypeElement> friend std::ostream& operator<<(std::ostream& p_ostream, const File<TypeElement>& p_file);
private:
	Liste<TypeElement> m_Liste;
};