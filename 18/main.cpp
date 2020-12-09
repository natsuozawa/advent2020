#include <iostream>
#include <vector>

using namespace std;

const int valid = 31161678;
const long long INF = 1e15;

int main() {
  vector<long long> seq;
  while (!cin.eof()) {
    long long n; cin >> n;
    seq.push_back(n);
    if (seq.size() == 1000) break;
  }

  vector<long long> cumsum(seq.size() + 1);
  cumsum[0] = 0;
  for (int i = 0; i < seq.size(); i++) {
    cumsum[i + 1] = cumsum[i] + seq[i];
  }

  for (int i = 0; i < seq.size(); i++) {
    for (int j = i + 2; j <= seq.size(); j++) {
      if (cumsum[j] - cumsum[i] == valid) {
        long long mn = INF; 
        long long mx = 0;
        for (int k = i; k < j; k++) {
          mn = min(mn, seq[k]);
          mx = max(mx, seq[k]);
        }
        cout << mn + mx << endl;
        return 0;
      }
    }
  }
}