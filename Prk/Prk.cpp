#include <iostream>
#include <string>

//1
class DivisionByZero
{
	std::string Message;

public:
	DivisionByZero(std::string message = "") : Message(message) {}

	const std::string& GetMessage() 
	{ 
		return Message;
	}
};

template <typename T>
T Div(T a, T b)
{
	if (b == 0)
	{
		throw DivisionByZero("Деление на ноль!");
	}	

	return a / b;
}

//2
template <typename T1>
class Ex
{
public:
	Ex(T1 x) : X(x) {};

	T1 X;
};

template <typename T3>
class Bar
{
	T3 Y;

public:
	Bar(T3 y = 0) : Y (y = 0) {}

	void Set(T3 a)
	{
		((Y + a) > 100) ? throw Ex <T3>(a * Y) : Y = a;
	}
};

////3
class OffTheField
{
	int CurPosX;
	int CurPosY;
	int NewPosX;
	int NewPosY;
	std::string Message;

public:
	OffTheField(int CX, int CY, int NX, int NY) :
		CurPosX(CX), CurPosY(CY), NewPosX(NX), NewPosY(NY), Message("")
	{
		if (NewPosX > 10 || NewPosX < 1)
		{
			Message += "Ошибка координаты X! Робот выходит за границу поля!\n";
			Message += '[' + std::to_string(CurPosX) + ';' + std::to_string(CurPosY) + "] => [" +
				std::to_string(NewPosX) + ';' + std::to_string(NewPosY) + "]\n";
		}
		if (NewPosY > 10 || NewPosY < 1)
		{
			Message += "Ошибка координаты Y! Робот выходит за границу поля!\n";
			Message += '[' + std::to_string(CurPosX) + ';' + std::to_string(CurPosY) + "] => [" +
				std::to_string(NewPosX) + ';' + std::to_string(NewPosY) + "]\n";
		}
	}

	const std::string& GetInfo() const
	{
		return Message;
	}
};

class IllegalCommand
{
	int CurPosX;
	int CurPosY;
	int NewPosX;
	int NewPosY;
	std::string Message;

public:
	IllegalCommand(int CX, int CY, int NX, int NY) :
		CurPosX(CX), CurPosY(CY), NewPosX(NX), NewPosY(NY), Message("")
	{
		if (abs(CurPosX - NewPosX) > 1)
		{
			Message += "Ошибка координаты X! Шаг слишком велик!\n";
			Message += '[' + std::to_string(CurPosX) + ';' + std::to_string(CurPosY) + "] => [" +
				std::to_string(NewPosX) + ';' + std::to_string(NewPosY) + "]\n";
		}

		if (abs(CurPosY - NewPosY) > 1)
		{
			Message += "Ошибка координаты Y! Шаг слишком велик!\n";
			Message += '[' + std::to_string(CurPosX) + ';' + std::to_string(CurPosY) + "] => [" +
				std::to_string(NewPosX) + ';' + std::to_string(NewPosY) + "]\n";
		}

		if (CurPosX == NewPosX && CurPosY == NewPosY)
		{
			Message += "Ошибка координаты X и Y! Нельзя шагнуть на текущее место!\n";
			Message += '[' + std::to_string(CurPosX) + ';' + std::to_string(CurPosY) + "] => [" +
				std::to_string(NewPosX) + ';' + std::to_string(NewPosY) + "]\n";
		}
	}

	const std::string& GetInfo() const
	{
		return Message;
	}
};

class Robot
{
	int PosX;
	int PosY;

public:
	Robot(int x = 5, int y = 5) : PosX(x), PosY(y)
	{
		std::cout << "Начальная позиция робота: [" << PosX << ";" << PosY << "]\n";
	}

	void Move(int x, int y)
	{
		if (x > 10 || x < 1 || y > 10 || y < 1)
		{
			throw OffTheField(PosX, PosY, x, y);
		}
		if (abs(PosX - x) > 1 || abs(PosY - y) > 1 || (PosX == x && PosY == y))
		{
			throw IllegalCommand(PosX, PosY, x, y);
		}
				
		std::cout << "Робот шагнул [" << PosX << ";" << PosY << "] => [" << x << ";" << y << "]\n";

		PosX = x;
		PosY = y;
	}
};

int main()
{
    setlocale(LC_ALL, "Ru");

//1
	try
	{
		double result = Div(10, 0);
		std::cout << result << std::endl;
	}
	catch (DivisionByZero& e)
	{
		std::cerr << e.GetMessage() << std::endl;
	}

//2
	Bar <int> b;
	int n;

	try
	{
		while (true)
		{
			std::cin >> n;
			if (n == 0)
			{
				break;
			}

			b.Set(n);
		}
	}
	catch (Ex <int> e)
	{
		std::cout << e.X << std::endl;
	}
//3
	int X = 0, Y = 0;
	Robot r;

	while (true)
	{
		std::cin >> X >> Y;

		if (X == 0 && Y == 0)
		{
			break;
		}
	
		try
		{
			r.Move(X, Y);
		}
		catch (const IllegalCommand& e)
		{
			std::cerr << e.GetInfo() << std::endl;
		}
		catch (const OffTheField& e)
		{
			std::cerr << e.GetInfo() << std::endl;
		}
	}

    return 0;
}