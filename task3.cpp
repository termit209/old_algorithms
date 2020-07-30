#include <iostream>
#include <cstdlib>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;
	int *input = new int[N]; 
	int *posit = new int[N];
	int *negat = new int[N];
	int *nindex = new int[N];
	int *pindex = new int[N];
	int itmax = 0;
	for (int i = 0; i < N; i++)
	{
		std::cin >> input[i];
		posit[i] = 1;
		negat[i] = 1;
		nindex[i] = -1;
		pindex[i] = -1;
	}
	posit[N-1] = 1;
	negat[N-1] = 1;
	nindex[N-1] = -1;
	pindex[N-1] = -1;
	for (int i = N-2; i >= 0; i = i - 1)
	{
		for (int j = N-1; j > i; j = j - 1)
		{
			if (input[j] != input[i])
			{
				if (input[j] < input[i])
				{
					itmax = negat[j] + 1;
					if (itmax >= posit[i])
					{
						posit[i] = itmax;
						pindex[i] = j;
					}
				}
				else
				{
					itmax = posit[j] + 1;
					if (itmax >= negat[i])
					{
						negat[i] = itmax;
						nindex[i] = j;
					}
				}
			}
			itmax = 0;
		}
	}
	/*for (int i = 0; i < N ; i++)
	{
		std::cout << i<< "      ";
		std::cout << posit[i] << "  ";
		std::cout << negat[i] << "  ";
		std::cout << pindex[i] << "  ";
		std::cout << nindex[i] << std::endl;
	}*/

	int max_element = -1;
	int ind_max_element = -1;

	bool flag;
	for (int i = 0; i < N; i++)
	{
		if (max_element < posit[i]) 
		{
			max_element = posit[i];
			ind_max_element = i;
			flag = true;
		}
		if (max_element < negat[i])
		{
			max_element = negat[i];
			ind_max_element = i;
			flag = false;
		}
	}
	int ind= ind_max_element;
	while (ind >= 0)
	{
		if (flag)
		{
			std::cout << input[ind]<<" ";
			ind = pindex[ind];
			flag = false;
		}
		else
		{
			std::cout << input[ind]<<" ";
			ind = nindex[ind];
			flag = true;
		}
	}

	// std::cout << max_element << "  " << ind_max_element << std::endl;
	system("Pause");
	return 0;
}