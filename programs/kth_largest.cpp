#include <iostream>
#include <cstdlib>
using namespace std ;

int partition(int *t, int l, int r)
{
    int temp,i = l,j = l ;
    while (j < r)
    {
        if (t[j] < t[r])
        {
            temp = t[j]; t[j] = t[i] ; t[i] = temp ;
            i++;   
            j++ ;
        }
        else 
        {
            j++;
        }
    }
    temp = t[r] ; t[r] = t[i] ; t[i] = temp ;
    return i;
}

int find_kth_largest(int *p, int l, int r, int k)
{
    int res,pivot,temp ;
    pivot = rand();
    // cout << "pivot "<<pivot<<endl;
    temp = pivot % (r-l+1);
    pivot = temp;
    // cout << "pivot " << pivot << " val : "<<r-l+1<< endl;
    pivot = pivot + l ;
    // cout << "pivot " << pivot << endl ;
    temp = p[pivot] ; p[pivot] = p[r] ; p[r] = temp;
    if (l < r)
    {

        res = partition(p,l,r);
        // cout << "res " << res << " : r-k+1 " << r-k+1<<endl;
        if (res == r - k + 1) 
        {
            // cout << "res " << res << " : r-k+1 " << r-k+1;
            return res ;
        } 
        else if(res < r - k + 1)
        {
            return find_kth_largest(p,res+1,r,k);
        }
        return find_kth_largest(p,l,res-1,k-r+res-1);
    }
    return l ;
}


int main()
{
    int res ,n,k,i ;
    cin >> n >> k ;
    int arr[n] ;
    for(int j = 0 ; j<n ; j++)
    {
        cin >> i ;
        arr[j] = i;
    }
    res = find_kth_largest(arr,0,n-1,k);
    cout << arr[res] << endl ;
    // for (auto x : arr) cout << x <<endl;
    return 0 ;
} // Sooooo Happy