#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>

#include <vector>
#include <set>

//
using namespace std; 

std::set<std::string> parseStringToWords(string rawWords)
{
    set<string> keywords;
    istringstream iss(rawWords);
    string word;
    string emptyString;
    int index = 0;
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




int main() {
    string text = "Hello, world! This is a an example: demonstrating I'll iteration. theses'nice 978-000000000-1";
    set<string> testSet = parseStringToWords(text);
    
for (set<string>::iterator it = testSet.begin(); it != testSet.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}


