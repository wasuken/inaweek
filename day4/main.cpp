#include <iostream>
#include "car.h"

using namespace std;

int main(int argc, char** argv) {
  Car car;
  car.setSpeed(40);
  car.drive(1.5);
  car.setSpeed(60);
  car.drive(2.0);
  cout << "総移動距離:" << car.getMigration() << "km" << endl;
  return 0;
}
