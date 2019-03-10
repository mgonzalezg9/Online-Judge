#include <list>
#include <iostream>
using namespace std;

list<int> *array;
int nbloques;

// Dado un numero de bloque devuelve su pila
int getPila(int bloque) {
	for(int i = 0; i < nbloques; i++) {
		/*cout << "lista " << i << ':' << endl;
		for (list<int>::iterator it = array[i].begin(); it != array[i].end(); ++it)
		{
			if (*it == bloque)
				return i;
		}*/
		for(auto item : array[i]) {
			if (item == bloque)
				return i;
		}
	}
	return -1;
}

// Devuelve a su posición a los elementos que hay por encima del bloque y borra el bloque
void quitarSuperiores(int pila, int bloque) {
	bool encontrado = false;
	list<int>::iterator ini;
	list<int>::iterator fin = array[pila].end();
	for (list<int>::iterator it = array[pila].begin(); it != fin; ++it) {
		if (!encontrado && *it == bloque)
		{
			encontrado = true;
			ini = it;
		} else if (encontrado)
			array[*it].push_back(*it);
	}

	array[pila].erase(ini, fin);
}

// Mueve los elementos desde el bloque hasta el tope al final de la pila de destino
void moverSuperiores(int pilaOrigen, int bloque, int pilaDestino) {
	bool encontrado = false;
	list<int>::iterator ini;
	list<int>::iterator fin = array[pilaOrigen].end();
	for (list<int>::iterator it = array[pilaOrigen].begin(); it != fin; ++it) {
		if (!encontrado && *it == bloque)
		{
			encontrado = true;
			ini = it;
		}
		if (encontrado)
			array[pilaDestino].push_back(*it);
	}

	array[pilaOrigen].erase(ini, fin);
}

void printArray() {
	for(int i = 0; i < nbloques; i++) {
		cout << i << ':';
		for(auto item : array[i]) {
			cout << " " << item;
		}
		cout << endl;
	}
}

void moveOnto(int a, int b) {
	int pilaA = getPila(a);
	int pilaB = getPila(b);

	quitarSuperiores(pilaA, a);
	quitarSuperiores(pilaB, b);

	array[pilaB].push_back(b);
	array[pilaB].push_back(a);
	
}

void moveOver(int a, int b) {
	int pilaA = getPila(a);
	int pilaB = getPila(b);

	array[pilaB].push_back(a);
	quitarSuperiores(pilaA, a);
}

void pileOnto(int a, int b) {
	int pilaA = getPila(a);
	int pilaB = getPila(b);

	quitarSuperiores(pilaB, b);
	array[pilaB].push_back(b);

	moverSuperiores(pilaA, a, pilaB);

}

void pileOver(int a, int b) {
	moverSuperiores(getPila(a), a, getPila(b));
}

void procesarComando(string comando, int a, string prep, int b)	{
	// Descarta dos numeros de bloque iguales
	if (a == b || getPila(a) == getPila(b)) 
		return;

	if (comando == "move")
	{
		if (prep == "onto") {
			// Llamada a la funcion
			moveOnto(a, b);
		} else moveOver(a, b);
	} else if (prep == "onto") {
			// Llamada a la funcion
			pileOnto(a, b);
		} else pileOver(a, b);
}
	

int main(int argc, char const *argv[]) {
	// Lee el número de bloques
	cin >> nbloques;

	// Inicialización del array
	array = new list<int>[nbloques];
	for(int i = 0; i < nbloques; i++) {
		array[i].push_back(i);
	}

	do {
		
		// Lee el comando
		string prep, comando;
		int a, b;
		
		cin >> comando;

		if (comando == "quit") {
			// Fin del programa
			printArray();
			break;
		}
		
		// Lo procesa
		cin >> a >> prep >> b;
		procesarComando(comando, a, prep, b);		
	} while (true);
}