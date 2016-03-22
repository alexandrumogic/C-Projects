
#include "Evidenta.h"

using namespace std;

int main()
{
	Evidenta evidenta;

	evidenta.imprumutNou("Strainul", "Albert Camus", "Pavel", "Popestilor nr.2", 0);
	evidenta.imprumutNou("Adolescentul", "Dostoievski", "Alex", "Rebreanu nr.5", 3);
	evidenta.imprumutNou("Crima si pedeapsa", "Dostoievski", "Ionut", "Pinului nr.7", 5);
	evidenta.imprumutNou("Un cuib de nobili", "Turgheniev", "Bianca", "Circumvalatiunii nr. 1", 4);
	evidenta.imprumutNou("Omul frumos", "Dan Puric", "Loredana", "Arsitei nr. 5", 5);

	evidenta.afisareEvidenta();

	evidenta.imprumutNou("Un cuib de nobili", "Turgheniev", "Bianca", "Circumvalatiunii nr. 1", 4);

	evidenta.actualizare();

	evidenta.returnare("Ionut");
	evidenta.returnare("Pavel");

	evidenta.afisareEvidenta();

	evidenta.actualizare();

	cin.get();

	return 0;
}