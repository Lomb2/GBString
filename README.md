# GBString
GBString is a C++ library for std::string variable management. 


## Purpose
This little library contains many useful methods for string management, all in only one singleton!

You may want to insert a substring inside other, or count how many times a substring is duplicated in a string, or maybe replace the same character... and end with a lot of StackOverflow functions dirtying your project, well, GBString is the solution! 

## Example 1:

The following code changes "Im using ??? to edit this!" to "Im using GBString to edit this!". First searchs all the positions of the '?' character, then cuts the string
from poslist[0] (the first '?' position found in the string) to poslist.back() (the last '?' position found in the string), then inserts in poslist[0] the substring "GBString".
```
std::string str = "Im using ??? to edit this!";

auto poslist = GBSTR.getPositionList(str, '?');

GBSTR.cut(str, poslist[0], poslist.back());

//Inserts a substring to the string
GBSTR.insert(str, poslist[0], "GBString");
```

## Example 2:

The following code replaces the character '=' to 'a', '{' to 'e', '&' to 'i' and '$' to 'u'. 
```
std::string str = "$h n$! th&s str&ng d${snt h=v{ th{ c$rr{ct ch=r=ct{rs!";

GBSTR.replaceChars(str,{ {'=', 'a'},{'{', 'e'},{'&', 'i'}, {'$','o'} });
```

## Example 3:

The following code returns the number of times the substring "pesto" appears in the string.
```
std::string str = "I love pesto for sure!, pesto is an italian sauce and its declicius!";

std::cout << GBSTR.count(str, "pesto") << "\n";
```

## Install

Just put the .hpp and .cpp files in your project! 
