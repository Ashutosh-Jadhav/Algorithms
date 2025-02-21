#include <cmath>
#include <bits/stdc++.h>
using namespace std;

vector<double> f(vector<double>& arr){
    int n = arr.size();
    stack<int> s;
    vector<double> b(n,0);
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

int func(int i,int rf , int lf,int p , vector<double>& arr , vector<double>& b1,vector<double>& b2,vector<int> &ans)
{
    // if (i == 0 || i >=arr.size()) return 0 ;
    if (b1[i] == b2[i] && b1[i] == i) return ans[i] = arr[i]/p;
    if (ans[i] != -1) return ans[i];
    if (rf==1 && lf==1) return ans[i] = min(func(b1[i],rf,lf,p,arr,b1,b2,ans) , func(b2[i],rf,lf,p,arr,b1,b2,ans));
    else if(rf==1 && lf==0) return ans[i] = func(b1[i],rf,lf,p,arr,b1,b2,ans);
    else return ans[i] = func(b2[i],rf,lf,p,arr,b1,b2,ans);
}

int main() {
	// your code goes here
	double t , n, p ;
	cin >> t ;
	while(t--){
	    cin >> n >> p ;
	    vector<double> arr(n,0);
	    vector<double> b1(n,0);
	    vector<double> b2(n,0);
	    vector<int> ans(n,-1);
	    int r_f,l_f,r_in;
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
	   r_f = 1 ; l_f = 0 ;
	   for (int i = 0 ; i < n ; i++) if (arr[n-i-1] == 0) { r_in = n-i-1;break; }
	   for (int i= 0 ; i < n ; i++) {
	       if (i > r_in) r_f = 0 ;
	       if (arr[i] == 0 && l_f == 0) l_f = 1 ;
	       if (arr[i] != 0 ) func(i,r_f,l_f,p,arr,b1,b2,ans);
	   }
	   for (int i= 0 ; i < n ; i++) {
	       if (arr[i] == 0) ans[i] = 0;
	   }
	   for (int i= 0 ; i < n ; i++) cout << ans[i] << " ";
	   cout << endl;
	}
	return 0 ;

}
