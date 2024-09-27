#include <iostream>
#include <math.h>
using namespace std ;

int main()
{
    float r,k;
    int r1,count=0 ;
    int y,x,tot,res,k1,flag=0;
    cin >> r >> k ;

    k1 = (int)k; r1 = int(r);
    if (k != k1){
        flag = 1 ;
    }
    // cout << flag << endl;
    k = (int)k ;
    cout << k<< endl;
    if (k>=0){
        y = r1 ;
        for(x = 1 ; x<r1+1;x++)
        {
            while(pow(x,2)+pow(y,2) > pow(r,2) ) y-- ;
            if (y-k >=0){
                count = count+y-k;
            }
        }
        cout <<  2*count+r1-k <<endl;
    }
    else{
        y = r1;
        for(x = 1;x<r1+1;x++)
        {
            while(pow(x,2)+pow(y,2)>pow(r,2)) y--;
            count= count+y+1;
        }
        tot = 4*count + 1;
        // cout << tot << endl;
        count = 0 ;
        k = -1*k;
        if (flag == 1 ){
        k = k+1;}
        cout << k <<endl;
        y = r1 ;
        for(x = 1 ; x<r1+1;x++)
        {
            while(pow(x,2)+pow(y,2) > pow(r,2) ) y-- ;
            if (y-k >=0){
                count = count+y-k+1;
            }
        }
        res = 2*count +r1-k+1;
        // cout << res <<endl;
        cout << tot - res << endl ;
        
    }
}