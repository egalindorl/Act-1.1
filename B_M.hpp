#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bad_character(string t, string p)
{
    int t_len=t.size();
    int p_len=p.size();
    int p_len_minus1=p_len-1;
    int skip=0;
    
    for (int i=p_len_minus1;i>p_len_minus1-p_len;i--)
    {
        string match;
        int pos=p_len_minus1;
        if (t[i]==p[i])
        {
            // cout<<t[i]<<"matchea con "<<p[i]<<endl;
            match.push_back(t[i]);
        }
        else 
        {
            // cout<<t[i]<<" no matchea con "<<p[i];
            for (int j=i;j>=0;j--)
            {
                if (t[i]==p[j])
                {
                    return skip;
                }
                else 
                skip++;
            }
            // cout<<"salta "<<skip<<" posiciones"<<endl;
            return skip;
            
        }
        if (match.size()==p_len)
        {
            match.push_back((p_len_minus1-p_len)-1);
            return -1;
        }
    }
}

vector<int> B_M (string T, string p)
{
    int T_len=T.size();
    int p_len=p.size();
    int p_len_minus1=p_len-1;

    vector<int> matches;
    
    int start=0;

    while (start <=T_len-p_len)
    {
        string t;
        for (int i=start;i<start+p_len;i++)
        {
            t.push_back(T[i]);
        }
        int skip=bad_character(t,p);
        if (skip==-1)
        {
            matches.push_back(start);
            start+=p_len;
        }
        start+=skip;
    }
    return matches;
}