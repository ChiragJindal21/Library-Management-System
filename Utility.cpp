#include <bits/stdc++.h>
#include <time.h>
using namespace std;

class date_t{
    public:
    int day,month,year;
};

void print_data(vector<vector<string>> data){
    for(auto ele:data){
        for(auto ele1:ele){
            cout<<ele1<<"   ";
        }
        cout<<endl;
    }
}

string lower(string s){
    string s1="";
    for(int i=0; i<s.length(); i++){
        if(s[i]>='A' && s[i]<='Z'){
            s1.push_back(s[i]+32);
        }else{
            s1.push_back(s[i]);
        }
    }
    return s1;
}

date_t convert_to_date(string s){
    date_t d;
    string s1 = "";
    s1.push_back(s[0]);
    s1.push_back(s[1]);
    d.day = stoi(s1);
    s1 = "";
    s1.push_back(s[3]);
    s1.push_back(s[4]);
    d.month = stoi(s1);
    s1 = "";
    s1.push_back(s[6]);
    s1.push_back(s[7]);
    s1.push_back(s[8]);
    s1.push_back(s[9]);
    d.year = stoi(s1);
    return d;
}

string first3_char(string s){
    string s1 = "";
    if(s.size()<3){
        cout<<"Atleast 3 charactes needed!!\n";
        return s1;
    }else{
        s1+=s[0];
        s1+=s[1];
        s1+=s[2];
        return s1;
    }      
}

