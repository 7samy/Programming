#pragma once
#include <iostream>
#include <string>	
#include <cstdint>

class car {
		
		private:
				std::string m_brand;
				std::string m_model;
				uint16_t m_year;
				double m_km;
		
	
		public:
		
		car(std::string b, std::string m, uint16_t y, double k){
				
				m_brand = b;
				m_model = m;
			   	m_year = y;
			   	m_km = k; 					
				std::cout << "Brand: " << m_brand << "\nModel: " << m_model << "\nJahr: " << m_year << "\nKilometer: " << m_km << std::endl;
		}

		~car(){
				std::cout << "Destruktor wurde aufgerufen!" << std::endl;
		}

		void setBrand(std::string b){ m_brand = b;}
		void setModel(std::string m){ m_model = m;}
		void setKilometer(double k){ m_km = k;}
		void setYear(uint16_t y){
				if(y>=1886 && y<=2026){
						m_year = y;
				}
				else{
						std::cout << "Ungültiges Datum!" << std::endl;
				}
		}

		std::string getBrand() const { return m_brand;}
		std::string getModel() const { return m_model;}
		uint16_t getYear() const { return m_year;}
		double getKilometer() const { return m_km;}

		void drive(double kilometers){
				if(kilometers<0)
				{
						std::cout << "Ungültiger Zahlenbereich!" << std::endl;
				}
				else{
						double neuerStand = getKilometer() + kilometers;
						setKilometer(neuerStand);
				}
		}

		void displayInfo(){
				std::cout << "Brand: " << getBrand() << "\nModel: " << getModel() << "\nJahr: " << getYear() << "\nKilometer: " << getKilometer() << std::endl;
		}
};

