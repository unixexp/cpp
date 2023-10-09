#include <iostream>
using namespace std;

// Class initialization variants

class A {
    private:
        int m_value;
    public:
        A(int value) {
            m_value = value;
            cout << "Constructor with params" << "\n";
        };

        A(const A &a) : m_value(a.m_value) {
            cout << "Copy constructor" << "\n";
        }
        
        ~A() {
            cout << "Destructor" << "\n";
        };
        
        int getValue() { return m_value; }
        void setValue(int value) { m_value = value; }
        void printValue() { cout << m_value << "\n"; }
};


int main() {
    // Using direct initialization by constructor with params - USE THIS WAY!
    A a1(5);
    a1.printValue();

    // Using uniform initialization by constructor with params - USE THIS WAY!
    A a5 {8};
    a5.printValue();

    // Using copy-style initialization by copy constructor - DANGER!
    // For dynamic class variables you should make overload of copy constructor and operator=
    A a2 = a1;
    a2.printValue();

    // Using copy-style initialization by constructor with params (elision) - DANGER!
    A a3 = A(6);
    a3.printValue();

    // Using copy-style initialization by constructor with params - DANGER!
    A a4 = 7;
    a4.printValue();

    return 0;
}