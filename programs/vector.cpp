#include <iostream>
#include <vector>
using namespace std ;

int main()
{
    vector<int> myvector;
    for (int i = 0 ; i < 10 ; i++ )
    {
        myvector.push_back(i);
    }
    for (int i = 0 ; i < myvector.size() ; ++i)
    {
        cout << myvector[i] << " " ;
    }
    cout << endl ;
    for (int i = 0 ; i < 5 ; i++)
    {
        
    }
    
}