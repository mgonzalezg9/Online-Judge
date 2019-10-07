#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num_casos;
	cin >> num_casos;

	for (int i = 0; i < num_casos; ++i)	{
		int tam;
		cin >> tam;
		cin.ignore();
		vector<int> l;

		// Inicializacion
		int RD = 0, NL = 0;

		for (auto e : l) {
			cout << e << " ";
		}
		cout << endl;

		while (!l.empty()) {
			// RD escoge el mayor de ambos
			int size = l.size();
			int escogido, pos_borrar;
			if (l[size - 1] > l[0]) {
				escogido = l[size - 1];
				pos_borrar = size - 1;
			} else {
				escogido = l[0];
				pos_borrar = 0;
			}
			RD += escogido;
			cout << "RD " << escogido << endl;
			l.erase(l.begin() + pos_borrar);

			// NL escoge el mayor
			size = l.size();
			if (l[size- 1] > l[0]) {
				escogido = l[size - 1];
				pos_borrar = size - 1;
			} else {
				escogido = l[0];
				pos_borrar = 0;
			}
			NL += escogido;
			cout << "NL " << escogido << endl;
			l.erase(l.begin() + pos_borrar);
		}

		if (NL < RD) {
			cout << NL << endl;
		} else
			cout << RD << endl;

		l.clear(); 
	}
	return 0;
}