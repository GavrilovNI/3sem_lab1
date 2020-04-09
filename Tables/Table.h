#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <iostream>
#include <fstream>
#include "Polynomial.h"

class Table
{
protected:
	
	//�������� �������� ������
	struct Record
	{
		std::string name;
		Polynomial polynomial;
		bool removed;

		Record(std::string name, Polynomial polynomial)
		{
			this->name = name;
			this->polynomial = polynomial;
			this->removed = false;
		}
	};

	int DataCount;//���������� �������
	virtual Record* FindRecord(std::string name) = 0;
public:
	Table();
	~Table();

	int GetCount() const;						//�������� ���������� �������

	Polynomial* Find(std::string name);			//����� ������, nullptr ���� �� �������
	virtual void Insert(std::string name, const Polynomial& polynomial) = 0;		//������� ������
	void Remove(std::string name);		//�������� ������
	void Replace(std::string name, Polynomial& polynomial);		//������ ������

	//��������
	bool IsEmpty() const;							//�������� �� �������

	//���������

	//�����
	void Read(std::string pFileName);						//������ �� �����
	void Write(std::string pFileName);						//������ � �����

};

#endif TABLE_H