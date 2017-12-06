#include "Alumno.h"


void Alumno::read(ifstream& in){
  int size; 
  in.read(reinterpret_cast<char*>(&size),sizeof(int));
  //buffer de nombre
  char nameBuffer[size];
  in.read(nameBuffer,size);
  
  nombre=nameBuffer;
  //cuenta
  in.read(reinterpret_cast<char*>(&size),sizeof(int));
  cout<<size;
  char numBuffer[size];
  in.read(numBuffer,size);

  cuenta=numBuffer;

  //carrera
  in.read(reinterpret_cast<char*>(&size),sizeof(int));
  char carreraBuffer[size];
  in.read(carreraBuffer,size);
  carrera = carreraBuffer;

  //edad
  in.read(reinterpret_cast<char*>(&edad),sizeof(int));

  



}

void Alumno::write(ofstream& out){
   int size = nombre.size();   
   //length del nombre y contenido
   out.write(reinterpret_cast<char*>(&size),sizeof(int));
 


  out.write(nombre.data(),nombre.size());

  //cuenta
  size=cuenta.size();
   out.write(reinterpret_cast<char*>(&size),sizeof(int));
   out.write(cuenta.data(),cuenta.size());
  //carrera
  size=carrera.size();
   out.write(reinterpret_cast<char*>(&size),sizeof(int));
   out.write(carrera.data(),carrera.size());

   out.write(reinterpret_cast<char*>(&edad),sizeof(int));

}



istream& operator>>(istream& in, Alumno& student){
  string buffer;
  //leer una línea del archivo
  getline(in,buffer);
  string parse="";
  int cont=0; 
  for(int i = 0; i<buffer.size();i++){
    if(buffer[i]!=',')
      parse+=buffer[i];
    else{
      
      switch(cont){
        case 0:
          student.nombre = parse;
           break;
        case 1:
           student.cuenta = parse; 
         
      }
      cont++;
    }
  }

  return in;
}


ostream& operator<<(ostream& out, const Alumno& student){

   out<<student.nombre<<","<<student.cuenta<<","<<student.carrera<<","<<student.edad<<endl;
   return out;

}


Alumno::Alumno(){
  nombre="Juan Pueblo";
  cuenta="11711111";
  carrera="I-1";
  edad=17;
}

Alumno::Alumno(string pNombre, string pCuenta, string pCarrera, int pEdad){
  nombre=pNombre;
  cuenta=pCuenta;
  carrera=pCarrera;
  edad=pEdad;
}
