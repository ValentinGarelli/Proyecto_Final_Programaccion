#include <iostream>
#include <string>
#include "lib.h"

Persona::Persona()
{
  DNI = 0;
  nombre = "";
  ingreso = 0;
}

void Persona::set_DNI(int num)
{
  try
  {
    if(num <= 1000000 || num >= 99999999)
    {
      throw "DNI invalido"; /* evita el el dni tenga menos de 7 cifras y mas de 8*/
    }
    DNI = num;
  }
  catch(const char* exception){
    std::cout << "Error: " << exception << std::endl;
  }

}

void Persona::set_nombre(std::string arg)
{
  nombre = arg;
}

void Persona::set_ingreso(int num)
{
  try
  {
    if(num < 1900)
    {
      throw "Ingreso invalido"; /* evita que el ingreso sea negativo*/
    }
    ingreso = num;
  }
  catch(const char* exception){
    std::cout << "Error: " << exception << std::endl;
  }

}

int Persona::get_DNI()
{
  return DNI;
}

std::string Persona::get_nombre()
{
  return nombre;
}

int Persona::get_ingreso()
{
  return ingreso;
}


