#include <iostream>
using namespace std ;
int main()
{
    int t , n , k , res=0 ;
    cin >> t ;
    while (t>0)
    {
        t--;
        cin >> n >> k ;
        while (n>0)
        {
            if (n % 10 == k)
            {res++ ;}
            n = n/10 ;
        }
        cout << res << endl ;
        res = 0 ;
    }
}