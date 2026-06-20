#include <iostream>
#include <string>

using namespace std;

class Item
{
private:
    string name;
    string type;
    int effectValue;
    int quantity;

public:
    Item(string n, string t, int e, int q)
    {
        name = n;
        type = t;
        effectValue = e;
        quantity = q;
    }

    void use()
    {
        if(quantity > 0)
        {
            quantity--;
            cout << name << " used!" << endl;
        }
    }

    void showInfo()
    {
        cout << "Item: " << name
             << " Quantity: "
             << quantity << endl;
    }

    bool isAvailable()
    {
        return quantity > 0;
    }
};

class Skill
{
private:
    string name;
    int damage;
    int mpCost;

public:
    Skill(string n, int d, int mp)
    {
        name = n;
        damage = d;
        mpCost = mp;
    }

    void use()
    {
        cout << name << " used!" << endl;
    }

    void showInfo()
    {
        cout << "Skill: " << name
             << " Damage: " << damage
             << " MP Cost: " << mpCost
             << endl;
    }

    int getDamage()
    {
        return damage;
    }
};

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

    Skill fireball("Fireball",30,10);
    Item potion("Potion","Heal",50,3);

    monster.showInfo();
    fireball.showInfo();
    potion.showInfo();

    return 0;
}
