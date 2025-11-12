#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector <long long> arr(n); 
	for (int i = 0; i < n; i ++) {
		cin >> arr [i];
	}
	
	if (n == 1) 
	{ // 如果只有一个元素，那么必定是 jolly
		cout << "Jolly" << endl;
		return 0;
	}
	
	// 不是一个元素的情况
	
	int diff[n - 1] = {0}; // diff 是储存差值的数组
	for (int i = 0; i < n - 1; i ++) {
		diff[i] = abs(arr[i + 1] - arr[i]);
	}
	// 接下来为 list 数组里的元素排序
	
	for (int i = 0; i < n - 2; i ++)
	{
		for (int j = 0; j < n - 2 - i; j ++)
		{
			if (diff[j] > diff[j + 1])	
			{
				long long tmp = diff[j + 1];
				diff[j + 1] = diff[j];
				diff[j] = tmp;
			}
		}
	}
	
	bool is_jolly = true;
	
	for (int i = 0; i < n - 2; i ++) // 判断差值是否符合 jolly 条件
	{
		if (diff[i] != i + 1)
		{
			is_jolly = false;
			break;
			
		}
	}
	
	if (!is_jolly)
	{
		cout << "Not jolly" << endl;
	}
	else cout << "Jolly" << endl;
	
	return 0;
}