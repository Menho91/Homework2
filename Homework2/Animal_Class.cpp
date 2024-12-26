#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Animal
{
public:
	virtual void MakeSound() = 0;  // ���������Լ� ����
	virtual ~Animal() {};  // �Ҹ��� ����
};

class Dog : public Animal
{
public:
	void MakeSound()  // Animal Ŭ������ MakeSound ������
	{
		cout << "�۸�!" << endl;
	}
	~Dog() {};
};

class Cat : public Animal
{
public:
	void MakeSound()
	{
		cout << "�߿�~" << endl;
	}
	~Cat() {};
};

class Cow : public Animal
{
public:
	void MakeSound()
	{
		cout << "����" << endl;
	}
	~Cow() {};
};


class Zoo
{
private:
	Animal* animals[10]; // ���� ��ü�� �����ϴ� ������ �迭
	int count;  // ����� ���� ��ü�� ��
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
			cout << "�������� �� ���� ������ �� ���� �� �����ϴ�!" << endl;
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
	srand(static_cast<int>(time(NULL)));  // ���� ������ ���� �õ尪 ����

	Zoo zoo1;  // Zoo ��ü ����

	for (int i = 0; i < 10; i++)
	{
		zoo1.addAnimal(createRandomAnimal());  // ��ü 10�� �����Ͽ� �迭�� ����
	}
	zoo1.addAnimal(createRandomAnimal()); // ��ü�� �迭�� �� ���� �� Ȯ��
	zoo1.addAnimal(createRandomAnimal());

	zoo1.performActions();  // �迭�� �ִ� ��ü ����

	return 0;
}