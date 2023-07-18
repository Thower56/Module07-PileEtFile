#pragma once
#include "Liste.h"
#include "Pile.h"
#include "File.h"

template <class TypeElement>
std::ostream& operator<<(std::ostream& p_ostream, const Liste<TypeElement>& p_liste)
{
	p_ostream << "Liste: ( ";

	for (int i = 0; i < p_liste.nombreElements(); i++)
	{
		p_ostream << p_liste.m_valeurs[i];
		p_ostream << " ";
	}
	p_ostream << ")" << std::endl;

	return p_ostream;
}

template <class TypeElement>
Liste<TypeElement> operator+(const Liste<TypeElement>& p_Liste1, const Liste<TypeElement>& p_Liste2)
{
	Liste<TypeElement> futureListe(p_Liste1);
	for (int i = 0; i < p_Liste2.m_NbDElements; i++)
	{
		futureListe.ajouterFin(p_Liste2.m_valeurs[i]);
	}
	return futureListe;
}


template <class TypeElement>
Liste<TypeElement> operator+(const Liste<TypeElement>& p_Liste, const TypeElement& p_valeur)
{

	Liste<TypeElement> futureListe(p_Liste);
	futureListe.ajouterFin(p_valeur);

	return futureListe;
}

template <class TypeElement>
Liste<TypeElement>& operator+=(Liste<TypeElement>& p_Liste, const TypeElement& p_valeur)
{
	p_Liste.ajouterFin(p_valeur);

	return p_Liste;
}

template <class TypeElement>
Liste<TypeElement>& operator+=(Liste<TypeElement>& p_Liste1, const Liste<TypeElement>& p_Liste2)
{
	for (int i = 0; i < p_Liste2.m_NbDElements; i++)
	{
		p_Liste1.ajouterFin(p_Liste2.m_valeurs[i]);
	}

	return p_Liste1;
}

template <class TypeElement>
bool operator==(const Liste<TypeElement>& p_Liste1, const Liste<TypeElement>& p_Liste2)
{
	bool pareil = p_Liste2.nombreElements() == p_Liste2.nombreElements();
	for (size_t i = 0; i < p_Liste2.nombreElements() && pareil; i++)
	{
		pareil = p_Liste2.obtenir(i) == p_Liste2.obtenir(i);
	}
	return pareil;
};

template <class TypeElement>
bool operator!=(const Liste<TypeElement>& p_Liste1, const Liste<TypeElement>& p_Liste2)
{
	bool pareil = p_Liste2.nombreElements() != p_Liste2.nombreElements();
	for (size_t i = 0; i < p_Liste2.nombreElements() && !pareil; i++)
	{
		pareil = p_Liste2.obtenir(i) != p_Liste2.obtenir(i);
	}
	return pareil;
};

/***************************************[ PILE ]*****************************************************************************/

template <class TypeElement>
std::ostream& operator<<(std::ostream& p_ostream, const Pile<TypeElement>& p_pile)
{
	p_ostream << p_pile.m_Liste;

	return p_ostream;
}

template <class TypeElement>
Pile<TypeElement> operator~(const Pile<TypeElement>& p_pile1)
{
	File<TypeElement> listeInversee;
	for (size_t i = 0; i < p_pile1.m_Liste.nombreElements(); i++)
	{
		listeInversee.enfiler(p_pile1.m_Liste.obtenir(i));
	}
	return listeInversee;
}

template <class TypeElement>
Pile<TypeElement> operator+(const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2)
{
	Pile<TypeElement> futurePile(p_pile1);
	for (int i = 0; i < p_pile2.m_Liste.nombreElements(); i++)
	{
		futurePile.empiler(p_pile2.m_Liste.obtenir(i));
	}
	return futurePile;
}


template <class TypeElement>
Pile<TypeElement> operator+(const Pile<TypeElement>& p_pile1, const TypeElement& p_valeur)
{

	Pile<TypeElement> futurePile(p_pile1);
	futurePile.empiler(p_valeur);

	return futurePile;
}

template <class TypeElement>
Pile<TypeElement>& operator+=(Pile<TypeElement>& p_pile, const TypeElement& p_valeur)
{
	p_pile.empiler(p_valeur);

	return p_pile;
}

template <class TypeElement>
Pile<TypeElement>& operator+=(Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2)
{
	for (int i = 0; i < p_pile2.m_Liste.nombreElements(); i++)
	{
		p_pile1.empiler(p_pile2.m_Liste.obtenir(i));
	}

	return p_pile1;
}

template <class TypeElement>
bool operator==(const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2)
{
	return p_pile1.m_Liste == p_pile2.m_Liste;
};

template <class TypeElement>
bool operator!=(const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2)
{
	return p_pile1.m_Liste != p_pile2.m_Liste;
};

/***************************************[ FILE ]*****************************************************************************/

template <class TypeElement>
std::ostream& operator<<(std::ostream& p_ostream, const File<TypeElement>& p_file)
{
	p_ostream << p_file.m_Liste;

	return p_ostream;
}

template <class TypeElement>
File<TypeElement> operator~(const File<TypeElement>& p_file1)
{
	File<TypeElement> listeInversee;
	for (size_t i = 0; i < p_file1.m_Liste.nombreElements(); i++)
	{
		listeInversee.enfiler(p_file1.m_Liste.obtenir(i));
	}
	return listeInversee;
}

template <class TypeElement>
File<TypeElement> operator+(const File<TypeElement>& p_file1, const File<TypeElement>& p_file2)
{
	File<TypeElement> futurePile(p_file1);
	for (int i = 0; i < p_file2.m_Liste.nombreElements(); i++)
	{
		futurePile.enfiler(p_file2.m_Liste.obtenir(i));
	}
	return futurePile;
}


template <class TypeElement>
File<TypeElement> operator+(const File<TypeElement>& p_pile1, const TypeElement& p_valeur)
{

	File<TypeElement> futurePile(p_pile1);
	futurePile.enfiler(p_valeur);

	return futurePile;
}

template <class TypeElement>
File<TypeElement>& operator+=(File<TypeElement>& p_file, const TypeElement& p_valeur)
{
	p_file.enfiler(p_valeur);

	return p_file;
}

template <class TypeElement>
File<TypeElement>& operator+=(File<TypeElement>& p_file1, const File<TypeElement>& p_file2)
{
	for (size_t i = 0; i < p_file2.m_Liste.nombreElements(); i++)
	{
		p_file1.enfiler(p_file2.m_Liste.obtenir(i));
	}

	return p_file1;
}

template <class TypeElement>
bool operator==(const File<TypeElement>& p_file1, const File<TypeElement>& p_file2)
{
	return p_file1.m_Liste == p_file2.m_Liste;
	
};

template <class TypeElement>
bool operator!=(const File<TypeElement>& p_file1, const File<TypeElement>& p_file2)
{
	return p_file1.m_Liste != p_file2.m_Liste;
};