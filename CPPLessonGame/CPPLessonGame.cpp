// CPPLessonGame.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

class Persons {
protected: 
    int _hp;
    int _attack;
    int _armor;
    int _speed;
    int _currenthp;
    string _name = "";
    //Inventory _inventory;
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
class Inventory {
public:
    Inventory() {}
};

class Item {
   /* Двуручная ёлка, пирожки с вишней, санки, шапка-ушанка*/
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
        return cout << "Игрок: " << player._name << "\n HP:" << player._currenthp << "/" << player._hp << "\n Level:"
            << player._level << "\n Exp:" << player._exp << "\n Attack:" << player._attack << "\n Armor:" 
            << player._armor << "\n Speed:" << player._speed << endl;
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
    Player player("Warrior", "Ilya");
    cout << player;



    return 0;
}