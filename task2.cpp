#include <iostream>
#include <cstdlib>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;
	int *input_X = new int[N];
	int *input_Y = new int[N];
	int *input_Z = new int[N];
	int *index = new int[N];
	int *cont = new int[N];

	for (int i = 0; i < N; i++)
	{
		std::cin >> input_X[i];
		std::cin >> input_Y[i];
		std::cin >> input_Z[i];
		cont[i] = 1;
		index[i] = -1;
	}
	
	int itmax = 0;
	for (int i = 0; i < N; i = i + 1)
	{
		for (int j = 0; j < i; j = j + 1)
		{
			if (input_X[j] != input_X[i])
			{
				if ((input_Y[j] < input_Y[i]) && (input_Z[j] < input_Z[i]))
				{
					if (cont[j] > itmax)
					{
						cont[i] = cont[j] +1;
						index[i] = j;
						itmax = cont[j];
					}
				}
			}
		}
		itmax = 0;
	}

	/*for (int i = 0; i < N ; i++)
	{
	//std::cout << input_X[i] << " " << input_Y[i] << " " << input_Z[i] << std::endl;
	std::cout << i<< "      ";
	std::cout << cont[i] << "  ";
	std::cout << index[i] << std::endl;
	}*/

	int max_element = 0;
	for (int i = 0; i < N; i = i + 1)
	{
		if (max_element < cont[i])
		{
			max_element = cont[i];
		}
	}

	std::cout << max_element << std::endl;
	system("Pause");
	return 0;
}