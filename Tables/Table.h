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
	class Record
	{
	protected:
		std::string name;
	public:
		Polynomial polynomial;

		Record() {}
		Record(std::string name, Polynomial polynomial);
		std::string GetName();
	};

	int DataCount;//���������� �������
	virtual Record* FindRecord(std::string name) = 0;
public:
	Table();

	int GetCount() const;												//�������� ���������� �������

	virtual void Insert(std::string name, Polynomial& polynomial) = 0;	//������� ������
	virtual void Remove(std::string name) = 0;							//�������� ������
	virtual void Clear() = 0;											//�������
	Polynomial* Find(std::string name);									//����� ������, nullptr ���� �� �������
	void Replace(std::string name, Polynomial& polynomial);				//������ ������

	//��������
	bool IsEmpty() const;							//�������� �� �������

	//���������

	//�����
	void Read(std::string pFileName);						//������ �� �����
	void Write(std::string pFileName);						//������ � �����

};

#endif TABLE_H