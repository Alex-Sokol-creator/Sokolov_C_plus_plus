#pragma once

class Player {
private:
	char* nickname;
	int health;
	int level;
	static int amount_of_players;
public:
	Player();
	Player(const char* nickname, int health, int level);
	~Player();

	void SetNickname(const char* nickname);
	void SetHealth(int health);

	const char* GetNickname() const;
	int GetHealth() const;
	int GetLevel() const;

	static int GetAmountOfPlayers();

	void takeDamage(int damage);
	void heal(int amount);
	void levelUp();
	void printStats() const;
};