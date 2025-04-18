#include "BookH.hpp"
#include "iostream"

using namespace std;
Book::Book(){
  title =" ";
  author = " ";
  ISBN = " ";
}
Book::Book(string t,string a,string i): title(t), author(a), ISBN(i) {}
Book::string getTitle(){
	return title;
}
Book::string getAuthor(){
  	return author;
}
Book::string getISBN(){
  	return ISBN;
}
Library::Library(){
	count = 0;
}
Library::void addBook(Book& b1){
	if(count<20){
    	books[count] = b1;
    	count++;
  	}
  	else{
    	cout<<"No space left to add another book!"<<endl;
  	}
}

Library::void removeBook(Book& b1){
    int flag=0;
    for(int i=0;i<count;i++){
        if(books[count].getISBN() == b1.getISBN()){
          count--;
          cout<<"Book removed!"<<endl;
          flag =1;
        }  
    }
  if(flag == 1){
    cout<<"Book "<<b1.getTitle()<<" has been removed!"<<endl;
  }
  else{
    cout<<"Book "<<b1.getTitle()<<" was not found!"<<endl;
  }
}

Library::void searchBook(Book &b1){
	int flag=0;
    for(int i=0;i<count;i++){
        if(books[count].getISBN() == b1.getISBN()){
          flag =1;
        }  
    }
    if(flag == 1){
    	cout<<"Book "<<b1.getTitle()<<" has been found!"<<endl;
  	}
  	else{
    	cout<<"Book "<<b1.getTitle()<<" was not found!"<<endl;
  	}
}
