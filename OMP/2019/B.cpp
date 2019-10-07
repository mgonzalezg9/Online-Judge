#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

bool es_capicuca(int num) {
	int tam = (int)(ceil(log10(num)))+1;
	char cad[tam];
	cad[(int)(ceil(log10(num)))+1] = '\0';
	for (int i = (int)(ceil(log10(num))); i  >= 0; --i)
	{
		cad[i] = char(num % 10) + '0';
		num = num / 10;
	}



	int j = tam-1;
	for (int i = 0; i <= j; ++i)
	{
		if (cad[i] != cad[j]){
			return false;
		}
		j--;
	}

	return true;
}

int main()
{
	int num_casos;
	cin >> num_casos;
	long long int a, b, capicuas;

	for (int i = 0; i < num_casos; ++i)
	{
		capicuas = 0;
		cin >> a >> b;
		if (b < a) {
			int aux = b;
			b = a;
			a = aux;
		}

		while (a <= b) {
			if (es_capicuca(a))
				capicuas++;
			a++;
		}

		cout << capicuas << endl;

	}
	return 0;
}