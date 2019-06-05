#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s)
{
    s.erase(remove(s.begin(),s.end(),' '),s.end()); //Remove all white spaces

    int L = s.size();
    int LB = floor(sqrt(L));
    int UB = ceil(sqrt(L));

    int r = LB;
    int c = LB;
    while(r*c < L)
    {
        c++;
        if(c>UB)
        {
            r++;
            c = r;
        }
    }
    string sout[r][c];
    string sfinal;
    int K=0;
    for(int i=0; i<r; ++i)
    {
        for(int j=0; j<c; ++j)
        {
            if(K<L)
            {
                sout[i][j] = s[K];
            }
            else
            {
                sout[i][j] = {' '};
            }
            K++;
        }
    }
    for(int i=0; i<c; ++i)
    {
        for(int j=0; j<r; ++j)
        {
            sfinal.append(sout[j][i]);
        }
        if(sout[r-1][i]!=" ")
            sfinal.append(" ");
    }
    return sfinal;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    cout << result << "\n";

    //fout.close();

    return 0;
}
