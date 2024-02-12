#include "mydatastore.h"
#include "user.h"
#include <iostream>
#include <iomanip>
#include "product.h"


using namespace std; 

MyDataStore::MyDataStore() {

}

MyDataStore::~MyDataStore() {
    for (std::vector<Product*>::iterator it = listOfProducts.begin(); it != listOfProducts.end(); ++it) {
        delete *it;
    }

    for (std::vector<User*>::iterator it = listOfUsers.begin(); it != listOfUsers.end(); ++it) {
        delete *it;
    }
}

void MyDataStore::addProduct(Product* p){
    //Add to the list of products
    listOfProducts.push_back(p);

    //get the keywords and add them to map
    set<string> productKeywords = p -> keywords();
    set<string>::iterator it = productKeywords.begin();
    while( it != productKeywords.end()){
        string keyword = *it;
        productsForKeywords[keyword].insert(p);
        it++;
    }

}

void MyDataStore::addUser(User* u){
    listOfUsers.push_back(u);
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type){
    vector<Product*> finalResults;
    set<Product*> results;
    set<Product*> andSet1;
    
  
    string firstKeyword = terms[0];
    andSet1 = productsForKeywords[firstKeyword];

    if (type == 1){

        for(size_t i = 0; i<terms.size(); i++ ){
            string keyword = terms[i];
            for(set<Product*>::iterator it = productsForKeywords[keyword].begin(); it != productsForKeywords[keyword].end(); it++ ){
                results.insert(*it);   
            }
        }

         for(set<Product*>::iterator it2 = results.begin(); it2 != results.end(); it2++){
        finalResults.push_back(*it2);
        }


   
    }else{
        for(size_t j = 1; j<terms.size(); j++ ){
            string keyword = terms[j];
            set<Product*> set2 = productsForKeywords[keyword]; 
            andSet1 = setIntersection(andSet1, set2);
          

            
        }

         for(set<Product*>::iterator it2 = andSet1.begin(); it2 != andSet1.end(); it2++){
        finalResults.push_back(*it2);
        }
    }


    return finalResults;
}

void MyDataStore::dump(ostream& ofile) {
    ofile << "<products>\n";
    for (Product* product : listOfProducts) {
        product->dump(ofile);
    }
    ofile << "</products>\n"; 

    ofile << "<users>\n";
    for (User* user : listOfUsers) {
        user->dump(ofile);
    }
    ofile << "</users>\n"; 
    ofile.flush(); 

}

void MyDataStore::addProductToCart(Product* p, User* u){



    map<User*, vector<Product*>>::iterator cartIt = cart.find(u);

    if (cartIt != cart.end()) {
        // If the user's cart exists, add the product to it
        cartIt->second.push_back(p);
    } else {
        // If the user's cart does not exist, create a new one and add the product
        vector<Product*> newCart;
        newCart.push_back(p);
        cart[u] = newCart; // Using 'u' directly since it's already a User* pointer
    }

}

void MyDataStore::viewCart(User* u){
    map<User*, vector<Product*>>::iterator cartIt = cart.find(u);
    if (cartIt == cart.end()) {
        std::cout << "Cart is empty or user does not exist." << std::endl;
        return;
    }

    // Retrieve the vector of products for the user
    std::vector<Product*> userCart = cartIt->second;

    // If the cart is empty, inform the user
    if (userCart.empty()) {
        std::cout << "Your cart is empty." << std::endl;
        return;
    }

    // Iterate through the products in the cart and display them
    for (size_t i = 0; i < userCart.size(); ++i) {
        std::cout << "Item " << i + 1 << endl; // Display item number starting from 1
        std::cout << userCart[i]->displayString() << endl;
        std::cout << endl; // Assuming Product has a method displayString() for a concise product description
    }
}

void MyDataStore::buyCart(User* u){
    map<User*, vector<Product*>>::iterator cartIt = cart.find(u);
    if (cartIt == cart.end()) {
        cout << "Cart not found for the user." << endl;
        return;
    }

    // Retrieve the user's cart
    vector<Product*>& userCart = cartIt->second;
    double totalCost = 0;

    // Iterate through the cart items
    for (vector<Product*>::iterator it = userCart.begin(); it != userCart.end(); ) {
        Product* product = *it;
        // Check if the item is in stock and the user has enough money
        if (product->getQty() > 0 && u->getBalance() >= product->getPrice()) {
            totalCost += product->getPrice();
            product->subtractQty(1); // Decrease the quantity by 1
            u->deductAmount(product->getPrice()); // Deduct the product's price from the user's balance
            
            // Remove purchased item from the cart
            it = userCart.erase(it);
        } else {
            
            ++it;
        }
    }


    if (totalCost > 0) {
        cout << "Purchase successful. Total cost: " << totalCost << endl;
    } else {
        cout << "No items were purchased." << endl;
    }

}

User* MyDataStore::getUser(string username) {
    for(User* user : listOfUsers) {
        if(user->getName() == username) {
            return user;
        }
    }
    return nullptr; 
}
