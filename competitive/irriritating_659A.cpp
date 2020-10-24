#include<bits/stdc++.h>
using namespace std;

string generate(int n,char x) {
    string ans;
    for(int i=0;i<n;i++) {
        ans+=x;
    }
    return ans;
}

char gennext(char x) {
    if(x!='z') {
        return (char)((int)x+1);
    } else return 'a';
}
int main() {
    int t;
    cin>>t;
    int n;
    while(t--) {
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        int i=0;
        vector<string> ans;
        if(a[i]!=0) {
            ans.push_back(generate(a[i],'a'));
            ans.push_back(generate(a[i],'a'));
        }
        else {
            ans.push_back("a");
            ans.push_back("d");
        }
        i++;
        while(i<n) {
            int temp = ans.size();
            if(a[i]!=0) {
                if(ans[temp-1].length() < a[i]) {
                    int extra = a[i] - ans[temp-1].length();
                    char end = 'a';
                    if(temp>=2 && a[i-2]>a[i-1] && a[i-1]<a[i]) {
                        int x=(int) ans[temp-2][a[i-1]];
                        x++;
                        x=x%97;
                        x+=97;
                        ans[temp - 1].append(extra,x);
                    }
                    else {
                        int x=(int) 'a';
                        x++;
                        x=x%97;
                        x+=97;
                        ans[temp - 1].append(extra, x);
                    }
                    ans.push_back(ans[temp-1]);
                }
                else  {
                    string tempo = ans[temp-1].substr(0,a[i]);
                    ans.push_back(tempo);
                }
            }

            else  {
                int temp = ans.size();
                if(ans[temp-1][0] == 'd') {
                    ans.push_back("a");
                }
                else {
                    ans.push_back("d");
                }
            }
            i++;
        }


        for(int k = 0;k<ans.size();k++) {
            cout<<ans[k]<<'\n';
        }
    }
}