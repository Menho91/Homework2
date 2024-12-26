#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Animal
{
public:
	virtual void MakeSound() = 0;  // 순수가상함수 정의
	virtual ~Animal() {};  // 소멸자 선언
};

class Dog : public Animal
{
public:
	void MakeSound()  // Animal 클래스의 MakeSound 재정의
	{
		cout << "멍멍!" << endl;
	}
	~Dog() {};
};

class Cat : public Animal
{
public:
	void MakeSound()
	{
		cout << "야옹~" << endl;
	}
	~Cat() {};
};

class Cow : public Animal
{
public:
	void MakeSound()
	{
		cout << "음메" << endl;
	}
	~Cow() {};
};


class Zoo
{
private:
	Animal* animals[10]; // 동물 객체를 저장하는 포인터 배열
	int count;  // 저장된 동물 객체의 수
public:
	Zoo() : count(0) {};

	void addAnimal(Animal* animal)
	{
		if (count < 10)
		{
			animals[count++] = animal;
		}
		else
		{
			cout << "동물원이 꽉 차서 동물을 더 넣을 수 없습니다!" << endl;
			return;
		}
	}

	void performActions()
	{
		for (int i = 0; i < count; i++)
		{
			animals[i]->MakeSound();
		}
	}

	~Zoo()
	{
		for (int i = 0; i < count; i++)
		{
			delete animals[i];
		}
	}
};

Animal* createRandomAnimal()
{
	int num = rand() % 3;
	if (num == 0) {
		return new Dog();
	}
	else if (num == 1) {
		return new Cat();
	}
	else {
		return new Cow();
	}
}

int main()
{
	srand(time(0));

	Zoo zoo1;  // Zoo 객체 생성

	for (int i = 0; i < 15; i++)
	{
		zoo1.addAnimal(createRandomAnimal());
	}

	zoo1.performActions();

	return 0;
}