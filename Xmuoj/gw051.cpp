/*
 * @Author: cdf
 * @Date: 2024-11-11 16:48:34
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-11 17:03:15
 * @Description: xmuoj_mymax
 */

#include <iostream>
using namespace std;
// 在此处补充你的代码

void* MyMax(void* arr, size_t elementSize, int n, int (*compare)(void*, void*)) {
    char* maxElem = (char*)arr;  // 初始化指向数组第一个元素
    for (int i = 1; i < n; ++i) {
        char* currentElem = (char*)arr + i * elementSize;  // 当前元素指针
        if (compare(currentElem, maxElem) > 0) {
            maxElem = currentElem;  // 更新最大元素指针
        }
    }
    return maxElem;  // 返回最大元素的指针
}


int Compare1(void * n1,void * n2)
{
	int * p1 = (int * )n1;
	int * p2 = (int * )n2;
	return ((*p1)%10) - ((*p2)%10);
}
int Compare2(void * n1,void * n2)
{
	int * p1 = (int * )n1;
	int * p2 = (int * )n2;
	return *p1 - *p2;
}
#define eps 1e-6
int	Compare3(void * n1,void * n2)
{
	float * p1 = (float * )n1;
	float * p2 = (float * )n2;
	if( * p1 - * p2 > eps)
		return 1;
	else if(* p2 - * p1 > eps)
		return -1;
	else
		return 0; 
}

int main()
{
	int t;
	int a[10];
	float d[10];
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0;i < n; ++i)
			cin >> a[i];
		for(int i = 0;i < n; ++i)
			cin >> d[i];
		int * p = (int *) MyMax(a,sizeof(int),n,Compare1);
		cout << * p << endl;
		p = (int *) MyMax(a,sizeof(int),n,Compare2);
		cout << * p << endl;
		float * pd = (float * )MyMax(d,sizeof(float),n,Compare3);
		cout << * pd << endl;
	}
	return 0;
}