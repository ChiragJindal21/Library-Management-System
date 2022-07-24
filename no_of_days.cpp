#include <bits/stdc++.h>
using namespace std;
const int monthDays[ ] = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
 
int countLeapYears(vector<int> &d)
{
    int years = d[0];
 
    //  current year needs to be leap year or not
    if (d[1] <= 2)
        years--;
 
    // An year is a leap year if it
    // is a multiple of 4,
    // multiple of 400 and not a
     // multiple of 100.
    return years / 4
           - years / 100
           + years / 400;
}

long int date_diff(string d1, string d2){
    string p = "";
    p+=d1[6];
    p+=d1[7];
    p+=d1[8];
    p+=d1[9];
    
    int y1 = stoi(p);
    
    p = "";
    p+= d1[3];p+=d1[4];
    
    int m1 = stoi(p);
    
    p = "";
    p+= d1[0];p+=d1[1];
    
    int day1 = stoi(p);
    

    p="";
    p+=d2[6];
    p+=d2[7];
    p+=d2[8];
    p+=d2[9];
    
    int y2 = stoi(p);
    
    p = "";
    p+= d2[3];p+=d2[4];
    
    int m2 = stoi(p);
    
    p = "";
    p+= d2[0];p+=d2[1];
    //
    int day2 = stoi(p);
    
    vector<int> D1 = {y1,m1, day1} ;
    vector<int> D2 = {y2,m2, day2} ;

    //vector<int> D1 = {stoi(""+d1[6]+ d1[7]+ d1[8]+ d1[9]),stoi(""+d1[3]+ d1[4]), stoi(""+d1[0]+ d1[1])} ;
    //vector<int> D2 = {stoi(""+d2[6]+ d2[7]+ d2[8]+ d2[9]),stoi(""+d2[3]+ d2[4]), stoi(""+d2[0]+ d2[1])} ;

    //cout<<D1[0]<<" "<<D1[1]<<" "<<D1[2]<<"\n";

    // Count from 00-00-0000    
    long int n1 = D1[0] * 365 + D1[2];
 
    // Add days for months in given date
    for (int i = 0; i < D1 [1] - 1; i++)
        n1 += monthDays[i];
 
    n1 += countLeapYears(D1);
 
    long int n2 = D2[0] * 365 + D2[2];
    for (int i = 0; i< D2[1]-1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(D2);
 
    // return difference between two counts
    return n2 - n1;
    
    //return 0;
}



string curr_date(){
    string s="";
    time_t t;
    t = time(0);
    struct tm* t_date = gmtime(&t);
    int day = t_date->tm_mday;
    if(day<10){
        s+="0";
    }
    s+=to_string(day);
    s+="-";
    int month = 1+t_date->tm_mon;
    if(month<10){
        s+="0";
    }
    s+=to_string(month);
    s+="-";
    s+=to_string(1900+(t_date->tm_year));
    return s;
}
