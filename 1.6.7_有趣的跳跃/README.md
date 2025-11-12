我大致能想出解决问题的总体思路：
- 先计算数组相邻元素的差值，填入一个新的数组
- 给新数组升序排序
- 判断相邻元素差值是否为+1

---

这是一道一维数组的题目，其中有很多细节我还搞不太明白
**如下**：
- 输入一行，第一个是数组长度，剩下的作为元素填入数组
- 排序的方法

- 以及cpp中独有的数组写法 例如vector

---

deepseek给出了相对简洁的写法：

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // 如果序列只有一个元素，直接输出Jolly
    if (n == 1) {
        cout << "Jolly" << endl;
        return 0;
    }
    
    // 计算相邻元素的差的绝对值
    vector<int> diffs;
    for (int i = 1; i < n; i++) {
        diffs.push_back(abs(nums[i] - nums[i-1]));
    }
    
    // 对差的绝对值进行排序
    sort(diffs.begin(), diffs.end());
    
    // 检查排序后的差值是否正好是1到n-1
    bool isJolly = true;
    for (int i = 0; i < n - 1; i++) {
        if (diffs[i] != i + 1) {
            isJolly = false;
            break;
        }
    }
    
    if (isJolly) {
        cout << "Jolly" << endl;
    } else {
        cout << "Not jolly" << endl;
    }
    
    return 0;
}
```
