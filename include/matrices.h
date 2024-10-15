#ifndef MATRICES_H
#define MATRICES_H

#include <iostream>
#include <vector>
using namespace std;

class matrices
{
private:
  int n;
  vector<double> resultados;
  vector<vector<double>> matriz;
  void multiplicarFilaPorEscalar(int fila, double escalar);
  void sumarFilas(int fila1, int fila2, double escalar);
  void intercambiarFilas(int fila1, int fila2);

public:
  matrices(int n);
  ~matrices();
  void cargarMatriz();
  void mostrarMatriz();
  void mostrarResultados();
  void eliminacion_gaussiana();
  void gauss_seidel();
  void metodo_de_LU();
  void CondicionDeLaMatriz();
};

#endif