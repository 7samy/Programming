#pragma once
#include <iostream>

class Vector{

		private:	

		double* m_elements;
		int m_size;


		public:

		Vector();
		Vector(int newSize);
		~Vector();

		void setSize(int newSize);
		int getSize() const;
		
};


