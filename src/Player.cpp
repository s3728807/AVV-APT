#include "../headers/Player.h"

using namespace Azul;

Player::Player()
{
  name = "";
  points = 0;
  floor = new Floor();
  mosaic = new Mosaic();
  turn = false;
}

Player::~Player()
{
  delete floor;
  delete mosaic;
}

void Player::addPoints(int p)
{
  points = points + p;
}

void Player::subtractPoints(int p)
{
  points = points - p;
}

void Player::setFloor(Floor *f)
{
  floor = f;
}

void Player::setFirstDump(bool b)
{
  firstDump = b;
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

void Player::setTurn(bool t)
{
  turn = t;
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

bool Player::isTurn()
{
  return turn;
}

bool Player::tookFirstDump()
{
  return firstDump;
}