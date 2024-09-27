// update query for segment tree

#include <iostream>
using namespace std ;

void segment_t(int arr[],int segment_tree[],int n)
{
    //int n = 8 ,i =0;
    int i = 0 ;
    //int arr[n] = {24,3,45,12,7,36,73,87};
    //int segment_tree[2*n-1] = {0};
    for (int j = -1 ; j < n-1 ; j++)
    {
        segment_tree[n+j] = j+1;
    }
    i = n - 2 ;
    while (i>=0)
    {
        if (arr[segment_tree[2*i + 1]] > arr[segment_tree[2*i + 2]])
        {
            segment_tree[i] = segment_tree[2*i + 2];
        }
        else
        {
            segment_tree[i] = segment_tree[2*i + 1];
        }
        i--;
    }
    for (int j = 0 ; j < 2*n - 1 ; j++)
    {
        cout << segment_tree[j] << " ";
    }
    cout << endl ;
}

void update(int i , int x,int arr[],int segment_tree[],int n)
{
    int j = n-1 + i ;
    int left , right ;
    arr[i] = x ;
    int p = (j-1)/2 ;
    while (p>0)
    {
        left = 2*p + 1;
        right = 2*p+2;
        if (arr[segment_tree[left]] < arr[segment_tree[right]])
        {
            segment_tree[p] = segment_tree[left];
        }
        else 
        {
            segment_tree[p] = segment_tree[right] ;
        }
        p = (p-1)/2;
    }
    left = 2*p + 1;
    right = 2*p+2;
    if (arr[segment_tree[left]] < arr[segment_tree[right]])
    {
        segment_tree[p] = segment_tree[left];
    }
    else 
        {
            segment_tree[p] = segment_tree[right] ;
        }
}

int main()
{
    int n=8 ;
    int i=1,x = 35;
    // printf("Enter size of array : ");
    // cin >> n ;
    int arr[n] = {24,3,45,12,7,36,73,87} ;
    int segment_tree[2*n + 1] = {0} ;
    // printf("Enter array elements : ");
    // for(int i = 0 ; i < n ; i++)
    // {
    //     cin >> arr[i] ;
    // }
    segment_t(arr,segment_tree,n);
    update(i,x,arr,segment_tree,n);  // ith index, index starting with 0 .
    for (int k = 0 ; k < 2*n-1 ; k++)
    {
        cout << segment_tree[k] << " " ;
    }
    cout << endl ;
    for (int k = 0 ; k<n;k++)
    {
        cout << arr[k]  << " "; 
    }
    cout << endl ;
}