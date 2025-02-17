#include<iostream>
#include<string.h>
using namespace std;

class LibraryItem {
         private:
                 static int uniqueCounter;
                 int uniqueID;
                 string* bookName;
                 float* cost;
                 int* quantity;
         public:
                LibraryItem(string name, float price, int stock): uniqueID(++uniqueCounter){
                         bookName = new string(name);
                         cost = new float(price);
                         quantity = new int(stock);
                }
                
                // Copy Constructor
                LibraryItem(const LibraryItem& obj) : uniqueID(++uniqueCounter) {  
                        bookName = new string(*obj.bookName);
                        cost = new float(*obj.cost);
                        quantity = new int(*obj.quantity);        
                }

                // Copy Assignment Operator
                LibraryItem& operator=(const LibraryItem& obj){
                    if (this != &obj) {
                        *bookName = *obj.bookName;
                        *cost = *obj.cost;
                        *quantity = *obj.quantity;
                    }
                    return *this;
                }

                int getItemID(){
                        return uniqueID;
                }
                string getBookName(){
                        return *bookName;
                }
                float getCost(){
                        return *cost;
                }
                int getQuantity(){
                        return *quantity;
                }
                void setQuantity(int stock){
                        *quantity = stock;
                }

                void modifyItemDetails(){
                        cout<<"Modifying Book Information!"<<endl;
                        cout<<"Enter new book name: ";
                        cin>>*bookName;
                        cout<<"Enter updated price: ";
                        cin>>*cost;
                        cout<<"The new price of "<<*bookName<<" is: "<<*cost<<endl;
                        cout<<"Enter updated stock: ";
                        cin>>*quantity;
                        cout<<"New stock for "<<*bookName<<" is: "<<*quantity<<endl;
                }

                int processTransaction(LibraryItem inventory[], int size){
                        string requestedBook;
                        int payment, requestedCopies;
                        float balance;
                        cout<<"Enter the name of the book you're looking for: ";
                        cin>>requestedBook;
                        for(int i=0; i<size; i++){
                                if(inventory[i].getBookName() == requestedBook){
                                        if(inventory[i].getQuantity() < 5){
                                                cout<<"Low stock alert! Consider restocking."<<endl;
                                                return 0;
                                        }
                                        cout<<"Current price per copy: "<<inventory[i].getCost()<<endl;
                                        cout<<"How many copies would you like to purchase? ";
                                        cin>>requestedCopies;
                                        int remainingStock = inventory[i].getQuantity() - requestedCopies;
                                        if(remainingStock < 0){
                                                cout<<"Transaction failed! Insufficient stock. Missing copies: "<<-1 * remainingStock<<endl;
                                                return 0;
                                        }
                                        float totalAmount = requestedCopies * inventory[i].getCost();
                                        float discountedTotal = applyDiscount(requestedCopies, totalAmount);
                                        cout<<"Please enter payment amount: ";
                                        cin>>payment;
                                        balance = payment - discountedTotal;
                                        cout<<"Transaction successful!" << (balance > 0.0 ? " Your change: " + to_string(balance) : "") << endl;

                                        inventory[i].setQuantity(remainingStock);
                                        if(inventory[i].getQuantity() < 5){
                                                cout<<"Low stock alert! Consider restocking."<<endl;
                                        }
                                        return 1;
                                }
                        }
                        cout<<"Book unavailable in inventory!"<<endl;
                        return 0;
                }

                float applyDiscount(int copies, float totalCost){
                        if(copies > 5 && copies < 10){
                                float newPrice = 0.95 * totalCost;
                                cout<<"Discount of 5% applied! New total: "<<newPrice<<endl;
                                return newPrice;
                        }                
                        else if(copies > 10){
                                float newPrice = 0.90 * totalCost;
                                cout<<"Discount of 10% applied! New total: "<<newPrice<<endl;
                                return newPrice;        
                        }
                        else{
                                cout<<"Total payable amount: "<<totalCost<<endl;
                                return totalCost;
                        }
                }
                void displayItem(){
                        cout<<"Book Details:"<<endl;
                         cout<<"Item ID: "<<getItemID()<<endl;
                         cout<<"Name: "<<getBookName()<<endl;
                         cout<<"Price: "<<getCost()<<endl;
                         cout<<"Available Stock: "<<getQuantity()<<endl;
                         cout<<endl;
                }

                ~LibraryItem(){
                        delete bookName;
                        delete cost;
                        delete quantity;
                        cout<<"Memory cleared. Object deleted."<<endl;
                }        
 };
 
 int LibraryItem::uniqueCounter = 0;

 int main(){
         LibraryItem bookA("Origins", 59.99, 40);
         LibraryItem bookB(bookA);
         cout<<"Details of First Book:"<<endl;
         bookA.displayItem();
         cout<<"Details of Copied Book:"<<endl;
         bookB.displayItem();
         return 0;
 }
