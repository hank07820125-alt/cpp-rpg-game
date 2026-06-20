#include <iostream>
#include <string>

using namespace std;

class Skill
{
private:
    string name;
    int damage;
    int mpCost;

public:
    Skill(string n, int d, int m)
    {
        name = n;
        damage = d;
        mpCost = m;
    }

    void use()
    {
        cout << name << " used!" << endl;
    }

    void showInfo()
    {
        cout << "Skill: " << name << endl;
        cout << "Damage: " << damage << endl;
        cout << "MP Cost: " << mpCost << endl;
    }

    int getDamage()
    {
        return damage;
    }

    int getMpCost()
    {
        return mpCost;
    }
};

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
        else
        {
            cout << "No item left." << endl;
        }
    }

    void showInfo()
    {
        cout << "Item: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Effect: " << effectValue << endl;
        cout << "Quantity: " << quantity << endl;
    }

    bool isAvailable()
    {
        return quantity > 0;
    }

    int getEffectValue()
    {
        return effectValue;
    }
};

class Monster;

class Player
{
private:
    string name;
    int hp;
    int mp;
    int attackPower;
    Item potion;

public:
    Player(string n)
        : potion("Potion", "Heal", 30, 2)
    {
        name = n;
        hp = 100;
        mp = 30;
        attackPower = 15;
    }

    int attack()
    {
        cout << name << " attacks!" << endl;
        return attackPower;
    }

    void takeDamage(int damage)
    {
        hp -= damage;

        if(hp < 0)
        {
            hp = 0;
        }
    }

    void useItem()
    {
        if(potion.isAvailable())
        {
            potion.use();
            hp += potion.getEffectValue();

            if(hp > 100)
            {
                hp = 100;
            }

            cout << "HP recovered." << endl;
        }
        else
        {
            cout << "Potion is empty." << endl;
        }
    }

    bool isAlive()
    {
        return hp > 0;
    }

    int getHP()
    {
        return hp;
    }

    int getMP()
    {
        return mp;
    }

    void useMP(int cost)
    {
        mp -= cost;

        if(mp < 0)
        {
            mp = 0;
        }
    }

    void showStatus()
    {
        cout << name << " HP: " << hp
             << " MP: " << mp << endl;
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

    int attack()
    {
        cout << name << " attacks!" << endl;
        return attackPower;
    }

    void takeDamage(int damage)
    {
        hp -= damage;

        if(hp < 0)
        {
            hp = 0;
        }
    }

    bool isAlive()
    {
        return hp > 0;
    }

    void showInfo()
    {
        cout << "Monster: " << name
             << " HP: " << hp << endl;
    }

    int getRewardGold()
    {
        return rewardGold;
    }
};

int main()
{
    cout << "===== Simple RPG Game =====" << endl;

    string playerName;

    cout << "Enter your name: ";
    cin >> playerName;

    Player player(playerName);
    Monster monster("Slime", 80, 10, 20);
    Skill fireball("Fireball", 25, 10);

    cout << "\nA Slime appears!" << endl;

    while(player.isAlive() && monster.isAlive())
    {
        cout << "\n===== Status =====" << endl;
        player.showStatus();
        monster.showInfo();

        cout << "\nChoose action:" << endl;
        cout << "1. Normal Attack" << endl;
        cout << "2. Use Skill" << endl;
        cout << "3. Use Item" << endl;
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if(choice == 1)
        {
            int damage = player.attack();
            monster.takeDamage(damage);
        }
        else if(choice == 2)
        {
            if(player.getMP() >= fireball.getMpCost())
            {
                fireball.use();
                monster.takeDamage(fireball.getDamage());
                player.useMP(fireball.getMpCost());
            }
            else
            {
                cout << "Not enough MP." << endl;
            }
        }
        else if(choice == 3)
        {
            player.useItem();
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

        if(monster.isAlive())
        {
            int damage = monster.attack();
            player.takeDamage(damage);
        }
    }

    if(player.isAlive())
    {
        cout << "\nYou win!" << endl;
        cout << "Reward gold: "
             << monster.getRewardGold()
             << endl;
    }
    else
    {
        cout << "\nGame over!" << endl;
    }

    return 0;
}
