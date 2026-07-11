/*
Solution:
The problem asks for the lexicographically smallest permutation.
This implies a greedy strategy:
1. Try to make p[0] as small as possible.
2. Then, try to make p[1] as small as possible.
3. And so on...

The operation allows us to change p[i] only if:
- p[i] = v + 2
- We can find j, k such that i < j < k
- {p[j], p[k]} = {v, v+1}

If these conditions hold, we can apply the operation:
- p[i] becomes v (p[i] - 2)
- p[j] becomes p[j] + 1
- p[k] becomes p[k] + 1

This operation is *always* beneficial for minimizing p[i], as it
reduces its value. Therefore, for each `i` from 0 to n-3, we should
repeatedly apply this operation as long as we can.

Algorithm:
1. Store the permutation `p` and an array `pos` where `pos[v]` 
   stores the index of value `v`.
2. Iterate with `i` from 0 to n-3.
3. Inside, run a `while(true)` loop to repeatedly reduce `p[i]`.
4. Let `v = p[i] - 2`. If `v < 1`, we can't form a valid triplet 
   {v, v+1, v+2}, so we `break` the inner loop.
5. Find the indices of `v` and `v+1`:
   `idx_v = pos[v]`
   `idx_v_plus_1 = pos[v + 1]`
6. Let `j = min(idx_v, idx_v_plus_1)` and `k = max(idx_v, idx_v_plus_1)`.
7. The condition `i < j < k` must hold. Since `j < k` is guaranteed 
   (as v != v+1), we just need to check `i < j`.
8. If `i < j`:
   - Perform the operation.
   - Store the old values: `val_j = p[j]`, `val_k = p[k]`.
   - Update `p`: 
     `p[i] = v`
     `p[j] = val_j + 1`
     `p[k] = val_k + 1`
   - Update `pos`:
     `pos[v] = i`
     `pos[val_j + 1] = j`
     `pos[val_k + 1] = k`
   - `continue` the `while` loop to see if we can reduce the new `p[i]` (which is `v`) even further.
9. If `i >= j`:
   - The condition `i < j < k` fails. We cannot reduce `p[i]` any more.
   - `break` the inner loop and move to the next `i`.

This algorithm has a total complexity of O(N^2) because the outer
loop runs N times, and the inner `while` loop can run at most O(N)
times (since p[i] decreases by 2 each time). The sum of N^2 over
all test cases is bounded, so this is fast enough.
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // p: 0-based index, stores the permutation value
    vector<int> p(n);
    // pos: 1-based index (for value), stores 0-based index (position)
    vector<int> pos(n + 1); 
    
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    // Iterate i from 0 to n-3 (corresponds to 1-based index 1 to n-2)
    for (int i = 0; i < n - 2; ++i) {
        // Repeatedly try to reduce p[i]
        while (true) {
            // Check if p[i] can be the 'v+2' part
            int v = p[i] - 2;
            
            // If v < 1, then v and v+1 are not valid permutation values (1..n)
            if (v < 1) {
                break;
            }

            // Find the 0-based indices of values v and v+1
            int idx_v = pos[v];
            int idx_v_plus_1 = pos[v + 1];

            // j must be the smaller index, k the larger
            int j = min(idx_v, idx_v_plus_1);
            int k = max(idx_v, idx_v_plus_1);

            // Check the condition i < j < k.
            // Since j < k is guaranteed (v != v+1), we just check i < j.
            if (i < j) {
                // Condition holds. Perform the operation.
                
                // Get the values at j and k before they are changed
                int val_j = p[j]; // This is either v or v+1
                int val_k = p[k]; // This is the other one

                // Calculate the new values
                int new_val_i = v;
                int new_val_j = val_j + 1; // Will be v+1 or v+2
                int new_val_k = val_k + 1; // Will be v+2 or v+1

                // Update the permutation array
                p[i] = new_val_i;
                p[j] = new_val_j;
                p[k] = new_val_k;

                // Update the position array
                pos[new_val_i] = i;
                pos[new_val_j] = j;
                pos[new_val_k] = k;

                // Continue the while loop to try and reduce p[i] (now v)
                // even further.
            } else {
                // Condition i < j fails. We cannot use this (v, v+1) pair.
                // Since this is the only pair that could reduce p[i] to v,
                // and we're checking v in descending order, we can't
                // reduce p[i] any more.
                // (Note: The `while` loop implicitly checks in descending order)
                break;
            }
        }
    }

    // Print the final, lexicographically smallest permutation
    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}