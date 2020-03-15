#include <iostream>
#include <string>

using namespace std;

int main() {

	int n, l1, l2, l3;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> l1 >> l2 >> l3;
		if (l1 == l2 && l1 == l3)
			cout << "equilatero" << endl;
		else if (l1 != l2 && l1 != l3 && l2 != l3)
			cout << "escaleno" << endl;
		else
			cout << "isosceles" << endl;
	}

}
