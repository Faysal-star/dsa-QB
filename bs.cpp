#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
int main(){
    int n ; cin >> n ;
    int a[n+1] ;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;
    }
    int num ; cin >> num ;
    int l = 0 , r = n-1 , mid  ;
    sort(a,a+n) ;
    while(l <= r){
        mid = (l+r)/2 ;
        if(a[mid] > num) r = mid-1 ;
        else l = mid+1 ;
    }
    for(int i = n-1 ; i >= l ; i--){
        a[i+1] = a[i] ;
    }
    a[l] = num ;
    for(int i = 0 ; i < n+1 ; i++){
        cout << a[i] << " " ;
    }
}