#include <bits/stdc++.h>
#include "Librarian_functions.cpp"
using namespace std;

int main(){
    int x = 1;
    char user,choice,choice2;
    int y,z;
    while(x==1){
        cout<<"Press 0 for Librarian Access.\nPress 1 for Member Access.\n";
        cin>>user;
        switch(user){
            case '0':
                y=1;
                while(y==1){
                    cout<<"Press 0 to work with Book_info.\n";
                    cout<<"Press 1 to work with Author_info.\n";
                    cout<<"Press 2 to work with Member_info.\n";
                    cout<<"Press 3 to work with Book_purchase_info.\n";
                    cout<<"Press 4 to work with Book_issue_info.\n";
                    cout<<"Press 5 to work with Book_request_info\n";
                    cout<<"Press 6 to search due_amount.\n";
                    cout<<"Press 7 to exit.\n";
                    cin>>choice;
                    switch(choice){
                        case '0':
                            z = 1;
                            while(z == 1){
                                cout<<"Press 0 to add a new Book's info.\n";
                                cout<<"Press 1 to search a Book's info by book name.\n";
                                cout<<"Press 2 to search a Book's info by book id.\n";
                                cout<<"Press 3 to search all Books' info.\n";
                                cout<<"Press 4 to delete a Book's info.\n";
                                cout<<"Press 5 to search a Book's info by author name.\n";
                                cout<<"Press 6 to exit.\n";
                                cin>>choice2;
                                switch(choice2){
                                    case '0':
                                        add_book_info();
                                        break;
                                    case '1':
                                        book_info_by_name();
                                        break;
                                    case '2':
                                        book_info_by_id();
                                        break;
                                    case '3':
                                        all_books_info();
                                        break;
                                    case '4':
                                        delete_book_info();
                                        break;
                                    case '5':
                                        book_info_by_author_name();
                                    case '6':
                                        z = 0;
                                        break;
                                    default:
                                        cout<<"Wrong Input. Please try again.\n";
                                }
                            }
                            break;
                        case '1':
                            z = 1;
                            while(z == 1){
                                cout<<"Press 0 to add a new Author's info.\n";
                                cout<<"Press 1 to search a Author's info by name.\n";
                                cout<<"Press 2 to search a Author's info by id.\n";
                                cout<<"Press 3 to search all Authors' info.\n";
                                cout<<"Press 4 to delete a Author's info.\n";
                                cout<<"Press 5 to exit.\n";
                                cin>>choice2;
                                switch(choice2){
                                    case '0':
                                        add_author_info();
                                        break;
                                    case '1':
                                        author_info_by_name();
                                        break;
                                    case '2':
                                        author_info_by_id();
                                        break;
                                    case '3':
                                        all_authors_info();
                                        break;
                                    case '4':
                                        delete_author_info();
                                        break;
                                    case '5':
                                        z = 0;
                                        break;
                                    default:
                                        cout<<"Wrong Input. Please try again.\n";
                                }
                            }
                            break;
                        case '2':
                            z = 1;
                            while(z == 1){
                                cout<<"Press 0 to add a new Member's info.\n";
                                cout<<"Press 1 to search a Member's info by name.\n";
                                cout<<"Press 2 to search a Member's info by id.\n";
                                cout<<"Press 3 to search all Member's info.\n";
                                cout<<"Press 4 to delete a Member's info.\n";
                                cout<<"Press 5 to exit.\n";
                                cin>>choice2;
                                switch(choice2){
                                    case '0':
                                        add_member_info();
                                        break;
                                    case '1':
                                        member_info_by_name();
                                        break;
                                    case '2':
                                        member_info_by_id();
                                        break;
                                    case '3':
                                        all_members_info();
                                        break;
                                    case '4':
                                        delete_member_info();
                                        break;
                                    case '5':
                                        z = 0;
                                        break;
                                    default:
                                        cout<<"Wrong Input. Please try again.\n";
                                }
                            }
                            break;
                        case '3':
                            z = 1;
                            while(z == 1){
                                cout<<"Press 0 to add a new Book_purchase_detail.\n";
                                cout<<"Press 1 to search a Book_purchase_detail by Book_id.\n";
                                cout<<"Press 2 to search a Book_purchase_detail by purchase date.\n";
                                cout<<"Press 3 to search all Book_purchase_details.\n";
                                cout<<"Press 4 to delete a Book_purchase_detail.\n";
                                cout<<"Press 5 to exit.\n";
                                cin>>choice2;
                                switch(choice2){
                                    case '0':
                                        add_purchase_details();
                                        break;
                                    case '1':
                                        search_book_pur_by_book_id();
                                        break;
                                    case '2':
                                        search_book_pur_by_pur_date();
                                        break;
                                    case '3':
                                        show_all_purchase_details();
                                        break;
                                    case '4':
                                        delete_purchase_details();
                                        break;
                                    case '5':
                                        z = 0;
                                        break;
                                    default:
                                        cout<<"Wrong Input. Please try again.\n";
                                }
                            }
                            break;
                        case '4':
                            z = 1;
                            while(z == 1){
                                cout<<"Press 0 to add a new Book_issue detail.\n";
                                cout<<"Press 1 to search a Book_issue detail by book_id.\n";
                                cout<<"Press 2 to search a Book_issue detail by borrower_id.\n";
                                cout<<"Press 3 to search a Book_issue detail by borrower name.\n";
                                cout<<"Press 4 to delete a Book_issue detail.\n";
                                cout<<"Press 5 to search all Book_issue details.\n";
                                cout<<"Press 6 to exit.\n";
                                cin>>choice2;
                                switch(choice2){
                                    case '0':
                                        add_book_issue_detail();
                                        break;
                                    case '1':
                                        book_issue_detail_by_book_id();
                                        break;
                                    case '2':
                                        book_issue_detail_by_borrower_id();
                                        break;
                                    case '3':
                                        book_issue_detail_by_borrower_name();
                                        break;
                                    case '4':
                                        delete_book_issue_detail();
                                        break;
                                    case '5':
                                        all_book_issue_detail();
                                        break;
                                    case '6':
                                        z = 0;
                                        break;
                                    default:
                                        cout<<"Wrong Input. Please try again.\n";
                                }
                            }
                            break;
                        case '5':
                            z = 1;
                            while(z == 1){
                                cout<<"Press 0 to add a new Book_request.\n";
                                cout<<"Press 1 to delete a Book_request.\n";
                                cout<<"Press 2 to search all Book_requests.\n";
                                cout<<"Press 3 to exit.\n";
                                cin>>choice2;
                                switch(choice2){
                                    case '0':
                                        add_book_request();
                                        break;
                                    case '1':
                                        delete_book_request();
                                        break;
                                    case '2':
                                        all_book_request();
                                        break;
                                    case '3':
                                        z = 0;
                                        break;
                                    default:
                                        cout<<"Wrong Input. Please try again.\n";
                                }
                            }
                            break;
                        case '6':
                            z = 1;
                            while(z == 1){
                                cout<<"Press 0 to see due amount of a members.\n";
                                cout<<"Press 1 to exit.\n";
                                cin>>choice2;
                                switch(choice2){
                                    case '0':
                                        due_amount_of_member();
                                        break;
                                    case '1':
                                        z = 0;
                                        break;
                                    default:
                                        cout<<"Wrong Input. Please try again.\n";
                                }
                            }
                            break;
                        case '7':
                            y = 0;
                            break;
                        default:
                            cout<<"Wrong Input. Please try again.\n";
                    }
                }
                x = 0;
                break;
            case '1':
                y = 1;
                while(y==1){
                    cout<<"Press 0 for search by Book_name.\n";
                    cout<<"Press 1 for search by Author_name.\n";
                    cout<<"Press 2 to search due_date.\n";
                    cout<<"Press 3 to search due_amount.\n";
                    cout<<"Press 4 to see your info.\n";
                    cout<<"Press 5 to exit.\n";
                    cin>>choice;
                    switch(choice){
                        case '0':
                            book_info_by_name();
                            break;
                        case '1':
                            book_info_by_author_name();
                            break;
                        case '2':
                            book_issue_detail_by_borrower_id();
                            break;
                        case '3':
                            due_amount_of_member();
                            break;
                        case '4':
                            member_info_by_id();
                            break;
                        case '5':
                            y = 0;
                            break;
                        default:
                            cout<<"Wrong Input. Please try again.\n";
                    }
                }
                x = 0;
                break;
            default:
                cout<<"Wrong Input. Please try again.\n";
        }
    }

    return 0;
}