#include <iostream>
#include <string>
#include <vector>

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
        cout << name << " Damage: " << damage
             << " MP Cost: " << mpCost << endl;
    }

    int getDamage()
    {
        return damage;
    }

    int getMpCost()
    {
        return mpCost;
    }

    string getName()
    {
        return name;
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
        cout << name << " Type: " << type
             << " Effect: " << effectValue
             << " Quantity: " << quantity << endl;
    }

    bool isAvailable()
    {
        return quantity > 0;
    }

    string getType()
    {
        return type;
    }

    int getEffectValue()
    {
        return effectValue;
    }
};

class Player
{
private:
    string name;
    int hp;
    int mp;
    int attackPower;
    vector<Item> items;

public:
    Player(string n)
    {
        name = n;
        hp = 100;
        mp = 40;
        attackPower = 15;

        items.push_back(Item("Potion", "HP", 30, 2));
        items.push_back(Item("Mana Potion", "MP", 20, 1));
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
        cout << "\nItems:" << endl;

        for(int i = 0; i < items.size(); i++)
        {
            cout << i + 1 << ". ";
            items[i].showInfo();
        }

        cout << "Choose item: ";

        int choice;
        cin >> choice;

        if(choice < 1 || choice > items.size())
        {
            cout << "Invalid item." << endl;
            return;
        }

        if(items[choice - 1].isAvailable() == false)
        {
            cout << "This item is not available." << endl;
            return;
        }

        if(items[choice - 1].getType() == "HP")
        {
            hp += items[choice - 1].getEffectValue();

            if(hp > 100)
            {
                hp = 100;
            }

            items[choice - 1].use();
            cout << "HP recovered." << endl;
        }
        else if(items[choice - 1].getType() == "MP")
        {
            mp += items[choice - 1].getEffectValue();

            if(mp > 40)
            {
                mp = 40;
            }

            items[choice - 1].use();
            cout << "MP recovered." << endl;
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
             << " HP: " << hp
             << " Attack: " << attackPower << endl;
    }

    int getRewardGold()
    {
        return rewardGold;
    }

    string getName()
    {
        return name;
    }
};

int main()
{
    cout << "===== Simple RPG Game =====" << endl;

    string playerName;

    cout << "Enter your name: ";
    cin >> playerName;

    Player player(playerName);

    Skill fireball("Fireball", 25, 10);
    Skill heavyStrike("Heavy Strike", 35, 15);

    Monster slime("Slime", 70, 10, 20);
    Monster goblin("Goblin", 90, 15, 30);

    vector<Monster> monsters;
    monsters.push_back(slime);
    monsters.push_back(goblin);

    int gold = 0;

    for(int i = 0; i < monsters.size(); i++)
    {
        cout << "\nA " << monsters[i].getName()
             << " appears!" << endl;

        while(player.isAlive() && monsters[i].isAlive())
        {
            cout << "\n===== Status =====" << endl;
            player.showStatus();
            monsters[i].showInfo();

            cout << "\nChoose action:" << endl;
            cout << "1. Normal Attack" << endl;
            cout << "2. Fireball" << endl;
            cout << "3. Heavy Strike" << endl;
            cout << "4. Use Item" << endl;
            cout << "Enter choice: ";

            int choice;
            cin >> choice;

            if(choice == 1)
            {
                int damage = player.attack();
                monsters[i].takeDamage(damage);
            }
            else if(choice == 2)
            {
                if(player.getMP() >= fireball.getMpCost())
                {
                    fireball.use();
                    monsters[i].takeDamage(fireball.getDamage());
                    player.useMP(fireball.getMpCost());
                }
                else
                {
                    cout << "Not enough MP." << endl;
                }
            }
            else if(choice == 3)
            {
                if(player.getMP() >= heavyStrike.getMpCost())
                {
                    heavyStrike.use();
                    monsters[i].takeDamage(heavyStrike.getDamage());
                    player.useMP(heavyStrike.getMpCost());
                }
                else
                {
                    cout << "Not enough MP." << endl;
                }
            }
            else if(choice == 4)
            {
                player.useItem();
            }
            else
            {
                cout << "Invalid choice." << endl;
            }

            if(monsters[i].isAlive())
            {
                int damage = monsters[i].attack();
                player.takeDamage(damage);
            }
        }

        if(player.isAlive())
        {
            cout << "\nYou defeated "
                 << monsters[i].getName()
                 << "!" << endl;

            gold += monsters[i].getRewardGold();

            cout << "Gold +"
                 << monsters[i].getRewardGold()
                 << endl;
        }
        else
        {
            cout << "\nGame over!" << endl;
            return 0;
        }
    }

    cout << "\nYou win!" << endl;
    cout << "Total gold: " << gold << endl;

    return 0;
}
    }

    return 0;
}
