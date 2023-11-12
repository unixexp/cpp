#ifndef SOMELIBRARY_HPP
#define SOMELIBRARY_HPP

#include <iostream>
#include <string>

template <class T>
class SmartContainer {
    private:
        int m_length;
        T *m_data;
    public:
        SmartContainer();
        SmartContainer(int length);
        ~SmartContainer();

        int getLength();

        T& operator[](int index);
};

class SmartContainerException {
    private:
        std::string m_text;
    public:
        SmartContainerException(std::string text);
        friend std::ostream& operator<<(std::ostream &out, const SmartContainerException &exception);
};

#endif // SOMELIBRARY_HPP