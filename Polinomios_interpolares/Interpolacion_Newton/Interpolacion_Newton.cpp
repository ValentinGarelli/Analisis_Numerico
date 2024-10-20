#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<double>> tabla_diferencias_divididas(vector<double> &x, vector<double> &y)
{
  int n = x.size();
  vector<vector<double>> tabla(n, vector<double>(n));
  for (size_t i = 0; i < n; i++)
  {
    tabla[i][0] = y[i];
  }

  for (size_t j = 1; j < n; j++)
  {
    for (size_t i = 0; i < n - j; i++)
    {
      tabla[i][j] = (tabla[i + 1][j - 1] - tabla[i][j - 1]) / (x[i + j] - x[i]);
    }
  }

  return tabla;
}

void Mostrar_Tabla(vector<vector<double>> &tabla, vector<double> &x)
{
  cout << "Tabla de diferencias divididas" << endl;
  cout << "--------------------------------" << endl;
  for (size_t i = 0; i < tabla.size(); i++)
  {
    cout << x[i] << "\t|";
    for (size_t j = 0; j < tabla[i].size(); j++)
    {
      cout << tabla[i][j] << "\t|";
    }
    cout << endl;
  }
}

void Polinomio_Newton(vector<vector<double>> &tabla, vector<double> &x)
{
  cout << "Polinomio de newton" << endl;
  cout << "--------------------------------" << endl;
  cout << tabla[0][0] << " ";
  for (size_t i = 1; i < tabla.size(); i++)
  {
    cout << "+ " << tabla[0][i];
    for (size_t j = 0; j < i; j++)
    {
      cout << "(x - " << x[j] << ")";
    }
  }
  cout << endl;
}

void Reducir_Polinomio(vector<vector<double>> &tabla, vector<double> &x)
{
  vector<double> coeficientes(x.size());

  for (int i = 0; i < x.size(); ++i)
  {
    coeficientes[i] = tabla[0][i];
  }

  cout << "Polinomio reducido :" << endl;
  cout << "--------------------------------" << endl;

  for (int i = 0; i < coeficientes.size(); ++i)
  {
    if (fabs(coeficientes[i]) > 1e-9)
    {
      if (i > 0 && coeficientes[i] > 0)
      {
        cout << " + ";
      }
      else if (coeficientes[i] < 0)
      {
        cout << " - ";
      }
      cout << fabs(coeficientes[i]);
      if (i > 0)
      {
        cout << "x";
        if (i > 1)
        {
          cout << "^" << i;
        }
      }
    }
  }
  cout << endl;
}

int main()
{
  vector<double> x = {0, 1, 2, 3};
  vector<double> y = {1, 2.7182, 7.3891, 20.0855};
  vector<vector<double>> tabla;

  cout << "Puntos: " << endl;
  for (size_t i = 0; i < x.size(); i++)
  {
    cout << "(" << x[i] << "; " << y[i] << ")" << endl;
  }

  tabla = tabla_diferencias_divididas(x, y);
  Mostrar_Tabla(tabla, x);
  Polinomio_Newton(tabla, x);
  Reducir_Polinomio(tabla, x);

  return 0;
}
