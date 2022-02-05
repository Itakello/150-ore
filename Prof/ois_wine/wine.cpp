//https://training.olinfo.it/#/task/ois_wine/statement
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

// input data
int N;
long long K, deleted = 0;
vector<int> V;

// Subarr with sum less of threshold
int countSubarr(int threshold) {
	int count = 0, sum = 0;
	int left = 0, right = 0;
	while (right < V.size()) {
		sum += V[right];
		while (sum > threshold) {
			sum -= V[left];
			left++;
			}
		count += right - left + 1;
		right++;
		}
	return count;
	}

int kthSmallestSubarraySum(int k) {
	int low = *min_element(V.begin(), V.end());
	int high = accumulate(V.begin(), V.end(), 0);
	while (low < high) {
		int mid = (high - low) / 2 + low;
		long long count = countSubarr(mid);
		if (count < k) {
			low = mid + 1;
			deleted = count;
			}
		else
			high = mid;
		}
	return low;
	}

void findVal(int val) {
	priority_queue < ii, vii, greater<ii>> pq;

	int left = 0, right = 0, sum = 0;
	int min = INT32_MAX;
	while (right < V.size()) {
		sum += V[right];
		if (sum == val && V[left] < min) {
			// cout << "Inserted:" << left << " " << right << endl;
			pq.push(MP(left, right));
			}
		while (sum > val) {
			sum -= V[left];
			left++;
			if (sum == val && V[left] < min) {
				// cout << "Inserted:" << left << " " << right << endl;
				pq.push(MP(left, right));
				}
			}
		right++;
		}
	for (int i = 0; i < K - deleted - 1; i++) {
		// pair s = pq.top();
		pq.pop();
		// cout << s.F << " " << s.S << endl;
		}
	cout << pq.top().F << " " << pq.top().S << endl;
	}

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	V.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> V[i];
		}
	int val = kthSmallestSubarraySum(K);
	// cout << val << endl;
	// cout << "Del: " << deleted << " K: " << K << endl;
	findVal(val);
	return 0;
	}