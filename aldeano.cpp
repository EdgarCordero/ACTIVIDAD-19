#include "aldeano.h"

using namespace std;

Aldeano::Aldeano()
{

}

void Aldeano::setName(const string &name){
    this->name = name;
}

void Aldeano::setGender(const string &gender){
    this->gender = gender;
}

void Aldeano::setAge(int age){
    this->age = age;
}

void Aldeano::setHealth(float health){
    this->health = health;
}

string Aldeano::getName()const{
    return name;
}

string Aldeano::getGender()const{
    return gender;
}

int Aldeano::getAge() const{
    return age;
}

int Aldeano::getHealth() const{
    return health;
}
