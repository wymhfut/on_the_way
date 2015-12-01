#include<iostream>
#include<malloc.h>
using namespace std;


void  PrintArr(int ar[],int n)
{
    for(int i = 0; i < n; ++i)
        cout<<ar[i]<<" ";
    cout<<endl;
}

int MapToIndex(int x,int max)  
{  
    return (10 * x) / max;  
} 

void insertion_sort(int arr[],int begin,int end)
{
    for(int i = begin+1; i <= end; ++i)
    {
        int v = arr[i];
        int j = i;
        while(j-1 >= begin && v<arr[j-1])
        {
            arr[j--] = arr[j-1];  
        }
        arr[j] = v;
    }
} 

void bucket_sort(int ar[], int begin, int end)  
{  
    const int radix = end-begin+2;  //ע�⣺Ϊʲô��11��
	int* count = new int[radix];
    int i, j;    
    int size = end-begin+1;

    //����ֵ�ÿ�
    for(i = 0; i < radix; ++i)  
    {
        count[i] = 0;    //�ÿ�
    }
    
    //end-begin+1 = 9 - 0 + 1 = 10
    int *Temp = (int *) malloc((size) * sizeof(int));     //������ʱ�ռ�

    //ȡ�õ�ǰ�����������е��������
    int max = 0;  
    for(i = begin; i < size; ++i)  
    {  
        if(ar[i] > max)  
            max = ar[i];  
    }  

    //ͳ�Ƹ�Ͱ��Ҫװ��Ԫ�صĸ���  
    for(i = begin; i < size; ++i)   
    {
        count[MapToIndex(ar[i], max)]++;   
    }
          
    //������������
    PrintArr(count, radix);

    //���Ͱ�ı߽�������count[i]Ϊ��i��Ͱ���ұ߽�����+1   
    for(i = 1; i < radix; ++i)   
    {
        count[i] = count[i] + count[i-1];  
    }

    //���Ͱ�߽�����        
    PrintArr(count, radix);

    //��������ɨ�裬��֤�����ȶ���   
    for(i = end; i >= begin; --i)             
    {    
        j = MapToIndex(ar[i], max);        
        Temp[count[j]-1] = ar[i];  //�����Ӧ�Ŀռ��У�count[j]-1�ǵ�j��Ͱ���ұ߽�����   
        --count[j];       //׼��������һ��Ԫ�ص�λ������   
    }     

    for(int i = 0; i < size; ++i)
    {
        cout<<Temp[i]<<"  ";
    }
    cout<<endl;

    PrintArr(count, radix);

    //�Ӹ���Ͱ���ռ�����   
    for(i = begin, j = 0; i < size; i++, j++)  
    {
        ar[i] = Temp[j];        
    }
    
    PrintArr(ar, end+1);

     //�ͷſռ�  
    free(Temp);                          
    
    for(i = 0; i < size; i++)  
    {   
        int index1 = begin + count[i];             //�õ���i��Ͱ����߽�   
        int index2 = begin + count[i+1] - 1;       //�õ���i��Ͱ���ұ߽�   
        if(index1 < index2)  
            insertion_sort(ar, index1, index2);          
    }  
}  

void  main()
{
    int  ar[] = {12, 14, 54, 5, 6, 3, 9, 8, 47, 89, 67, 104, 25, 79};
    int len = sizeof(ar)/sizeof(int);
    bucket_sort(ar, 0, len-1);
    PrintArr(ar, len);
}
/*
4 3 0 0 0 1 1 0 0 0 1
4 7 7 7 7 8 9 9 9 9 10
5  6  3  8  12  14  9  47  54  89
0 4 7 7 7 7 8 9 9 9 9
5 6 3 8 12 14 9 47 54 89
3 5 6 8 9 12 14 47 54 89
*/