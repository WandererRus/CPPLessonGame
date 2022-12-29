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
    int GetSpeed()
    {
        if (getDesination() == "maunt")
            return _increaseSpeed;
    }
    int GetWeapon()
    {
        if (getDesination() == "weapon")
            return _attack;
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
    int getWeaponItem()
    {
        return _weapon.GetWeapon();
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
    int getSpeedItem()
    {
        return _speed.GetSpeed();
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

class Dialog  {
    private: 
        int _location = 0;
        int _sequencing = 0;
        string _txt;
    public :
        Dialog(string txt)
        {
            /*_location = location;
            _sequencing = sequencing;*/
            _txt = txt;
        }
        void print()
        {
            cout << _txt << endl;
        }
};

class Command {

};
class Player : Persons {
private:
    int _level = 1;
    int _exp = 0;
    string _type = "";
    int _countFlush = 0;
public:
    Player() {}
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
    int GetAttack()
    {
        return _attack;
    }
    int GetArmor()
    {
        return _armor;
    }
    int GetSpeed()
    {
        return _speed;
    }
    void IncreaseCountFlush()
    {
        _countFlush++;
    }
    int GetCountFlush()
    {
        return _countFlush;
    }
    void ResetCountFlush()
    {
        _countFlush = 0;
    }
    void SetHP(int hp)
    {
        if (hp <= 0)
        {
            cout << "\nВам нанесли " + to_string(hp * -1) + "единиц урона"<< endl;            
        }
        if (hp > 0)
        {
            cout << "\nВы вылечили " + to_string(hp) + "единиц жизни" << endl;
        }
        cout << "\nВаше здоровье " + to_string(_currenthp) + "/" + to_string(_hp) << endl;
        _currenthp += hp;
    }
    int GetCurrentHP()
    {
        return _currenthp;
    }
    friend ostream& operator<<(ostream& out, Player& player) 
    {
        out << "Игрок: " << player._name;
        out << "\n HP:" << player._currenthp << "/" << player._hp;
        out << "\n Level:" << player._level;
        out << "\n Exp:" << player._exp;
        out << "\n Attack:" << player._attack;
        if (player._inventory.getWeaponItem() > 0)
        {
            out << "(" + to_string(player._inventory.getWeaponItem() + player._attack) + ")";

        }
        out << "\n Armor:" << player._armor;
        if (player._inventory.getArmorItem() > 0)
        {
            out << "(" + to_string(player._inventory.getArmorItem() + player._armor) + ")";

        }
        out << "\n Speed:" << player._speed;
        if (player._inventory.getSpeedItem() > 0)
        {
            out << "(" + to_string(player._inventory.getSpeedItem() + player._speed) + ")";

        }
        out << player._inventory << endl;
        return out;
    }

    void WearArmor(Item item) 
    {
        _inventory.setArmorItem(item);
    }
    void WearWeapon(Item item)
    {
        _inventory.setWeaponItem(item);
    }
    void HealOnBelt(Item item)
    {
        _inventory.setHealingItem(item);
    }
    void WearSpeed(Item item)
    {
        _inventory.setSpeedItem(item);
    }

};
class Enemy : Persons {
private:
    int _giveExp = 0;
public:
    Enemy() {}
    Enemy(int giveExp) 
    {
        _giveExp = giveExp;
    }
    Enemy(int hp, int attack, int armor, int speed, int giveExp, string name)
    {
        _giveExp = giveExp;
        _hp = hp;
        _attack = attack;
        _armor = armor;
        _speed = speed;
        _currenthp = hp;
        _name = name;
    }
    int GetAttack()
    {
        return _attack;
    }
    int GetArmor()
    {
        return _armor;
    }
    int GetSpeed() 
    {
        return _speed;
    }
    int GetEXP()
    {
        return _giveExp;
    }
    int GetCurrentHP()
    {
        return _currenthp;
    }
    void SetHP(int hp)
    {
        if (hp <= 0)
        {
            cout << "\nВы нанесли " + to_string(hp * -1) + "единиц урона" + _name << endl;
        }
        if (hp > 0)
        {
            cout << "\nВраг вылечил " + to_string(hp) + "единиц жизни" << endl;
        }
        cout << "\nЗдоровье врага " + to_string(_currenthp) + "/" + to_string(_hp) << endl;
        _currenthp += hp;
    }
    /* Дед мороз, эльфы */
};
class Action {
private:
    Player _player;
    Enemy _enemy;
public:
    Action(Player& player, Enemy& enemy) 
    {
        _player = player;
        _enemy = enemy;
    }
    void BattleAction() 
    {
        int turn = 0;
        if (_player.GetSpeed() < _enemy.GetSpeed())
        {
            turn = 1;
        }
        string turntxt = turn ? "враг" : "игрок";
        cout << "Первым ходит " + turntxt;
        while (_player.GetCurrentHP() >= 0 && _enemy.GetCurrentHP() >= 0)
        {
            double damage = 1;
            if (turn)
            {
                if (_player.GetArmor() > _enemy.GetAttack())
                {
                    damage = _enemy.GetAttack() * 0.5;
                }
                if (_player.GetArmor() == _enemy.GetAttack())
                {
                    damage = _enemy.GetAttack() * 0.75;
                }
                if (_player.GetArmor() < _enemy.GetAttack())
                {
                    damage = _enemy.GetAttack();
                }
                _player.SetHP(0 - damage);
                turn = 0;
            }
            else
            {
                if (_enemy.GetArmor() > _player.GetAttack())
                {
                    damage = _player.GetAttack() * 0.5;
                }
                if (_enemy.GetArmor() == _player.GetAttack())
                {
                    damage = _player.GetAttack() * 0.75;
                }
                if (_enemy.GetArmor() < _player.GetAttack())
                {
                    damage = _player.GetAttack();
                }
                _enemy.SetHP(0 - damage);
                turn = 0;
                ++turn;
            }
        }
    }
    bool FlushAction() 
    {
        double playerLuck = rand() % 12 + 8;
        double enemyLuck = rand() % 12 + 8;
        if (_player.GetSpeed() * playerLuck / 10 > _enemy.GetSpeed() * enemyLuck / 10)
        {
            _player.IncreaseCountFlush();
            return true;
        }
        else
        {
            return false;
        }
    }
    void GetFlushActionExp()
    {
        _player.SetExp(_enemy.GetEXP()/2);
    }
    int GetFlushActionHPDamage()
    {
        int damage = rand() % _player.GetCountFlush() + 1;
        _player.SetHP( 0-damage);
        return damage;
    }
    

};
class Game {
    public:
        Game() {}

        Player NewGame() 
        {
            bool startgame = false;
            while(!startgame)
            { 
                cout << "Для начала игры создайте персонажа." << endl;
                cout << "Можно создать воина или разбойника." << endl;
                cout << "Воин более стойкий к урону и имеет больше жизней, но обладает слабой атакой и маленькой скоростью." << endl;
                cout << "Разбойник менее стойкий к урону и имеет меньше жизней, но обладает сильной атакой и большой скоростью." << endl;
                cout << "Нажмите W для выбора воина и R для выбора разбойника" << endl;
                char type = ' ';
                cin >> type;
                string name = "";
                cout << "Введите имя персонажа" << endl;
                cin >> name;
                if (type == 'W' || type == 'w')
                {
                    startgame = true;
                    return Player("Warrior", name);

                }
                else if (type == 'R' || type == 'r')
                {
                    startgame = true;
                    return Player("Rogue", name);
                }
            }
            
        }
};
int main()
{
    setlocale(LC_ALL, "Russian");
    Player player;
    Game game;
    player = game.NewGame();
    char answerPlayer = ' ';
    cout << player;
    Dialog dialog1("Здравствуй игрок. Добро пожаловать в Новогодний мир. \nВ него пришла беда и только ты, избранный, можешь помочь его жителям и вернуть Новый Год.");
    Dialog dialog2("Как только вы прочитали это сообщение, вы увидели садового гнома, несущегося к вам с оскаленным лицом. \nВы понимаете, что сейчас вам предстоит битва. Хотите попытаться смыться или вступить в сражение? \nY- смыться, N - сражаться.");
    dialog1.print();
    dialog2.print();
    Enemy elf(20, 4, 4, 35, 100, "Эльф-рядовой");
    Action action(player, elf);
    cin >> answerPlayer;    
    if (answerPlayer == 'Y')
    {
        if (action.FlushAction())
        {
            action.GetFlushActionExp();
            
            cout << "Вы успешно смылись. За смывку вы получаете половину опыта вашего врага и теряете " 
                << action.GetFlushActionHPDamage() << "здоровья. Помните, чем больше смывок без битв - тем больше будет урон." << endl;
        }
        else
        {
            action.BattleAction();
        }
    }
    else
    {
        action.BattleAction();
    }
    /*
    Item twoHandedSpruce(1, "Двуручная ель", 4, 0, 0, -15, "weapon");
    Item cherryPie(2, "Пирожок с вишней", 0, 0, 5, 0, "heal");
    Item sled(3, "Санки", 0, 0, 0, +10, "maunt");
    Item USSRHat(4, "Шапка-ушанка", 0, 3, 0, 0, "armor");   
   
    cout << player;*/

    return 0;
}