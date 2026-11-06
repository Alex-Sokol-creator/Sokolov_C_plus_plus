#pragma once

class IHackable {
public:
	virtual void applyHack(int techLevel) = 0;
	virtual bool isHacked() const = 0;

	virtual ~IHackable() = default;
};

class VendingMachine : public IHackable{
private:
	bool hacked = false;
public:
	VendingMachine();
	void applyHack(int techLevel) override;
	bool isHacked() const override;
};

class SmartDoor : public IHackable{
private:
	bool hacked = false;
public:
	SmartDoor();
	void applyHack(int techLevel) override;
	bool isHacked() const override;
};

class Netrunner {
private:
	int skillLevel;
	int health;
public:
	Netrunner(int skillLevel, int health);
	void breachProtocol(IHackable& target);

	int GetHealth() const;
	void TakeDamage(int amount);
};

class CyberEnemy {
protected:
	int health;
public:
	CyberEnemy(int health);	
	virtual void Attack(int amount, Netrunner& player) = 0;
};

class CyborgGuard : public CyberEnemy, public IHackable {
private:
	bool hacked = false;
public:
	CyborgGuard(int health);
	void applyHack(int techLevel) override;
	bool isHacked() const override;
	void Attack(int amount, Netrunner& player) override;
};

class AutoTurret : public CyberEnemy, public IHackable {
private:
	bool hacked = false;
public:
	AutoTurret(int health);
	void applyHack(int techLevel) override;
	bool isHacked() const override;
	void Attack(int amount, Netrunner& player) override;
};

