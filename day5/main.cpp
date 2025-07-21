#include <iostream>
#include "car.h"
#include "ambulance.h"

using namespace std;

int main (int argc, char** argv){
  cout << "-- Carクラスの処理" << endl;
  Car* pCar = new Car();
  pCar->setSpeed(40);
  pCar->drive(1.5);
  cout << "総移動距離: " << pCar->getMigration() << "km" << endl;
  delete pCar;

  cout << "-- Ambulanceクラスの処理" << endl;
  Ambulance* pAmb = new Ambulance();

  pAmb->setSpeed(60);
  pAmb->drive(2);

  cout << "総移動距離: " << pCar->getMigration() << "km" << endl;
  pAmb->sevePeople();

  delete pAmb;
  return 0;
}
