#pragma once

#include <string>
#include <vector>
#include <regex>
#include <ctime>
#include <map>

#define GBSTR GBString::Instance()

class GBString
{
public:

    static GBString& Instance()
    {
        static GBString strBdr_;
        return strBdr_;
    }

    //Appends other string
    void append(std::string& str, std::string str_);

    //Removes the characters between start and end (both included)
    void cut(std::string& str, unsigned int start, unsigned int end);

    //Returns a substring with the characters between start and end (both included)
    std::string getCut(std::string str, unsigned int start, unsigned int end);

    //Inserts a string in a position
    void insert(std::string& str, unsigned int position, std::string str_);

    //Erases the string
    void erase(std::string& str);

    //Reverses the string
    void reverse(std::string& str);

    //Transforms every character of the string into uppercase (only ASCII characters)
    void toUpperCase(std::string& str);

    //Transforms every character of the string into lowercase (only ASCII characters)
    void toLowerCase(std::string& str);

    //Transforms the characters between start and end of the string into uppercase (only ASCII characters)
    //both start and end included
    void toUpperCase(std::string& str, unsigned int start, unsigned int end);

    //Transforms the characters between start and end of the string into lowercase (only ASCII characters)
    //both start and end included
    void toLowerCase(std::string& str, unsigned int start, unsigned int end);

    //Returns true if the string contains at least one time this character
    bool containsChar(std::string& str, char c);

    //Returns true if the string contains at least one character for each character in the collection
    bool containsChar(std::string str, std::vector<char> chars);

    //Removes every of this character in the string
    void eraseChar(std::string& str, char c);

    //Removes every these characters in the string
    void eraseChars(std::string& str, std::vector<char> chars);

    //Returns true if the string matches with a regex pattern
    bool matches(std::string& str, std::string pattern);

    //Replaces every character in the string for other character
    void replaceChar(std::string& str, char original, char replace);
    
    //Replaces every characters in the string with others
    void replaceChars(std::string& str, std::map<char, char> chars);

    //Replaces every character in the string for other character from "start" to "end" (both included)
    void replaceCharInRange(std::string& str, char original, char replace, unsigned int start, unsigned int end);

    //Replaces all substrings with the same value as the first one with the second one
    void replace(std::string& str, std::string original, std::string replace);

    //Replaces all substrings with se same value as the firts ones with the second ones
    void replace(std::string& str, std::map<std::string, std::string> substrs);

    //Encrypts the string with a key
    void encrypt(std::string& str, std::string key);

    //Decrypts the string with a key
    std::string decrypt(std::string str, std::string key);

    //Returns true if the string contains a specific substring
    bool search(std::string str, std::string search);

    //Splits the string in a collection using a separator character (not included in the collection)
    std::vector<std::string> split(std::string str, char separator);

    //Returns the number of times that "c" is in the string
    int count(std::string str, char c);

    //Returns the number of times that a substring is in the string
    int count(std::string str, std::string substr);

    //Returns all the positions of a character in the string
    std::vector<unsigned int> getPositionList(std::string str, char c);

    //Fuses a string collection in one string
    std::string fuse(std::vector<std::string> chain, char join = '\0');

private:

    GBString()
    {

    };

    std::vector<char> chars = 
    {
    'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u',
    'v', 'w', 'x', 'y', 'z', '{', '}',
    '<', '>', '"', '=', '[', ']', ';',
    '1', '2', '3', '4', '5', '6', '7',
    '8', '9', '0', 'A', 'B', 'C', 'D',
    'E', 'F', 'G', 'H', 'I', 'J', 'K',
    'L', 'M', 'N', 'O', 'P', 'Q', 'R',
    'S', 'T', 'U', 'V', 'W', 'X', 'Y',
    'Z', '.', ',', '(', ')', '$', '%',
    '@', '#', '?', '/', '&', '!', '|',
    ':', '-', '_'
    };

    std::vector<unsigned int> getIndexList(std::string key);
};
