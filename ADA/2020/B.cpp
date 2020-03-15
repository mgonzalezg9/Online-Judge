#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int nCasos;
    string entrada;
    string nota;
    bool asc = false;
    bool desc = false;
    bool nada = false;
    bool una = false;
    string ante, actual;

    cin >> nCasos;
    getline(cin, entrada);

    while (nCasos > 0) {
        getline(cin, entrada);
        std::istringstream iss(entrada);

        string actual;
        iss >> actual;
        ante = actual;

        if (iss >> actual) {
            if ((ante == "do" && actual == "re") ||
                    (ante == "re" && actual == "mi") ||
                    (ante == "mi" && actual == "fa") ||
                    (ante == "fa" && actual == "sol") ||
                    (ante == "sol" && actual == "la") ||
                    (ante == "la" && actual == "si") ||
                    (ante == "si" && actual == "do")
               )
                asc = true;
            else if ((ante == "do" && actual == "si") ||
                     (ante == "re" && actual == "do") ||
                     (ante == "mi" && actual == "re") ||
                     (ante == "fa" && actual == "mi") ||
                     (ante == "sol" && actual == "fa") ||
                     (ante == "la" && actual == "sol") ||
                     (ante == "si" && actual == "la")
                    )
                desc = true;
            else
                nada = true;
        } else
            una = true;

        ante = actual;

        for (; !una && !nada && iss >> actual; ) {
            if (asc && !((ante == "do" && actual == "re") ||
                         (ante == "re" && actual == "mi") ||
                         (ante == "mi" && actual == "fa") ||
                         (ante == "fa" && actual == "sol") ||
                         (ante == "sol" && actual == "la") ||
                         (ante == "la" && actual == "si") ||
                         (ante == "si" && actual == "do")
                        ))
                nada = true;
            else if (desc && !((ante == "do" && actual == "si") ||
                               (ante == "re" && actual == "do") ||
                               (ante == "mi" && actual == "re") ||
                               (ante == "fa" && actual == "mi") ||
                               (ante == "sol" && actual == "fa") ||
                               (ante == "la" && actual == "sol") ||
                               (ante == "si" && actual == "la")
                              ))
                nada = true;

            ante = actual;
        }
        nCasos--;

        if (nada)
            cout << "no hay escala" << endl;
        else if (desc)
            cout << "escala descendente" << endl;
        else
            cout << "escala ascendente" << endl;

        asc = false;
        desc = false;
        nada = false;
        una = false;

    }
}
