#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
    int x;
    int y;
};

// Rule1_compare 函数，比较两个整数的个位数以及十位数
bool Rule1_compare(int a, int b)
{
    if (a % 10 < b % 10)
        return true;
    if (a % 10 == b % 10)
    {
        int tempa = a / 10;
        int tempb = b / 10;
        if (tempa > tempb)
            return true;
    }

    return false;
}

// Rule2 的比较函数
bool Rule2_compare(const Point &a, const Point &b)
{
    double distA = pow(a.x, 2) + pow(a.y, 2);
    double distB = pow(b.x, 2) + pow(b.y, 2);
    if (distA < distB)
        return true;
    else if (distA == distB)
    {
        if (a.x < b.x)
            return true;
        else if (a.x == b.x)
            return a.y < b.y;
    }
    return false;
}

// 包装函数，返回 Rule1_compare
bool (*Rule1())(int, int) 
{
    return Rule1_compare;
}

// 包装函数，返回 Rule2_compare
bool (*Rule2())(const Point&, const Point&) // 实际上表示返回一个比较函数指针，返回一个
{
    return Rule2_compare;
}

/* 函数指针的使用，用来包装函数
    return_type (*pointer_name)(parameter_types);
    return_type：函数的返回类型。
    pointer_name：函数指针的名字。
    parameter_types：函数的参数类型。
*/

int main()
{
    int a[8] = {6, 5, 55, 23, 3, 9, 87, 10};
    sort(a, a + 8, Rule1()); // 使用包装后的 Rule1
    for (int i = 0; i < 8; ++i)
        cout << a[i] << ",";
    cout << endl;

    Point ps[8] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, -1}, {1, 1}, {2, 0}, {-2, 0}};
    sort(ps, ps + 8, Rule2()); // 使用包装后的 Rule2
    for (int i = 0; i < 8; ++i)
        cout << "(" << ps[i].x << "," << ps[i].y << ")";
    return 0;
}
