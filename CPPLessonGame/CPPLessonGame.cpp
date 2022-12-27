// CPPLessonGame.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;
class Item {
private:
    int _id;
    string _name;
    int _attack;
    int _armor;
    int _restoreHP;
    int _increaseSpeed;
    string _destination;
public:
    Item()
    {
        _id = 0;
        _name = "";
        _attack = 0;
        _armor = 0;
        _restoreHP = 0;
        _increaseSpeed = 0;
        _destination = "";
    }
    Item(int id, string name, int attack, int armor, int restoreHP, int increaseSpeed, string destination)
    {
        _id = id;
        _name = name;
        _attack = attack;
        _armor = armor;
        _restoreHP = restoreHP;
        _increaseSpeed = increaseSpeed;
        _destination = destination;
    }
    string getDesination()
    {
        return _destination;
    }
    friend ostream& operator<<(ostream& out, Item item)
    {
        if (item._id > 0)
        { 
            string ItemOut = item._name + "\n Тип предмета: " + item._destination;
            if (item._attack > 0)
            {
                ItemOut += "\n Атака:" + to_string(item._attack);
            }
            if (item._armor > 0)
            {
                ItemOut += "\n  Броня: " + to_string(item.GetArmor());
            }
            if (item._restoreHP > 0)
            {
                ItemOut += "\n Восстановление здоровья:" + to_string(item._restoreHP);
            }
            if (item._increaseSpeed > 0)
            {
                ItemOut += "\n Увеличение скорости:" + to_string(item._increaseSpeed);
            }
            out << ItemOut << endl;
            return out;
        }
        return out;
    }

    int GetArmor()
    {
        if (getDesination() == "armor")
            return _armor;
    }
};
class Inventory {
private:
    Item _weapon;
    Item _armor;
    Item _healing;
    Item _speed;
public:
    Inventory() {}

    void setWeaponItem(Item item)
    {
        if (item.getDesination() == "weapon")
            _weapon = item;
    }
    void setArmorItem(Item item)
    {
        if (item.getDesination() == "armor")
            _armor = item;
    }
    int getArmorItem()
    {
        return _armor.GetArmor();
    }
    void setHealingItem(Item item)
    {
        if (item.getDesination() == "heal")
            _healing = item;
    }
    void setSpeedItem(Item item)
    {
        if (item.getDesination() == "maunt")
            _speed = item;
    }

    friend ostream& operator<<(ostream& out, Inventory inv)
    {
        return out << "\n Содержимое инвентаря: \n " << inv._weapon << inv._armor << inv._healing << inv._speed << endl;

    }
};
class Persons {
protected: 
    int _hp;
    int _attack;
    int _armor;
    int _speed;
    int _currenthp;
    string _name = "";
    Inventory _inventory;
public: 
    Persons(int hp = 0, int attack = 0, int armor = 0, int speed = 0)
    {
        _hp = hp;
        _attack = attack;
        _armor = armor;
        _speed = speed;
        _currenthp = hp;
    }
    void SetHP(int hp) {
        _currenthp += hp;
        if (_currenthp > _hp)
            _currenthp = _hp;
    }
    int GetHP()
    {
        return _currenthp;
    }
    void SetAttack(int attack) {
        _attack = attack;
    }
    int GetAttack()
    {
        return _attack;
    }
    void SetArmor(int armor) {
        _armor = armor;
    }
    int GetArmor()
    {
        return _armor;
    }
    void SetSpeed(int speed) {
        _speed = speed;
    }
    int GetSpeed()
    {
        return _speed;
    }
};
class TextAction {

};
class Game {

};



class Dialog : TextAction {

};
class Action : TextAction {

};
class Command : TextAction {

};
class Player : Persons {
private:
    int _level = 1;
    int _exp = 0;
    string _type = "";
public:
    Player(string type, string name)  
    {        
        _name = name;
        _type = type;
        if (_type == "Warrior")
        {
            _attack = 5;
            _armor = 10;
            _speed = 50;
            _hp = 50;
            _currenthp = _hp;
        }                  
        if (_type == "Rogue")
        {
            _attack = 8;
            _armor = 7;
            _speed = 100;
            _hp = 30;
            _currenthp = _hp;
        }                   
    }
    int GetLevel()
    {
        return _level;
    }
    void SetExp(int exp) {
        _exp += exp;
        if (_exp > _level * 1000)
        {
            _exp = _exp - _level * 1000;
            _level++;
            _attack++;
            _armor++;
            _speed += 5;
            _currenthp += 5;
            _hp += 5;
        }
    }
    int GetExp()
    {
        return _exp;
    }
    string GetType()
    {
        return _type;
    }
    friend ostream& operator<<(ostream& out, Player& player) 
    {
        out << "Игрок: " << player._name;
        out << "\n HP:" << player._currenthp << "/" << player._hp;
        out << "\n Level:" << player._level;
        out << "\n Exp:" << player._exp;
        out << "\n Attack:" << player._attack;
        out << "\n Armor:" << player._armor;
        if (player._inventory.getArmorItem() > 0)
        {
            out << "(" + to_string(player._inventory.getArmorItem() + player._armor) + ")";

        }
        out << "\n Speed:" << player._speed;
        out << player._inventory << endl;
        return out;
    }

    void WearArmor(Item item) 
    {
        _inventory.setArmorItem(item);
    }
};
class Enemy : Persons {
private:
    int _giveExp;
public:
    Enemy() 
    {

    }
    /* Дед мороз, эльфы */
};
int main()
{
    setlocale(LC_ALL, "Russian");

    Item twoHandedSpruce(1, "Двуручная ель", 4, 0, 0, -15, "weapon");
    Item cherryPie(2, "Пирожок с вишней", 0, 0, 5, 0, "heal");
    Item sled(3, "Санки", 0, 0, 0, +10, "maunt");
    Item USSRHat(4, "Шапка-ушанка", 0, 3, 0, 0, "armor");
    Player player("Warrior", "Ilya");
    player.WearArmor(USSRHat);
    cout << player;


    return 0;
}