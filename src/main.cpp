#include <iostream>
#include "../include/raices.h"
#include "../include/funciones.h"
using namespace std;

void menu_raices()
{
  int opcion;
  raices r;
  string funcion;
  cout << "Ingrese la funcion: " << endl;
  cin >> funcion;
  r.setFuncion(funcion);
  do
  {
    cout << "Ingrese una opcion: " << endl;
    cout << "1. Metodo de la biseccion" << endl;
    cout << "0. Salir" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      r.metodo_biseccion();
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
