#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N = 500005;
int n, m, w;
ll k, a[N], b[N], c[N];

void gb(int l, int mid, int r){
    int i = l, j = mid + 1;
    for(int k = 1; i <= r; k++)
        if(j > r || (i <= mid && b[i] <= b[j]) ) c[k] = b[i++];
        else c[k] = b[j++];
}

ll f(int l, int r){
    if(r > n) r = n;
    for(int i = w + 1; i <= r; i++)b[i] = a[i];
    sort(b + w + 1, b + r + 1);
    gb(l, w, r);
    ll ans = 0;
    int t = m;
    while(t && l<r){
        ans += (c[r]- c[l])*(c[r--] - c[l++]);
        t--;
    }
    return ans;
}

void Genius_ACM(){
    cin >> n >> m;
    cin >> k;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    int ans = 0, l = 1, r = 1;
    w = 1;
    b[1] = a[1];
    while(l <= n){
        int p = 1;
        while(p){
            ll num = f(l, r+p);
            if(num <= k){
                w = r = min(r+p, n);
                for(int i = 1; i <= r; i++) b[i] = c[i];
                if( r == n)break;
                p <<= 1;

            }else p >>= 1;
        }
        ans++;
        l = r + 1;
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) Genius_ACM();
    return 0;

}
