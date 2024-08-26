#include <iostream>
#include <string>
#include "../include/funciones.h"
#include "../include/raices.h"
using namespace std;

raices::raices()
{
  funcion = "";
}

raices::raices(string f)
{
  funcion = f;
}

raices::~raices()
{
}

void raices::setFuncion(string f)
{
  funcion = f;
}

string raices::getFuncion()
{
  return funcion;
}

void raices::metodo_biseccion()
{
  double a, b, c = 0, error, fa, fb, fc, v_ant;

  cout << "Ingrese el valor de a: ";
  cin >> a;
  cout << "Ingrese el valor de b: ";
  cin >> b;
  cout << "Ingrese el valor del error: ";
  cin >> error;

  if (expresion(funcion, a) * expresion(funcion, b) > 0)
  {
    cout << "No hay raices en el intervalo" << endl;
  }
  else
  {
    do
    {
      v_ant = c;
      c = (a + b) / 2;
      fa = expresion(funcion, a);
      fb = expresion(funcion, b);
      fc = expresion(funcion, c);
      if (fa * fc < 0)
      {
        b = c;
      }
      else if (fa * fc > 0)
      {
        a = c;
      }

    } while (abs(c - v_ant) > error);
    cout << "La raiz es: " << c << endl;
  }
}

void raices::metodo_de_punto_fijo()
{
  string g;
  double x, error, v_ant, a, b, epsilon;

  cout << "Ingrese la funcion g(x): ";
  cin.ignore();
  getline(cin, g);
  cout << "Ingrese el valor de a: ";
  cin >> a;
  cout << "Ingrese el valor de b: ";
  cin >> b;
  cout << "Ingrese el valor de epsilon (numero que maximiza la funcion entre a y b): ";
  cin >> epsilon;
  cout << "ingrese el error maximo: ";
  cin >> error;

  if ((expresion(g, a) < a || expresion(g, a) > b) || (expresion(g, b) < a || expresion(g, b) > b))
  {
    cout << "La funcion no converge" << endl;
  }
  else if (abs(derivada(g, epsilon)) > 1)
  {
    cout << "La funcion no converge" << endl;
  }
  else
  {
    do
    {
      v_ant = x;
      x = expresion(g, x);
    } while (abs(x - v_ant) > error);
  }
  cout << "La raiz es: " << x << endl;
}

void raices::metodo_newton_raphson()
{
  double x, error, v_ant;
  cout << "Ingrese el valor de x: ";
  cin >> x;
  cout << "Ingrese el valor del error: ";
  cin >> error;
  do
  {
    v_ant = x;
    x = x - (expresion(funcion, x) / derivada(funcion, x));
  } while (abs(x - v_ant) > error);
  cout << "La raiz es: " << x << endl;
}
