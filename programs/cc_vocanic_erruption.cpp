#include <cmath>
#include <bits/stdc++.h>
using namespace std;

vector<int> f(vector<int>& arr){
    int n = arr.size();
    stack<int> s;
    vector<int> b(n,0);
    s.push(0);
    for (int i= 0 ; i < n ; i++){
        if (arr[i] == 0){
            if (i == 0) s.pop();
            while(!s.empty()) {b[s.top()] = s.top() ; s.pop();}
            b[i] = -1 ; i++ ; if (i < n ) s.push(i) ; continue;
        }
        while (!s.empty() && arr[s.top()] < arr[i]){
            b[s.top()] = i ;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) {
        b[s.top()] = s.top() ;
        s.pop();
    }
    return b ;
}

int main() {
	// your code goes here
	int t , n, p ;
	cin >> t ;
	while(t--){
	    cin >> n >> p ;
	    vector<int> arr(n,0);
	    vector<int> b1(n,0);
	    vector<int> b2(n,0);
	    vector<int> ans(n,0);
	    for (int i = 0 ; i < n ; i++) cin >> arr[i] ;
	    b1 = f(arr);
	    reverse(arr.begin(),arr.end());
	    b2 = f(arr);
	   // for (int i = 0 ; i < n ; i++) cout << b1[i] ;
	   // cout << endl;
	    for (int i= 0 ; i < n ; i++) {
	        if (b2[i] != -1) b2[i] = n-b2[i] -1 ;
	    }
	    reverse(b2.begin(),b2.end());
	    reverse(arr.begin(),arr.end());
	   // for (int i = 0 ; i < n ; i++) cout << b2[i] ;
	   // cout << endl;
	   for (int i= 0 ; i < n ; i++) {
	       ans[i] = min(ceil(arr[b1[i]]/p),ceil(arr[b2[i]]/p));
	       //if (ans[i] < ceil(arr[i]/p)) ans[i] = ceil(arr[i]/p);
	   }
	   for (int i= 0 ; i < n ; i++) cout << ans[i] << " ";
	   cout << endl;
	}
	return 0 ;

}
