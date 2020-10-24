#include<bits/stdc++.h>
using namespace std;
string test = "abacaba";
bool check(string s) {
    bool isposs = true;
    for(int i=0;i<7;i++){
        if(s[i]!=test[i] && s[i]!='?') {
            isposs = false;
            break;
        }
    }
    if(!isposs) {
        return false;
    }
    else{
        return true;
    }
}
int main() {
    int t;
    cin>>t;
    int n;
    string s;
    while(t--) {
        cin>>n;
        cin>>s;
        vector<int> pos;
        int maincnt=0;
        for(int i=0;i<=(n-7);i++){
            string r = s.substr(i,7);
            if(r == test) {
                maincnt++;
            }
        }
        if(maincnt>1) {
            cout<<"No"<<'\n';
            continue;
        }
        else if(maincnt==1) {
            cout<<"Yes"<<'\n';
            for(int i=0;i<n;i++) {
                if(s[i]=='?'){
                    s[i]='z';
                }
            }
            cout<<s<<'\n';
            continue;
        }
        else { //maincnt=0
            int cnt=0;
            for (int i = 0; i <= (n - 7); i++) {
                string r = s.substr(i, 7);
                bool res = check(r);
                if (res) {
                    cnt++;
                    pos.push_back(i);
                }
            }
            if (cnt == 0) {
                cout << "No" << '\n';
                continue;
            } else {
                bool got;
                int nposs = pos.size();
                for (int i = 0; i < nposs; i++) {
                    got = false;
                    string temp = s;
                    for (int j = pos[i], rap = 0; j < pos[i] + 7; j++, rap++) {
                        temp[j] = test[rap];
                    }
                    for (int k = 0; k < n; k++) {
                        if (temp[k] == '?') {
                            temp[k] = 'z';
                        }
                    }
                    int cnto = 0;
                    for (int k = 0; k <= (n - 7); k++) {
                        string r = temp.substr(k, 7);
                        if (r == test) {
                            cnto++;
                        }
                    }
                    if (cnto == 1) {
                        cout << "Yes" << '\n';
                        cout << temp << '\n';
                        got = true;
                        break;
                    }
                }
                if (!got) {
                    cout << "No" << '\n';
                }
            }
        }
    }
}