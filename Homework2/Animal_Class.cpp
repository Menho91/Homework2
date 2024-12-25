#include <iostream>
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

int main()
{
	Animal* zoo[3];

	zoo[0] = new Dog();  // Animal의 생성자 호출 후 Dog의 생성자 호출
	zoo[1] = new Cat();
	zoo[2] = new Cow();

	for (int i = 0; i < 3; i++)
	{
		zoo[i]->MakeSound();
	}

	for (int i = 0; i < 3; i++)
	{
		delete zoo[i];	// 자식 클래스의 소멸자 호출 후 Animal 클래스의 소멸자 호출, 3번 반복
	}
	return 0;
}