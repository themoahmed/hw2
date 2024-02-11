#include "mydatastore.h"
#include "user.h"
#include <iostream>

using namespace std; 

MyDataStore::MyDataStore() {

}

MyDataStore::~MyDataStore() {

}

void MyDataStore::addProduct(Product* p){

}

void MyDataStore::addUser(User* u){

}

vector<Product*> MyDataStore::search(vector<string>& terms, int type){
    vector<Product*> results;

    return results;
}

void MyDataStore::dump(ostream& ofile) {
    delete &ofile;
}

void MyDataStore::addProductToCart(Product*, User* u){

}

void MyDataStore::viewCart(User* u){

}

void MyDataStore::buyCart(User* u){

}