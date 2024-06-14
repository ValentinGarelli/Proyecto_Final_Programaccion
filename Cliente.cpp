#include <iostream>
#include "lib.h"
using namespace std;

Cliente::Cliente()
{
  estado = "ACTIVO";
  Cuenta();
  nivel = "PLATA";
}



void Cliente::set_estado(std::string est)
{
  estado = est;
}


string Cliente::get_estado()
{
  return estado;
}

void Cliente::depositar_pesos(long double monto)
{
  try
  {
    if (monto < 0)
    {
      throw "Monto invalido";
    }
    else
    {
      cuenta.set_saldoPesos(cuenta.get_saldoPesos() + monto);
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

void Cliente::depositar_dolares(long double monto)
{
  try
  {
    if (monto < 0)
    {
      throw "Monto invalido";
    }
    else
    {
      cuenta.set_saldoDolares(cuenta.get_saldoDolares() + monto);
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

void Cliente::retirar_pesos(long double monto)
{
  try
  {
    if (cuenta.get_saldoPesos() < monto)
    {
      throw "Saldo insuficiente";
    }
    else
    {
      cuenta.set_saldoPesos(cuenta.get_saldoPesos() - monto);
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

void Cliente::retirar_dolares(long double monto)
{
  try
  {
    if (cuenta.get_saldoDolares() < monto)
    {
      throw "Saldo insuficiente";
    }
    else
    {
      cuenta.set_saldoDolares(cuenta.get_saldoDolares() - monto);
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

int Cliente::get_numCuenta()
{
  return cuenta.get_numero_cuenta();
}

double Cliente::get_saldoPesos(){
  return cuenta.get_saldoPesos();
}

double Cliente::get_saldoDolares(){
  return cuenta.get_saldoDolares();
}

void Cliente::set_numcuenta(int numero_cuenta){
  cuenta.set_numero_cuenta(numero_cuenta);

}

void Cliente::set_saldo_Pesos(int n){
  cuenta.set_saldoPesos(n);
}

void Cliente::set_saldoDolares(int n){
  cuenta.set_saldoDolares(n);
}

void Cliente::set_nivel(string niv)
{
  try
  {
    if (niv == "PLATA"|| niv== "plata")
    {
      cuenta.set_limite(0);
      nivel = "PLATA";
    }
    else if (niv == "ORO"|| niv =="oro")
    {
      cuenta.set_limite(250000);
      nivel = "ORO";
    }
    else if (niv == "PLATINO"|| niv == "platino")
    {
      cuenta.set_limite(500000);
      nivel = "PLATINO";
    }
    else
    {
      throw "Nivel invalido";
    }
  } 
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

string Cliente::get_nivel()
{
  return nivel;
}

void Cliente::gastarlimite(double num){
  try
  {
    if (num > cuenta.get_limite() || num < 0)
    {
      throw "Limite excedido o monto invalido";
    }
    else
    {
      cuenta.set_limite(cuenta.get_limite() - num);
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}
