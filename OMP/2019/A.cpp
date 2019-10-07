#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool myFunction(int i, int j) {
	return (i>j);
}

int main()
{
	int num_casos;
	cin >> num_casos;

	int numPlanetas;
	int votosTotales = 0;
	int votosDelPlaneta;

	for (int i = 0; i < num_casos; ++i)
	{
		int numPlanetas = 0;
		int votosTotales = 0;
		int votosDelPlaneta = 0;

		//Leo los votos de cada planeta y calculo el total de votos.
		cin >> numPlanetas;
		std::vector<int> votos(numPlanetas);
		for (int i = 0; i < numPlanetas; i++) {
			cin >> votosDelPlaneta;
			votos[i] = votosDelPlaneta;
			votosTotales += votosDelPlaneta;

			votosDelPlaneta = 0;
		}

		//Lo ordeno.
		sort(votos.begin(), votos.end(), myFunction);
	
		//Cojo planetas hasta superar la mitad de votos.
		int mitadVotos = ceil(votosTotales/2);
		int votosActuales = 0;
		int planetasNecesarios = 0;
		while (votosActuales <= mitadVotos) {
			votosActuales += votos[planetasNecesarios];
			planetasNecesarios++;
		}

		cout << "Case " << (i+1) << ": " << planetasNecesarios << " planets" << endl;

		votos.clear();
	}
	return 0;
}