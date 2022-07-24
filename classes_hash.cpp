#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// classes -------------------------------------------------

class Book_Details{

    public:

    std::string book_id;
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
    // f name? l name?
    

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
    //string return_date;
    
    //string book_id;
    
    

};


// ----------------------------------------------------



/// File handling ------------------------------------------


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
                ///cout<<s1<<"\n";
            }
            v.push_back(v1);
            // for (int i =0;i<v.size();i++)
            // {
            //     /* code */
            //     cout<<(v[i][0])<<" ";
            // }cout<<"\n";
            
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
        }
    }
    fs.close();
}

void print_data(vector<vector<string>> &data){
    for(auto ele:data){
        for(auto ele1:ele){
            cout<<ele1<<"";
        }
        cout<<"\n";
    }
}

/// ---------------------------------------------------



//// Hash Table details -------------------------------------------------


int book_bucket_size = 3;

int book_table_size =5;

int key(int num, map<int,int> &hashf){
  //std::cout << num<<" "<<hashf[num%book_table_size]<<" "<< num%book_table_size<< '\n';
  return num%hashf[num%book_table_size];
}

int value(string S){
  int ret= 0 ;

  int cnt=0;
  //std::cout << S << '\n';
  for(int i=0;i<S.size();i++){
    if(cnt==1 and S[i]=='_'){
      break;
    }
    if(S[i]=='_'){
      cnt++;
      continue;
    }
    else{
      ret+=(int)S[i];
    }
  }
  //std::cout << "ret "<<ret << '\n';
  return ret;
}


void find_book(string Bookname, map<int, std::vector< Book_Details* >> &book_hash_table, map<int,int> &hashf ){
    int ccc;
    ccc = value( "Harry Potter and the goblet of fire" );

    std::cout << "Found records: " << '\n';
    for(auto it:book_hash_table[key(ccc,hashf)]){
      if(value(it->book_name)==ccc){
        std::cout << it->book_id << '\n';
      }
    }
}

void delete_book_from_hash(string Book_id, string Bookname, map<int, std::vector< Book_Details* >> &book_hash_table, map<int,int> &hashf, std::vector< Book_Details* > &Book_Details_Table ){
    int ccc;
    ccc = value( Bookname );

    std::cout << "Found records: " << '\n';
    //Book_Details *to_be_del;
    int index = -1;
    bool found = false;
    Book_Details *to_be_del;
    for(auto it:book_hash_table[key(ccc,hashf)]){
      index+=1;
      if(value(it->book_name)==ccc and Book_id==it->book_id){
        to_be_del = it;
        found=true;
        break;
      }
    }

    if(found==false){
      return;
    }
    
    book_hash_table[key(ccc,hashf)].erase(book_hash_table[key(ccc,hashf)].begin()+index);
    //Book_Details_Table
    index = -1;
    //Book_Details *to_be_del;
    for(auto it:Book_Details_Table){
      index+=1;
      if(it==to_be_del){
        
        break;
      }
    }
    Book_Details_Table.erase(Book_Details_Table.begin()+index);
    delete to_be_del;

    //cout<< to_be_del->book_name<<"\n";

}

/////-------------------------------------------------





map<string,bool> tobecleaned;

int main(){
    vector<vector<string>> data;
    //vector<Book_Details> Book_Details_Table;
    vector<Book_Details*> Book_Details_Table;
    get_data_from_db("Book_details.txt", data);
    for(int i =0;i<data.size();i++){
        
        Book_Details *temp = new Book_Details;

        temp->book_id = data[i][0];
        temp->book_name = data[i][1];
        temp->author_id_1 = data[i][2];
        temp->author_id_2 = data[i][3];
        temp->author_id_3 = data[i][4];
        temp->genre = data[i][5];
        temp->version = stoi(data[i][6]);
        temp->total_copies = stoi(data[i][7]);
        temp->available_copies = stoi(data[i][8]);

        Book_Details_Table.push_back(temp);

        

        cout<<"\n";
    }

    for(int j =0;j<Book_Details_Table.size();j++){
        cout<<Book_Details_Table[j]->book_id<<" "<<Book_Details_Table[j]->book_name<<"\n";
    }

    map<int, std::vector< Book_Details* > > book_hash_table;
    map<int,int> hashf;

    for (int i = 0; i <  book_table_size; i++) {
      hashf[i] =  book_table_size;
    }
    

    int n=11;
    //cin>>n;

    
    int curr_book_table_size = 5;
    //int table_size =5;
    int curr_overflow_ptr=0;

    auto start1 = chrono::steady_clock::now();
    // do some stuff her

    for (int i = 0; i < Book_Details_Table.size(); i++) {
      std::cout << "********************************\n" << '\n';
      int inp;
      inp = value(Book_Details_Table[i]->book_name);
      //cin>>inp;

      // if overflow, add another entry..redistibute elements, else simply add
      if(book_hash_table[key(inp,hashf)].size()>=book_bucket_size){
        // add entry to table
        book_hash_table[curr_book_table_size]={};



        // update hash functions
        int index = curr_book_table_size-book_table_size;//key(inp,hashf);
        std::cout << "overflow "<<"arranging between "<<index<<" and "<<curr_book_table_size << '\n';
        int old_fun= hashf[index];
        hashf[index] = hashf[index]*2;
        hashf[curr_book_table_size] = hashf[index]; //0,..4,  5

        // redistibute the elements from curr_overflow_ptr
        std::vector<Book_Details*> tmp;
        for (int i = 0; i < book_hash_table[index].size(); i++) {
          if(key(value(book_hash_table[index][i]->book_name) ,hashf)==index){
            tmp.push_back(book_hash_table[index][i]);
          }
          else{
            book_hash_table[curr_book_table_size].push_back(book_hash_table[index][i]);
          }
        }
        book_hash_table[index]=tmp;

        book_hash_table[key(inp,hashf)].push_back(Book_Details_Table[i]);

        if(curr_overflow_ptr==book_table_size-1){
          curr_overflow_ptr=0;
          book_table_size*=2;
        }
        curr_book_table_size++;
      }
      else{
        int tmp1 = key(inp,hashf);
        std::cout << "Normal insertion at "<<tmp1 << '\n';
        book_hash_table[tmp1].push_back( Book_Details_Table[i]);
      }

      if(i==9){

        for (auto it: book_hash_table) {
          std::cout << it.first << '\n';
          for (auto it1:it.second) {
            std::cout<<"(" << it1->book_id << ' '<< it1->book_name<<")";
          }std::cout << '\n';
        }

      }
      std::cout << "********************************\n" << '\n';
    }
    
    find_book("Harry Potter and the goblet of fire", book_hash_table, hashf);
    // int ccc;
    // ccc = value( "Harry Potter and the goblet of fire" );

    // std::cout << "Found records: " << '\n';
    // for(auto it:book_hash_table[key(ccc,hashf)]){
    //   if(value(it->book_name)==ccc){
    //     std::cout << it->book_id << '\n';
    //   }
    // }
    delete_book_from_hash("567890", "Harry Potter and the goblet of fire", book_hash_table, hashf, Book_Details_Table);


    for (auto it: book_hash_table) {
        std::cout << it.first << '\n';
        for (auto it1:it.second) {
            std::cout<<"(" << it1->book_id << ' '<< it1->book_name<<")";
        }std::cout << '\n';
    }

    

    for (auto it: book_hash_table) {
        std::cout << it.first << '\n';
        for (auto it1:it.second) {
            std::cout<<"(" << it1->book_id << ' '<< it1->book_name<<")";
        }std::cout << '\n';
    }

    for (int  i = 0; i <Book_Details_Table.size(); i++)
    {
      cout<<"{"<<( Book_Details_Table[i])<<","<<( Book_Details_Table[i])->book_id<<"} ";
    }
    //Book_Details_Table.erase(Book_Details_Table.begin());
    cout<<"\n";
    for (int  i = 0; i <Book_Details_Table.size(); i++)
    {
      cout<<"{"<<( Book_Details_Table[i])<<","<<( Book_Details_Table[i])->book_id<<"} ";
    }
    cout<<"\n";
    cout<<(long int)( Book_Details_Table[0])-(long int)( Book_Details_Table[1])<<" "<<(long int) Book_Details_Table[1]-(long int) Book_Details_Table[2]<<" "<<sizeof(Book_Details_Table)<<"\n";
    //cout<<
    //store_data_to_db("Book_details.txt", data);
    //print_data(data);
    return 0;
}