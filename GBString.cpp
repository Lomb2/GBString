#include "GBString.hpp"

void GBString::append(std::string& str, std::string str_)
{
    str += str_;
}

std::string GBString::getCut(std::string str, unsigned int start, unsigned int end)
{
    return str.substr(start, (end - start) + 1);
}

void GBString::cut(std::string& str, unsigned int start, unsigned int end)
{
    std::string substr1 = getCut(str, 0, start - 1);
    std::string substr2 = getCut(str, end + 1, str.length());

    str = substr1 + substr2;
}

void GBString::insert(std::string& str, unsigned int position, std::string str_)
{
    str.insert(position, str_);
}

void GBString::erase(std::string& str)
{
    str = "";
}

void GBString::reverse(std::string& str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        std::swap(str[i], str[str.length() - i - 1]);
    }
}

void GBString::toUpperCase(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

void GBString::toLowerCase(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void GBString::toUpperCase(std::string& str, unsigned int start, unsigned int end)
{
    std::string substr1 = getCut(str, 0, start);
    std::string substr2 = getCut(str, start, end);
    std::string substr3 = getCut(str, end, str.length());

    toUpperCase(substr2);

    str = substr1 + substr2 + substr3;
}

void GBString::toLowerCase(std::string& str, unsigned int start, unsigned int end)
{
    std::string substr1 = getCut(str, 0, start);
    std::string substr2 = getCut(str, start, end);
    std::string substr3 = getCut(str, end, str.length());

    toLowerCase(substr2);

    str = substr1 + substr2 + substr3;
}

bool GBString::containsChar(std::string& str, char c)
{
    return str.find(c) < str.length();
}

bool GBString::containsChar(std::string str, std::vector<char> chars)
{
    for (auto& c : chars)
    {
        if (containsChar(str, c)) return true;
    }

    return false;
}

void GBString::eraseChar(std::string& str, char c)
{
    std::string result;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != c) result += str[i];
    }

    str = result;
}

void GBString::eraseChars(std::string& str, std::vector<char> chars)
{
    for (auto& c : chars)
    {
        eraseChar(str, c);
    }
}

bool GBString::matches(std::string& str, std::string pattern)
{
    static const std::regex re{ pattern };

    return std::regex_match(str, re);
}

void GBString::replaceChar(std::string& str, char original, char replace)
{
    std::replace(str.begin(), str.end(), original, replace);
}

void GBString::replaceChars(std::string& str, std::map<char, char> chars)
{
    for (auto& cs : chars)
    {
        replaceChar(str, cs.first, cs.second);
    }
}

void GBString::replaceCharInRange(std::string& str, char original, char replace, unsigned int start, unsigned int end)
{
    std::string substr1 = getCut(str, 0, start);
    std::string substr2 = getCut(str, start, end);
    std::string substr3 = getCut(str, end, str.length());

    replaceChar(substr2, original, replace);

    str = substr1 + substr2 + substr3;
}

void GBString::removeChar(std::string& str, char c)
{
    replaceChar(str, c, '\0');
}

std::vector<unsigned int> GBString::getIndexList(std::string key)
{
    std::vector<unsigned int> indexList;
    bool indexationComplete = false;
    int index, cont = 0;
    bool repeated;
    unsigned int seed = std::hash<std::string>{}(key);

    srand(seed);

    while (!indexationComplete)
    {
        repeated = false;

        index = rand() % chars.size();

        for (auto i : indexList)
        {
            if (i == index)
            {
                repeated = true;
                break;
            }
        }

        if (!repeated)
        {
            indexList.push_back(index);
            cont++;
        }

        if (cont == chars.size()) indexationComplete = true;
    }

    srand(time(NULL));

    return indexList;
}

void GBString::encrypt(std::string& str, std::string key)
{
    std::vector<unsigned int> indexList = getIndexList(key);
    int j;
    bool exit;

    for (int i = 0; i < str.length(); i++)
    {
        j = 0;
        exit = false;

        while (j < chars.size() && !exit)
        {
            if (str[i] == chars[j])
            {
                str[i] = chars[indexList[j]];
                exit = true;
            }

            j++;
        }
    }
}

std::string GBString::decrypt(std::string str, std::string key)
{
    std::vector<unsigned int> indexList = getIndexList(key);
    int j;
    bool exit;

    for (int i = 0; i < str.length(); i++)
    {
        j = 0;
        exit = false;

        while (j < chars.size() && !exit)
        {
            if (str[i] == chars[indexList[j]])
            {
                str[i] = chars[j];
                exit = true;
            }

            j++;
        }
    }

    return str;
}

//original code -> https://stackoverflow.com/questions/27286515/find-and-replace-words-in-c
void GBString::replace(std::string& str, std::string original, std::string replace)
{
    for (size_t pos = 0; ; pos += replace.length())
    {
        pos = str.find(original, pos);
        if (pos == std::string::npos) break;

        str.erase(pos, original.length());
        str.insert(pos, replace);
    }
}

bool GBString::search(std::string str, std::string search)
{
    if (strstr(str.c_str(), search.c_str())) return true;

    return false;
}

std::vector<std::string> GBString::split(std::string str, char separator)
{
    std::vector<std::string> strings;
    std::string current_str = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == separator)
        {
            strings.push_back(current_str);
            current_str = "";
        }
        else if (i == str.length() - 1)
        {
            current_str += str[i];
            strings.push_back(current_str);
        }
        else
        {
            current_str += str[i];
        }
    }

    return strings;
}

int GBString::count(std::string str, char c)
{
    return std::count(str.begin(), str.end(), c);
}

int GBString::count(std::string str, std::string substr)
{
    int count = 0;
    int i = 0;

    while (i < str.length())
    {
        if (str[i] == substr[0] && str[i + substr.length() - 1] == substr[substr.length() - 1])
        {
            std::string _substr = "";

            int k = i;

            while (i < substr.length() + k)
            {
                _substr += str[i];
                i++;
            }

            if (_substr == substr) count++;

            i = k;
        }

        i++;
    }

    return count;
}

std::vector<unsigned int> GBString::getPositionList(std::string str, char c)
{
    int i = 0;

    std::vector<unsigned int> positions;

    while (i < str.length())
    {
        if (str[i] == c) positions.push_back(i);

        i++;
    }

    return positions;
}

std::string GBString::fuse(std::vector<std::string> chain, char join)
{
    std::string str = "";

    for (int i = 0; i < chain.size(); i++)
    {
        str += chain[i];

        if (i != chain.size() - 1) str += join;
    }

    return str;
}
