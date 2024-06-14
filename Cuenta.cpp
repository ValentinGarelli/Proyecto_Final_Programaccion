#include <iostream>
#include <ctime>
#include <cstdlib>
#include "lib.h"
using namespace std;

/*Declaracion metodos de Cuenta*/

Cuenta::Cuenta()
{
  numero_cuenta = rand() %  999999 + 100000;
  saldoPesos = 0;
  saldoDolares = 0;
  limite = 0;
}


void Cuenta::set_numero_cuenta(int num)
{
    try
    {
      if(num < 100000 || num > 999999)
      {
        throw "Numero de cuenta invalido"; /* evita que el numero de cuenta tenga menos de 6 cifras y mas de 7*/
      }
      else
      {
        numero_cuenta = num;
      }
    }
    catch(const char* exception)
    {
      cerr << "Error: " << exception << endl;
    }
    
}

int Cuenta::get_numero_cuenta()
{
  return numero_cuenta;
}

void Cuenta::set_saldoPesos(long double num)
{
  saldoPesos = num;
}

long double Cuenta::get_saldoPesos()
{
  return saldoPesos;
}

void Cuenta::set_saldoDolares(long double num)
{
  saldoDolares = num;
}

long double Cuenta::get_saldoDolares()
{
  return saldoDolares;
}

void Cuenta::set_limite(int num)
{
  limite = num;
}

int Cuenta::get_limite()
{
  return limite;
}

void Cuenta::gastarlimite( double num){
  if (limite > num)
  {
    limite -= num;
  }
  else{
    cout << "saldo insuficiente" << endl;
  }
  
}