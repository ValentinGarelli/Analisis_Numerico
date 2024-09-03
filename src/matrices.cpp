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

void matrices::triangulacion_inferior()
{
  for (int i = 0; i < filas; i++)
  {
    for (int j = 0; j < columnas - 1; j++)
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
        else
        {
          multiplicar_fila(i, 1 / M[i][j]);
        }
      }
      else if (i < j)
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
  matrices L, U;
  vector<double> y;
  y = vector<double>(filas);
  L.setFilas(filas);
  L.setColumnas(columnas);
  U.setFilas(filas);
  U.setColumnas(columnas);
  L.setMatriz(M);
  U.setMatriz(M);

  for (size_t i = 0; i < filas; i++)
  {
    y[i] = L.getDato(i, columnas - 1);
  }
  L.triangulacion_inferior();
  for (size_t i = 0; i < filas; i++)
  {
    L.setDato(i, columnas - 1, y[i]);
  }

  cout << "Matriz L" << endl;
  L.mostrarMatriz();
  U.triangulacion_superior();
  cout << "Matriz U" << endl;
  U.mostrarMatriz();
  L.sustitucion_progresiva();

  cout << "Resultados de L" << endl;
  L.mostrarResultados();

  for (size_t i = 0; i < filas; i++)
  {
    U.setDato(i, columnas - 1, y[i]);
  }
  cout << "Matriz U con resultados de L" << endl;
  U.mostrarMatriz();

  U.sustitucion_regresiva();
  resultados = U.resultados;
}

matrices::~matrices()
{
}