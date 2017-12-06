#include "Personaje.h"

Personaje::Personaje(){

};

Personaje::Personaje(double pHp,int pPoder,string pTipo,string pNombre,int pXp,int pNivel,double pMagia){
  hp = pHp;
  poder = pPoder;
  tipo = pTipo;
  nombre = pNombre;
  xp = pXp;
  nivel = pNivel;
  magia = pMagia;
}

void Personaje::write(ofstream& out){
   out.write(reinterpret_cast<char*>(&hp),sizeof(double));

   out.write(reinterpret_cast<char*>(&poder),sizeof(int));

   int size = tipo.size();
   out.write(reinterpret_cast<char*>(&size),sizeof(int));
   out.write(tipo.data(),tipo.size());

   size=nombre.size();
   out.write(reinterpret_cast<char*>(&size),sizeof(int));
   out.write(nombre.data(),nombre.size());

   out.write(reinterpret_cast<char*>(&xp),sizeof(int));

   out.write(reinterpret_cast<char*>(&nivel),sizeof(int));

   out.write(reinterpret_cast<char*>(&magia),sizeof(double));
}

void Personaje::read(ifstream& in){
  in.read(reinterpret_cast<char*>(&hp),sizeof(double));

  in.read(reinterpret_cast<char*>(&poder),sizeof(int));

  int size;
  in.read(reinterpret_cast<char*>(&size),sizeof(int));
  char tipoBuffer[size];
  in.read(tipoBuffer,size);
  tipo=tipoBuffer;

  in.read(reinterpret_cast<char*>(&size),sizeof(int));
  char nombreBuffer[size];
  in.read(nombreBuffer,size);
  nombre=nombreBuffer;

  in.read(reinterpret_cast<char*>(&xp),sizeof(int));

  in.read(reinterpret_cast<char*>(&nivel),sizeof(int));

  in.read(reinterpret_cast<char*>(&magia),sizeof(double));
}

ostream& operator<<(ostream& out, const Personaje& character){
   out<<character.nombre<<","<<character.tipo<<","<<character.hp<<","<<character.magia<<","<<character.poder<<","<<character.nivel<<","<<character.xp<<endl;
   return out;
}
