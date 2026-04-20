#pragma once
#include <iostream>
#include <string>


class GameCharacter {

  private:
  std::string m_name;
  int m_health;
  GameCharacter* m_buddy;

  public:
  GameCharacter(std::string m_name, int m_health, GameCharacter* m_buddy = nullptr)
  : m_name(m_name), m_health(m_health), m_buddy(m_buddy)
  { 
  }

  ~GameCharacter(){
    std::cout << "Destroy: " << m_name << std::endl;
    if (m_buddy != nullptr){
      std::cout << "Free buddy: " << m_buddy->m_name << std::endl;
      delete m_buddy;
      m_buddy = nullptr;
    }
  }

};
