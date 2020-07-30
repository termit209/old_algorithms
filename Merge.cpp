#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

void Merge(int *Array, int start, int end) // 
{
	int middle = (end + start) / 2;
	int r = middle + 1;
	int l = start;
	int i = 0;
	int *sorted = new int[end - start + 1];
	while ((r <= end) && (l <= middle))
	{
		if (Array[l] <= Array[r])
		{
			sorted[i] = Array[l];
			l = l + 1;
		}
		else
		{
			sorted[i] = Array[r];
			r = r + 1;
		}
		i = i + 1;
	}
	while (i <= end - start)
	{
		if (r > end)
		{
			sorted[i] = Array[l];
			l = l + 1;
		}
		else
		{
			sorted[i] = Array[r];
			r = r + 1;
		}
		i = i + 1;
	}
	for (int i = start; i <= end; i = i + 1)
	{
		Array[i] = sorted[i - start];
	}
	delete[] sorted;

}


int main()
{
	
	int N;
	std::cin >> N;
	int M;
	std::cin >> M;
	int d = ceil((log2(N * M)));
	int up = static_cast < int > (pow(2, d));
	int max = 1000000005;
	int *inp = new int[M*up];
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> inp[index];
			index = index + 1;
		}
	}
	std::cout << up << std::endl;
	for (int i = index; i < M*up; i++)
	{
		inp[index] = max;
		index = index + 1;
	}

	for (int deg = 2; deg <= up; deg = deg*2)
	{
		for (int i = 0; i < up; i = i + deg*M)
		{
			Merge(inp, i, i + deg * M - 1);
		}
	}
	for (int i = 0; i < M*N; i++)
	{
		std::cout << inp[i] << " ";
	}
	system("Pause");
	return 0;
}