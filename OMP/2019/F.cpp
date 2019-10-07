#include <iostream>

using namespace std;

int main()
{
	int num_casos,n ,m;
	cin >> num_casos;

	for (int i = 0; i < num_casos; ++i)
	{
		cin >> n >> m;
		int primeras, ultima;
		if (m==3) {
			primeras = 6;
			ultima = 2;
		} else if (m==4) {
			primeras = 10;
			ultima = 4;
		} else {
			primeras = 10 + (m-4)*4;
			ultima = 4 + (m-4)*2;
		}

		int total = primeras * (n-2) + ultima;
		cout << total << endl;

	}
	return 0;
}