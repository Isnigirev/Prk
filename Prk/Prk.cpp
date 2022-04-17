#include <iostream>
#include <vector>

/*
4.Создать класс Card, описывающий карту в игре БлэкДжек. 
У этого класса должно быть три поля: масть, 
значение карты и положение карты (вверх лицом или рубашкой). 
Сделать поля масть и значение карты типом перечисления (enum). 
Положение карты - тип bool. Также в этом классе должно быть два метода:
метод Flip(), который переворачивает карту, 
т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, 
и наоборот.
метод GetValue(), который возвращает значение карты, пока можно считать, 
что туз = 1.
*/

class Card
{
    enum Suit
    {
        Worms,
        Diamonds,
        Clubs,
        Peaks
    };

    enum MapValue
    {
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Hine,
        Ten,
        J,
        O,
        K,
        A,
    };

    bool stMapMosition; //(1 - face up 0 - shirt up)

public:
    bool Flip(bool stMapMosition)
    {
        if (stMapMosition == 1)
        {
            std::cout << "Карта перевернута рубашкой вверх\n";
            return stMapMosition = 0;
        }
        else
        {
            std::cout << "Карта перевернута лицом вверх\n";
            return stMapMosition = 1;
        }
    }

    const int GetValue(int a)
    {
        switch (a)
        {
        case Two:
            return 2;
        case Three:
            return 3;
        case Four:
            return 4;
        case Five:
            return 5;
        case Six:
            return 6;
        case Seven:
            return 7;
        case Eight:
            return 8;
        case Hine:
            return 9;
        case Ten:
            return 10;
        case J:
            return 10;
        case O:
            return 10;
        case K:
            return 10;
        case A:
            return 1;
        default:
            break;
        }
    }
};

class Hand
{
    std::vector <Card> vCard;

public:
    void Add(Card)
    {
        std::vector <Card> vCard;
    }

    void Clear()
    {

    }

    void GetValue()
    {

    }
};

class GenericPlayer : public Hand
{
    std::string stName;

public:
    GenericPlayer(std::string stName)
    {
        this->stName = stName;
    }

    virtual bool IsHitting() 
    {
        char a;
        std::cout << "Взять карту? (y/n) \n";
        std::cin >> a;

        return (a == 'y' || a == 'Y') ? 1 : 0;
    }

    bool IsBoosted()
    {

    }

    void Bust()
    {
        std::cout << stName << "\tперебор!\n";
    }

    void GetName()
    {
        std::cout << stName << std::endl;
    }
};

class Player : public GenericPlayer
{
public:
    virtual bool isHitting() const {}

    void Win() const 
    {
        GenericPlayer::GetName;
        std::cout << " Выйграл!" << std::endl;
    }

    void Lose() const
    {
        GenericPlayer::GetName;
        std::cout << " Проиграл!" << std::endl;
    }

    void Push() const
    {
        GenericPlayer::GetName;
        std::cout << " Сыграл в ничью!" << std::endl;
    }
};

class House : public GenericPlayer
{
public:
    virtual bool isHitting() const {} // working...

    void FlipFirstCard()
    {
        Card::Flip;
    }
};

int main()
{
    setlocale(LC_ALL, "Ru");

    return 0;
}