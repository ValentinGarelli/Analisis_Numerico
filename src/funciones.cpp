#include <iostream>
#include "../include/funciones.h"
using namespace std;

double expresion(const string f, double x)
{
  typedef exprtk::symbol_table<double> symbol_table_t;
  typedef exprtk::expression<double> expression_t;
  typedef exprtk::parser<double> parser_t;

  symbol_table_t symbol_table;
  symbol_table.add_variable("x", x);
  symbol_table.add_constant("e", exp(1));
  symbol_table.add_constants();

  expression_t func;
  func.register_symbol_table(symbol_table);

  parser_t parser;
  parser.compile(f, func);

  return func.value();
}

double derivada(const string f, double x)
{
  typedef exprtk::symbol_table<double> symbol_table_t;
  typedef exprtk::expression<double> expression_t;
  typedef exprtk::parser<double> parser_t;

  symbol_table_t symbol_table;
  symbol_table.add_variable("x", x);
  symbol_table.add_constant("e", exp(1));
  symbol_table.add_constants();

  expression_t func;
  func.register_symbol_table(symbol_table);

  parser_t parser;
  parser.compile(f, func);

  double derivada = exprtk::derivative(func, "x");
  return derivada;
}