#include <sstream>
#include <iomanip>
#include "movie.h"
#include "util.h"
using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating):
    Product(category, name, price, qty),
    genre_(genre),
    rating_(rating)
    {
    }

Movie::~Movie() {}

std::set<std::string> Movie::keywords() const {

    string genreLower = name_ + " " + genre_;
    std::set<std::string> keywords = parseStringToWords(genreLower);
    
    return keywords;
}

std::string Movie::displayString() const {
    return name_ + "\nGenre: " + genre_ + " Rating: " + rating_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
}

void Movie::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << std::endl;
}