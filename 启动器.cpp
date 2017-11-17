#include<iostream>
#include<string>
#include<Windows.h>
#include"loading.h"
#include<fstream>
#include<cstdlib>
#include"GUI.h"
#include<io.h>
#include<cstdio>
using namespace std;
int main()
{
	system("md config");
	system("md temp");
	system("attrib +s +h config");
	system("attrib +s +h temp");
	char userin;
	ofstream musicconfig("config\\musicconfig.txt");
	system("color 0F");
	system("title PMstarter");
	system("mode con cols=65 lines=12");
	string filein, fileout;
	log1();
	cin >> filein;
	fileout = "copy " + filein + " temp\\PetList_100.txt /y";
	system(fileout.c_str());
	log2();
	cin >> filein;
	fileout = "copy " + filein + " temp\\MasterList.txt /y";
	system(fileout.c_str());
music:	music();
	userin = _getche();
	if (userin == 'y' || userin == 'Y')
	{
		musicconfig << "y";
	}
	else if (userin == 'n' || userin == 'N')
	{
		musicconfig << "n";
	}
	else
	{
		goto music;
	}
	ofstream themeconfig("config\\themeconfig.txt");
SettingthemeMenu:
	settingtheme();
	userin = _getche();
	switch (userin)
	{
	case '1':
		system("color 0F");
		themeconfig << "1";
		break;
	case '2':
		system("color F0");
		themeconfig << "2";
		break;
	case '3':
		system("color 4F");
		themeconfig << "3";
		break;
	case '4':
		system("color 0A");
		themeconfig << "4";
		break;
	case '5':
		system("color 1F");
		themeconfig << "5";
		break;
	case '6':
		system("color 2F");
		themeconfig << "6";
		break;
	default: {
		error();
		goto SettingthemeMenu;
	}
	}
	musicconfig.close();
	themeconfig.close();
	system("attrib -a -s -h -r pet.exe");
	system("copy pet.exe petmanage.exe");
	system("attrib +a +s +h +r pet.exe");
	system("start petmanage.exe");
	return 0;
}
