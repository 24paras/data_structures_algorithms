#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {  
        cin >> n;
        vector<int> v1(n);
        unordered_map<int, int> m1;
        int x = 0LL;
        for(int i=0; i<n; i++)
        {
            cin >> v1[i];
        }

        for(int i : v1)
        {
            x ^= i;
            m1[i]=1;
        }

        int flag = 0;

        for(int j : v1)
        {
            int t=x^j;
            //cout << "t: " << t << endl;
            //cout << "m1[t]: " << m1[t] << endl;
            if(m1[t] != 1)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            cout << x << endl;
        }
        else
            cout << -1 << endl;
    }
}