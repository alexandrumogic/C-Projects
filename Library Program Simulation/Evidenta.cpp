#include "Evidenta.h"

using namespace std;

struct Evidenta::imprumut {
	string titluCarte;
	string autorCarte;
	string numeCititor;
	string adresaCititor;
	int termen;
	imprumut * imprumutUrmator;
};

Evidenta::Evidenta()
{
	primulImprumut = NULL;
}

void Evidenta::imprumutNou(string titluCarte, string autorCarte, string numeCititor, string adresaCititor, int termen)
{
	bool areImprumut = false;
	imprumut * parcurgereImprumuturi = primulImprumut;

	while (parcurgereImprumuturi != NULL && parcurgereImprumuturi->numeCititor != numeCititor)
	{
		parcurgereImprumuturi = parcurgereImprumuturi->imprumutUrmator;
	}

	if (parcurgereImprumuturi != NULL) areImprumut = true;

	if (areImprumut == false) {

		imprumut * inregistrareImprumut = new imprumut();
		inregistrareImprumut->titluCarte = titluCarte;
		inregistrareImprumut->autorCarte = autorCarte;
		inregistrareImprumut->numeCititor = numeCititor;
		inregistrareImprumut->adresaCititor = adresaCititor;
		inregistrareImprumut->termen = termen;

		if (primulImprumut == NULL) {
			inregistrareImprumut->imprumutUrmator = primulImprumut;
			primulImprumut = inregistrareImprumut;
		}
		else {
			imprumut * imprumutCurent = primulImprumut;
			imprumut ** imprumutUrmator = &primulImprumut;

			while (imprumutCurent != NULL && (imprumutCurent->termen < inregistrareImprumut->termen))
			{
				imprumutUrmator = &imprumutCurent->imprumutUrmator;
				imprumutCurent = imprumutCurent->imprumutUrmator;
			}

			*imprumutUrmator = inregistrareImprumut;
			inregistrareImprumut->imprumutUrmator = imprumutCurent;
		}
	}


	else
	{
		cout << "\nAti efectuat deja un imprumut." << endl;
	}
}

void Evidenta::returnare(string numeCititor)
{
	imprumut * imprumutActual = primulImprumut;
	imprumut * parcurgereImprumuturi = primulImprumut;

	while (parcurgereImprumuturi != NULL && parcurgereImprumuturi->numeCititor != numeCititor)
	{
		imprumutActual = parcurgereImprumuturi;
		parcurgereImprumuturi = parcurgereImprumuturi->imprumutUrmator;
	}

	if (parcurgereImprumuturi == NULL)
	{
		cout << "\nNu aveti nici o carte de returnat." << endl;
	}

	else {

		if (parcurgereImprumuturi == primulImprumut) {
			primulImprumut = primulImprumut->imprumutUrmator;
			delete parcurgereImprumuturi;
		}
		else {
			imprumutActual->imprumutUrmator = parcurgereImprumuturi->imprumutUrmator;
			delete parcurgereImprumuturi;
		}

		cout << "\nCarte returnata." << endl;
	}
}

void Evidenta::actualizare()
{
	imprumut * actualizareImprumut = primulImprumut;
	imprumut * afisareIntarzieri = primulImprumut;

	while (actualizareImprumut != NULL)
	{
		actualizareImprumut->termen -= 1;
		actualizareImprumut = actualizareImprumut->imprumutUrmator;
	}

	cout << "\nEvidenta a fost actualizata. Lista restanti: ";

	while (afisareIntarzieri != NULL)
	{
		if (afisareIntarzieri->termen < 0) cout << afisareIntarzieri->numeCititor << " ";
		afisareIntarzieri = afisareIntarzieri->imprumutUrmator;
	}
	cout << endl;
}

void Evidenta::afisareEvidenta()
{
	cout << "\nAfisare evidenta:\n" << endl;
	imprumut * parcurgereImprumuturi = primulImprumut;

	while (parcurgereImprumuturi != NULL)
	{
		cout << "Titlu: " << parcurgereImprumuturi->titluCarte << " | Autor: " << parcurgereImprumuturi->autorCarte << " | Cititor: " << parcurgereImprumuturi->numeCititor << " | Adresa: " << parcurgereImprumuturi->adresaCititor << " | Termen ramas: " << parcurgereImprumuturi->termen << " zile" << endl;
		parcurgereImprumuturi = parcurgereImprumuturi->imprumutUrmator;
	}
}


Evidenta::~Evidenta()
{
}
