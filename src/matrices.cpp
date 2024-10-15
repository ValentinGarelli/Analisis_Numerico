#include <iostream>
#include <vector>
#include <cmath>
#include "../include/matrices.h"
using namespace std;

matrices::matrices(int n)
{
  this->n = n;
  matriz.resize(n, vector<double>(n, 0));
  resultados.resize(n, 0);
}

matrices::~matrices()
{
}

void matrices::cargarMatriz()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (j < n)
      {
        cout << "Ingrese el valor de la posicion [" << i + 1 << "][" << j + 1 << "]: ";
        cin >> matriz[i][j];
      }
      else
      {
        cout << "Ingrese el valor del resultado de la ecuacion " << i + 1 << ": ";
        cin >> resultados[i];
      }
    }
  }
}

void matrices::mostrarMatriz()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matriz[i][j] << "\t";
    }
    cout << "| " << resultados[i] << endl;
  }
}

void matrices::mostrarResultados()
{
  for (int i = 0; i < n; i++)
  {
    cout << "x" << i + 1 << ": " << resultados[i] << endl;
  }
}

void matrices::multiplicarFilaPorEscalar(int fila, double escalar)
{
  for (int i = 0; i < n; i++)
  {
    matriz[fila][i] *= escalar;
  }
}

void matrices::sumarFilas(int fila1, int fila2, double escalar)
{
  for (int i = 0; i < n; i++)
  {
    matriz[fila2][i] += matriz[fila1][i] * escalar;
  }
}

void matrices::intercambiarFilas(int fila1, int fila2)
{
  for (int i = 0; i < n; i++)
  {
    swap(matriz[fila1][i], matriz[fila2][i]);
  }
}

void matrices::eliminacion_gaussiana()
{
  double factor;
  for (int i = 0; i < n; i++)
  {
    // Check for zero pivot element
    if (matriz[i][i] == 0)
    {
      cout << "elemento pivote es cero " << i << std::endl;
      return;
    }

    for (int j = i + 1; j < n; j++)
    {
      factor = matriz[j][i] / matriz[i][i];
      // elimina elementos bajo el pivote
      for (int k = i; k < n; k++)
      {
        matriz[j][k] -= factor * matriz[i][k];
      }
      resultados[j] -= factor * resultados[i];
    }
  }
  cout << "Matriz triangular superior" << endl;
  mostrarMatriz();
  // sustitucion hacia atras
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = i + 1; j < n; j++)
    {
      resultados[i] -= matriz[i][j] * resultados[j];
    }
    resultados[i] /= matriz[i][i];
  }
  cout << "\n matriz final " << endl;
  mostrarMatriz();
}

void matrices::gauss_seidel()
{
  double error, suma;
  vector<double> x(n, 0);
  vector<double> x_ant(n, 0);
  bool error_flag = false;
  cout << "Ingrese el error: ";
  cin >> error;

  do
  {
    error_flag = false;
    for (int i = 0; i < n; i++)
    {
      suma = 0;
      for (int j = 0; j < n; j++)
      {
        if (j != i)
        {
          suma += matriz[i][j] * x[j];
        }
      }
      x[i] = (resultados[i] - suma) / matriz[i][i];
    }
    for (int i = 0; i < n; i++)
    {
      cout << "x" << i + 1 << ": " << x[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
      if (abs(x[i] - x_ant[i]) > error)
      {
        error_flag = true;
        break;
      }
    }

    // Debug print statements
    cout << "Iteration complete. error_flag: " << error_flag << endl;
    for (int i = 0; i < n; i++)
    {
      cout << "x[" << i << "]: " << x[i] << ", x_ant[" << i << "]: " << x_ant[i] << ", abs(x[i] - x_ant[i]): " << abs(x[i] - x_ant[i]) << endl;
    }
    cout << "------------------------" << endl;
    x_ant = x;

  } while (error_flag);
}

void matrices::metodo_de_LU()
{
  vector<vector<double>> L(n, vector<double>(n, 0));
  vector<vector<double>> U(n, vector<double>(n, 0));
  double suma;
  // descomposicion LU
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      suma = 0;
      for (int k = 0; k < i; k++)
      {
        suma += L[i][k] * U[k][j];
      }
      U[i][j] = matriz[i][j] - suma;
    }
    for (int j = i; j < n; j++)
    {
      if (i == j)
      {
        L[i][i] = 1;
      }
      else
      {
        suma = 0;
        for (int k = 0; k < i; k++)
        {
          suma += L[j][k] * U[k][i];
        }
        L[j][i] = (matriz[j][i] - suma) / U[i][i];
      }
    }
  }
  cout << "Matriz L" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << L[i][j] << "\t";
    }
    cout << endl;
  }
  cout << "Matriz U" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << U[i][j] << "\t";
    }
    cout << endl;
  }
  // sustitucion hacia adelante
  vector<double> y(n, 0);
  for (int i = 0; i < n; i++)
  {
    suma = 0;
    for (int j = 0; j < i; j++)
    {
      suma += L[i][j] * y[j];
    }
    y[i] = (resultados[i] - suma) / L[i][i];
  }
  cout << "Matriz Y" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << y[i] << "\t";
  }
  cout << "\n";

  // sustitucion hacia atras
  vector<double> x(n, 0);

  for (int i = n - 1; i >= 0; i--)
  {
    suma = 0;
    for (int j = i + 1; j < n; j++)
    {
      suma += U[i][j] * x[j];
    }
    x[i] = (y[i] - suma) / U[i][i];
  }

  cout << "Resultados: " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "x" << i + 1 << ": " << x[i] << endl;
  }
}

void matrices::CondicionDeLaMatriz()
{
  double max = 0;
  double suma;
  for (int i = 0; i < n; i++)
  {
    suma = 0;
    for (int j = 0; j < n; j++)
    {
      suma += abs(matriz[i][j]);
    }
    if (suma > max)
    {
      max = suma;
    }
  }
  cout << "La condicion de la matriz es: " << max << endl;
}
