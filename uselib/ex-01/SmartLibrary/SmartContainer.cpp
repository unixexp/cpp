#include "include/SmartContainer.hpp"

template <typename T>
SmartContainer<T>::SmartContainer() {
    m_length = 0;
    m_data = nullptr;
}

template <typename T>
SmartContainer<T>::SmartContainer(int length) {
    if (length > 0) {
        m_data = new T(length);
        m_length = length;
    } else {
        throw SmartContainerException("Container length should be > 0");
    }
}

template <typename T>
SmartContainer<T>::~SmartContainer() {
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

template <typename T>
int SmartContainer<T>::getLength() {
    return m_length;
}

template <typename T>
T& SmartContainer<T>::operator[](int index) {
    if (index < 0 || index > m_length) {
        throw SmartContainerException("Index outbound");
    } else {
        return m_data[index];
    }
}

SmartContainerException::SmartContainerException(std::string text) {
    m_text = text;
}

std::ostream& operator<<(std::ostream &out, const SmartContainerException &exception) {
    out << exception.m_text;
    return out;
}

template class SmartContainer<int>;