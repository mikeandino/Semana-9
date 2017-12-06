#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Personaje.h"
using namespace std;

int main(){
 Personaje personaje(70,5,"Thunder","Crono",0,1,5);
 ofstream binario("personaje.sota",ios::binary | ios::app);
 personaje.write(binario);
 binario.close();
 ifstream readBinary("personaje.sota",ios::binary);
 Personaje otroPersonaje;
 otroPersonaje.read(readBinary);
 readBinary.close();
 cout<<otroPersonaje;
 return 0;
}
