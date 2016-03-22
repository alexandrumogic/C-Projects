#include "CutiePostala.h"

int main()
{
	CutiePostala cutiepostala;

	cutiepostala.trimitereMesaj(1, "Alexandru", "Salut ma ce mai faci?");
	cutiepostala.trimitereMesaj(1, "Vlad", "Numa bine tie si familiei tale.");
	cutiepostala.trimitereMesaj(0, "Pavel", "Te-am cautat.");
	cutiepostala.trimitereMesaj(0, "Alexandru", "Nu raspunzi la mesaje.");
	cutiepostala.trimitereMesaj(1, "Pavel", "Sunt la lucru nu pot vorbi.");
	cutiepostala.trimitereMesaj(0, "Vlad", "Numa bine.");
	cutiepostala.trimitereMesaj(0, "Xonia", "Buna ce mai zici?");
	cutiepostala.trimitereMesaj(0, "Ion", "Vino sa mananci sarmale.");

	cutiepostala.primireMesaj("Alexandru");
	cutiepostala.primireMesaj("Pavel");
	cutiepostala.primireMesaj("Xonia");

	cutiepostala.afisareMesaje();

	cin.get();

	return 0;
}