#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include "product.h"


class Book : public Product {
    public:
        Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);
        virtual ~Book();
        std::string getAuthor();
        std::string getISBN();
        virtual std::set<std::string> keywords() const override;
        virtual std::string displayString() const override;
        void dump(std::ostream& os) const;


    private:
        std::string isbn_;
        std::string author_;


};


#endif