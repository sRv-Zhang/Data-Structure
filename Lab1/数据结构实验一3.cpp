#include<iostream>
#include<stdio.h>
#include<string>
#include<time.h>
using namespace std;

int n;
int temp[10];
//借助辅助空间1
//先根据个位进行排序
//再根据十位进行排序
void compositor(int* ptr)
{

    //使用冒泡排序
    //根据个位进行第一轮排序 
    //借助辅助空间计个位数相同的数的数量
    for (int i = 0; i < n; i++)
        temp[ptr[i] % 10]++;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((ptr[i] % 10) > (ptr[j] % 10))
            {
                swap(ptr[i], ptr[j]);
            }
        }
    }
    //根据辅助数组所计数量和十位数进行第二轮排序
    int sum = 0;//用来表示需要进行排序的第一个数字的位置
    for (int k = 0; k < 10; k++)
    {
        for (int i = sum; i < temp[k]+sum; i++)
        {
            for (int j = i + 1; j < temp[k]+sum; j++)
            {
                if ((ptr[i] / 10) > (ptr[j] / 10))
                {
                    swap(ptr[i], ptr[j]);
                }
            }
        }
        sum += temp[k];
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < 10; i++)
	{
		temp[i] = 0;
	}
    //生成n个10-100的随机数
    int* element = new int[n];
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        element[i]=rand()%90+10;
        //cin >> element[i];
    }
    cout << "Input: ";
    for (int i = 0; i < n; i++)
        cout << element[i] << " ";
    compositor(element);
    cout << endl;
    //for (int i = 0; i < 10; i++)//测试辅助数组计数是否正确
    //    cout << temp[i] << " ";
    //cout << endl;
    cout << "Output: ";
    for (int i = 0; i < n; i++)
        cout << element[i] << " ";
    return 0;
}