#include "CutiePostala.h"


struct CutiePostala::mesaj {
	int prioritate;
	string destinatar;
	string continut;
	mesaj * mesajUrmator;
};

CutiePostala::CutiePostala()
{
	primulMesaj = NULL;
}

void CutiePostala::trimitereMesaj(int prioritate, string destinatar, string continut)
{
	// prioritate 1 = urgent
	// prioritate 0 = ordinar

	if (primulMesaj == NULL || (prioritate == 1))
	{
		mesaj * mesajNou = new mesaj();
		mesajNou->prioritate = prioritate;
		mesajNou->destinatar = destinatar;
		mesajNou->continut = continut;
		mesajNou->mesajUrmator = primulMesaj;

		primulMesaj = mesajNou;
	}
	else if (prioritate == 0) {
		mesaj * mesajNou = new mesaj();
		mesajNou->prioritate = prioritate;
		mesajNou->destinatar = destinatar;
		mesajNou->continut = continut;

		mesaj * mesajCurent = primulMesaj;
		mesaj ** mesajCurentUrmator = &primulMesaj;

		while (mesajCurent != NULL && (mesajCurent->prioritate > 0)) {
			mesajCurentUrmator = &mesajCurent->mesajUrmator;
			mesajCurent = mesajCurent->mesajUrmator;
		}

		while (mesajCurent != NULL && (mesajCurent->destinatar > mesajNou->destinatar))
		{
			mesajCurentUrmator = &mesajCurent->mesajUrmator;
			mesajCurent = mesajCurent->mesajUrmator;
		}

		*mesajCurentUrmator = mesajNou;
		mesajNou->mesajUrmator = mesajCurent;
	}
}

void CutiePostala::primireMesaj(string destinatar)
{
	mesaj * mesajCurent = primulMesaj;
	mesaj * mesajPrimit = primulMesaj;

	if (primulMesaj->destinatar == destinatar)
	{
		cout << "\n# Mesaj de prioritate " << mesajCurent->prioritate << endl; cout << "# Continut: " << endl; cout << mesajCurent->continut << endl;

		primulMesaj = primulMesaj->mesajUrmator;
	}
	else {

		while (mesajCurent != NULL && mesajCurent->destinatar != destinatar)
		{
			mesajPrimit = mesajCurent;
			mesajCurent = mesajCurent->mesajUrmator;
		}

		if (mesajCurent == NULL)
		{
			cout << "\nNici un mesaj de primit." << endl;
		}
		else
		{
			cout << "\n# Mesaj de prioritate " << mesajCurent->prioritate << endl; cout << "# Continut: " << endl; cout << mesajCurent->continut << endl;

			mesaj * mesajStergere = mesajPrimit->mesajUrmator;
			mesajPrimit->mesajUrmator = mesajStergere->mesajUrmator;
			delete mesajStergere;
		}
	}
}

void CutiePostala::afisareMesaje()
{
	mesaj * ultimulMesaj = primulMesaj;

	cout << "\nLista mesaje: " << endl << endl;

	while (ultimulMesaj != NULL)
	{
		if (ultimulMesaj->prioritate == 0)
		{
			cout << "Prioritate: " << ultimulMesaj->prioritate << " | Destinatar: " << ultimulMesaj->destinatar << " | Continut: \"" << ultimulMesaj->continut << "\"" << endl;
			ultimulMesaj = ultimulMesaj->mesajUrmator;
		}
		else {
			ultimulMesaj = ultimulMesaj->mesajUrmator;
		}
	}
}


CutiePostala::~CutiePostala()
{
}
