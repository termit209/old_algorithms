#include <iostream>
#include <cstdlib>


int main()
{
	int N;
	std::cin >> N;
	int *X = new int[N];
	for (int i = 0; i < N; i++)
	{
		std::cin >> X[i];
	}
	int M;
	std::cin >> M;
	int *Y = new int[M];
	for (int i = 0; i < M; i = i + 1)
	{
		std::cin >> Y[i];
	}

	int memory;
	if (M >= N)
	{
		memory = N;
	}
	else
	{
		memory = M;
	}

	int *ans = new int[memory];
	int *ans_y = new int[memory];
	int index = 0;
	int index_y = 0;
	int r = 0;
	int l = 0;
	int last = 0;
	int last_y = 0;
	while (r < N)
	{	
		l = last;
		while (l < M)
		{
			if (X[r] == Y[l])
			{
				ans[index] = X[r];
				index = index + 1;
				last = l + 1;
				l = l + 1;
				break;
			}
			l = l + 1;
		}
		r = r + 1;
	}
	int k = 0;
	int t = 0;
	while (t < M)
	{
		k = last_y;
		while (k < N)
		{
			if (X[k] == Y[t])
			{
				ans_y[index_y] = X[k];
				index_y = index_y + 1;
				last_y = k + 1;
				k = k + 1;
				break;
			}
			k = k + 1;
		}
		t = t + 1;
	}

	if (index < index_y)
	{
		std::cout << index_y;
	}
	else
	{
		std::cout << index;
	}
	std::cout << std::endl;
	for (int i = 0; i < index ; i = i + 1)
	{
		std::cout << ans[i];
	}
	std::cout << std::endl;
	for (int i = 0; i < index_y; i = i + 1)
	{
		std::cout << ans_y[i];
	}
	system("Pause");
	return 0;
}