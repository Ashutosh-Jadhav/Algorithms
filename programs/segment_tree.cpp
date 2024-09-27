#include <iostream>
using namespace std ;
int main()
{
    int n = 8 ,i =0;
    int arr[n] = {24,3,45,12,7,36,73,87};
    int segment_tree[2*n-1] = {0};
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