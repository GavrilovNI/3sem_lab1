#pragma once
#include <string>
#include "TConsole.h"
#include "../TableManager.h"


class Visual
{
private:
	
	enum class menus
	{
		Formula,
		DeletePolynom,
		SaveToFile,
		LoadFromFile,
		Exit,
		menusCount
	};

	std::string menuStrings[(int)menus::menusCount] = {
		"������ �������",
		"������� �������",
		"��������� � ����",
		"��������� �� �����",
		"�����"
	};
	char allowedChars[11]{' ','=','+','-','*','^','.','(',')','\'',','};

	TConsole console;
	int tableXPos;
	Vector2i consoleSize;

	menus curMenu;

	bool OnMenuPressed();
	void InputOnMenu();
	void UpdateMenu();

	std::string InputStr(std::string info, bool goBack);

	TableManager tableManager;

	int c = 0;//TODO REMOVE

	int prevPolynomsCount = 0;
	Vector2i prevMenuPos;

public:
	Visual(TableManager& tableManager);
	
	void UpdatePolynoms();

	

};

