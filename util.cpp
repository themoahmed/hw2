#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

//
using namespace std; 

std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    set<string> keywords;
    rawWords = convToLower(rawWords);
    istringstream iss(rawWords);
    string word;
    string emptyString;
    std::string::size_type index = 0; 

    while (iss >> word){

        if(isdigit(word[0])){
            keywords.insert(word);
            continue;
        }
         
        if(word.length() >= 2){
                for (char c : word){
                    //Addresses the last character

                    
                    if (index == word.length()-1){

                        if (!ispunct(c)){
                            emptyString += c; 
                        }
                        //if the word is more the 2, insert
                        if (emptyString.length() >= 2){

                            keywords.insert(emptyString);
                            
                        }
                        //reset for next word
                        index = 0;
                        emptyString = "";
                        continue;
                    }

                    //If you reach a punctuation 
                    if (ispunct(c)){

                        if (emptyString.length() >= 2){
                            keywords.insert(emptyString);
                        } 
                        emptyString = "";
                        index++;
                        continue;
                    }
                        emptyString += tolower(c);
                        index++;
                        continue;
                    
                
            }
        }
        
    }
    
    return keywords;

}


/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
