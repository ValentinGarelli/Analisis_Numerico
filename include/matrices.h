#ifndef MATRICES_H
#define MATRICES_H

#include <iostream>
#include <vector>
using namespace std;

class matrices
{
private:
  int filas, columnas;
  vector<vector<double>> M;
  vector<double> resultados;
  void intercambiar_filas(int fila1, int fila2);
  void multiplicar_fila(int fila, double escalar);
  void sumar_filas(int fila1, int fila2, double escalar);
  void triangulacion_superior();
  void sustitucion_regresiva();

public:
  matrices();
  ~matrices();
  void setFilas(int f);
  int getFilas();
  void setColumnas(int c);
  int getColumnas();
  void setMatriz(vector<vector<double>> m);
  vector<vector<double>> getMatriz();
  void cargarMatriz();
  void mostrarMatriz();
  void mostrarResultados();
  void eliminacion_gaussiana();
  void gauss_seidel();
};

#endif