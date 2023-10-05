#include "Vector4.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

Vector4::Vector4() : x(0.0), y(0.0), z(0.0), w(0.0) {}

Vector4::Vector4(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}

void Vector4::menu() {
    int opcion;
    Vector4 otro;

    do {
        cout << "\nMenu Vector 4:" << endl;
        cout << "1. Leer valores" << endl;
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

void Vector4::leer() {
    cout << "Ingrese las coordenadas (x y z w): ";
    cin >> x >> y >> z >> w;
}

void Vector4::imprimir() const {
    cout << "(" << x << ", " << y << ", " << z << ", " << w << ")";
}

Vector4 Vector4::suma(const Vector4& otro) const {
    return Vector4(x + otro.x, y + otro.y, z + otro.z, w + otro.w);
}

Vector4 Vector4::resta(const Vector4& otro) const {
    return Vector4(x - otro.x, y - otro.y, z - otro.z, w - otro.w);
}

double Vector4::productoPunto(const Vector4& otro) const {
    return x * otro.x + y * otro.y + z * otro.z + w * otro.w;
}

double Vector4::magnitud() const {
    return std::sqrt(x * x + y * y + z * z + w * w);
}

Vector4 Vector4::normalizar() const {
    double mag = magnitud();
    if (mag != 0.0) {
        return Vector4(x / mag, y / mag, z / mag, w / mag);
    }
    return *this;
}

Vector4 Vector4::multiplicarPorEscalar(double escalar) const {
    return Vector4(x * escalar, y * escalar, z * escalar, w * escalar);
}
