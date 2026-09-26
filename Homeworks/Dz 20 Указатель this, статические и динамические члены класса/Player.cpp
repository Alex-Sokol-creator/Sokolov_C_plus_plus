#include "Player.h"
#include <iostream>
#include <Windows.h>


int Player::amount_of_players = 0;

Player::Player() : Player("Unknown", 100, 1) {}

Player::Player(const char* nickname, int health, int level) : nickname(nullptr), health(health), level(level) {
	SetNickname(nickname);
	amount_of_players++;
}

Player::~Player() {
	if (nickname != nullptr) {
		delete[] nickname;
		amount_of_players--;
	}
}

void Player::SetNickname(const char* nickname) {
	if (this->nickname != nullptr) {
		delete[] this->nickname;
	}
	int nicknameSize = strlen(nickname) + 1;
	this->nickname = new char[nicknameSize];
	strcpy_s(this->nickname, nicknameSize, nickname);
}

void Player::SetHealth(int health) {
	if (health <= 0) {
		this->health = 0;
	}
	else if (health >= 100) {
		this->health = 100;
	}
	else {
		this->health = health;
	}
}

const char* Player::GetNickname() const{
	return nickname;
}

int Player::GetHealth() const{
	return health;
}

int Player::GetLevel() const{
	return level;
}

int Player::GetAmountOfPlayers() {
	return amount_of_players;
}

void Player::takeDamage(int damage) {
	int newHealth = this->health - damage;
	SetHealth(newHealth);
}

void Player::heal(int amount) {
	int newHealth = this->health + amount;
	SetHealth(newHealth);
}

void Player::levelUp() {
	this->level++;
}

void Player::printStats() const{
	std::cout << "Никнейм игрока: " << nickname << "\nЗдоровье: " << health << "\nУровень: " << level << '\n';
}