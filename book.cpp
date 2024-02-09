#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"

Book::Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author):
    Product(category, name, price, qty),
    isbn_(isbn),
    author_(author)

{

}

std::set<std::string> Book::keywords() const {
    std::set<std::string> keyWords = parseStringToWords(name_);
    std::set<std::string> authorWords = parseStringToWords(author_);
    keyWords.insert(authorWords.begin(), authorWords.end());
    keyWords.insert(isbn_);
    return keyWords;
}

std::string Book::displayString() const {
    return name_ + "\nAuthor: " + author_ + " ISBN: " + isbn_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
}

void Book::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << std::endl;
}