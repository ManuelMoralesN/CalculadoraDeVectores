#include "Vector3.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

Vector3::Vector3() : x(0.0), y(0.0), z(0.0) {}

Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

void Vector3::menu() {
    int opcion;
    Vector3 otro;

    do {
        cout << "\nMenu Vector3:" << endl;
        cout << "1. Ingresa tus valores 1" << endl;
        cout << "2. Sumar" << endl;
        cout << "3. Restar" << endl;
        cout << "4. Producto Punto" << endl;
        cout << "5. Producto Cruz" << endl;
        cout << "6. Magnitud" << endl;
        cout << "7. Normalizar" << endl;
        cout << "8. Multiplicar por escalar" << endl;
        cout << "9. Imprimir" << endl;
        cout << "10. Volver al menu principal" << endl;
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
            otro.leer();
            cout << "Producto Cruz: ";
            productoCruz(otro).imprimir();
            cout << endl;
            break;
        case 6:
            cout << "Magnitud: " << magnitud() << endl;
            break;
        case 7:
            normalizar().imprimir();
            cout << " (normalizado)" << endl;
            break;
        case 8:
            double escalar;
            cout << "Ingrese un escalar: ";
            cin >> escalar;
            imprimir();
            cout << " * " << escalar << " = ";
            multiplicarPorEscalar(escalar).imprimir();
            cout << endl;
            break;
        case 9:
            imprimir();
            cout << endl;
            break;
        case 10:
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    } while (opcion != 10);
}

void Vector3::leer() {
    cout << "Ingrese las coordenadas (x y z): ";
    cin >> x >> y >> z;
}

void Vector3::imprimir() const {
    cout << "(" << x << ", " << y << ", " << z << ")";
}

Vector3 Vector3::suma(const Vector3& otro) const {
    return Vector3(x + otro.x, y + otro.y, z + otro.z);
}

Vector3 Vector3::resta(const Vector3& otro) const {
    return Vector3(x - otro.x, y - otro.y, z - otro.z);
}

double Vector3::productoPunto(const Vector3& otro) const {
    return x * otro.x + y * otro.y + z * otro.z;
}

Vector3 Vector3::productoCruz(const Vector3& otro) const {
    return Vector3(y * otro.z - z * otro.y, z * otro.x - x * otro.z, x * otro.y - y * otro.x);
}

double Vector3::magnitud() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::normalizar() const {
    double mag = magnitud();
    if (mag != 0.0) {
        return Vector3(x / mag, y / mag, z / mag);
    }
    return *this;
}

Vector3 Vector3::multiplicarPorEscalar(double escalar) const {
    return Vector3(x * escalar, y * escalar, z * escalar);
}
