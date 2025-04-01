#pragma once
#include <iostream>
template <typename T>
class complex_number{
public:
    T a;
    T b;
    complex_number() : a(0), b(0) {}

    // Costruttore esplicito che inizializza 'a' con 'r' e 'b' con 0
    explicit complex_number(T r) : a(r), b(0) { 
        std::cout << "converting constructor called" << std::endl;
    }
    complex_number(T r,T i): a(r),b(i) {}
    complex_number<T> coniugato() const {
        return complex_number<T>(a,-b);
    }

    // Metodi per ottenere parte reale e immaginaria
    T reale() const { return a; }
    T immaginaria() const { return b; }
    complex_number& operator+=(const complex_number& other) {
        a += other.a;  // Aggiorna direttamente la parte reale
        b += other.b;
        return *this;
	}
    complex_number operator+(const complex_number& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
    complex_number& operator+=(const T& other) {
        a += other;
        return *this;
    }
    complex_number operator+(const T& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
    complex_number& operator*=(const complex_number& other) {
        a = a*other.a-b*other.b;
        b = a*other.b+b*other.a;
        return *this;
	}
    complex_number operator*(const complex_number& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
    complex_number& operator*=(const T& other) {
        a = a*other;
        b = b*other;
        return *this;
    }
    complex_number operator*(const T& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
};
double epsilon = 1.0e-6;
template<typename T>
std::ostream &operator<<(std::ostream &os, const complex_number<T> &c) {
    if (c.reale()>epsilon || c.reale()<-epsilon)
    {
        if (c.immaginaria()>epsilon)
        {
            os<<c.reale()<<"+"<<c.immaginaria()<<"i";
        }
        else if (c.immaginaria()<-epsilon)
        {
            os<<c.reale()<<c.immaginaria()<<"i";

        }
        else
        {
            os<<c.reale();
        }
    }
    else
    {
        if (c.immaginaria()>epsilon || c.immaginaria()<-epsilon)
        {
            os<<c.immaginaria()<<"i";
        }
        else if (c.immaginaria()==0)
        {
            os<<"0";
        }
    }
    return os;
}