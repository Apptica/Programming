/*
Saurabh Joshi
IIIT Jabalpur
*/
#include<bits/stdc++.h>
#define LL long long int
#define M 1000000007
#define endl "\n"
#define eps 0.00000001
LL pow(LL a,LL b,LL m){ a%=m;LL x=1,y=a;while(b > 0){if(b%2 == 1){x=(x*y);if(x>m) x%=m;}y = (y*y);if(y>m) y%=m;b /= 2;}return x%m;}
LL gcd(LL a,LL b){if(b==0) return a; else return gcd(b,a%b);}
LL gen(LL start,LL end){LL diff = end-start;LL temp = rand()%start;return temp+diff;}
using namespace std;
/****************************************/
//This algorithm finds all the bridges in a graph and adds them to a set
const int maxn = 100001;
vector<int> graph[maxn];
void find_bridges(int )

/****************************************/
int main()	{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, e;
    cin >> n >> e;
}