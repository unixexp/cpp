#include <iostream>
using namespace std;

class AbstractAnimal {
    virtual void run() = 0;
};

class Animal : AbstractAnimal {
    public:
        string name;
        Animal(string _name) {
            name = _name;
        }
        void say() { cout << "Hello" << endl; }
        void run() {
            cout << "Animal is running" << endl;
        }
};

class Dog : public Animal {
    public:
        Dog(string t) : Animal(t) {};
        void run() {
            cout << "dog " << name << " is running" << endl;
        }
};

class Cat : public Animal {
    public:
        Cat(string t) : Animal(t) {};
        void run() {
            cout << "cat " << name << " is running" << endl;
        }
};

void makeFriends(Animal &a, Animal &b) {
    cout << a.name << " and " << b.name << " are friends now" << endl;
    a.run();
    b.run();
}

int main() {

    string a;

    Dog dog("Bob");
    Cat cat("Catty");

    makeFriends(dog, cat);

    return 0;
}
