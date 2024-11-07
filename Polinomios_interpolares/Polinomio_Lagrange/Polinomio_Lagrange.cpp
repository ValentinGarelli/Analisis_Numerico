#include <iostream>
#include <vector>

using namespace std;

// Función para calcular el polinomio base de Lagrange L_i(x)
double polinomioBaseLagrange(const vector<double> &x, int i, double x_val)
{
  double resultado = 1.0;
  for (int j = 0; j < x.size(); ++j)
  {
    if (j != i)
    {
      resultado *= (x_val - x[j]) / (x[i] - x[j]);
    }
  }
  return resultado;
}

// Función para calcular el polinomio de Lagrange P(x)
double polinomioLagrange(const vector<double> &x, const vector<double> &y, double x_val)
{
  double resultado = 0.0;
  for (int i = 0; i < x.size(); ++i)
  {
    resultado += y[i] * polinomioBaseLagrange(x, i, x_val);
  }
  return resultado;
}

int main()
{
  // Vectores x e y
  vector<double> x = {-1, 0, 1, 2};
  vector<double> y = {2, -0.7183, 0, 0.8964};

  // Calcular e imprimir todos los polinomios base de Lagrange
  cout << "Polinomios base de Lagrange:" << endl;
  for (int i = 0; i < x.size(); ++i)
  {
    cout << "L_" << i << "(x) = ";
    bool primerTermino = true;
    for (int j = 0; j < x.size(); ++j)
    {
      if (j != i)
      {
        if (!primerTermino)
        {
          cout << " * ";
        }
        cout << "((x - " << x[j] << ") / (" << x[i] << " - " << x[j] << "))";
        primerTermino = false;
      }
    }
    cout << endl;
  }

  // Calcular e imprimir el polinomio de Lagrange P(x)
  cout << "\nPolinomio de Lagrange P(x):" << endl;
  cout << "P(x) = ";
  for (int i = 0; i < x.size(); ++i)
  {
    if (i > 0)
    {
      cout << " + ";
    }
    cout << y[i] << " * L_" << i << "(x)";
  }
  cout << endl;

  // Evaluación del polinomio de Lagrange en un punto específico
  double x_val = -1.5342;
  double resultado = polinomioLagrange(x, y, x_val);
  cout << "\nP(" << x_val << ") = " << resultado << endl;
  x_val = -0, 5732;
  resultado = polinomioLagrange(x, y, x_val);
  cout << "P(" << x_val << ") = " << resultado << endl;
  x_val = 1.5;
  resultado = polinomioLagrange(x, y, x_val);
  cout << "P(" << x_val << ") = " << resultado << endl;
  x_val = 1.5674;
  resultado = polinomioLagrange(x, y, x_val);
  cout << "P(" << x_val << ") = " << resultado << endl;

  return 0;
}