#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>


void Merge(long long int *Array, long long int* index, int start, int end) // 
{
	int middle = (start + end) / 2;
	int r = middle + 1;
	int l = start;
	int i = 0;
	long long int *sorted = new long long int[end - start + 1];
	while ((r <= end) && (l <= middle))
	{
		if (Array[index[l]] <= Array[index[r]])
		{
			sorted[i] = index[l];
			l = l + 1;
		}
		else
		{
			sorted[i] = index[r];
			r = r + 1;
		}
		i = i + 1;
	}
	while (i <= end - start)
	{
		if (r > end)
		{
			sorted[i] = index[l];
			l = l + 1;
		}
		else
		{
			sorted[i] = index[r];
			r = r + 1;
		}
		i = i + 1;
	}
	for (int i = start; i <= end; i = i + 1)
	{
		index[i] = sorted[i - start];
	}
	delete[] sorted;

}

void Merge_sort(long long int *Array, long long int*index, int start, int end)
{
	if (start - end != 0 )
	{
		Merge_sort(Array, index, start, (end + start) / 2);
		Merge_sort(Array, index, (end + start) / 2 + 1, end);
		Merge(Array, index, start, end);
	}
}

int main()
{

	int N;
	std::cin >> N;
	long long int *index = new long long int[N];
	long long int *inp = new long long int[N];
	for (int i = 0; i < N; i++)
	{
		std::cin >> inp[i];
		index[i] = i;
	}
	if (N == 1)
	{
		std::cout << inp[0] << std::endl;
		std::cout << 1;
		return 0;
	}
	Merge_sort(inp, index, 0, N-1);

	int r = 1;
	int l = 0;
	long long int sum = inp[index[0]] + inp[index[1]];
	long long int sum_max = 0;
	int r_max = 0;
	int l_max = 0;

	while (r < N  - 1)
	{
		if (inp[index[l]] + inp[index[l + 1]] < inp[index[r]])
		{
			if (sum >= sum_max)
			{
				sum_max = sum - inp[index[r]];
				l_max = l;
				r_max = r - 1;
			}
			sum = sum - inp[index[l]];
			l = l + 1;
		}
		else
		{
			r = r + 1;
			sum = sum + inp[index[r]];
		}
	}
	if (inp[index[l]] + inp[index[l + 1]] < inp[index[r]])
	{
		if (sum >= sum_max)
		{
			sum_max = sum - inp[index[r]];
			l_max = l;
			r_max = r - 1;
		}
		sum = sum - inp[index[l]];
		l = l + 1;
	}
	while (inp[index[l]] + inp[index[l + 1]] < inp[index[r]])
	{
		sum = sum - inp[index[l]];
		l = l + 1;
	}
	if (sum > sum_max)
	{
		sum_max = sum;
		r_max = N - 1;
		l_max = l;
	}
	delete[] inp; 
	long long int *ind_index = new long long int[N];
	for (int i = 0; i < N; i++)
	{
		ind_index[i] = i;
	}
	Merge_sort(index, ind_index, l_max, r_max);

	/*for (int i = 0; i < N; i++)
	{
		std::cout << inp[i] ;
		std::cout << index[i] << std::endl;

	}
	std::cout << r_max << "**";
	std::cout << l_max;
	std::cout << sum_max<< std::endl;

	for (int i = l_max; i < r_max +1 ; i++)
	{
		std::cout << index[i];
		std::cout << ind_index[i] ;
		std::cout << index[ind_index[i]] + 1<< std::endl;

	}*/
	std::cout << sum_max << std::endl;
	for (int i = l_max; i <= r_max; i++)
	{
		std::cout << index[ind_index[i]] + 1 << " ";
	}
	system("Pause");
	return 0;
}