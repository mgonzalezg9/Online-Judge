#include <iostream>
using namespace std;

int main() {
	int distancia;
	cin >> distancia;

	int numObstaculos;
	cin >> numObstaculos;

	int act = 0;
	int ant;
	bool obstaculoAlFinal = false;
	int obstaculo, obstaculoFinal;
	string salida = "";
	for (int i = 0; i < numObstaculos; ++i) {
		ant = act;
		cin >> act;

		// Se guarda la distancia del obstaculo con respecto al anterior, no al origen
		if (i == 0) {
			// Inicialmente no salta ningún obstaculo
			obstaculo = act - ant;
		} else if (i == numObstaculos - 1) {
			// Si es el último obstaculo hay que ver si está al final
			if (act == distancia) {
				obstaculoAlFinal = true;
			}

			obstaculo = act - ant - 1;
			obstaculoFinal = obstaculo;
		} else {
			obstaculo = act - ant - 1;
		}

		// Calcula el paso que hay que obtener para cada obstaculo
		if (obstaculo >= 10) {
			while (obstaculo >= 10) {
				salida += 'G';
				obstaculo -= 10;
			}
		}

		if (obstaculo >= 4) {
			while (obstaculo >= 4) {
				salida += 'T';
				obstaculo -= 4;
			}
		}

		if (obstaculo >= 1) {
			while (obstaculo >= 1) {
				salida += 'P';
				obstaculo--;
			}
		}

		salida += 'S';
	}

	if (!obstaculoAlFinal) {
		if (obstaculoFinal >= 10) {
			while (obstaculoFinal >= 10) {
				salida += 'G';
				obstaculoFinal -= 10;
			}
		}

		if (obstaculo >= 4) {
			while (obstaculo >= 4) {
				salida += 'T';
				obstaculoFinal -= 4;
			}
		}

		if (obstaculoFinal >= 1) {
			while (obstaculoFinal >= 1) {
				salida += 'P';
				obstaculoFinal--;
			}
		}
	}

	cout << salida << endl;
}



