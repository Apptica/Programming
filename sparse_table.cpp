/*
Saurabh Joshi
PDPM IIITDM Jabalpur
*/
/*
Best problem to practice - > www.codechef.com/problems/FRMQ
also 1<<x means 2^x  (This line is for beginner only. You can replace that part with pow(2,j) also
*/
#include < bits / stdc++.h >
  using namespace std;
int a[100];
int n;
int dp[100][100];
int query(int L, int R) {
  //to query i will use the fact that decompose L and R into two overlapping ranges
  int y = log(R - L + 1) / log(2); //log base 2 of total elements in the range
  //this y means dp[L][y]
  int x = R - (1 << y) + 1;
  return min(dp[L][y], dp[x][y]);
}

void process() {
  int N = n;
  int i, j;
  int k = log(N) / log(2); //maximum value for which i + 2 to the power k is valid i.e. less than N
  //k is the maximum power of 2 for range formation
  //now for every i I will search for 2^j th range
  for (i = 0; i < N; ++i) {
    for (j = 0; j <= k; ++j)
      dp[i][j] = 999999999;
  }
  for (i = 0; i < N; ++i)
    dp[i][0] = a[i]; //the range i to i is the ith element itself
  for (j = 1; j <= k; ++j) {
    for (i = 0;
      (i + (1 << j) - 1) < N; ++i) {
      dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]); //1<<(j-1) means 2 to the power j-1 	
    }
  }
}

int main() {
  int i, n, q, L, R;
  cin >> n;::n = n;
  for (i = 0; i < n; ++i)
    cin >> a[i];
  cin >> q;
  process(); //make preprocessing
  while (q--) {
    cin >> L >> R;
    cout << query(L, R) << endl;
  }
}
