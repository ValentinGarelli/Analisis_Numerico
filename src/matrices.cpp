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

void matrices::intercambiar_filas(int fila1, int fila2)
{
  cout << "Intercambiando filas " << fila1 + 1 << " y " << fila2 + 1 << endl;
  vector<double> aux = M[fila1];
  M[fila1] = M[fila2];
  M[fila2] = aux;
}

void matrices::multiplicar_fila(int fila, double escalar)
{
  cout << "Multiplicando la fila " << fila + 1 << " por " << escalar << endl;
  for (int i = 0; i < M[fila].size(); i++)
  {
    M[fila][i] *= escalar;
  }
}

void matrices::sumar_filas(int fila1, int fila2, double escalar)
{
  cout << "Sumando la fila " << fila2 + 1 << " multiplicada por " << escalar << " a la fila " << fila1 + 1 << endl;
  for (int i = 0; i < M[fila1].size(); i++)
  {
    M[fila1][i] += M[fila2][i] * escalar;
  }
}

void matrices::triangulacion_superior()
{
  for (int i = 0; i < filas; i++)
  {
    for (int j = 0; j < columnas; j++)
    {
      if (i == j)
      {
        if (M[i][j] == 0)
        {
          for (int k = i + 1; k < filas; k++)
          {
            if (M[k][j] != 0)
            {
              intercambiar_filas(i, k);
              break;
            }
          }
        }
      }
      else if (i > j)
      {
        if (M[i][j] != 0)
        {
          sumar_filas(i, j, -(M[i][j] / M[j][j]));
        }
      }
    }
  }
}

void matrices::sustitucion_regresiva()
{
  resultados = vector<double>(filas, 1);

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
      cout << M[i][j] << " ";
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
  } while (abs(x[0] - x_ant[0]) > error);

  resultados = x;
}

matrices::~matrices()
{
}