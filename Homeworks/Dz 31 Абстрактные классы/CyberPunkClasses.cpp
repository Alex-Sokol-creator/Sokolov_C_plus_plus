#include "CyberPunkClasses.h"
#include <iostream>

bool VendingMachine::isHacked() const {
	return hacked;
}

void VendingMachine::applyHack(int techLevel) {
	if (techLevel >= 2) {
		std::cout << "Автомат с газировкой был хакнут, напитки выпадают из него!\n";
		hacked = true;
	}
	else {
		std::cout << "Так как уровень взлома ниже 2, хакера ударило током\n";
	}
}

bool SmartDoor::isHacked() const {
	return hacked;
}

void SmartDoor::applyHack(int techLevel) {
	if (techLevel >= 5) {
		std::cout << "Двери были открыты\n";
		hacked = true;
	}
	else {
		std::cout << "Так как уровень взлома ниже 5, дверь не была открыта\n";
	}
}

bool CyborgGuard::isHacked() const {
	return hacked;
}

void CyborgGuard::applyHack(int techLevel) {
	if (health == 0) {
		std::cout << "Киборг был уничтожен, невозможен взлом\n";
		return;
	}
	if (techLevel >= 7) {
		std::cout << "Киборг переводится в режим заморозки\n";
		hacked = true;
	}
	else {
		health -= 20;
		if (health <= 0) {
			std::cout << "Киборг был уничтожен\n";
			health = 0;
		}
		else {
			std::cout << "Так как уровень взлома ниже 7, киборгу было нанесено 20 единиц урона\n";
		}
	}
}

void CyborgGuard::Attack(int amount, Netrunner& player) {
	std::cout << "Киборг атакует хакера!\n";
	player.TakeDamage(amount);
}

bool AutoTurret::isHacked() const {
	return hacked;
}

void AutoTurret::applyHack(int techLevel) {
	if (techLevel >= 4) {
		std::cout << "Турель была взломана, и изменила свою цель на других врагов\n";
		hacked = true;
	}
	else {
		std::cout << "Так как уровень взлома ниже 4, цель турели по прежнему хакер\n";
	}
}

void AutoTurret::Attack(int amount, Netrunner& player) {
	std::cout << "Турель стреляет по хакеру!\n";
	player.TakeDamage(amount);
}

void Netrunner::breachProtocol(IHackable& target) {
	std::cout << "Хакер приступает к взлому объекта...\n";
	target.applyHack(this->skillLevel);
}

int Netrunner::GetHealth() const {
	return health;
}

void Netrunner::TakeDamage(int amount) {
	health -= amount;
	if (health < 0) {
		health = 0;
	}
}

VendingMachine::VendingMachine() : hacked(false) {}

SmartDoor::SmartDoor() : hacked(false) {}

Netrunner::Netrunner(int skillLevel, int health) : skillLevel(skillLevel), health(health) {}

CyberEnemy::CyberEnemy(int health) : health(health) {}

CyborgGuard::CyborgGuard(int health) : CyberEnemy(health), hacked(false) {}