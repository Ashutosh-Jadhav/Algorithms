#include <iostream>
using namespace std ;
int TopDown(int n ,int arr[]){
    // int arr[n+1] = {-1};
        // arr[0] = 0 ;
        // arr[1] = 1 ;
        if (n == 0 || n == 1){
            return arr[n];
        }
        if (arr[n]!=0){
            // cout<<"yes"<<endl;
            return arr[n];
        }
        // cout << "no"<<endl;
        return arr[n]=TopDown(n-1,arr) + TopDown(n-2,arr) ;
}

int main()
{

    int n = 20 ;
    int arr[n+1]={0};
    int arr1[n+1]={0};
    arr1[1] = 1 ;
    arr[1] = 1 ;
    // cout << arr[2] << endl ;
    for (int i = 2 ; i < n+1 ; i++)
    {
        arr1[i] = arr1[i-1] + arr1[i-2] ;
        // cout<<i << " : "<<arr1[i]<<endl;
    }
    // cout<<arr[n-1]<<endl; 
    cout <<"Top Down : "<< TopDown(n,arr) << endl;
    cout << "BottomUp : " << arr1[n]<<endl;
}
