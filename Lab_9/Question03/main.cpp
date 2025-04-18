#include "BookH.hpp"
#include "iostream"

using namespace std;

int main(){
	Book b1("title1","Jack","t64887537");
	Book b2("code 01","wyatt","t64684845");
	Book b3("Dexter","Jim","t54676656");
	Book b4("Vamos","urvin","t57576862");
	Library l1;
	l1.addBook(b1);
	l1.addBook(b2);
	l1.addBook(b3);
	l1.addBook(b4);
	l1.removeBook(b3);
	l1.searchBook(b2);
	l1.searchBook(b3);
	return 0;
}
