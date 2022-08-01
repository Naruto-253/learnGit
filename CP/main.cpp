#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define WhoCare ios_base::sync_with_stdio(false);cin.tie(NULL);
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy8[8] = {1, -1, 0, 1, -1, 1, -1, 0};

const int N = 1e6 + 7, LGN = __lg(N) + 1;

int main() {


    WhoCare


    int tc;

    cin >> tc;

    while(tc--) {



        string t;

        vector<pair<int, pair<string, int>>>v, V; // sz , match



        cin >> t;

        int n;
        cin >> n;

        set<int>st;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            int same = 0;
            for(int j = 0; j <t.size(); j++) {
                if(s[j] == t[j])
                    same++;
                else break;
            }


            V.push_back({same, {s, i}});
            v.push_back({s.size(), {s, i}});

            st.insert(s.size());

        }


        if(st.size() == 1)
        {

            v = V;
            sort(v.rbegin(), v.rend());
        }
        else
        sort(v.begin(), v.end());


        int sz = t.size();

        bool red[sz] = {0};

        set<pair<int, int>>ans;
        for(pair<int, pair<string, int>>x : v) {

            for(int i = 0; i < sz; i++) {
                if(i + x.S.F.size() - 1 >= sz)break;

                bool ok = 1;
                int idx = 0;
                for(int j = i; j < i + x.S.F.size(); j++) {
                    ok &= (t[j] == x.S.F[idx++] && red[j] == 0);
                }

                if(ok) {
                    ans.insert({x.S.S + 1, i + 1});
                    for(int j = i; j < i + x.S.F.size(); j++) {
                        red[j] = 1;
                    }
                    i = i + x.S.F.size() - 1;
                }

            }


        }

        for(pair<int, pair<string, int>>x : v) {

            for(int i = 0; i < sz; i++) {
                if(i + x.S.F.size() - 1 >= sz)break;

                bool ok = 1;
                int idx = 0;
                bool atleast = 0;
                for(int j = i; j < i + x.S.F.size(); j++) {
                    ok &= (t[j] == x.S.F[idx++]);
                    atleast |= (red[j] == 0);
                }

                if(ok && atleast) {
                    ans.insert({x.S.S + 1, i + 1});
                    for(int j = i; j < i + x.S.F.size(); j++) {
                        red[j] = 1;
                    }
                }

            }


        }



        bool f = 1;

        for(int i = 0; i < sz; i++)
            f &= (red[i] == 1);

        if(f) {
            cout << ans.size() << "\n";
            for(auto x : ans)
                cout << x.F << ' ' << x.S << "\n";
        } else
            cout << "-1\n";


    }

    return 0;
}
