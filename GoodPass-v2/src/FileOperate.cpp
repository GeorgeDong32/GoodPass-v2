/* FileOperate.cpp version 2.7.0     */
#include "FileOperate.h"
#include <direct.h>
#include <io.h>
#include <Windows.h>
#include "Display.h";
ofstream fblog; ofstream fdata;
ofstream MKconO;
ifstream MKconI;

void FloderInit(int mode)
{
	string L0path = "D:\\My Project";
	string L1fpath = "D:\\My Project\\GoodPass";
	string L2Bpath = "D:\\My Project\\GoodPass\\Blog";
	string L2Dpath = ".\\MData";
	if (mode)
		printLine(33);
	if (_access(L2Dpath.c_str(), 00))
	{
		int flag = _mkdir(L2Dpath.c_str());
		if (flag == 0 && mode == 1)
			cout << "|  Data floder created                |" << endl;
		else if (mode == 1)
			cout << "|  Failed to create Data floder       |" << endl;
	}
	else if (mode == 1)
		cout << "|  The Data floder exists             |" << endl;
	if (mode)
		printLine(33);
}

void BlogInit(int mode)
{
	string blogpath = ".\\Blog\\GeneratorBlog.csv";
	fblog.open(blogpath, ios_base::app);
}

int MKconInit()
{
	string MKconpath = ".\\MData\\MKCheck.config";
	if (!_access(MKconpath.c_str(), 00))//?????????ļ??Ƿ?????
	{
		MKconI.open(MKconpath, ios::in);
		char check;
		if (MKconI >> check)
		{
			MKconI.close();
			return 1;
		}
		else
		{
			SetColor(14);
			printf("+-------------------<!>------------------+\n");
			printf("!  :(                                    !\n");
			printf("!  Error! MainKey config has a problem!  !\n");
			printf("+-------------------<!>------------------+\n");
			SetColor(15);
			MKconI.close();
		}
		return 2;
	}
	else
	{
		MKconO.open(MKconpath, ios::out);
		return 0;
	}
}

void DataInit()
{
	string MDpath = ".\\MData\\Data.csv";
	fdata.open(MDpath, ios::app);
}
