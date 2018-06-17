#include"sort.h"
using namespace std;
int main()
{
    int a[] = {1,65,23,45,22,1,55,6,21,2,55,52,12,5,6,1,22,212,34};
    int *p = new int[sizeof(a)/sizeof(a[0])];
    cout<<"before sort"<<endl;
    Sort::PrintData(a,sizeof(a)/sizeof(a[0]));
    //Sort::BubbleSort(a,sizeof(a)/sizeof(a[0]));
    //Sort::InsertSort(a,sizeof(a)/sizeof(a[0]));
    //Sort::MergeSort(a,p,0,sizeof(a)/sizeof(a[0]));
    //Sort::ShellSort(a,sizeof(a)/sizeof(a[0]));
    //Sort::HeapSort(a,sizeof(a)/sizeof(a[0]));
    //Sort::SelectSort(a,sizeof(a)/sizeof(a[0]));
    Sort::QuickSort(a,0,sizeof(a)/sizeof(a[0]));
    cout<<"after sort"<<endl;
    Sort::PrintData(a,sizeof(a)/sizeof(a[0]));
    if(p != NULL)
    {
	delete []p;
	p = NULL;
    }
    return 0;
}
