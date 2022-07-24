#include <bits/stdc++.h>
#include "RW.cpp"
#include "Utility.cpp"
#include "no_of_days.cpp"
using namespace std;

int calc_due_amt(string d1);

void all_books_info(){
    vector<vector<string>> v;
    get_data_from_db("Book_details.txt", v);
    cout<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    print_data(v);
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    cout<<endl;
}

void book_info_by_name(){
    string name;
    cout<<"Enter Book's name (atleast first 3 characters): ";
    cin.ignore();
    getline(cin, name);
    vector<vector<string>> v;
    get_data_from_db("Book_details.txt", v);
    vector<vector<string>> v1;
    int count = 0;
    for(auto ele:v){
        string lower_name = lower(name);
        if(first3_char(ele[1]) == first3_char(lower_name)){
            v1.push_back(ele);
            count++;
        }
    }
    if(count>0){
        cout<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        print_data(v1);
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<endl;
    }else{
        cout<<endl;
        cout<<"No results found!\n";
        cout<<endl;
    }
}

void book_info_by_id(){
    int id;
    cout<<"Enter Book's id: ";
    cin>>id;
    vector<vector<string>> v;
    get_data_from_db("Book_details.txt", v);
    vector<vector<string>> v1;
    int count = 0;
    for(auto ele:v){
        if(stoi(ele[0]) == id){
            v1.push_back(ele);
            count++;
        }
    }
    if(count>0){
        cout<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        print_data(v1);
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<endl;
    }else{
        cout<<endl;
        cout<<"No results found!\n";
        cout<<endl;
    }
}

void add_book_info(){
    cout<<"Enter Book's id: ";
    cin.ignore();
    string b_id,name,a1_id,a2_id,a3_id,genre, version, total, avail;
    getline(cin, b_id);
    cout<<"Enter Book's name: ";
    getline(cin, name);
    cout<<"Enter Author_id1 (press enter if none): ";
    getline(cin, a1_id);
    cout<<"Enter Author_id2 (press enter if none): ";
    getline(cin, a2_id);
    cout<<"Enter Author_id3 (press enter if none): ";
    getline(cin, a3_id);
    cout<<"Enter genre: ";
    getline(cin, genre);
    cout<<"Enter version: ";
    getline(cin, version);
    cout<<"Enter total copies: ";
    getline(cin, total);
    cout<<"Enter available copies: ";
    getline(cin, avail);
    vector<string> v;
    v.push_back(b_id);
    v.push_back(lower(name));
    v.push_back(a1_id);
    v.push_back(a2_id);
    v.push_back(a3_id);
    v.push_back(genre);
    v.push_back(version);
    v.push_back(total);
    v.push_back(avail);
    vector <vector<string>> v1,v2;
    get_data_from_db("Author_details.txt", v1);
    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;
    for(auto ele:v1){
        if(ele[0]==a1_id){
            flag1 = true;
        }
        if(ele[0]==a2_id){
            flag2=true;
        }
        if(ele[0]==a3_id){
            flag3=true;
        }

    } 
    get_data_from_db("Book_details.txt",v2);
    bool flag4 = true;
    for(auto ele: v2){
        if(ele[0]==b_id){
            flag4=false;
            break;
        }
    }
    if(flag4){
        if(flag1 && flag2 && flag3){
            append_data_to_db("Book_details.txt", v);
            cout<<"\nBook added to database.\n\n";
        }else{
            cout<<"\nData can't be added to maintain referential integrity.\n";
            cout<<"One of the author not already present in the database.\n\n";
        }
    }else{
        cout<<"\nData can't be added because Book already present in the Book_details table.\n\n";
    }
}

void delete_book_info(){
    cout<<"Enter Book ID: ";
    string id;
    cin>>id;
    vector<vector<string>>v,v1,v2;
    get_data_from_db("Book_details.txt",v);
    get_data_from_db("Book_Issue_Details.txt",v1);
    get_data_from_db("Book_Purchase_Details.txt",v2);
    bool flag = false;
    bool flag1 = true;
    bool flag2 = true;
    vector<vector<string>> :: iterator it;
    for(it = v.begin(); it!=v.end(); it++){
        if((*it)[0] == id){
            flag = true;
            for(auto ele:v1){
                if(id==ele[3]){
                    flag1 = false;
                    break;
                }
            }
            for(auto ele: v2){
                if(id==ele[0]){
                    flag2 = false;
                    break;
                }
            }
            if(flag1 && flag2){
                v.erase(it);
                it--;
            }
        }
    }
    store_data_to_db("Book_details.txt",v);

    if(!flag)
        cout<<"\nNo entry found.\n\n";
    else if(flag1 && flag2)
        cout<<"\nBook info successfully deleted.\n\n";
    else if(flag1 && !flag2){
        cout<<"\nEntry can't be deleted to maintain referential integrity.\n";
        cout<<"This Book ID present in Book_Purchase_Details table.\n\n";
    }else if(!flag1 && flag2){
        cout<<"\nEntry can't be deleted to maintain referential integrity.\n";
        cout<<"This Book ID present in Book_Issue_Details table.\n\n";
    }else{
        cout<<"\nEntry can't be deleted to maintain referential integrity.\n";
        cout<<"This Book ID present in Book_Purchase_Details table and Book_Issue_Details table.\n\n";
    }
}

void book_info_by_author_name(){
    cout<<"Enter author's name (atleast first 3 characters).\n";
    string name;
    cin.ignore();
    getline(cin, name);
    vector<vector<string>> v,v1,v3;
    vector<string> v2; 
    get_data_from_db("Author_details.txt", v);
    for(auto ele: v){
        if(lower(first3_char(ele[1])) == lower(first3_char(name))){
            v2.push_back(ele[0]);
        }
    }
    get_data_from_db("Book_details.txt", v1);
    int count = 0;
    for(auto ele1:v1){
        for(auto ele2:v2){
            if(ele2==ele1[2] || ele2==ele1[3] || ele2==ele1[4]){
                v3.push_back(ele1);
                count++;
            }
        }
    }

    if(count>0){
        cout<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        print_data(v3);
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<endl;
    }else{
        cout<<endl;
        cout<<"No results found!\n";
        cout<<endl;
    }
}

void all_authors_info(){
    vector<vector<string>> v;
    get_data_from_db("Author_details.txt", v);
    cout<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    print_data(v);
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    cout<<endl;
}

void author_info_by_name(){
    string name;
    cout<<"Enter Author's name: ";
    cin.ignore();
    getline(cin, name);
    vector<vector<string>> v;
    get_data_from_db("Author_details.txt", v);
    vector<vector<string>> v1;
    int count = 0;
    for(auto ele:v){
        string lower_name = lower(name);
        if(ele[1] == lower_name){
            v1.push_back(ele);
            count++;
        }
    }
    if(count>0){
        cout<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        print_data(v1);
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<endl;
    }else{
        cout<<endl;
        cout<<"No results found!\n";
        cout<<endl;
    }
}

void author_info_by_id(){
    int id;
    cout<<"Enter Author's id: ";
    cin>>id;
    vector<vector<string>> v;
    get_data_from_db("Author_details.txt", v);
    vector<vector<string>> v1;
    int count = 0;
    for(auto ele:v){
        if(stoi(ele[0]) == id){
            v1.push_back(ele);
            count++;
        }
    }
    if(count>0){
        cout<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        print_data(v1);
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<endl;
    }else{
        cout<<endl;
        cout<<"No results found!\n";
        cout<<endl;
    }
}

void add_author_info(){
    cout<<"Enter Author's name: ";
    cin.ignore();
    string id,name;
    getline(cin, name);
    vector<vector<string>>v1,v2;
    get_data_from_db("Author_details.txt",v2);
    bool flag = true;
    for(auto ele:v2){
        if(ele[1] == lower(name)){
            flag = false;
            break;
        }
    }
    if(flag){
        get_data_from_db("imp_info.txt", v1);
        id = to_string(stoi(v1[0][1]) + 1);
        v1[0][1] = id;
        store_data_to_db("imp_info.txt", v1);
        vector<string> v;
        v.push_back(id);
        v.push_back(lower(name));
        append_data_to_db("Author_details.txt", v);
        cout<<"\nAuthor added to database.\n\n";
    }else{
        cout<<"\nAuthor already present in the Author_details table.\n\n";
    }
} 

void delete_author_info(){
    cout<<"Enter Author ID: ";
    string id;
    cin>>id;
    vector<vector<string>>v,v1;
    get_data_from_db("Author_details.txt",v);
    get_data_from_db("Book_details.txt",v1);
    bool flag = false;
    bool flag1 = false;
    vector<vector<string>> :: iterator it;
    for(it = v.begin(); it!=v.end(); it++){
        if((*it)[0] == id){
            flag = true;
            for(auto ele: v1){
                if(ele[2]==id || ele[3]==id || ele[4]==id){
                    flag1 = true;
                }
            }
            if(!flag1){
                v.erase(it);
                it--;
            }
        }
    }
    store_data_to_db("Author_details.txt",v);
    if(!flag)
        cout<<"\nNo entry found.\n\n";
    else if(!flag1)
        cout<<"\nAuthor info successfully deleted.\n\n";
    else{
        cout<<"\nEntry can't be deleted to maintain referential integrity.\n";
        cout<<"This Author ID present in Book_details table.\n\n";
    }
}

void all_members_info(){
    vector<vector<string>> v;
    get_data_from_db("Borrower_Details.txt", v);
    cout<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    print_data(v);
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    cout<<endl;
}

void member_info_by_name(){
    string name;
    cout<<"Enter member's name: ";
    cin.ignore();
    getline(cin, name);
    vector<vector<string>> v;
    get_data_from_db("Borrower_Details.txt", v);
    vector<vector<string>> v1;
    int count = 0;
    for(auto ele:v){
        string lower_name = lower(name);
        if(ele[1] == lower_name){
            v1.push_back(ele);
            count++;
        }
    }
    if(count>0){
        cout<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        print_data(v1);
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<endl;
    }else{
        cout<<endl;
        cout<<"No results found!\n";
        cout<<endl;
    }
}

void member_info_by_id(){
    int id;
    cout<<"Enter member's id: ";
    cin>>id;
    vector<vector<string>> v;
    get_data_from_db("Borrower_Details.txt", v);
    vector<vector<string>> v1;
    int count = 0;
    for(auto ele:v){
        if(stoi(ele[0]) == id){
            v1.push_back(ele);
            count++;
        }
    }
    if(count>0){
        cout<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        print_data(v1);
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<endl;
    }else{
        cout<<endl;
        cout<<"No results found!\n";
        cout<<endl;
    }
}

void add_member_info(){
    cout<<"Enter member name: ";
    cin.ignore();
    string member_id,name,dob,m_no,email;
    getline(cin, name);
    cout<<"Enter dob in the format(dd-mm-yyyy): ";
    getline(cin, dob);
    cout<<"Enter mobile no.: ";
    getline(cin, m_no);
    cout<<"Enter Email ID: ";
    getline(cin, email);
    vector<vector<string>>v1,v2;
    get_data_from_db("Borrower_Details.txt",v2);
    bool flag = true; 
    for(auto ele:v2){
        if(ele[1]==lower(name) && ele[2]==dob && ele[3]==m_no && ele[4]==email){
            flag = false;
            break;
        }
    }
    if(flag){
        get_data_from_db("imp_info.txt", v1);
        member_id = to_string(stoi(v1[1][1]) + 1);
        v1[1][1] = member_id;
        store_data_to_db("imp_info.txt", v1);
        vector<string> v;
        v.push_back(member_id);
        v.push_back(lower(name));
        v.push_back(dob);
        v.push_back(m_no);
        v.push_back(email);
        v.push_back("0");
        append_data_to_db("Borrower_Details.txt", v);
        cout<<"\nMember added to database.\n\n";
    }else{
        cout<<"\nMember already present in the Borrower_Details table.\n\n";
    }
} 

void delete_member_info(){
    cout<<"Enter Member ID: ";
    string member_id;
    cin>>member_id;
    vector<vector<string>>v,v1;
    get_data_from_db("Borrower_Details.txt",v);
    get_data_from_db("Book_Issue_Details.txt",v1);
    bool flag = false;
    bool flag1 = false;
    vector<vector<string>> :: iterator it;
    for(it = v.begin(); it!=v.end(); it++){
        if((*it)[0] == member_id){
            flag = true;
            for(auto ele: v1){
                if(ele[0]==member_id){
                    flag1 = true;
                }
            }
            if(!flag1){
                v.erase(it);
                it--;
            }
        }
    }
    store_data_to_db("Borrower_Details.txt",v);
    if(!flag)
        cout<<"\nNo entry found.\n\n";
    else if(!flag1)
        cout<<"\nMember info successfully deleted.\n\n";
    else{
        cout<<"\nEntry can't be deleted to maintain referential integrity.\n";
        cout<<"This Member ID present in Book_Issue_Details table.\n\n";
    }
}

void search_book_pur_by_book_id(){
    int id;
    cout<<"Enter book's id: ";
    cin>>id;
    vector<vector<string>> v;
    get_data_from_db("Book_Purchase_Details.txt", v);
    vector<vector<string>> v1;
    int count = 0;
    for(auto ele:v){
        if(stoi(ele[0]) == id){
            v1.push_back(ele);
            count++;
        }
    }
    if(count>0){
        cout<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        print_data(v1);
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<endl;
    }else{
        cout<<endl;
        cout<<"No results found!\n";
        cout<<endl;
    }
}

void search_book_pur_by_pur_date(){
    string date;
    cout<<"Enter purchase date in the format dd-mm-yyyy: ";
    cin>>date;
    vector<vector<string>> v;
    get_data_from_db("Book_Purchase_Details.txt", v);
    vector<vector<string>> v1;
    int count = 0;
    for(auto ele:v){
        if(ele[1] == date){
            v1.push_back(ele);
            count++;
        }
    }
    if(count>0){
        cout<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        print_data(v1);
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<endl;
    }else{
        cout<<endl;
        cout<<"No results found!\n";
        cout<<endl;
    }
}

void show_all_purchase_details(){
    vector<vector<string>> v;
    get_data_from_db("Book_Purchase_Details.txt", v);
    cout<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    print_data(v);
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    cout<<endl;
}

void add_purchase_details(){
    cout<<"Enter book id: ";
    cin.ignore();
    string book_id,pur_date,copies,price;
    getline(cin, book_id);
    cout<<"Enter purchase date in the format(dd-mm-yyyy): ";
    getline(cin, pur_date);
    cout<<"Enter copies purchased: ";
    getline(cin, copies);
    cout<<"Enter price of 1 book: ";
    getline(cin, price);
    vector<string> v;
    v.push_back(book_id);
    v.push_back(pur_date);
    v.push_back(copies);
    v.push_back(price);
    vector <vector<string>> v1,v2;
    get_data_from_db("Book_Purchase_Details.txt", v2);
    bool flag = true;
    for(auto ele:v2){
        if(ele[0]==book_id && ele[1]==pur_date){
            flag=false;
            break;
        }
    }

    if(flag){
        get_data_from_db("Book_details.txt", v1);
        bool flag1 = false;
        for(auto ele:v1){
            if(ele[0]==book_id){
                flag1 = true;
            }
        } 

        if(flag1){
            //Trigger
            vector<vector<string>> :: iterator it;
            for(it = v1.begin(); it!=v1.end(); it++){
                if((*it)[0]==book_id){
                    (*it)[7] = to_string(stoi((*it)[7]) + stoi(copies));
                    (*it)[8] = to_string(stoi((*it)[8]) + stoi(copies));
                    break;
                }
            }
            store_data_to_db("Book_details.txt",v1);
            
            append_data_to_db("Book_Purchase_Details.txt", v);
            cout<<"\nEntry added to database.\n\n";
        }else{
            cout<<"\nData can't be added to maintain referential integrity.\n";
            cout<<"Book not already present in the Book_details table.\n\n";
        }
    }else{
        cout<<"\nBook Purchase detail already present in the Database.\n\n";
    }
} 

void delete_purchase_details(){
    cout<<"Enter Book ID: ";
    string book_id;
    cin>>book_id;
    cout<<"Book Purchase date in the format dd-mm-yyyy: ";
    string date;
    cin>>date;
    vector<vector<string>>v,v1;
    get_data_from_db("Book_Purchase_Details.txt",v);
    bool flag = false;
    vector<vector<string>> :: iterator it,it1;
    for(it = v.begin(); it!=v.end(); it++){
        if(((*it)[0] == book_id) && ((*it)[1] == date)){
            flag = true;

            //trigger
            get_data_from_db("Book_details.txt",v1);
            for(it1 = v1.begin(); it1!=v1.end(); it1++){
                if((*it1)[0] == book_id){
                    (*it1)[7] = to_string(stoi((*it1)[7]) - stoi((*it)[2]));
                    (*it1)[8] = to_string(stoi((*it1)[8]) - stoi((*it)[2]));
                    break;
                }
            }
            store_data_to_db("Book_details.txt",v1);

            v.erase(it);
            it--;
        }
    }
    store_data_to_db("Book_Purchase_Details.txt",v);
    if(!flag)
        cout<<"\nNo entry found.\n\n";
    else
        cout<<"\nPurchase details successfully deleted.\n\n";
}

void all_book_issue_detail(){
    vector<vector<string>> v;
    get_data_from_db("Book_Issue_Details.txt", v);
    cout<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    print_data(v);
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    cout<<endl;
}

void book_issue_detail_by_borrower_id(){
    int id;
    cout<<"Enter Member's id: ";
    cin>>id;
    vector<vector<string>> v;
    get_data_from_db("Book_Issue_Details.txt", v);
    vector<vector<string>> v1;
    int count = 0;
    for(auto ele:v){
        if(stoi(ele[0]) == id){
            v1.push_back(ele);
            count++;
        }
    }
    if(count>0){
        cout<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        print_data(v1);
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<endl;
    }else{
        cout<<endl;
        cout<<"No results found!\n";
        cout<<endl;
    }
}

void book_issue_detail_by_book_id(){
    int id;
    cout<<"Enter Book's id: ";
    cin>>id;
    vector<vector<string>> v;
    get_data_from_db("Book_Issue_Details.txt", v);
    vector<vector<string>> v1;
    int count = 0;
    for(auto ele:v){
        if(stoi(ele[3]) == id){
            v1.push_back(ele);
            count++;
        }
    }
    if(count>0){
        cout<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        print_data(v1);
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<endl;
    }else{
        cout<<endl;
        cout<<"No results found!\n";
        cout<<endl;
    }
}

void book_issue_detail_by_borrower_name(){
    cout<<"Enter Member's name (atleast first 3 characters).\n";
    string name;
    cin.ignore();
    getline(cin, name);
    vector<vector<string>> v,v1,v3;
    vector<string> v2; 
    get_data_from_db("Borrower_Details.txt", v);
    for(auto ele: v){
        if(lower(first3_char(ele[1])) == lower(first3_char(name))){
            v2.push_back(ele[0]);
        }
    }
    get_data_from_db("Book_Issue_Details.txt", v1);
    int count = 0;
    for(auto ele1:v1){
        for(auto ele2:v2){
            if(ele2==ele1[0]){
                v3.push_back(ele1);
                count++;
            }
        }
    }

    if(count>0){
        cout<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        print_data(v3);
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<endl;
    }else{
        cout<<endl;
        cout<<"No results found!\n";
        cout<<endl;
    }
}

void add_book_issue_detail(){
    cout<<"Enter Member's id: ";
    cin.ignore();
    string m_id, issue_dt, due_dt, b_id;
    getline(cin, m_id);
    cout<<"Enter Issue Date in the format dd-mm-yyyy: ";
    getline(cin, issue_dt);
    cout<<"Enter Due Date in the format dd-mm-yyyy: ";
    getline(cin, due_dt);
    cout<<"Enter Book's id: ";
    getline(cin, b_id);
    vector<string> v;
    v.push_back(m_id);
    v.push_back(issue_dt);
    v.push_back(due_dt);
    v.push_back(b_id);
    vector <vector<string>> v1,v2,v3;
    get_data_from_db("Book_Issue_Details.txt",v3);
    bool flag = true;
    for(auto ele: v3){
        if(ele[0]==m_id && ele[3]==b_id){
            flag=false;
            break;
        }
    }

    if(flag){
        get_data_from_db("Borrower_Details.txt", v1);
        get_data_from_db("Book_details.txt", v2);
        bool flag1 = false;
        bool flag2 = false;
        for(auto ele:v1){
            if(ele[0]==m_id){
                flag1 = true;
                break;
            }
        } 
        for(auto ele:v2){
            if(ele[0]==b_id){
                flag2 = true;
                break;
            }
        }

        if(flag1 && flag2){
            vector<vector<string>> :: iterator it;
            for(it = v2.begin(); it!=v2.end(); it++){
                if((*it)[0]==b_id){
                    (*it)[8] = to_string(stoi((*it)[8])-1);
                    break;
                }
            }
            store_data_to_db("Book_details.txt",v2);
            append_data_to_db("Book_Issue_Details.txt", v);
            cout<<"\nEntry added to database.\n\n";
        }else if(!flag1 && flag2){
            cout<<"\nData can't be added to maintain referential integrity.\n";
            cout<<"Member not already present in the Borrower_Details table.\n\n";
        }else if(flag1 && !flag2){
            cout<<"\nData can't be added to maintain referential integrity.\n";
            cout<<"Book not already present in the Book_details table.\n\n";
        }else{
            cout<<"\nData can't be added to maintain referential integrity.\n";
            cout<<"Member not already present in the Borrower_Details table.\n";
            cout<<"Book not already present in the Book_details table.\n\n";
        }
    }else{
        cout<<"\nEntry already present in the database.\n\n";
    }
}

void delete_book_issue_detail(){
    cout<<"Enter Member ID: ";
    string m_id;
    cin>>m_id;
    cout<<"Enter Book ID: ";
    string b_id;
    cin>>b_id;
    vector<vector<string>>v,v1,v2;
    get_data_from_db("Book_Issue_Details.txt",v);
    get_data_from_db("Borrower_Details.txt",v1);
    bool flag = false;
    vector<vector<string>> :: iterator it,it1;
    int amt = 0;
    for(it = v.begin(); it!=v.end(); it++){
        if(((*it)[0] == m_id) && ((*it)[3] == b_id)){
            flag = true;
            //Trigger1
            amt = calc_due_amt((*it)[2]);

            for(it1 = v1.begin(); it1!=v1.end(); it1++){
                if((*it1)[0]==m_id){
                    amt += stoi((*it1)[5]);
                    (*it1)[5] = to_string(amt);
                    break;
                }
            }

            //Trigger2
            get_data_from_db("Book_details.txt",v2);
            for(it1 = v2.begin(); it1!=v2.end(); it1++){
                if((*it1)[0]==b_id){
                    (*it1)[8] = to_string(1+stoi((*it1)[8]));
                    break;
                }
            }
            store_data_to_db("Book_details.txt",v2);
            v.erase(it);
            it--;
        }
    }
    store_data_to_db("Book_Issue_Details.txt",v);
    store_data_to_db("Borrower_Details.txt",v1);
    if(!flag)
        cout<<"\nNo entry found.\n\n";
    else
        cout<<"\nBook issue detail successfully deleted.\n\n";
}

void all_book_request(){
    vector<vector<string>> v;
    get_data_from_db("Book_Requests.txt", v);
    cout<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    print_data(v);
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    cout<<endl;
}

void add_book_request(){
    cout<<"Enter Book's name: ";
    cin.ignore();
    string b_name, a_name, version;
    getline(cin, b_name);
    cout<<"Enter Author's name: ";
    getline(cin, a_name);
    cout<<"Enter version: ";
    getline(cin, version);
    vector<vector<string>>v1;
    get_data_from_db("imp_info.txt", v1);
    string book_request_id = to_string(stoi(v1[2][1]) + 1);
    v1[2][1] = book_request_id;
    store_data_to_db("imp_info.txt", v1);
    vector<string> v;
    v.push_back(book_request_id);
    v.push_back(b_name);
    v.push_back(a_name);
    v.push_back(version);
    append_data_to_db("Book_Requests.txt", v);
    cout<<"\nEntry added to database.\n\n";
}

void delete_book_request(){
    cout<<"Enter Book_request ID: ";
    string r_id;
    cin>>r_id;
    vector<vector<string>>v;
    get_data_from_db("Book_Requests.txt",v);
    bool flag = false;
    vector<vector<string>> :: iterator it;
    for(it = v.begin(); it!=v.end(); it++){
        if((*it)[0] == r_id){
            flag = true;
            v.erase(it);
            it--;
        }
    }
    cout<<v.size();
    store_data_to_db("Book_Requests.txt",v);
    if(!flag)
        cout<<"\nNo entry found.\n\n";
    else
        cout<<"\nBook request successfully deleted.\n\n";
}

void due_amount_of_member(){
    vector<vector<string>> v1,v2;
    vector <vector<string>> data;
    get_data_from_db("Book_Issue_Details.txt", v1);
    get_data_from_db("Borrower_Details.txt", v2);
    int total_amt = 0;
    cout<<"Enter Member ID: ";
    string id;
    cin>>id;
    for(auto ele: v2){
        if(ele[0]==id){
            total_amt+=stoi(ele[5]);
            data.push_back(ele);
        }
    }
    for(auto ele:v1){
        if(ele[0]==id){
            string d1 = ele[2];
            string d2 = curr_date();
            int tot_day = max(0,(int)date_diff(d1,d2));
            total_amt += min(3000, tot_day*5);
        }
    }
    cout<<endl;
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    print_data(data);
    cout<<"Total due amount is Rs. "<<total_amt<<".\n";
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    cout<<endl;
}

int calc_due_amt(string d1){
    int total_amt = 0;
    string d2 = curr_date();
    int tot_day = max(0,(int)date_diff(d1,d2));
    total_amt += min(3000, tot_day*5);
    return total_amt;
}