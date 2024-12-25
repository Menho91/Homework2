#include <iostream>
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

int main()
{
	Animal* zoo[3];

	zoo[0] = new Dog();  // Animal�� ������ ȣ�� �� Dog�� ������ ȣ��
	zoo[1] = new Cat();
	zoo[2] = new Cow();

	for (int i = 0; i < 3; i++)
	{
		zoo[i]->MakeSound();
	}

	for (int i = 0; i < 3; i++)
	{
		delete zoo[i];	// �ڽ� Ŭ������ �Ҹ��� ȣ�� �� Animal Ŭ������ �Ҹ��� ȣ��, 3�� �ݺ�
	}
	return 0;
}