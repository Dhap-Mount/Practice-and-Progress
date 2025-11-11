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