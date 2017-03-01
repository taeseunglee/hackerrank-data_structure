#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    
    vector<int> *seq_list = new vector <int> [n];
    
    int last_ans = 0;
    for (int query_i = 0; query_i < q; ++query_i) {
        int q_type, x, y;
        scanf("%d %d %d", &q_type, &x, &y);
        
        int idx = (x^last_ans)%n;
        if (q_type%2) { // q_type : 1
            seq_list[idx].push_back(y);
        }
        else { // q_type : 2
            last_ans = seq_list[idx][y%seq_list[idx].size()];
            printf("%d\n", last_ans);
        }
    }
    
    return 0;
}
