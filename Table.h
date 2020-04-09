#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <iostream>
#include <fstream>
#include "Polynomial.h"

//�������� �������� ������





class Table
{
protected:
	
	struct Record
	{
		std::string name;
		Polynomial polynomial;
	};

	int DataCount;//���������� �������
	virtual Record* FindRecord(std::string name) = 0;
public:
	Table();
	~Table();

	int GetCount() const;						//�������� ���������� �������

	Polynomial* Find(std::string name);			//����� ������, nullptr ���� �� �������
	virtual void Insert(const Record &rec) = 0;		//������� ������
	virtual void Remove(std::string name) = 0;		//�������� ������
	virtual void Replace(std::string name, const Polynomial& rec) = 0;		//�������� ������
	
	//��������
	bool IsEmpty() const;							//�������� �� �������

	//���������

	//�����
	void Read(std::string pFileName);						//������ �� �����
	void Write(std::string pFileName);						//������ � �����

};

#endif TABLE_H