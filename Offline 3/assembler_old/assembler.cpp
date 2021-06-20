
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("in.txt", "r", stdin)
#define WRITE       freopen("out.txt", "w", stdout)

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

/**

R : add  , sub  , and  , or  , sll , srl , nor
I : addi , subi , andi , ori , sw  , lw  , beq ,  bneq
J : j

**/

string lower(string s)
{
    string ret;

    for(auto c:s) ret += tolower(c);

    return ret;
}

string remove_whitespace(string str)
{
    string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());
    return str;
}

vector<string> tokenize(string const str,char delim)
{
    vector<string> ret;

    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        ret.push_back(str.substr(start, end - start));
    }

    return ret;
}

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

    READ;
    WRITE;

    vector<string>instructions = {"add"  , "sub"  , "and"  , "or"  , "sll" , "srl" , "nor" , "addi" , "subi" , "andi" , "ori" , "sw"  , "lw"  , "beq" ,  "bneq" , "j"};
    vector<string>instructionsR = {"add"  , "sub"  , "and"  , "or"  , "sll" , "srl" , "nor"};
    vector<string>instructionsI = {"addi" , "subi" , "andi" , "ori" , "sw"  , "lw"  , "beq" ,  "bneq"};


    map<string,string>MAP_REG_ADD;

    /// in hex
    MAP_REG_ADD["$zero"] = "0";
    MAP_REG_ADD["$t0"]   = "1";
    MAP_REG_ADD["$t1"]   = "2";
    MAP_REG_ADD["$t2"]   = "3";
    MAP_REG_ADD["$t3"]   = "4";
    MAP_REG_ADD["$t4"]   = "5";
    MAP_REG_ADD["$t5"]   = "6";
    MAP_REG_ADD["$sp"]   = "7";

    map<string,string>MAP_INS_OPC;

    /// in hex
    MAP_INS_OPC["add"]   = "e";
    MAP_INS_OPC["sub"]   = "9";
    MAP_INS_OPC["and"]   = "8";
    MAP_INS_OPC["or"]    = "b";
    MAP_INS_OPC["sll"]   = "3";
    MAP_INS_OPC["srl"]   = "c";
    MAP_INS_OPC["nor"]   = "2";
    MAP_INS_OPC["addi"]  = "7";
    MAP_INS_OPC["subi"]  = "f";
    MAP_INS_OPC["andi"]  = "4";
    MAP_INS_OPC["ori"]   = "5";
    MAP_INS_OPC["sw"]    = "0";
    MAP_INS_OPC["lw"]    = "d";
    MAP_INS_OPC["beq"]   = "1";
    MAP_INS_OPC["bneq"]  = "a";
    MAP_INS_OPC["j"]     = "6";

    map<string,string>MAP_LABEL_ADD;

    map<string,string>label_rem;
    map<string,int>MAP_INSTRUCTION_COUNTER;

    vector<string>machine_code;

    string ins,og;

    int counter = 0;

    while(cin>>ins)
    {
        og = ins;
        ins = lower(ins);

        counter = machine_code.size();

//        DBG(ins);

//        if(ins=="exit") break;

        if(find(ALL(instructionsR),ins) != instructionsR.end()) /// R type
        {
            string info;
            getline(cin, info);

            info = remove_whitespace(info);
            vector <string> res = tokenize(info,',');

            string dest_reg  = res[0];
            string src_reg_1 = res[1];
            string src_reg_2 = res[2];

            string opcode = MAP_INS_OPC[ins];
            string sh_amt = "0";

            string output = "";

            output = MAP_INS_OPC[ins] + MAP_REG_ADD[src_reg_1] + MAP_REG_ADD[src_reg_2] + MAP_REG_ADD[dest_reg] + sh_amt;

            if(ins == "sll" || ins == "srl")
            {
                sh_amt = dec_to_hex(src_reg_2);
                output = MAP_INS_OPC[ins] + MAP_REG_ADD[src_reg_1] + "0" + MAP_REG_ADD[dest_reg] + sh_amt;
            }

            machine_code.push_back(output);

//            DBG(output);

        }
        else if(find(ALL(instructionsI),ins) != instructionsI.end()) /// I type
        {
            string info;
            getline(cin, info);

            info = remove_whitespace(info);
            vector <string> res = tokenize(info,',');

            string dest_reg = res[0];
            string src_reg  = res[1];

            string opcode = MAP_INS_OPC[ins];

            string output = "";

            if(ins=="addi" || ins=="subi" || ins=="andi" || ins=="ori")
            {
                string add_imm  = res[2];
                string t = dec_to_hex_pad_trim(add_imm);

                output = MAP_INS_OPC[ins] + MAP_REG_ADD[src_reg] + MAP_REG_ADD[dest_reg] + t;

            }
            else if(ins=="sw" || ins=="lw")
            {
                /// address  = 0 ?????

                string one   = res[0];
                string other = res[1];

                if(other[0]=='$')
                {
                    output = MAP_INS_OPC[ins] + MAP_REG_ADD[src_reg] + MAP_REG_ADD[dest_reg] + "00";
                }
                else
                {
                    vector <string> temp = tokenize(other,'(');
                    string offset_d = temp[0];
                    string left = temp[1];

                    vector <string> temp2 = tokenize(left,')');
                    other = temp2[0];

//                    DBG(offset_d);
//                    DBG(other);

                    string t = dec_to_hex_pad_trim(offset_d);

                    output = MAP_INS_OPC[ins] + MAP_REG_ADD[other] + MAP_REG_ADD[one] + t ;
                }

            }
            else if(ins=="beq" || ins=="bneq")
            {
                string one   = res[0];
                string other = res[1];
                string label = res[2];

                if(MAP_LABEL_ADD.find(label)==MAP_LABEL_ADD.end()) /// label not present
                {
                    output = MAP_INS_OPC[ins] + MAP_REG_ADD[one] + MAP_REG_ADD[other];
                    label_rem[output] = label;
                    MAP_INSTRUCTION_COUNTER[output] = counter;
                }
                else /// label already exist
                {
                    int offsetCount = stringHexToDec(MAP_LABEL_ADD[label]) - counter - 1;
                    string offsetCountStr = dec_to_hex_pad_trim(to_string(offsetCount));
//                    DBG(counter);
//                    DBG(offsetCountStr);

                    output = MAP_INS_OPC[ins] + MAP_REG_ADD[one] + MAP_REG_ADD[other] + offsetCountStr;
                }
            }

            machine_code.push_back(output);
//            DBG(output);

        }
        else if(ins == "j")
        {
            string target;
            cin>>target;

            string output = "";

            if(MAP_LABEL_ADD.find(target)==MAP_LABEL_ADD.end())
            {
                output = MAP_INS_OPC[ins];
                label_rem[output] = target;
            }
            else
            {
                output = MAP_INS_OPC[ins] + MAP_LABEL_ADD[target] + "00";
            }

            machine_code.push_back(output);
//            DBG(output);
        }
        else if(ins == "push")
        {
            string other;
            cin>>other;

            string output = "";

            if(other[0]=='$')
            {
                /**
                    push $t0
                 => sw $t0,0($sp)
                 => subi $sp,$sp,1

                **/

                output = MAP_INS_OPC["sw"] + MAP_REG_ADD["$sp"] + MAP_REG_ADD[other] + "00";
                machine_code.push_back(output);

                output = MAP_INS_OPC["subi"] + MAP_REG_ADD["$sp"] + MAP_REG_ADD["$sp"] + "01";
                machine_code.push_back(output);
            }
            else
            {
                vector <string> temp = tokenize(other,'(');
                string offset_d = temp[0];
                string left = temp[1];

                vector <string> temp2 = tokenize(left,')');
                other = temp2[0];

//                    DBG(offset_d);
//                    DBG(other);

                string t = dec_to_hex_pad_trim(offset_d);

                output = MAP_INS_OPC["lw"] + MAP_REG_ADD[other] + MAP_REG_ADD["$t5"] + t ;
                machine_code.push_back(output);

                output = MAP_INS_OPC["sw"] + MAP_REG_ADD["$sp"] + MAP_REG_ADD["$t5"] + "00" ;
                machine_code.push_back(output);

                output = MAP_INS_OPC["subi"] + MAP_REG_ADD["$sp"] + MAP_REG_ADD["$sp"] + "01";
                machine_code.push_back(output);
            }
        }
        else if(ins == "pop")
        {
            string reg;
            cin>>reg;

            string output = "";

            output = MAP_INS_OPC["addi"] + MAP_REG_ADD["$sp"] + MAP_REG_ADD["$sp"] + "01";
            machine_code.push_back(output);

            output = MAP_INS_OPC["lw"] + MAP_REG_ADD["$sp"] + MAP_REG_ADD[reg] + "00" ;
            machine_code.push_back(output);
        }
        else
        {
            /// label
            vector <string> res = tokenize(og,':');
            string label = res[0];
//            DBG(label);

            string addr = dec_to_hex(to_string(counter));
            if((int)addr.size()==1) addr = "0"+addr;

            MAP_LABEL_ADD[label] = addr;
//            DBG(addr);

//            counter--; /// compensate
        }

//        counter++;
    }


    for(auto &str:machine_code)
    {
        if(label_rem.find(str)!=label_rem.end())
        {
//            DBG(str);

            if(str == MAP_INS_OPC["j"])
            {
                str += MAP_LABEL_ADD[label_rem[str]];
                str += "00";
            }
            else
            {
                int offsetCount =  stringHexToDec(MAP_LABEL_ADD[label_rem[str]]) - MAP_INSTRUCTION_COUNTER[str] - 1;
                string offsetCountStr = dec_to_hex_pad_trim(to_string(offsetCount));
//                DBG(offsetCountStr);

                str += offsetCountStr;
            }


//            DBG(str);
        }
    }

//    DBG(machine_code);

    cout<<"v2.0 raw"<<endl;

    for(auto x:machine_code)
    {
        cout<<x<<" ";
    }


    return 0;
}

/**


Corner cases:
- label declared later
- jump to actual address ?



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


