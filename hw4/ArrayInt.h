#include <cassert>
#pragma once

class ArrayInt {
private:
    int m_length;
    int* m_data;
public:
    ArrayInt() : m_length(0), m_data(nullptr) {};
    ArrayInt(int l) : m_length(l) {
        assert(l >= 0);
        if (l > 0)
            m_data = new int[l];
        else
            m_data = nullptr;
    }
    ~ArrayInt() {
        delete[] m_data;
    }
    void erase() {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    int getLength() const {
        return m_length;
    }
    int& operator[] (int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    void resize(int newL) {
        if (m_length == newL)
            return;
        if (newL <= 0) {
            erase();
            return;
        }
        int* data = new int[newL];
        if (m_length > 0) {
            int elementsToCopy = newL > m_length ? m_length : newL;
            for (size_t i = 0; i < elementsToCopy; i++)
            {
                data[i] = m_data[i];
            }
            delete[] m_data;
            m_data = data;
            m_length = newL;
        }
    }
    void insertBefore(int value, int index) {
        assert(index >= 0 && index <= m_length);
        int* data = new int[m_length + 1];
        for (size_t i = 0; i < index; i++)
        {
            data[i] = m_data[i];
        }
        data[index] = value;
        for (size_t i = index; i < m_length; i++)
        {
            data[i + 1] = m_data[i];
        }
        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    void push_back(int value) {
        insertBefore(value, m_length);
    }

    /*task 1*/
    void pop_back() {
        resize(m_length - 1);
    }

    void pop_front() {
        int* data = new int[m_length-1];
        for (size_t i = 0; i < m_length; i++)
        {
            data[i] = m_data[i + 1];
        }
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void sort(){
        int temp;
        for (size_t i = 0; i < m_length-1; i++)
        {
            for (size_t j = 0; j < m_length-i-1; j++)
            {
                if (m_data[j] > m_data[j + 1]) {
                    temp = m_data[j];
                    m_data[j] = m_data[j + 1];
                    m_data[j + 1] = temp;
               }
            }
        }
    }

    void print() const {
        cout << "[ ";
        for (size_t i = 0; i < m_length; i++)
        {
            cout << m_data[i] << ", ";
        }
        cout << "]" << endl;
    }
};