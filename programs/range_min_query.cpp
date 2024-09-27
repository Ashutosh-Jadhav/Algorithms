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

int range_min_query(int i ,int l,int r,int ss,int se,int seg_t[],int a[])  // l to r is query
{
    int mid, left , right ;
    mid = (ss+se)/2;
    if (l<=ss && r>=se)
    {
        return seg_t[i];
    }   
    else if (l>mid)
    {
        return range_min_query(2*i+2,l,r,mid+1,se,seg_t,a);
    }
    else if (r<=mid)
    {
        return range_min_query(2*i+1,l,r,ss,mid,seg_t,a);
    }
    left = range_min_query(2*i+1,l,r,ss,mid,seg_t,a);
    right = range_min_query(2*i+2,l,r,mid+1,se,seg_t,a);
    if (a[left] < a[right])
    {
        return left;
    }
    return right;
}

int main()
{
    int  l=0,r=0,n = 0 ;
    int min;
    cout << "Enter length of array : ";
    cin >> n ;
    r = n-1 ;
    int arr[n]={0};
    cout << "Enter array elements :" ;
    for (int i=0 ; i< n ; i++)
    {
        cin >> arr[i] ;
    }
    cout << "enter l and r (query range )  : ";
    cin >> l >> r ;
    //int arr[n] = {24,3,45,12,7,36,73,87} ;
    int segment_tree[2*n-1] = {0};
    segment_t(arr,segment_tree,n);
    min = range_min_query(0,l,r,0,7,segment_tree,arr);
    cout << min<< ","<<arr[min]<< endl;
}