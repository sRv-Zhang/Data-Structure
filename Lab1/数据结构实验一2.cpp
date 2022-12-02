#include<iostream>
#include<stdio.h>
#include<string>
#include<time.h>
using namespace std;


int n;
//不借辅助空间2
//一、将个位和十位调换位置
//二、排序
//三、将个位和十位位置换回来
void _swap(int* ptr1)
{
    for (int i = 0; i < n; i++)
    {
        if (ptr1[i] > 9)
            ptr1[i] = ptr1[i] / 10 + ptr1[i] % 10 * 10;//使用这个方式调换位置会出现70换成7状况，所以分类
        else
            ptr1[i] *= 10;
    }
}
//void compositor(int* ptr2)
//{
//    //使用冒泡排序
//    for (int i = 0; i < n - 1; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            if (ptr2[i] > ptr2[j])
//            {
//                swap(ptr2[i], ptr2[j]);
//            }
//        }
//    }
//}

//快速排序
int solution(int* nums, int left, int right)
{
    int pivot = nums[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (nums[j] <= pivot)
        {
            i += 1;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[right]);
    return i + 1;
}
void quicksort(int* nums, int left, int right)
{
    if (left < right)
    {
        int pos = solution(nums, left, right);
        quicksort(nums, left, pos - 1);
        quicksort(nums, pos + 1, right);
    }
}
int main()
{
    cin >> n;
    //生成n个10-100的随机数
    int* element = new int[n];
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        element[i] = rand() % 90 + 10;
        //cin >> element[i];
    }
    cout << "Input: ";
    for (int i = 0; i < n; i++)
        cout << element[i] << " ";
    _swap(element);
    //compositor(element);
    quicksort(element,0,n-1);
    _swap(element);
    cout << endl;
    cout << "Output: ";
    for (int i = 0; i < n; i++)
        cout << element[i] << " ";
    cout << endl;
    return 0;
}