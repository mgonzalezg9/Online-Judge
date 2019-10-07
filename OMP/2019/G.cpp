#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int num_casos;
	cin >> num_casos;

	for (int i = 0; i < num_casos; ++i)
	{
		int numProgramas;
		cin >> numProgramas;
		vector<string> secuencias;
		vector<int> apariciones;

		while (numProgramas > 0) {
			string cad = "";
			char ult;
			char pult;
			cin >> pult;
			
			if (pult != '#') {
				cin >> ult;

				while (ult != '#' && cin.peek() != '#') {
					cad = "";
					char c;
					cin >> c;

					cad += pult;
					cad += ult;
					cad += c;
					
					bool encontrado = false;
					int j;
					int fin1 = secuencias.size();
					for (j = 0; j < fin1; j++) {
						if (secuencias[j] == cad) {
							encontrado = true;
							break;
						}
					}

					if (encontrado) {
						apariciones[j]++;
					} else {
						secuencias.push_back(cad);
						apariciones.push_back(1);
					}

					pult = ult;
					ult = c;
				}
			}

			numProgramas--;
			cin.ignore();
		}

		int tamano = apariciones.size();
		if (tamano > 0){
			int max = apariciones[0];
			int maxIndice = 0;
			int fin2 = apariciones.size();
			for (int i = 1; i < fin2; i++) {
				if (apariciones[i] >= max) {
					if (apariciones[i] > max) {
						max = apariciones[i];
						maxIndice = i;
					} else {
						string cadMax = secuencias[maxIndice];
						string cadActual = secuencias[i];
						if (cadActual < cadMax) {
							max = apariciones[i];
							maxIndice = i;
						}
					}
				}
			}

			cout << "PATENT " << secuencias[maxIndice] << " AND WIN " << (max*1000) << " EUROS!" << endl;
		} 
		secuencias.clear();
		apariciones.clear();

	}
	return 0;
}