#ifndef HASH_TABLE_LIST
#define HASH_TABLE_LIST

#include "Table.h"
#include <list>

using namespace std;


class HashTableList : public Table
{
private:
	list<Record>* mas;
	int size;
	int curList;
	int listPos;
	int hash(std::string name);	//���������� ����

public:
	
	HashTableList(int msize = 25);
	~HashTableList();

	Record* FindRecord(std::string name) override;	//����� ������

	void Insert(std::string name, Polynomial& polynomial) override;	//�������
	void Remove(std::string name) override;	//��������
	void Clear() override;	//������� �������

	//���������
	iterator begin();
	iterator end();

};

#endif HASH_TABLE_LIST
