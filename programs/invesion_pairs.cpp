#include <iostream>
using namespace std ;

int arr[] = {23,70,55,48,39,91};

void print_array(int a[],int n)
{
    for (int i ; i < n; i++)
    {
        cout << a[i] << " " ;
    }
    cout << endl ;
}

int merge(int l , int r)
{
    int n , p=0 , e=0 , k = l,j = (l+r)/2 + 1 ;
    n = r-l+1 ;
    cout << n << " " << p << " "<< k  <<" " << j << endl;
    int auxilary[n] ;
    for (int i = 0 ; i<n ; i++)
    {
        auxilary[i] = arr[k++];
    }
    k=l;
    while (p<=(l+r)/2 &&  j<= r )
    {
        if (auxilary[p] > auxilary[j])
        {
            arr[k++] = auxilary[j++];
            e += ((l+r)/2) - k +1 ;
        }
        else 
        {
            arr[k++] = auxilary[p++];
        }
    }
    while(p<=(l+r)/2 )
    {
        arr[k++] = auxilary[p++];
    }
    while(j<=r )
    {
        arr[k++] = auxilary[j++];
    }
    // print_array(auxilary,r-l+1);
    cout << n << " " << p << " "<< k  <<" " << j << endl << endl;

    return e ;
}

int ip(int l,int r)
{
    if (l<r)
    {
        return ip(l,(l+r)/2) + ip((l+r)/2 +1 , r) + merge(l,r);
    }
    return 0 ;
}

int main()
{
    print_array(arr,6);
    int res ;
    res = ip(0,5);
    // cout << res << endl;
    print_array(arr,6);

}