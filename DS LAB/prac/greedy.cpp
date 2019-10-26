#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; 
	cin >> n >> k;
    vector<int> tower(n);
    for(int i = 0; i < n; ++i)
        cin >> tower[i];
    
    int count = 0,  last = -1, front = -1;
    while(front < n-1) {
        int seek = min(front+k, n-1);
        cout<<seek<<endl;
        while(seek > last && tower[seek] == 0)
            seek -= 1;

        if(seek == last) {
            count = -1;
            break;
        }
    
        count += 1;
        last = seek;
        front = seek + k - 1;
    }
    cout << count << endl;
    return 0;
}

