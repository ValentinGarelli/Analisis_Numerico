#include <iostream>
#include "../include/raices.h"
#include "../include/funciones.h"
using namespace std;

void menu_raices()
{
  int opcion;
  raices r;
  string funcion;
  // cout << "Ingrese la funcion: " << endl;
  // cin >> funcion;
  funcion = "-0.874*(x^2) + 1.750*x + 2.627";
  r.setFuncion(funcion);
  do
  {
    cout << "Ingrese una opcion: " << endl;
    cout << "1. Metodo de la biseccion" << endl;
    cout << "2. Metodo de punto fijo" << endl;
    cout << "3. Metodo de Newton-Raphson" << endl;
    cout << "4. Metodo de la secante" << endl;
    cout << "0. Salir" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      r.metodo_biseccion();
      break;
    case 2:
      r.metodo_de_punto_fijo();
      break;
    case 3:
      r.metodo_newton_raphson();
      break;
    case 4:
      r.metodo_secante();
      break;
    default:
      break;
    }
  } while (opcion != 0);
}

int main()
{
  int opcion;
  do
  {
    cout << "Ingrese una opcion: " << endl;
    cout << "1. Raices de una funcion" << endl;
    cout << "0. Salir" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
    {
      menu_raices();
      break;
    }
    }

  } while (opcion != 0);

  return 0;
}
