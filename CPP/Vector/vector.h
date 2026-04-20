#pragma once
#include <iostream>
#include <istream>
#include <ostream>

class Vector{
  
		private:	

		double* m_elements;
		int m_size;


		public:

		Vector();
		Vector(int newSize);
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
		~Vector();

		void setSize(int newSize);
		int getSize() const;	

    double& operator[](int index);

    double& at(int index);

    bool operator == (const Vector& other);

    friend std::ostream &operator << (std::ostream &output,const Vector &o);
    friend std::istream &operator >> (std::istream &input,Vector &i);

    void push_back(double user_input);

    Vector operator + (const Vector& other) const;
    Vector operator - (const Vector& other) const;
    Vector operator * (const Vector& other) const;

    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);
    Vector& operator*=(const Vector& other);

    Vector& operator+=(double value);
    Vector& operator-=(double value);
    Vector& operator*=(double value);

    Vector operator+(double value) const;
    Vector operator-(double value) const;
    Vector operator*(double value) const;
  
};





