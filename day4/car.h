#ifndef _CAR_H_
#define _CAR_H_

class Car {
public:
  Car();
  ~Car();
  void setSpeed(double speed);
  double getSpeed();
  double getMigration();
  void drive(double hour);
private:
  double m_speed;
  double m_migration;
};
#endif // _CAR_H_
