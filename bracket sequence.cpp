#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream> 
#include <cstring> 

int main()
{
	FILE * ptrFile = fopen("input.txt", "r");
	char a;
	bool ind = true;
	int index = -1;
	std::vector<short int> vec;
	int ctr = 0;   // счетчик символов

	while ((!feof(ptrFile)) && (ind))                           // пока не конец файла
	{
		a = fgetc(ptrFile);// прочитать символ из файла
		switch (a) // начало оператора switch
		{
		case *"(": // если count = 1
		{
			vec.push_back(0);
			index++;
			ctr++;
			break;
		}
		case *"[":
		{
			vec.push_back(1);
			index++;
			ctr++;
			break;
		}
		case *"{":
		{
			vec.push_back(2);
			index++;
			ctr++;
			break;
		}
		case *")":
		{
			if (index < 0)
			{
				ind = false;
				break;
			}
			else
			{
				if (vec[index] == 0)
				{
					vec.pop_back();
					index--;
					ctr++;
				}
				else
					ind = false;
			}
		}
		break;

		case *"]":
		{
			if (index < 0)
			{
				ind = false;
				break;
			}
			else
			{
				if (vec[index] == 1)
				{
					vec.pop_back();
					index--;
					ctr++;
				}
				else
					ind = false;
			}
		}
		break;

		case *"}":
		{
			if (index < 0)
			{
				ind = false;
				break;
			}
			else
			{
				if (vec[index] == 2)
				{
					vec.pop_back();
					index--;
					ctr++;
				}
				else
					ind = false;
			}
		}
		break;
		}
	}
	fclose(ptrFile);                                    // закрыть файл

	std::ofstream fout("output.txt");
	if (ind && (index == -1))
	{
		fout << "CORRECT";
	}
	else
	{
		fout << ctr; // Записываем данные в файл out.put.txt
	}
	fout.close();

	return 0;
}
