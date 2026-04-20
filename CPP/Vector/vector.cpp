#include "vector.h"
#include <iostream>
#include <istream>
#include <ostream>


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


int Vector::getSize() const{ return m_size; }


void Vector::setSize(int newSize){
  if (newSize==0){
    delete[] m_elements;
    m_elements = nullptr;
    m_size = newSize;
    return;
  }

  if (newSize==m_size){
    return;
  }

  double* new_elements = new double[newSize];
  for(int i = 0; i < newSize && i < m_size; i++){
    new_elements[i] = m_elements[i];
  }

  delete[] m_elements;
  m_elements = new_elements;
  m_size = newSize;
}


double& Vector::operator[](int index){
  return m_elements[index];
}


Vector::Vector(const Vector& other) : m_size(other.m_size){
  if(m_size > 0){
    m_elements = new double[m_size];
    for(int i = 0; i < m_size; i++){
      m_elements[i] = other.m_elements[i];
    }
  }else{
    m_elements = nullptr;
  }
}


Vector& Vector::operator=(const Vector& other){
  if(this == &other) return *this;

  delete[] m_elements;
  m_size = other.m_size;

  if(m_size > 0){
    m_elements = new double[m_size];
    for(int i = 0; i < m_size; i++){
      m_elements[i] = other.m_elements[i];
    }
  }else{
    m_elements = nullptr;
  }
  return *this;
}


double& Vector::at(int index){
  if(index >= m_size){
    std::cout << "Ungültiger bereich!" << std::endl;
    return m_elements[0];
  }
  return m_elements[index];
}


bool Vector::operator == (const Vector& other){
  if(m_size != other.m_size) return false;
  for(int i = 0; i < m_size; i++){
    if(m_elements[i] != other.m_elements[i]) return false;
  }  
  return true;
}


std::ostream &operator << (std::ostream &output, const Vector &o){
  output << "[";
  for(int i = 0; i < o.m_size; i++){
    output << o.m_elements[i];
    if(i < o.m_size - 1){
      output << ", ";
    }
  }
  output << "]";
  return output;
}


std::istream &operator >> (std::istream &input, Vector &i){
  for(int h = 0; h < i.m_size; h++){
    input >> i.m_elements[h];
  }
  return input;
}


void Vector::push_back(double user_input){
  setSize(m_size + 1);
  m_elements[m_size -1] = user_input;
}


Vector Vector::operator+(const Vector& other ) const {
  if (m_size != other.m_size){
    std::cout << "Vektoren müssen gleich groß sein" << std::endl;
    return Vector();
  }
  Vector result(m_size);
  for(int i = 0; i < m_size; i++){
    result.m_elements[i] = this->m_elements[i] + other.m_elements[i];
  }
  return result;
}


Vector Vector::operator-(const Vector& other) const {
  if(m_size != other.m_size){
    std::cout << "Vektoren müssen gleich groß sein" << std::endl;
    return Vector();
  }
  Vector result(m_size);
  for(int i=0; i < m_size; i++){
    result.m_elements[i] = this->m_elements[i] - other.m_elements[i];
  }
  return result;
}


Vector Vector::operator*(const Vector& other) const {
  if(m_size != other.m_size){
    std::cout << "Vektoren müssen gleich groß sein" << std::endl;
    return Vector();
  }
  Vector result(m_size);
  for(int i = 0; i < m_size; i++){
    result.m_elements[i] = this->m_elements[i] * other.m_elements[i];
  }
  return result;
}


Vector& Vector::operator+=(const Vector& other){
  if (m_size != other.m_size){
    std::cout << "Vektoren müssen gleich groß sein" << std::endl;
    return *this;
  }
  for(int i = 0; i < m_size; i++){
    this->m_elements[i] += other.m_elements[i];
  }
  return *this;
}


Vector& Vector::operator-=(const Vector& other){
  if (m_size != other.m_size){
    std::cout << "Vektoren müssen gleich groß sein" << std::endl;
    return *this;
  }
  for(int i = 0; i < m_size; i++){
    this->m_elements[i] -= other.m_elements[i];
  }
  return *this;
}


Vector& Vector::operator*=(const Vector& other){
  if (m_size != other.m_size){
    std::cout << "Vektoren müssen gleich groß sein" << std::endl;
    return *this;
  }
  for(int i = 0; i < m_size; i++){
    this->m_elements[i] *= other.m_elements[i];
  }
  return *this;
}


Vector& Vector::operator+=(double value){
  for(int i = 0; i < m_size; i++){
    m_elements[i] += value;
  }
    return *this;
}


Vector& Vector::operator-=(double value){
  for(int i = 0; i < m_size; i++){
    m_elements[i] -= value;
  }
    return *this;
}


Vector& Vector::operator*=(double value){
  for(int i = 0; i < m_size; i++){
    m_elements[i] *= value;
  }
    return *this;
}


Vector Vector::operator+(double value) const {
  Vector result = *this;
  result += value;
  return result;
}


Vector Vector::operator-(double value) const {
  Vector result = *this;
  result -= value;
  return result;
}


Vector Vector::operator*(double value) const {
  Vector result = *this;
  result *= value;
  return result;
}























