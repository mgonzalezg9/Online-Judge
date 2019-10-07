#include <iostream>
#include <string>
#define A_SIZE 6 

using namespace std;

int A[A_SIZE] = {4, 6, 8, 10, 12, 20};

void getDadoAndProbabilidad(int maxNum) {
	

	// Busqueda del dado
	int i = 0;
	while (i < A_SIZE && maxNum > A[i]) {
		i++;
	}
	cout << A[i] << " ";

	// Calculo de la probabilidad
	int cont = 0;
	while (i < A_SIZE) {
		cont++;
		i++;
	}
	cout << (double) 1/cont << endl;
}

int main() {
	int num;
	int max = 0;
	while (cin >> num) {
		// comprobar si es el mayor de las tiradas
		if (num > max) {
			max = num;
		}

		if (cin.peek() == '\n') {
			// comrpobar dador
			getDadoAndProbabilidad(max);

			// A por la siguiente linea
			cin.ignore();
			max = 0;
			if (cin.peek() == '\n') {
				// Caso Base
				if (max == 0) {
					cout << "4 0.17" << endl;
				}
			}
		}
	}

}