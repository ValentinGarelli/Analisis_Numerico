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

void menu_matrices()
{
  int opcion, filas, columnas;
  matrices matriz, matriz_aux;
  cout << "Ingrese el numero de filas: ";
  cin >> filas;
  cout << "Ingrese el numero de columnas: ";
  cin >> columnas;
  matriz.setFilas(filas);
  matriz.setColumnas(columnas);
  matriz.cargarMatriz();
  matriz.mostrarMatriz();

  do
  {
    matriz_aux.copiarMatriz(matriz);
    cout << "Ingrese una opcion: " << endl;
    cout << "1. Metodo de eliminacion gaussiana" << endl;
    cout << "2. Metodo de Gauss-Seidel" << endl;
    cout << "3. Metodo de LU" << endl;
    cout << "0. Salir" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      matriz_aux.eliminacion_gaussiana();
      matriz_aux.mostrarMatriz();
      matriz_aux.mostrarResultados();
      break;
    case 2:
      matriz_aux.gauss_seidel();
      matriz_aux.mostrarResultados();
      break;
    case 3:
      matriz_aux.metodo_de_LU();
      matriz_aux.mostrarResultados();
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
