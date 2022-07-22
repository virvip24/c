// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
/*
int main()
{
    std::cout << "Hello World!\n";
}*/
#include <stdio.h>
#include <stdlib.h>
/* 数组和函数 */
void change(int val)// int val = number
{
    val = 55;
}
// 数组名还代表了该数组在内存中的起始地址,实参数组名将该数组的起始地址传递给形参数组,系统不再为形参数组分配存储单元, 
// 两个数组共享一段内存单元, 所以形参数组修改时，实参数组也同时被修改了
void change2(int array[])// int array = 0ffd1  
{
    array[0] = 88;
}
/* 冒泡排序 */
// 交换两个元素的值, i/j需要交换的索引
void swapEle(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
// 插入排序
//针对部分有序的集合来说（这里说的有序 是指与我们想得到的顺序一致） 插入排序效率优于冒泡排序

void bubbleSort(int numbers[], int length) {
    for (int i = 0; i < length; i++) {
        // -1防止`角标越界`: 访问到了不属于自己的索引
        for (int j = 0; j < length - i - 1; j++) {
            //  1.用当前元素和相邻元素比较
            if (numbers[j] < numbers[j + 1]) {
                //  2.一旦发现小于就交换位置
                swapEle(numbers, j, j + 1);
            }
        }
    }
}

/*函数指针：回调函数*/
/*回调函数就是一个通过函数指针调用的函数。
如果你把函数的指针（地址）作为参数传递给另一个函数，
当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。*/
//回调函数如下
//认为如果x y 符合排序要求返回1，不符合返回0；
typedef int (*Cmp)(int x, int y);      //这里的Cmp是函数指针的类型
//通过回调函数来满足调用者不同的需求，达到一段代码、多种用途的目的
int less(int x, int y)//x:当前值 < y:前一个值, 返回1，符合要求，进行调换，使当前值>上一个值，是升序
{
    //这个函数表示用于升序排序
    //如果x比y小，就是符合排序要求
    return x < y ? 1 : 0;
}
int greater(int x, int y)
{
    //降序排序
    return x > y ? 1 : 0;
}
/*冒泡排序*/
void bubbleSort(int arr[], int len, Cmp cmp)
{
    for (int bubble = 0; bubble < len; bubble++)
    {
        for (int cur = len - 1; bubble < cur; cur--)
        {
            if (cmp(arr[cur], arr[cur - 1]) == 1)
            {
                int tmp = arr[cur];
                arr[cur] = arr[cur - 1];
                arr[cur - 1] = tmp;
            }
        }
    }
}

int main(){
    printf("Hello, C!\r\n");
    int i,ages[3] = { 1, 2, 3 };

    /* 数组和函数 */
    printf("把数组元素作为实参使用\r\n");
    printf("ages[0] = %d\r\n", ages[0]);// 1
    change(ages[0]);
    printf("ages[0] = %d\r\n", ages[0]);// 还是1,形参的改变不影响实参

    printf("把数组名作为函数的形参和实参使用\r\n");
    printf("ages[0] = %d\r\n", ages[0]);// 1
    change2(ages);
    printf("ages[0] = %d\r\n", ages[0]);// 88

    printf("冒泡排序\r\n");
    for (i = 0; i < 3; i++)
    {
        ages[i] = i + 1;
        printf("ages[i] = %d\r\n", ages[i]);
    }
    bubbleSort(ages, 3);
    for (i = 0; i < 3; i++)
    {
        printf("ages[i] = %d\r\n", ages[i]);
    }

    printf("指针变量\r\n");
    int num = 666;
    int* q = &num; // 一个用于指向整型变量的指针
    int* p;
    p = &num;
    printf("%d %d\r\n", *q, *p); // 访问指针变量
    printf("%d %d %d\r\n", &num, q, p); // 地址

    printf("数组指针\r\n");
    int a[3] = { 1,2,3 };
    int* p2 = a;
    p2++;
    printf("%d %d\r\n", *p2, *(p2+1)); // 

    printf("函数指针应用：回调函数，冒泡排序\r\n");
    int arr[] = { 8,3, 9, 5, 7, 4, 6 };
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("降序\r\n");
    bubbleSort(arr, len, greater);
    for (int i = 0; i < len; ++i)
    {
        printf("% d\n", arr[i]);
    }
    printf("升序\r\n");
    bubbleSort(arr, len, less);
    for (int i = 0; i < len; ++i)
    {
        printf("% d\n", arr[i]);
    }
    //函数指针用作转移表，大大降低了函数的圈复杂度。实现计算器。https://blog.csdn.net/Diligent_wu/article/details/117924012

    //链表
    
    //文件

    system("pause");
    return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
