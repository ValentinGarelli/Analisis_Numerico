#include <iostream>
#include <vector>

#include "../include/matrices.h"
using namespace std;

matrices::matrices()
{
  filas = 0;
  columnas = 0;
  M = vector<vector<double>>(filas, vector<double>(columnas));
}

void matrices::setFilas(int f)
{
  filas = f;
}

int matrices::getFilas()
{
  return filas;
}

void matrices::setColumnas(int c)
{
  columnas = c;
}

int matrices::getColumnas()
{
  return columnas;
}

void matrices::setMatriz(vector<vector<double>> m)
{
  M = vector<vector<double>>(filas, vector<double>(columnas));
  M = m;
}

vector<vector<double>> matrices::getMatriz()
{
  return M;
}

void matrices::setDato(int f, int c, double d)
{
  M[f][c] = d;
}

double matrices::getDato(int f, int c)
{
  return M[f][c];
}

void matrices::cargarMatriz()
{
  M = vector<vector<double>>(filas, vector<double>(columnas));
  for (int i = 0; i < M.size(); i++)
  {
    for (int j = 0; j < M[i].size(); j++)
    {
      cout << "Ingrese el valor de la posicion [" << i + 1 << "][" << j + 1 << "]: ";
      cin >> M[i][j];
    }
  }
}

void matrices::copiarMatriz(matrices &m)
{
  filas = m.getFilas();
  columnas = m.getColumnas();
  M = m.getMatriz();
}

vector<double> matrices::getResultados()
{
  return resultados;
}

void matrices::intercambiar_filas(int fila1, int fila2)
{
  vector<double> aux = M[fila1];
  M[fila1] = M[fila2];
  M[fila2] = aux;
}

void matrices::multiplicar_fila(int fila, double escalar)
{
  for (int i = 0; i < M[fila].size(); i++)
  {
    M[fila][i] *= escalar;
  }
}

void matrices::sumar_filas(int fila1, int fila2, double escalar)
{
  for (int i = 0; i < M[fila1].size(); i++)
  {
    M[fila1][i] += M[fila2][i] * escalar;
  }
}

void matrices::triangulacion_superior()
{
  const double epsilon = 1e-10;

  for (size_t iteraciones = 0; iteraciones < 100; iteraciones++)
  {
    for (int i = 0; i < filas; i++)
    {
      for (int j = 0; j < columnas; j++)
      {

        if (i > j)
        {
          if (abs(M[i][j]) >= epsilon)
          {
            sumar_filas(i, j, -(M[i][j] / M[j][j]));
          }
        }
      }
    }
  }
}

void matrices::triangulacion_inferior()
{
  const double epsilon = 1e-10;

  for (size_t iteraciones = 0; iteraciones < 100; iteraciones++)
  {
    for (int i = 0; i < filas; i++)
    {
      for (int j = 0; j < columnas; j++)
      {

        if (i < j)
        {
          if (abs(M[i][j]) >= epsilon)
          {
            sumar_filas(i, j, -(M[i][j] / M[j][j]));
          }
        }
      }
    }
  }
}

void matrices::sustitucion_regresiva()
{
  resultados = vector<double>(filas);

  for (int i = filas - 1; i >= 0; i--)
  {
    double suma = 0;
    for (int j = columnas - 2; j > i; j--)
    {
      suma += M[i][j] * resultados[j];
    }
    resultados[i] = (M[i][columnas - 1] - suma) / M[i][i];
  }
}

void matrices::sustitucion_progresiva()
{
  resultados = vector<double>(filas, 1);

  for (int i = 0; i < filas; i++)
  {
    double suma = 0;
    for (int j = 0; j < i; j++)
    {
      suma += M[i][j] * resultados[j];
    }
    resultados[i] = (M[i][columnas - 1] - suma) / M[i][i];
  }
}

void matrices::eliminacion_gaussiana()
{
  triangulacion_superior();
  sustitucion_regresiva();
}

void matrices::mostrarMatriz()
{
  for (int i = 0; i < M.size(); i++)
  {
    for (int j = 0; j < M[i].size(); j++)
    {
      cout << M[i][j] << "\t";
    }
    cout << endl;
  }
}

void matrices::mostrarResultados()
{
  for (int i = 0; i < resultados.size(); i++)
  {
    cout << "X" << i + 1 << " = " << resultados[i] << endl;
  }
}

void matrices::gauss_seidel()
{
  double error, suma;
  vector<double> x, x_ant;
  x = vector<double>(filas, 1);
  x_ant = vector<double>(filas, 0);
  cout << "Ingrese el error: ";
  cin >> error;
  do
  {
    for (int i = 0; i < filas; i++)
    {
      suma = 0;
      for (int j = 0; j < columnas - 1; j++)
      {
        if (j != i)
        {
          suma += M[i][j] * x[j];
        }
      }
      x_ant[i] = x[i];
      x[i] = (M[i][columnas - 1] - suma) / M[i][i];
    }
  } while (calculo_error(x, x_ant, error));

  resultados = x;
}

bool matrices::calculo_error(vector<double> x, vector<double> x_ant, double error)
{
  for (int i = 0; i < x.size(); i++)
  {
    if (abs(x[i] - x_ant[i]) > error)
    {
      return true;
    }
  }
  return false;
}

void matrices::metodo_de_LU()
{
  vector<vector<double>> L, U;
  vector<double> x, y;
  L = vector<vector<double>>(filas, vector<double>(columnas, 0));
  U = vector<vector<double>>(filas, vector<double>(columnas, 0));
  x = vector<double>(filas, 0);
  y = vector<double>(filas, 0);

  for (int i = 0; i < filas; i++)
  {
    L[i][i] = 1;
  }

  for (int i = 0; i < filas; i++)
  {
    for (int j = 0; j < columnas; j++)
    {
      double suma = 0;

      for (int k = 0; k < i; k++)
      {
        suma += L[i][k] * U[k][j];
      }
    }

    for (int j = i; j < columnas; j++)
    {
      double suma = 0;

      for (int k = 0; k < i; k++)
      {
        suma += L[i][k] * U[k][j];
      }

      U[i][j] = M[i][j] - suma;
    }

    for (int j = i + 1; j < filas; j++)
    {
      double suma = 0;

      for (int k = 0; k < i; k++)
      {
        suma += L[j][k] * U[k][i];
      }

      L[j][i] = (M[j][i] - suma) / U[i][i];
    }
  }

  for (int i = 0; i < filas; i++)
  {
    double suma = 0;

    for (int j = 0; j < i; j++)
    {
      suma += L[i][j] * y[j];
    }

    y[i] = (M[i][columnas - 1] - suma) / L[i][i];
  }

  for (int i = filas - 1; i >= 0; i--)
  {
    double suma = 0;

    for (int j = columnas - 2; j > i; j--)
    {
      suma += U[i][j] * x[j];
    }

    x[i] = (y[i] - suma) / U[i][i];
  }

  resultados = x;
}

matrices::~matrices()
{
}