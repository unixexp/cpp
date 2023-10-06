#include <iostream>
using namespace std;

// Poly

class Parent {
    protected:
        string m_name;
    public:
        Parent(string name) : m_name(name) {};
        const string &getName() { return m_name; }
        virtual const string whoAreYou() { return "I'm Parent! My name is " + m_name; }
};

class Child: public Parent {
    public:
        Child(string name) : Parent(name) {};
        virtual const string whoAreYou() { return "I'm Child! My name is " + m_name; }
};

void report(Parent &obj) {
    cout << obj.whoAreYou() + "\n";
}

int main() {
    Parent parent("Bob");
    Child child("Joe");

    report(parent);
    report(child);

    return 0;
}