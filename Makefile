CXX=g++
CXXFLAGS=-g -Wall -std=c++11

OBJS=amazon.o user.o db_parser.o product.o product_parser.o util.o mydatastore.o book.o clothing.o movie.o

all: amazon

amazon: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

amazon.o: amazon.cpp db_parser.h datastore.h product_parser.h
	$(CXX) $(CXXFLAGS) -c amazon.cpp

user.o: user.cpp user.h
	$(CXX) $(CXXFLAGS) -c user.cpp

# Add other object files compilation rules here

book.o: book.cpp book.h product.h
	$(CXX) $(CXXFLAGS) -c book.cpp

clothing.o: clothing.cpp clothing.h product.h
	$(CXX) $(CXXFLAGS) -c clothing.cpp

movie.o: movie.cpp movie.h product.h
	$(CXX) $(CXXFLAGS) -c movie.cpp

# Ensure to replace spaces with a tab in your Makefile for the lines starting with $(CXX)

clean:
	rm -f *.o amazon
