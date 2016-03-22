#include <iostream>
#include <string>

using namespace std;

class CutiePostala
{
	struct mesaj;
public:
	CutiePostala();
	void trimitereMesaj(int prioritate, string destinatar, string continut);
	void primireMesaj(string destinatar);
	void afisareMesaje();
	~CutiePostala();
private:
	mesaj * primulMesaj;
};

