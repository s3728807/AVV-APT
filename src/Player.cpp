#include "../headers/Player.h"

using namespace Azul;

Player::Player()
{}

Player::~Player()
{}

void Player::setFloor(Floor *f)
{
  floor = f;
}

void Player::setMosaic(Mosaic *m)
{
  mosaic = m;
}

void Player::setName(std::string n)
{
  name = n;
}

void Player::setPoints(int p)
{
  points = p;
}

Floor *Player::getFloor()
{
  return floor;
}

Mosaic *Player::getMosaic()
{
  return mosaic;
}

std::string Player::getName()
{
  return name;
}

int Player::getPoints()
{
  return points;
}