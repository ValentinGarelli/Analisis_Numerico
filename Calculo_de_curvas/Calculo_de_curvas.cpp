#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double Sumatoria_lineal(vector<double> &vect)
{
  double sum = 0;
  for (size_t i = 0; i < vect.size(); i++)
  {
    sum += vect[i];
  }
  return sum;
}

double sumatoria_exponencial(vector<double> &vect)
{
  double sum = 0;
  for (size_t i = 0; i < vect.size(); i++)
  {
    sum += log(vect[i]);
  }
  return sum;
}

double sumatoria_exponencial_10(vector<double> &vect)
{
  double sum = 0;
  for (size_t i = 0; i < vect.size(); i++)
  {
    sum += log10(vect[i]);
  }
  return sum;
}

void regresion_lineal(vector<double> &x, vector<double> &y, double &a_cero, double &a_uno)
{
  int n = x.size();
  double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
  sum_x = Sumatoria_lineal(x);
  sum_y = Sumatoria_lineal(y);

  for (size_t i = 0; i < n; i++)
  {

    sum_xy += x[i] * y[i];
    sum_x2 += pow(x[i], 2);
  }

  cout << "Sumatoria de x: " << sum_x << endl;
  cout << "Sumatoria de y: " << sum_y << endl;
  cout << "Sumatoria de xy: " << sum_xy << endl;
  cout << "Sumatoria de x^2: " << sum_x2 << endl;

  a_uno = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - pow(sum_x, 2));
  a_cero = ((sum_y / n) - a_uno * (sum_x / n));
}

void regresion_exponecial(vector<double> &x, vector<double> &y, double &a_cero, double &a_uno)
{
  int n = x.size();
  double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
  sum_x = Sumatoria_lineal(x);
  sum_y = sumatoria_exponencial(y);

  for (size_t i = 0; i < n; i++)
  {

    sum_xy += x[i] * log(y[i]);
    sum_x2 += pow(x[i], 2);
  }

  cout << "Sumatoria de x: " << sum_x << endl;
  cout << "Sumatoria de y: " << sum_y << endl;
  cout << "Sumatoria de xy: " << sum_xy << endl;
  cout << "Sumatoria de x^2: " << sum_x2 << endl;

  a_uno = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - pow(sum_x, 2));
  a_cero = exp((sum_y / n) - (a_uno * (sum_x / n)));
}

void regresion_potencial(vector<double> &x, vector<double> &y, double &a_cero, double &a_uno)
{
  int n = x.size();
  double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
  sum_x = sumatoria_exponencial_10(x);
  sum_y = sumatoria_exponencial_10(y);

  for (size_t i = 0; i < n; i++)
  {
    sum_xy += log10(x[i]) * log10(y[i]);
    sum_x2 += pow(log10(x[i]), 2);
  }

  cout << "Sumatoria de x: " << sum_x << endl;
  cout << "Sumatoria de y: " << sum_y << endl;
  cout << "Sumatoria de xy: " << sum_xy << endl;
  cout << "Sumatoria de x^2: " << sum_x2 << endl;

  a_uno = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - pow(sum_x, 2));
  a_cero = pow(10, (sum_y / n) - (a_uno * (sum_x / n)));
}

int main()
{
  vector<double> x = {1, 2, 3, 4, 5};
  vector<double> y = {0.5, 1.7, 3.4, 5.7, 8.4};
  int n, opcion;
  double a_cero, a_uno;
  n = x.size();

  cout << "Datos de entrada: " << endl;
  for (size_t i = 0; i < n; i++)
  {
    cout << "x: " << x[i] << " y: " << y[i] << endl;
  }

  cout << "1. Calcular regresion lineal" << endl;
  cout << "2. Calcular regresion exponencial" << endl;
  cout << "3. Calcular regresion potencial" << endl;
  cout << "Ingrese una opcion: ";
  cin >> opcion;
  switch (opcion)
  {
  case 1:
    regresion_lineal(x, y, a_cero, a_uno);
    cout << "La ecuacion de la recta es: y = " << a_uno << "X + " << a_cero << endl;
    break;
  case 2:
    regresion_exponecial(x, y, a_cero, a_uno);
    cout << "La ecuacion de la recta es: y = " << a_cero << "e^" << a_uno << "X" << endl;
    break;
  case 3:
    regresion_potencial(x, y, a_cero, a_uno);
    cout << "La ecuacion de la recta es: y = " << a_cero << "X^" << a_uno << endl;
    break;

  default:
    cout << "Opcion no valida" << endl;
    break;
  }

  return 0;
}