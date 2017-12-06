#include "Alumno.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std; 


int main(){
 ofstream salida("alumnos.txt", ios::app );
 Alumno alumno("Reynod Bocanegra Sanchez","10311115","I-1 Sistemas Comp",25);

 salida<<alumno;

 int a = atoi("123");
// cout<<a<<endl;
 salida.close();

 ///archivo binario
 ofstream binario("alumnos.dat",ios::binary | ios::app);
 

 alumno.write(binario);
 binario.close();
 
 ifstream readBinary("alumnos.dat",ios::binary);

 Alumno otroAlumno;
 otroAlumno.read(readBinary);
 readBinary.close();
 cout<<otroAlumno;
 

 return 0;
}
