#include <iostream>
using namespace std;

class A {
    private:
        string m_value;
    public:
        static const int FLAG = 1;
        static string m_svalue;

        A(const string &value="") { m_value = value; }

        const string &getValue() { return m_value; }
};

string A::m_svalue = "Static value";

int main() {
    A a("Class A");
    cout << a.getValue() << endl;
    cout << A::m_svalue << endl;

    return 0;
}