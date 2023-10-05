#pragma once

class Vector4 {
private:
    double x;
    double y;
    double z;
    double w;

public:
    Vector4();
    Vector4(double x, double y, double z, double w);

    void menu();
    void leer();
    void imprimir() const;
    Vector4 suma(const Vector4& otro) const;
    Vector4 resta(const Vector4& otro) const;
    double productoPunto(const Vector4& otro) const;
    double magnitud() const;
    Vector4 normalizar() const;
    Vector4 multiplicarPorEscalar(double escalar) const;
};
