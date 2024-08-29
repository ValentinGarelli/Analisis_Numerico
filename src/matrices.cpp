#include <iostream>
#include <vector>
#include "../include/matrices.h"
using namespace std;

matrices::matrices(int filas, int columnas)
{
  M.resize(filas);
  for (int i = 0; i < filas; i++)
  {
    M[i].resize(columnas);
  }
}

void matrices::setMatriz(vector<vector<double>> m)
{
  M = m;
}

vector<vector<double>> matrices::getMatriz()
{
  return M;
}

void matrices::cargarMatriz()
{
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
  vector<double> aux = M[fila1];
  M[fila1] = M[fila2];
  M[fila2] = aux;
}

bool matrices::fila_nula(int fila)
{
  for (int i = 0; i < M[fila].size(); i++)
  {
    if (M[fila][i] != 0)
    {
      return false;
    }
  }
  return true;
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
  for (int i = 0; i < M.size(); i++)
  {
    for (int j = 1; j < M[i].size(); j++)
    {
      if (M[i][i] == 0)
      {
        for (int k = i + 1; k < M.size(); k++)
        {
          if (M[k][i] != 0)
          {
            intercambiar_filas(i, k);
            break;
          }
        }
      }
      if (M[i][i] != 0)
      {
        if (M[j][i] != 0)
        {
          sumar_filas(j, i, -M[j][i] / M[i][i]);
        }
      }
    }
  }
}

void matrices::sustitucion_regresiva()
{
  vector<double> x(M.size());
  for (int i = M.size(); i >= 0; i--)
  {
    for (int j = M[i].size(); j < i; j--)
    {
    }
  }
}

void matrices::eliminacion_gaussiana()
{
  vector<double> fila1, fila2, aux;
  triangulacion_superior();
}
