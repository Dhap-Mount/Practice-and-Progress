// Created by dhapmount on 2025/11/16.
/*
洛谷 B2102 计算鞍点：
给定一个 5×5 的矩阵，每行只有一个最大值，每列只有一个最小值，寻找这个矩阵的鞍点。
鞍点指的是矩阵中的一个元素，它是所在行的最大值，并且是所在列的最小值。
输出行列和鞍点数，如果没有输出 no found
*/
#include <iostream>
using namespace std;
int main () {
    bool isSaddlePoint = false;

    int mat[5][5] = {0};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> mat[i][j];
        }
    }

    int big[5] {0};
    int small[5] {0};
    for (int i = 0; i < 5; i++) {
        int tmp1 = mat[i][0];
        for (int j = 0; j < 5; j++) { // 这个循环结束后，tmp1的值就是这行最大值
            if (tmp1 <= mat[i][j]) {
                tmp1 = mat[i][j];
            }
        }
        big[i] = tmp1; // 第i行最大的值被填入数组
    }
    for (int j = 0; j < 5; j++) {
        int tmp2 = mat[0][j];
        for (int i = 0; i < 5; i++) {
            if (tmp2 >= mat[i][j]) {
                tmp2 = mat[i][j];
            }
        }
        small[j] = tmp2; // 第j列最小的值被填入数组
    }

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            if (big[x] == small[y]) {
                cout << x + 1 << " " << y + 1 << " " << big[x] << endl;
                isSaddlePoint = true;
                return 0;
            }
        }
    }
    if (!isSaddlePoint) cout << "not found\n";

    return 0;
}

// 难道只要行列有相同的数字就一定是鞍点吗？
// 不需要再回到原始的二维数组里做一下位置的索引吗？ ds说需要加上一个 && max[x][y] == big[x] 来做判断