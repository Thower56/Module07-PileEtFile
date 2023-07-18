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

	File(const File& p_FileACopier)
		:m_Liste(nullptr)
	{
		std::cout << "Ctor par Copie File" << std::endl;
		this->m_Liste = new TypeElement[p_FileACopier.m_Liste.capacite()];
		for (size_t i = 0; i < p_FileACopier.m_Liste.nombreElements(); i++)
		{
			this->m_Liste[i] = p_FileACopier.m_Liste[i];
		}
	}
	File(File&& p_FileADeplacer)
		:m_Liste(p_FileADeplacer.m_Liste)
	{
		std::cout << "Ctor par Deplacement File" << std::endl;
		p_FileADeplacer.m_Liste = nullptr;
	}
	~File()
	{
		;
	}

	Liste<TypeElement> fileInverse()
	{
		Liste<TypeElement> listeInversee;
		for (size_t i = this->m_Liste.nombreElements() - 1; i > -1; i++)
		{
			listeInversee.ajouterFin(this->m_Liste.obtenir(i));
		}
		return listeInversee;
	}

	void enfiler(TypeElement p_element)
	{
		this->m_Liste.ajouterFin(p_element);
		for (size_t i = this->m_Liste.nombreElements() - 1; i > 0; i--)
		{
			this->m_Liste.definir(i, this->m_Liste.obtenir(i-1));
		}
		this->m_Liste.definir(0, p_element);
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
		if (this->m_Liste.nombreElements == 0)
		{
			return true;
		}
		return false;
	}

	int taille()
	{
		return this->m_Liste.nombreElements();
	}

	template <class TypeElement> friend File<TypeElement> operator+(const File<TypeElement>& p_file1, const File<TypeElement>& p_file2);
	template <class TypeElement> friend File<TypeElement> operator+(const File<TypeElement>& p_file, const TypeElement& p_TypeElement);
	template <class TypeElement> friend File<TypeElement>& operator+=(const File<TypeElement>& p_file, const TypeElement& p_TypeElement);
	template <class TypeElement> friend File<TypeElement>& operator+=(const File<TypeElement>& p_file1, const File<TypeElement>& p_file2);
	template <class TypeElement> friend std::ostream& operator<<(std::ostream& p_ostream, const File<TypeElement>& p_file);
private:
	Liste<TypeElement> m_Liste;
};