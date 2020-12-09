#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include<string>
#include <iomanip>

class Aldeano
{
    private:
        std::string name;
        int age;
        std::string gender;
        int health;

    public:
        Aldeano();
        Aldeano(const std::string &name, int age, const std::string &gender, float health = 0): name(name), age(age), gender(gender), health(health) {}

        void setName(const std::string &name);
        void setGender(const std::string &gender);
        void setAge(int age);
        void setHealth(float health);

        std::string getName() const;
        std::string getGender() const;
        int getAge() const;
        int getHealth() const;

        friend std::ostream& operator << (std::ostream &out, Aldeano &a){

         out << std::left;
         out << std::setw(20) << a.name;
         out << std::setw(20) << a.age;
         out << std::setw(20) << a.gender;
         out << std::setw(20) << a.health;
         out << std::endl;

         return out;

        }
        friend std::istream& operator >> (std::istream &in, Aldeano &a){
        std::cout << "NOMBRE: ";
        fflush(stdin);
        getline(std::cin, a.name);

        std::cout << "EDAD: ";
        std::cin >> a.age;

        std::cout << "GENERO: ";
        fflush(stdin);
        getline(std::cin, a.gender);

        std::cout << "SALUD: ";
        std::cin >> a.health;
        std::cin.ignore();
        }

        bool operator == (const Aldeano& c){
            return name == c.name;
        }

        bool operator == (const Aldeano& c) const{
            return name == c.name;
        }

        bool operator < (const Aldeano& c){
            return name < c.name;
        }

        bool operator < (const Aldeano& c) const{
            return name < c.name;
        }

};

#endif // ALDEANO_H
