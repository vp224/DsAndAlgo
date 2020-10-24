#include<bits/stdc++.h>
using namespace std;
struct Compare {
    // priority queue is max heap by default, use compare
    // to make it minheap
    bool operator() (const int& a, const int& b) {
        return a>b;
    }
};

typedef priority_queue<int, vector<int>, Compare> pqSize;
void priorityQueueFixedSize(pqSize& pq, int size, vector<int>& vec) {
    for (int i=0;i<vec.size();i++) {
        if (pq.size() < size) {
            pq.push(vec[i]);
        } else {
            if (vec[i] > pq.top()) {
                pq.pop();
                pq.push(vec[i]);
            }
        }
    }
}

bool printPQ(pqSize pq, int x) {
    while (!pq.empty()) {
//        cout << pq.top() << " ";
        if(pq.top()==x) {
            return true;
        }
        pq.pop();
    }
    return false;
//    cout << endl;
}

int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    int q;
    cin>>q;
    pqSize pq;
    vector<int> a(n);
    unordered_map<int,int> um;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        um[a[i]]=i+1;
    }
    int typ;
    int id;

    while(q--) {
        cin>>typ;
        cin>>id;
        if(typ==1) {
            if (pq.size() < k) {
                pq.push(a[id-1]);
            } else {
                if (a[id-1] > pq.top()) {
                    pq.pop();
                    pq.push(a[id-1]);
                }
            }
        }
        else {
            bool res = printPQ(pq, a[id-1]);
            if(res) {
                cout<<"YES"<<'\n';
            }
            else {
                cout<<"NO"<<'\n';
            }
        }
    }
}