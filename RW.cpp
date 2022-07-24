#include <bits/stdc++.h>
#include "classes.cpp"
using namespace std;

void get_data_from_db(string file_name, vector<vector<string>>& v){
    fstream fs;
    fs.open(file_name,ios::in);
    if(!fs){
        cout<<"Unable to open file "<<file_name<<"\n";
    }else{
        string s;
        while(getline(fs,s)){
            vector <string> v1;
            string s1;
            stringstream ss(s);
            while(ss.good()){
                getline(ss,s1,',');
                v1.push_back(s1);
            }
            v.push_back(v1);
        }
    }
    fs.close();
}

void store_data_to_db(string file_name, vector<vector<string>> v){
    fstream fs;
    fs.open(file_name, ios::out);
    if(!fs){
       cout<<"Unable to open file "<<file_name<<"\n"; 
    }else{
        string s;
        vector<vector<string>> :: iterator it1;
        it1 = v.begin();
        for(auto ele:v){
            s = "";
            vector<string>::iterator it;
            for(it = ele.begin(); it!=ele.end()-1; it++){
                s+=*it;
                s+=",";
            }
            s+=*(ele.end()-1);
            s+="\n";
            fs<<s;
            it1++;
        }
    }
    fs.close();
}

void append_data_to_db(string file_name, vector<vector<string>> v){
    fstream fs;
    fs.open(file_name, ios::app);
    if(!fs){
       cout<<"Unable to open file "<<file_name<<"\n"; 
    }else{
        string s;
        vector<vector<string>> :: iterator it1;
        it1 = v.begin();
        for(auto ele:v){
            s = "";
            vector<string>::iterator it;
            for(it = ele.begin(); it!=ele.end()-1; it++){
                s+=*it;
                s+=",";
            }
            s+=*(ele.end()-1);
            s+="\n";
            fs<<s;
            it1++;
        }
    }
    fs.close();
}

void append_data_to_db(string file_name, vector<string> v){
    fstream fs;
    fs.open(file_name, ios::app);
    if(!fs){
       cout<<"Unable to open file "<<file_name<<"\n"; 
    }else{
        string s;
        s = "";
        vector<string>::iterator it;
        for(it = v.begin(); it!=v.end()-1; it++){
            s+=*it;
            s+=",";
        }
        s+=*(v.end()-1);
        s+="\n";
        fs<<s;
    }
    fs.close();
}

vector<Book_Details> convert_vector_to_book_details(vector<vector<string>> v){
    vector<Book_Details> v1;
    for(auto ele: v){
        Book_Details b;
        b.book_id = ele[0];
        b.book_name = ele[1];
        b.author_id_1 = ele[2];
        b.author_id_2 = ele[3];
        b.author_id_3 = ele[4];
        b.genre = ele[5];
        b.available_copies = stoi(ele[6]);
        b.total_copies = stoi(ele[7]);
        b.version = stoi(ele[8]);
        v1.push_back(b);
    }
    return v1;
}

vector<vector<string>> convert_book_details_to_vector(vector<Book_Details> v){
    vector<vector<string>> v1;
    for(auto ele:v){
        vector<string> v2;
        v2.push_back(ele.book_id);
        v2.push_back(ele.book_name);
        v2.push_back(ele.author_id_1);
        v2.push_back(ele.author_id_2);
        v2.push_back(ele.author_id_3);
        v2.push_back(ele.genre);
        v2.push_back(to_string(ele.available_copies));
        v2.push_back(to_string(ele.total_copies));
        v2.push_back(to_string(ele.version));
        v1.push_back(v2);
    }
    return v1;
}