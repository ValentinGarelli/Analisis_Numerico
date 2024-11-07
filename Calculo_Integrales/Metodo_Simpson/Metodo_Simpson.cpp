#include <iostream>
#include <cmath>

using namespace std;

// Define la función a integrar
double f(double x)
{
  return 2 - ((x + 2) / exp(x));
}

// Método de Simpson
double simpson_integration(double (*func)(double), double a, double b, int n)
{
  // Asegúrate de que n sea par
  if (n % 2 != 0)
  {
    n++;
  }

  double h = (b - a) / n;
  double integral = func(a) + func(b);

  cout << "h = " << h << endl;
  cout << "func(a) = " << func(a) << ", func(b) = " << func(b) << endl;

  for (int i = 1; i < n; i += 2)
  {
    double x = a + i * h;
    double fx = func(x);
    integral += 4 * fx;
    cout << "i = " << i << ", x = " << x << ", 4 * func(x) = " << 4 * fx << endl;
  }

  for (int i = 2; i < n - 1; i += 2)
  {
    double x = a + i * h;
    double fx = func(x);
    integral += 2 * fx;
    cout << "i = " << i << ", x = " << x << ", 2 * func(x) = " << 2 * fx << endl;
  }

  integral *= h / 3;
  cout << "Integral final (antes de multiplicar por h/3) = " << integral << endl;
  return integral;
}

int main()
{
  double a = 0; // Límite inferior
  double b = 5; // Límite superior
  int n = 20;   // Número de subintervalos

  double resultado = simpson_integration(f, a, b, n);
  cout << "La integral definida de f(x) desde " << a << " hasta " << b << " es: " << resultado << endl;

  return 0;
}