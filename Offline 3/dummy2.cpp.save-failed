
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#define endl "\n"
#endif

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;

string dec_to_hex(string d_s)
{
    int decimal_value = stoi(d_s);

    stringstream ss;
    ss<< hex << decimal_value;
    string res ( ss.str() );

    return res;
}

string dec_to_hex_pad_trim(string d_s)
{
    string t = dec_to_hex(d_s);

    int n = t.size();

    if(n==1)
    {
        t = "0"+t;
        return t;
    }
    else if(n>2)
    {
        return t.substr(n-2,2);
    }

    return t;
}

void solve(string s)
{
    for(auto c:s)
    {
        cout<<c-'A'<<" : "<<dec_to_hex(to_string(c-'A'))<<endl;
    }
}

int stringHexToDec(string s)
{
    stringstream str;
    str << s;
    int value;
    str >> hex >> value;
    return value;
}


int32_t main()
{
    optimizeIO();

    cout<<dec_to_hex_pad_trim("-3")<<endl;
    cout<<dec_to_hex_pad_trim(to_string(-3))<<endl;
//    cout<<dec_to_hex_pad_trim("3")<<endl;
//    cout<<dec_to_hex_pad_trim("13")<<endl;
//    cout<<dec_to_hex_pad_trim("-13")<<endl;
//    cout<<dec_to_hex_pad_trim("-24")<<endl;

//        cout<<stringHexToDec("fa")<<endl;

    cout<<to_string(-110)<<endl;

//    int x;
//    std::cin >> std::hex >> x;
//    std::cout << x << std::endl;


    return 0;
}

/**

**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}

