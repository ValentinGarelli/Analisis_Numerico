#ifndef RAICES_H
#define RAICES_H

#include <iostream>
using namespace std;

class raices
{
private:
  string funcion;

public:
  raices();
  raices(string f);
  ~raices();
  void setFuncion(string f);
  string getFuncion();
  void metodo_biseccion();
  void metodo_de_punto_fijo();
  void metodo_newton_raphson();
  void metodo_secante();
};

#endif