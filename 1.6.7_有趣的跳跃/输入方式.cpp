#include <iostream>
using namespace std;
// 题目要求：输入第一个值是数组长度，剩下的值是数组元素
int main()
{
	int n;
	while (cin >> n) 
	{
		int arr[n] = {0};
		for (int i = 0; i < n; i ++)
		{
			cin >> arr[i];
		}
		
		cout << "遍历数组并输出：\n";
		for (int j = 0; j < n; j ++)
		{
			cout << arr[j] << " ";
		}
	}
	
	return 0;
}

// Gemini使用一个 while 语句贯穿了整个 main 函数，这是可行的
// 在和deepseek的交流中，我发现Gemini的书写方法总是很繁琐，实际上没有必要这样

int input() // 这样写就行，我会去问问Gemini那样写的缘由
{
	int n;
	cin >> n; // 输入第一个值n

	long long arr[n];
	for (int i = 0; i < n; i ++)
	{
		cin >> arr[i];
	}
}
