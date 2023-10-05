#pragma once

class Vector2 {
private:
    double x;
    double y;

public:
    Vector2();
    Vector2(double x, double y);

    void menu();
    void leer();
    void imprimir() const;
    Vector2 suma(const Vector2& otro) const;
    Vector2 resta(const Vector2& otro) const;
    double productoPunto(const Vector2& otro) const;
    double magnitud() const;
    Vector2 normalizar() const;
    Vector2 multiplicarPorEscalar(double escalar) const;
};
