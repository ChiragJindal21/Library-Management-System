#include <bits/stdc++.h>
using namespace std;


class Book_Details{

    public:

    string book_id;
    string book_name;
    string author_id_1;
    string author_id_2;
    string author_id_3;
    string genre;
    int version;
    int total_copies;
    int available_copies;


};

class Author_Details{

    public:

    std::string author_id;
    string author_name;

};

class Book_Purchase_Details{

    public:

    std::string book_id;
    string purchase_date;
    int copies;
    int price;
    

};

class Borrower_Details{

    public:

    std::string borrower_id;
    string name;
    string dob;
    long int contact_num;
    string email;
    long int due_amount;
    

};

class Book_Issue_Details{

    public:

    std::string borrower_id;
    string issue_date;
    string due_date;
    string book_id;
    
    

};

class Book_Requests {

    public:

    std::string book_name;
    string author_name;
    int version;

};

// Borrower_Details.borrower_id<-->Book_Issue_details.borrower_id;
// table1.pkey--->table2.fkey

// 

