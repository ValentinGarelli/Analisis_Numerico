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
  void sustitucion_progresiva();
  bool calculo_error(vector<double> x, vector<double> x_ant, double error);
  void triangulacion_inferior();
  double normadeMatriz(vector<vector<double>> m);
  int obtenerExponente(double num);
  bool VerificarDiagonalmenteDominante();
  void hacerDiagonalmenteDominante();

public:
  matrices();
  ~matrices();
  void setFilas(int f);
  int getFilas();
  void setColumnas(int c);
  int getColumnas();
  void setDato(int f, int c, double d);
  double getDato(int f, int c);
  void setMatriz(vector<vector<double>> m);
  vector<vector<double>> getMatriz();
  vector<double> getResultados();
  void cargarMatriz();
  void mostrarMatriz();
  void mostrarResultados();
  void eliminacion_gaussiana();
  void gauss_seidel();
  void metodo_de_LU();
  void copiarMatriz(matrices &m);
  void CondicionDeLaMatriz();
  vector<vector<double>> CalcularInversa();
  void ChequarSolucion(vector<double> x);
};

#endif