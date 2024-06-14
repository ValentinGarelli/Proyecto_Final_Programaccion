#include <iostream>
#include "lib.h"
#include <fstream>
#include <string>
#include <limits>
using namespace std;


int CantClientes(){
  ifstream fich("fclientes.txt");
  string aux;
  int cantidad = 0;
  try
  {
    if (fich.is_open())
    {
      fich >> aux;
      fich >> aux;
      fich >> aux;
      fich >> cantidad;
    }
    else
    {
      throw "no se pudo abrir el archivo";
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
  fich.close();
  return cantidad;

}

void detalleCliente(Banco &bancoUCC){
  int numcuenta;
  cout << "Ingrese el numero de cuenta del cliente: ";
  cin >> numcuenta;
  bancoUCC.detalleCliente(numcuenta);
}

void listadoClientes(Banco &bancoUCC){
  bancoUCC.listadoClientes();
}

void transaccionesCliente(sistema &sistemaUCC){
  int numcuenta;
  cout << "Ingrese el numero de cuenta del cliente: ";
  cin >> numcuenta;
  sistemaUCC.transaccionPorCliente(numcuenta);
}

void transaccionesMes(sistema &sistemaUCC){
  int mes;
  cout << "Ingrese el mes en formato numerico(mm): ";
  cin >> mes;
  sistemaUCC.transaccionPorMes(mes);
}

void transaccionesAnio(sistema &sistemaUCC){
  int A;
  cout << "Ingrese el anio en formato numerico(yyyy): ";
  cin >> A;
  sistemaUCC.transaccionPorAnio(A);
}

void todasTransacciones(sistema &sistemaUCC){
  sistemaUCC.mostrarTransacciones();
}

void depositar(Banco &bancoUCC, sistema &sistemaUCC){
  long double monto, numero;
  char moneda;
  try
  {
    cout<<"ingrese la moneda (P)pesos (D)dolares"<<endl;
    cin>>moneda;
    if (!cin.fail() || (moneda == 'P' || moneda == 'D') || (moneda == 'p' || moneda == 'd'))
    {
      cout<<"ingrese el nro de cuenta en el que desea depositar"<<endl;
      cin>>numero;
      if (!cin.fail())
      {
        cout<<"ingrese el monto a depositar"<<endl;
        cin>>monto;
        if (!cin.fail())
        {
        bancoUCC.deposito(monto,numero,moneda);
        sistemaUCC.guardartransaccion(monto,numero,moneda);
        }
        else
        {
          throw "Dato no valido";
        }
      }
      else
      {
        throw "Dato no valido";
      }
    }
    else
    {
      throw "Dato no valido";
    }
  }
  catch(const char* exception)
  {
    cerr << "Error:" << exception  << endl;
  }

  
  
}
void extraccion(Banco &bancoUCC, sistema &sistemaucc){
  long double monto,numero;
  char moneda;
  try
  {
    cout<<"ingrese la moneda (P)pesos (D)dolares"<<endl;
    cin>>moneda;
    if (!cin.fail() || (moneda == 'P' || moneda == 'D') || (moneda == 'p' || moneda == 'd'))
    {
      cout<<"ingrese el nro de cuenta en el que desea extraer"<<endl;
      cin>>numero;
      if (!cin.fail())
      {
        cout<<"ingrese el monto a extraer"<<endl;
        cin>>monto;
        if (!cin.fail())
        {
        bancoUCC.extraer(monto,numero,moneda);
        monto = monto * (-1);
        sistemaucc.guardartransaccion(monto,numero,moneda);
        }
        else
        {
          throw "Dato no valido";
        }
      }
      else
      {
        throw "Dato no valido";
      }
    }
    else
    {
      throw "Dato no valido";
    }
  }
  catch(const char* exception)
  {
    cerr << "Error:" << exception  << endl;
  }
  
  
  
}

void credito(Banco &BancoUCC){
  double monto,numero;
  
  try{
    cout << "Ingrese el numero de cuenta del cliente: ";
    cin >> numero;
    if (!cin.fail())
    {
      cout << "Ingrese el monto a usar de credito: ";
      cin >> monto;
      if (!cin.fail())
      {
        BancoUCC.credito(numero,monto);
      }
      else
      {
        throw "Dato no valido";
      }
    }
    else
    {
      throw "Dato no valido";
    }
  }
  catch(const char* exception)
  {
    cerr << "Error:" << exception  << endl;
  }
  
  
}

void agregarCliente(Banco &bancoUCC){
  string nom,lvl,apellido;
  int dni;
  try
  {
    
    cout << "Ingrese el dni del cliente: ";
    cin >> dni;
    if (!cin.fail())
    {
      cout << "Ingrese el nombre del cliente: ";
      cin >> nom;
      cout << "Ingrese el apellido del cliente: ";
      cin >> apellido;
      nom = nom + " " + apellido;
      cout << "Ingrese el nivel del cliente: ";
      cin >> lvl;
      
      bancoUCC.agregarCliente(nom,dni,lvl);
    }
    else
    {
      throw "DNI no valido";
    }
    
  }
  catch(const char* exception)
  {
    cerr << "Error:" << exception  << endl;
  }
  
  
}
void estadoCliente(Banco &bancoUCC){
  int numC;
  string estado;
  cout<<"ingrese el numero de cuenta"<<endl;
  cin>>numC;
  cout<<"ingrese a que estado lo desea poner, (a) Activar, (b) Dar de baja "<<endl;
  cin>>estado;

  bancoUCC.baja(numC,estado);

}

void sist(int operacion,Banco &bancoUCC,sistema &sistemaUCC){
  switch (operacion)
  {
  case 1:
    detalleCliente(bancoUCC);
    break;
  case 2:
    listadoClientes(bancoUCC);
    break;
  case 3:
    transaccionesCliente(sistemaUCC);
    break;
  case 4:
    transaccionesMes(sistemaUCC);
    break;
  case 5:
    transaccionesAnio(sistemaUCC);
    break;
  case 6:
    todasTransacciones(sistemaUCC);
    break;
  case 7:
    depositar(bancoUCC, sistemaUCC);
    break;
  case 8:
    extraccion(bancoUCC, sistemaUCC);
    break;
  case 9:
    credito(bancoUCC);
    break;
  case 10:
    agregarCliente(bancoUCC);
    break;
  case 11:
    estadoCliente(bancoUCC);
    break;
  default:
  cout << "numero invalido"<< endl;
    break;
  }

};

void Menu(){
  try
  {
    Banco bancoUCC(CantClientes());
    sistema sistemaUCC;
    bancoUCC.cargaclientes();
    int operacion;
    string variable = "si";
    string test_op;

    while (variable == "si")
    {
      cout << "ingrese la operacion que desea realizar: " << endl;
      cout << "(1) Ver detalle de un cliente ingresando su numero de cuenta" << endl;
      cout << "(2) Ver listado de todos los clientes del banco" << endl;
      cout << "(3) Ver Listado de transacciones de un cliente" << endl;
      cout << "(4) Ver listado de transacciones de un mes" << endl;
      cout << "(5) ver listado de transacciones de un anio" << endl;
      cout << "(6) Ver listado de todas las transacciones" << endl;
      cout << "(7) Depositar dinero" << endl;
      cout<<  "(8) Extraer dinero" << endl;
      cout<<  "(9) Pagar en credito" << endl;
      cout<<  "(10) Agregar cliente" << endl;
      cout<< "(11) Cambiar Estado"<<endl;
      
      do
      {
        operacion = 0;
        cin >> test_op;
        try {
            operacion = stoi( test_op );
            if(operacion > 11 || operacion < 1) throw 404;
        }
        catch( ... )
        {
            cout << "Invalid value, try again\n";
        }    
      }
      while(operacion > 11 || operacion < 1);

      sist(operacion,bancoUCC,sistemaUCC);
      cout<<"si desea seguir operando, ingrese si"<<endl;
      cin >> variable;
      
      
    }
    sistemaUCC.guardarClientes(bancoUCC);
  }
  catch(const char* exception){
    cerr << exception << endl;
  }
  catch(bad_alloc& exception)
  {
    cerr << "Error de memoria"<< endl;
  }
  catch(...){
    cerr << "Error inesperado" << endl;
  }
}


int main(){
  Menu();
  system("pause");
  return 0;
}


