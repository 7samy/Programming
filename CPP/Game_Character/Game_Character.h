#pragma once
#include <iostream>
#include <string>


class GameCharacter {

  private:
  std::string m_name;
  int m_health;
  GameCharacter* m_buddy;

  public:
  GameCharacter(std::string m_name, int m_health, GameCharacter* m_buddy = nullptr);
  ~GameCharacter();
  void takeDamage(int amount);

};
