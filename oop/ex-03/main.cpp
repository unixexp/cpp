#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Vector of class objects

class Parent {
    protected:
        string m_name;
    public:
        Parent(string name) : m_name(name) {};
        virtual ~Parent() { cout << "Parent destructor call" << "\n"; };
        
        const string &getName() { return m_name; }
        virtual const string whoAreYou() { return "I'm Parent! My name is " + m_name; }
};

class Child final : public Parent {
    public:
        Child(string name) : Parent(name) {};
        virtual ~Child() { cout << "Child destructor call" << "\n"; };

        virtual const string whoAreYou() override { return "I'm Child! My name is " + m_name; }
};

int main() {

    // Example with manually memory clean

    vector<Parent*> v1;

    v1.push_back(new Parent("Bob"));
    v1.push_back(new Child("Joe"));

    for (int i = 0; i < v1.size(); ++i) {
        if (static_cast<bool>(v1[i])) {
            cout << v1[i]->whoAreYou() << "\n";
            delete v1[i];
        }
    }

    // Example with automatically memory clean by unique pointer template

    vector<unique_ptr<Parent>> v2;

    v2.push_back(unique_ptr<Parent>(new Parent("Bob")));
    v2.push_back(unique_ptr<Parent>(new Child("Joe")));

    for (int i = 0; i < v2.size(); ++i) {
        if (static_cast<bool>(v2[i]))
            cout << v2[i]->whoAreYou() << "\n";
    }

    return 0;
}