#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b) {
    // if (b == 0) return a;
    long long temp;
    if (b > a) {temp = b ; b = a ; a = temp;}
    if (b == 0) return a;
    // if (a % b == 0) return b;
    else return gcd(b,a%b);
}
int main(){
    long long t,a,b,c,d,h1,h2,h3,h4,ans;
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d;
        ans = 0;
        h1 = gcd(a,b);
        h2 = gcd(c,d);
        a = a/h1; b = b/h1;
        c = c/h2; d = d/h2;
        h3 = gcd(a,c);
        h4 = gcd(b,d);
        if (a == c) ans += 0;
        else if (h3 == a || h3 == c) ans++;
        else ans += 2;
        if (b == d) ans+=0;
        else if (h4 == b || h4 == d) ans++;
        else ans += 2;
        cout << ans << endl;
    }
    return 0;
}