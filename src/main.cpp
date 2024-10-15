#include <iostream>
#include "../include/raices.h"
#include "../include/funciones.h"
#include "../include/matrices.h"
using namespace std;

void menu_raices()
{
  int opcion;
  raices r;
  string funcion;
  // cout << "Ingrese la funcion: " << endl;
  // cin >> funcion;
  // funcion = "(x+1)/(e^x)";
  funcion = "2-((x+2)/e^x)";
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

void menu_matrices()
{
  int opcion, n;
  cout << "Ingrese el la cantidad de filas de la matriz: ";
  cin >> n;
  matrices m(n), m2(n);
  do
  {
    cout << "Ingrese una opcion: " << endl;
    cout << "1. Cargar matriz" << endl;
    cout << "2. Mostrar matriz" << endl;
    cout << "3. Eliminacion gaussiana" << endl;
    cout << "4. Gauss-Seidel" << endl;
    cout << "5. Metodo de LU" << endl;
    cout << "6. Condicion de la matriz" << endl;
    cout << "0. Salir" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      m.cargarMatriz();
      break;
    case 2:
      m.mostrarMatriz();
      break;
    case 3:
      m.eliminacion_gaussiana();
      break;
    case 4:
      m.gauss_seidel();
      break;
    case 5:
      m.metodo_de_LU();
      break;
    case 6:
      // m.CondicionDeLaMatriz();
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
    cout << "2. Operaciones con matrices" << endl;
    cout << "0. Salir" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
    {
      menu_raices();
      break;
    }
    case 2:
    {
      menu_matrices();
      break;
    }

    default:
    {
      break;
    }
    }
  } while (opcion != 0);

  return 0;
}
