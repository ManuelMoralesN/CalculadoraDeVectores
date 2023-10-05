#include "App.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void App::ejecutar() {
    int opcion;
    Vector2 v2;
    Vector3 v3;
    Vector4 v4;

    do {
        cout << "*****************************************" << endl;
        cout << "Bienvenido a la calculadora de Vectores:" << endl;
        cout << "Eliga su opcion:" << endl;
        cout << "1. Operar con Vector2" << endl;
        cout << "2. Operar con Vector3" << endl;
        cout << "3. Operar con Vector4" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opcion: " << endl;
        cout << "*****************************************" << endl;
        cin >> opcion;

        switch (opcion) {
        case 1:
            v2.menu();
            break;
        case 2:
            v3.menu();
            break;
        case 3:
            v4.menu();
            break;
        case 4:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    } while (opcion != 4);
}
