#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "product.h"

class Movie : public Product {
    public:
    Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
    virtual ~Movie();
    virtual std::set<std::string> keywords() const override;
    virtual std::string displayString() const override;
    virtual void dump(std::ostream& os) const override;


    private:
    std::string genre_;
    std::string rating_;

};

#endif