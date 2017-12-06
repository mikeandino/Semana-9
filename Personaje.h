#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>
using namespace std;
class Personaje{
private:
  double hp;
  int poder;
  string tipo;
  string nombre;
  int xp;
  int nivel;
  double magia;
public:
  Personaje();
  Personaje(double,int,string,string,int,int,double);
  void write(ofstream&);
  void read(ifstream&);
  friend ostream& operator<<(ostream&,const Personaje&);
};
#include "Personaje.cpp"
#endif
