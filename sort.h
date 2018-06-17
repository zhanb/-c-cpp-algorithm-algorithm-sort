#ifndef __SORT__H_
#define __SORT__H_
#include<iostream>
class Sort
{
private:
template <class T>
    static void MergeData(T *a,T *p,int start,int mid,int end);
template <class T>
    static void AdjustHeap(T *a,int size,int element);
public:
template <class T>
    static void PrintData(T arr[],int len);
template <class T>
    static void BubbleSort(T a[],int len);
template <class T>
    static void InsertSort(T a[],int len);
template <class T>
    static void MergeSort(T *a,T *p,int start,int end);
template <class T>
    static void ShellSort(T *a,int len);
template <class T>
    static void HeapSort(T *a,int len);
template <class T>
    static void SelectSort(T *a,int len);
template <class T>
    static void QuickSort(T a[],int left,int right);
};
template <class T>
void Sort::MergeData(T *a,T *p,int start,int mid,int end)
{
    int i = start,j = mid + 1,k = start;
    while(i != mid + 1 &&  j != end + 1)
    {
        if(a[i] < a[j])
            p[k++] = a[i++];
        else
            p[k++] = a[j++];
    }
    while(i != mid + 1)
        p[k++] = a[i++];
    while(j != end + 1)
        p[k++] = a[j++];
    for(int n = start; n <= end; n++)
        a[n] = p[n];
}
template <class T>
void Sort::AdjustHeap(T *a,int size,int element)
{
    int lchild = element*2  + 1;//左节点位置
    int rchild = element*2  + 2;//右节点位置
    int tmp = 0;
    while(rchild < size)//在数组范伟内
    {
        if(a[lchild] <= a[element] && a[rchild] <= a[element])
            return ;
        else if(a[lchild] >= a[rchild])//左边最大
        {
            tmp = a[element];
            a[element] = a[lchild];
            a[lchild] = tmp;
            element = lchild;
        }
        else //右边最大
        {
            tmp = a[element];
            a[element] = a[rchild];
            a[rchild] = tmp;
            element=rchild;
        }
        lchild=element*2+1;
        rchild=element*2+2;
    }
    if(lchild < size && a[lchild] > a[element])
    {
        tmp = a[element];
        a[element] = a[lchild];
        a[lchild] = tmp;
    }
}
template <class T>
void Sort::MergeSort(T *a,T *p,int start,int end)
{
    if(start < end)
    {
        int mid = (start + end)>>1;
        MergeSort(a,p,start,mid);
        MergeSort(a,p,mid+1,end);
        MergeData(a,p,start,mid,end);
    }
}
template <class T>
void Sort::HeapSort(T *a,int len)
{
    int tmp = 0;
    for(int i = len-1;i >= 0; i--)
    {
        AdjustHeap(a,len,i);
    }
    while(len > 0)
    {
        tmp = a[len-1];
        a[len-1] = a[0];
        a[0] = tmp;
        len --;
        AdjustHeap(a,len,0);
    }
}
template <class T>
void Sort::SelectSort(T *a,int len)
{
    for(int i = 0; i < len; i++)
    {
        int min = i;
        for(int j = i + 1; j < len; j++)
        {
            if(a[min] > a[j])
                min = j;
        }
        if(min != i)
        {
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
}
template <class T>
void Sort::ShellSort(T *a,int len)
{
    for(int i = len/2;i > 0;i = i/2)
    {
        for(int j = i; j < len; j++)
        {
            if(a[j] < a[j-1])
            {
                int k = 0;
                int tmp = a[j];
                for(k = j-1; k > 0 && a[k] >= tmp;k--)
                {
                    a[k+1] = a[k];
                }
                a[k+1] = tmp;
            }
        }
    }
}
template <class T>
void Sort::BubbleSort(T a[],int len)
{
    for(int i = 0; i < len - 1; i ++)
    {
        for(int j = 0 ;j < len - i - 1; j++)
        {
           if(a[j] < a[j + 1])
           {
               int tmp = a[j];
               a[j] = a[j + 1];
               a[j + 1] = tmp;
           }
        }
    }
}
template <class T>
void Sort::InsertSort(T a[],int len)
{
    int tmp = 0;
    for(int i = 1; i < len ; i ++)
    {
        if(a[i] < a[i - 1])
        {
            tmp = a[i];
            int j =0;
            for(j = i - 1;j >= 0 && a[j] > tmp; j--)
            {
                a[j+1] = a[j];
            }
            a[j + 1] = tmp;
        }
    }
}
template <class T>
void Sort::QuickSort(T a[],int left,int right)
{
    if(left >= right)
        return ;
    int low = left;
    int hight = right;
    int key = a[low];
    while(low < hight)
    {
        while(low < hight && a[hight] <= key)
        {
            hight --;
        }
        a[low] = a[hight];
        while(low < hight && a[low] >= key)
        {
            low ++;
        }
        a[hight] = a[low];
    }
    a[low] = key;
    QuickSort(a,left,low - 1);
    QuickSort(a,low + 1,right);
}
template <class T>
void Sort::PrintData(T arr[],int len)
{
    for(int i = 0; i < len; i ++)
    {
        std::cout<<i<<":"<<arr[i]<<std::endl;
    }
}
#endif
