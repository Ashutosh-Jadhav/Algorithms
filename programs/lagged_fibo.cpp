#include <iostream>
#include <math.h>
using namespace std ;

// void print_array(int p[][100] ,int n )
// {
//     for(int i = 0 ; i < n ; i++ )
//     {
//         for (int j = 0 ; j<n ; j++)
//         {
//             cout << p[i][j] ;
//         }
//         cout << endl;
//     }
// }

void matrix_pow(int a[][100],long long n)
{
    int i,j ,count=0,no_of_odds = 0;
    int temp[100][100] = {0};
    int c[100][100] = {0} ;

    //base case
    if (n == 2){
        for (i = 0;i<100 ; i++){
            for (j = 0 ; j<100;j++){
                temp[i][j] = a[i][j];
            }
        }
        for(i = 0 ; i<100; i++){
            for(j=0;j<100;j++){
                a[i][j] = 0 ;
                for (int k = 0 ; k<100;k++){
                    a[i][j] += temp[i][k] * temp[k][j];
                }
            }
        }

        
    }
    else if (n == 1){

    }
    //recursive starts
    else if (n%2 ==1)
    {
        for (i = 0; i<100;i++)
        {
            for (j = 0 ; j< 100 ; j++)
            {
                temp[i][j] = a[i][j];
            }
        }
        matrix_pow(a,n-1);
        for (i = 0; i<100;i++){
            for (j = 0;j<100;j++){
                for(int k = 0; k<100 ; k++){
                    c[i][j]  += temp[i][k] * a[k][j];
                }
            }
        }
        for (i = 0 ; i < 100 ; i++){
            for(j = 0 ; j< 100 ; j++){
                a[i][j] = c[i][j];
                c[i][j] = 0 ;
            }
        }
    }
    else {
        matrix_pow(a,n/2);
        for (i = 0;i<100 ; i++){
            for (j = 0 ; j<100;j++){
                temp[i][j] = a[i][j];
            }
        }
        for(i = 0 ; i<100; i++){
            for(j=0;j<100;j++){
                a[i][j] = 0 ;
                for (int k = 0 ; k<100;k++){
                    a[i][j] += temp[i][k] * temp[k][j];
                }
            }
        }
    }
    //recursive ends


    //Iterative stars
    // if (n%2 == 1){
    //     n = n -1 ;
    //     no_of_odds++ ;
    // }
    // while (n>0)                  //copying array in temp
    // {
    //     for (i=0;i<100;i++)
    //     {
    //         for (j = 0 ; j< 100 ;j++)
    //         {
    //             temp[i][j] = a[i][j];
    //         }
    //     }
    //     n = n/2;
    //     if (n%2 == 1){
    //         n = n-1 ;
    //         no_of_odds++;
    //     }
    //     count++;
    //     for (i = 0 ; i < 100 ; i++){
    //         for(j = 0 ; j<100;j++){
    //             a[i][j] = 0;
    //             for (int k=0 ; k<100 ; k++ ){
    //                 a[i][j] += temp[i][k] * temp[k][j] ;
    //             }
    //         }
    //     }
    // }
    // cout << count <<" "<< no_of_odds << endl ;
    //iterative ends
}

int main()
{
    int arr[100][100] = {0} ;
    int i=1,j=0 ;
    long long res=0;
    long long n ;
    cin >> n ;
    if (n>99){
        arr[0][98] = 1 ; arr[0][99] = 1;
        while (i<100)
        {
            arr[i++][j++] = 1 ;
        }
    
        matrix_pow(arr,n-99); 
        // print_array(arr,100);
        for (i = 0 ; i<100;i++){
            res += arr[0][i]*(100-i-1);
        }
        cout << res << endl;
    }
    else{
        cout << n << endl;
    }
    return 0 ;
}