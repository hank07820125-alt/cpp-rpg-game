#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    string name;
    int hp;
    int attackPower;

public:
    Player(string n, int h, int atk)
    {
        name = n;
        hp = h;
        attackPower = atk;
    }

    void attack()
    {
        cout << name << " attacks!" << endl;
    }

    void takeDamage(int damage)
    {
        hp -= damage;
    }

    bool isAlive()
    {
        return hp > 0;
    }
};

class Monster
{
private:
    string name;
    int hp;
    int attackPower;
    int rewardGold;

public:
    Monster(string n, int h, int atk, int gold)
    {
        name = n;
        hp = h;
        attackPower = atk;
        rewardGold = gold;
    }

    void attack()
    {
        cout << name << " attacks!" << endl;
    }

    void takeDamage(int damage)
    {
        hp -= damage;
    }

    bool isAlive()
    {
        return hp > 0;
    }

    void showInfo()
    {
        cout << "Monster: " << name << endl;
    }
};

int main()
{
    cout << "===== Dungeon Hero =====" << endl;

    Player player("Hero",100,20);
    Monster monster("Slime",50,10,20);

    monster.showInfo();

    return 0;
}
