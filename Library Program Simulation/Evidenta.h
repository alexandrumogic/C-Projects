#include <iostream>
#include <string>

using namespace std;

class Evidenta
{
	struct imprumut;
public:
	Evidenta();
	void imprumutNou(string titluCarte, string autorCarte, string numeCititor, string adresaCititor, int termen);
	void returnare(string numeCititor);
	void actualizare();
	void afisareEvidenta();
	~Evidenta();
private:
	imprumut * primulImprumut;
};

