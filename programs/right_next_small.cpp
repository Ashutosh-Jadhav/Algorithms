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

int next_small(int i , int a[], int segment_tree[],int n)
{
    int j = n -1+i ;
    int left,right,p ;
    p = (j-1)/2;
    while(p>=0 && j<2*n-1 )
    {
        if (j == 2*p+2)    // coming from Right
        {
            j=p;
            p = (p-1)/2;
        }
        else 
        {
            right = 2*p +2 ;
            if (a[segment_tree[right]] > a[i])
            {
                j=p;
                p = (p-1)/2 ;
            }
            else 
            {
                p = 2*p+2;
                if (p > n-2)
                {
                    return p+1-n ;
                }
                while (p<2*n+1)
                {
                    if (a[i]>a[segment_tree[2*p+1]])
                    {
                        
                        p = 2*p+1;
                        if (p > n-2)
                        return p+1-n ;
                    }
                    else 
                    {
                        p = 2*p+2;
                        if (p>n-2)
                        return p+1-n;
                    }
                }
            }
        }
    }
    return -1 ;
}

int main()
{
    int n = 8 , i = 0;
    int res ;
    int arr[] = {24,30,45,120,107,36,110,87};
    int segment_tree[2*n - 1] = {0};
    segment_t(arr,segment_tree,n);
    res = next_small(i,arr,segment_tree,n) ;  // i indexing start with 0 
    cout << res << " " << arr[res] << endl;
}