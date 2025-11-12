#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // For std::abs
#include <sstream> // For std::istringstream (if needed for more robust line parsing, though not strictly necessary here)

int main() {
    // 禁用与C语言stdio的同步，可以提高iostream的效率
    std::ios_base::sync_with_stdio(false);
    // 解除cin和cout的绑定，可以进一步提高效率
    std::cin.tie(NULL);

    int n;
    // 循环读取每一行输入
    while (std::cin >> n) { // 首先读取长度 n
        std::vector<long long> sequence(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> sequence[i]; // 接着读取 n 个元素，它们都在同一行
        }

        if (n == 1) { // 任何只包含单个元素的序列一定存在“有趣的跳跃”
            std::cout << "Jolly\n"; // 使用 '\n' 代替 std::endl 可以提高输出效率
            continue;
        }

        std::vector<int> diffs;
        diffs.reserve(n - 1); // 预分配内存，提高效率

        for (int i = 0; i < n - 1; ++i) {
            diffs.push_back(std::abs(sequence[i] - sequence[i+1]));
        }

        std::sort(diffs.begin(), diffs.end());

        bool isJolly = true;
        for (int i = 0; i < n - 1; ++i) {
            if (diffs[i] != i + 1) {
                isJolly = false;
                break;
            }
        }

        if (isJolly) {
            std::cout << "Jolly\n";
        } else {
            std::cout << "Not jolly\n";
        }
    }
    return 0;
}