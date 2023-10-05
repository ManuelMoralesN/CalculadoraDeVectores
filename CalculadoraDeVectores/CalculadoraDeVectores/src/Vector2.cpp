#include "Vector2.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

Vector2::Vector2() : x(0.0), y(0.0) {}

Vector2::Vector2(double x, double y) : x(x), y(y) {}

void Vector2::menu() {
    int opcion;
    Vector2 otro;

    do {
        cout << "\nMenu Vector2:" << endl;
        cout << "1. Ingresa tus valores 1" << endl;
        cout << "2. Sumar" << endl;
        cout << "3. Restar" << endl;
        cout << "4. Producto Punto" << endl;
        cout << "5. Magnitud" << endl;
        cout << "6. Normalizar" << endl;
        cout << "7. Multiplicar por escalar" << endl;
        cout << "8. Imprimir" << endl;
        cout << "9. Volver al menu principal" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            leer();
            break;
        case 2:
            otro.leer();
            imprimir();
            cout << " + ";
            otro.imprimir();
            cout << " = ";
            suma(otro).imprimir();
            cout << endl;
            break;
        case 3:
            otro.leer();
            imprimir();
            cout << " - ";
            otro.imprimir();
            cout << " = ";
            resta(otro).imprimir();
            cout << endl;
            break;
        case 4:
            otro.leer();
            cout << "Producto Punto: " << productoPunto(otro) << endl;
            break;
        case 5:
            cout << "Magnitud: " << magnitud() << endl;
            break;
        case 6:
            normalizar().imprimir();
            cout << " (normalizado)" << endl;
            break;
        case 7:
            double escalar;
            cout << "Ingrese un escalar: ";
            cin >> escalar;
            imprimir();
            cout << " * " << escalar << " = ";
            multiplicarPorEscalar(escalar).imprimir();
            cout << endl;
            break;
        case 8:
            imprimir();
            cout << endl;
            break;
        case 9:
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    } while (opcion != 9);
}

void Vector2::leer() {
    cout << "Ingrese las coordenadas (x y): ";
    cin >> x >> y;
}

void Vector2::imprimir() const {
    cout << "(" << x << ", " << y << ")";
}

Vector2 Vector2::suma(const Vector2& otro) const {
    return Vector2(x + otro.x, y + otro.y);
}

Vector2 Vector2::resta(const Vector2& otro) const {
    return Vector2(x - otro.x, y - otro.y);
}

double Vector2::productoPunto(const Vector2& otro) const {
    return x * otro.x + y * otro.y;
}

double Vector2::magnitud() const {
    return std::sqrt(x * x + y * y);
}

Vector2 Vector2::normalizar() const {
    double mag = magnitud();
    if (mag != 0.0) {
        return Vector2(x / mag, y / mag);
    }
    return *this;
}

Vector2 Vector2::multiplicarPorEscalar(double escalar) const {
    return Vector2(x * escalar, y * escalar);
}
