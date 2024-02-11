#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include "util.h"
#include "product.h"
#include <vector>
#include <string>
#include <map>
#include "user.h"

class MyDataStore : public DataStore {
    public: 
        MyDataStore();
        virtual ~MyDataStore();

        virtual void addProduct(Product* p) override;
        virtual void addUser(User* u) override;
        std::vector<Product *> search(std::vector<std::string>& terms, int type) override;
        virtual void dump(std::ostream& ofile) override;
        void addProductToCart(Product*, User*); 
        void viewCart(User*);
        void buyCart(User*); 

    private:
        std::unordered_map<std::string, std::set<Product*>> productsForKeyword;
        std::map<std::string, User*> users;
        std::map<User*, std::vector<Product*>> cart; 


};

#endif