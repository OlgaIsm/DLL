#include <iostream>
#include <windows.h>
#include <Winioctl.h>
#include <wchar.h>
#include <algorithm>
#include "DLLlibrary.h"


using namespace std;


int main()
{
	string diskName;// Имя диска (C, D или другое)

	while (1)
	{
		cout << "Please specify volume name (C, D etc.)" << endl;
		diskName = cin.get();
		if (diskName.length() == 1)
		{
			break;
		}
	}


	string diskNameFormated = "\\\\.\\" + diskName + ":"; // Формируем путь

	string SysName = FindFSName(diskName);
	if (!fsIsSupported(SysName))// Определяем поддерживается ли ФС нашей программой (пока что только NTFS)
	{
		cout << "Sorry, " << SysName << " is not supported yet!" << endl;
		cin.get();
		cin.get();
		exit(0);
	}


	NTFS_BootRecord _bpb;// Создаем объект структуры из DLL
	if (getFsInfo(diskNameFormated, &_bpb))// Выводим информацию о ФС
	{
		PrintBootSectInfo(_bpb);
	}
	cout << "Press Enter to exit";
	cin.get();
	cin.get();
	exit(0);
}