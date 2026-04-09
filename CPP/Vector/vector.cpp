#include "vector.h"
#include <iostream>


Vector::Vector(): m_elements(nullptr), m_size(0) {
}

Vector::Vector(int newSize) : m_size(newSize){
		if (newSize > 0){
				m_elements = new double[m_size];
		}
		else{
				m_elements = nullptr;
				m_size = 0;
				std::cout << "Ungültige größe!" << std::endl;
		}
}

Vector::~Vector(){
		delete[] m_elements;
		std::cout << "Destruktor aufgerufen!" << std::endl;
}

int Vector::getSize(){
		return m_size;
}


void Vector::setSize(int newSize){
		m_size = newSize;
}
