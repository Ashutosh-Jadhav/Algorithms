#include <iostream>
#include <math.h>
using namespace std ;

int count_lattice_above(float r,float k)
{
    int x,y,r1,count = 0 ;
    r1 = int(r);
    y = r1 ;
    for(x = 1 ; x<r1+1;x++)
    {
        while(pow(x,2)+pow(y,2) > pow(r,2) ) y-- ;
        if (y-k >=0){
            count = count+y-k;
        }
    }
    return 2*count+r1-k ;
}

int count_total(float r)
{
    int x,y,r1,count = 0 ;
    r1 = int(r);
    y = r1 ;
    for (x = 1 ; x<r1+1;x++)
    {
        while(pow(x,2)+pow(y,2) > pow(r,2) ) y-- ;
        count = count + y + 1;
    }
    return 4*count+1;
}

int main(){
    float r,k; 
    int k1,res,r1,k2,flag = 0 ;
    cin >> r >> k ;
    k2 = (int)k;
    if (k != k2){
        flag = 1;
    }
    k2 = (-1)*k;
    r1 = (int)r;
    if (k>r1){
        res = count_total(r);
        // cout << "1"<<endl;
    }
    else if (k>=0 ){
        k1 = int(k);
        res = count_lattice_above(r,k1);
        // cout << "2"<<endl;
    }
    else if (k2>r){
        res = count_total(r);
        // cout << "3"<<endl;    
        }
    else {
        k1 = (int)k2;
        if (flag == 1){
            k1 = k1-1;
        }
        // cout << count_total(r)<<endl;
        // cout << count_lattice_above(r,k1) <<endl ;
        res = count_total(r) - count_lattice_above(r,k1);
        // cout << "4"<<endl;
    }
    cout<< res << endl;
    return 0 ;
}