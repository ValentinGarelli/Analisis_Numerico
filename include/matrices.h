#ifndef MATRICES_H
#define MATRICES_H

#include <iostream>
#include <vector>
using namespace std;

class matrices
{
private:
  vector<vector<double>> M;
  bool fila_nula(int fila);
  void intercambiar_filas(int fila1, int fila2);
  void multiplicar_fila(int fila, double escalar);
  void sumar_filas(int fila1, int fila2, double escalar);
  void triangulacion_superior();
  void sustitucion_regresiva();

public:
  matrices(int filas, int columnas);
  ~matrices();
  void setMatriz(vector<vector<double>> m);
  vector<vector<double>> getMatriz();
  void cargarMatriz();
  void eliminacion_gaussiana();
  void gauss_seidel();
};

#endif