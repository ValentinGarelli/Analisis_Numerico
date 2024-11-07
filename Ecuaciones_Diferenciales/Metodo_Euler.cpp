#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Definimos la función que representa la ecuación diferencial
double f(double x, double y)
{
  // Aquí puedes cambiar la función según la ecuación diferencial que quieras resolver
  return ((1 / x) * ((y * y) + y)); // Ejemplo: dy/dx = x + y
}

// Función que implementa el método de Euler
void euler(double x0, double y0, double h, double x_end)
{
  double x = x0;
  double y = y0;
  int iteration = 0; // Contador de iteraciones

  cout << setw(10) << "Iteración" << setw(10) << "x" << setw(10) << "y" << endl;
  cout << fixed << setprecision(6);

  while (x < x_end)
  {
    cout << setw(10) << iteration << setw(10) << x << setw(10) << y << endl;
    y = y + h * f(x, y); // Actualizamos y
    x = x + h;           // Actualizamos x
    iteration++;         // Incrementamos el contador de iteraciones
  }
}

int main()
{
  double x0, y0, h, x_end;

  x0 = 1; // Valor inicial de x
  y0 = -2;
  h = 0.2;
  x_end = 3; // Valor final de x

  // Llamamos a la función de Euler
  euler(x0, y0, h, x_end);

  return 0;
}
