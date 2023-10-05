#pragma once

class Vector3 {
private:
    double x;
    double y;
    double z;

public:
    Vector3();
    Vector3(double x, double y, double z);

    void menu();
    void leer();
    void imprimir() const;
    Vector3 suma(const Vector3& otro) const;
    Vector3 resta(const Vector3& otro) const;
    double productoPunto(const Vector3& otro) const;
    Vector3 productoCruz(const Vector3& otro) const;
    double magnitud() const;
    Vector3 normalizar() const;
    Vector3 multiplicarPorEscalar(double escalar) const;
};
