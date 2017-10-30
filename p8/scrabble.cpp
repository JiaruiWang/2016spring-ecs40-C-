#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;

static const int TASK_LENGTH = 10;
static const char A = 'a';
static const int nLetters = 26;

typedef map<string, int> WordMap;

void setLetterMap(map<char, int> &letterMap)
{
  int value[nLetters] = {1, 3, 3, 2, 1, 4, 2, 4, 2, 8, 5, 1, 3, 1, 1, 3, 10,
    1, 1, 1, 1, 4, 4, 8, 4, 10};

  for (int i = 0; i < nLetters; ++i)
    letterMap.insert(map<char, int>::value_type(char(i + A), value[i]));
}//

void findWord(WordMap &wordMap, multimap<int, string> &stringMap,
              string &s, int deduct)
{
  string t = s;

  do 
  {  
    if (wordMap.find(s) != wordMap.end())
      stringMap.insert(multimap<int, string>::value_type
                       (wordMap.find(s)->second - deduct, s));

    next_permutation(s.begin(), s.end());
  } while(t != s); //
}//

void printWord(multimap<int, string> &stringMap,  string &s)
{
  set<string> answer;

  if (stringMap.empty())
    cout << setw(2) << right << 0 << " " << s << ": No words found.\n";
  else //
  {
    multimap<int, string>::reverse_iterator last = stringMap.rbegin();
    multimap<int, string>::reverse_iterator i = stringMap.rbegin();
    
    for (; i->first == last->first; i++)
      answer.insert(i->second);

    cout << setw(2) << right << last->first << " " << s << ":";

    for (set<string>::iterator it = answer.begin(); it != answer.end(); ++it)
      cout << " " << *it;

    cout << endl;
  }//  
}//

void replaceSpace(WordMap &wordMap, map<char, int> &letterMap, 
                  multimap<int, string> &stringMap, string &s)
{
  for (int i = 0; i < nLetters; ++i)
  {
    int pos = s.find(" ");
    s.replace(pos, 1, string(1, char(i + A)));
    findWord(wordMap, stringMap, s, letterMap.find(char(i + A))->second);
    s.replace(pos, 1, " ");
  }  //
}//

void getCombination(WordMap &wordMap, map<char, int> &letterMap, string &s)
{
  int all = 1;
  all = all << s.size(); 
  multimap<int, string> stringMap;

  for (int i = 1; i < all; ++i)
  {
    string temp;
    int index = 0;

    for (int j = 1; j < all; j <<= 1, index++)
      if (j & i)
        temp.push_back(s.at(index));

    if (temp.find(" ") != string::npos)
      replaceSpace(wordMap, letterMap, stringMap, temp);
    else //
      findWord(wordMap, stringMap, temp, 0);
  }//

  printWord(stringMap, s);
}//

void readTask(char const * filename, WordMap &wordMap, 
              map<char, int> &letterMap)
{
  ifstream infTask(filename);
  string t;

  while(getline(infTask, t))
    getCombination(wordMap, letterMap, t);

  infTask.close();
}//

bool isLower(char &c)
{
    return (c >= 'a' && c <= 'z');
}//

bool isLegal(string &word)
{
  if (word.length() > 7)
    return false;

  for (unsigned int i = 0; i < word.length(); ++i)
    if (!isLower(word.at(i)))
      return false;
  
  return true;
}//

int computeValue(string &word, map<char, int> &letterMap)
{
  int value = 0;

  for (unsigned int i = 0; i < word.length(); ++i)
    value += letterMap.find(word.at(i))->second;
  
  return value;
}//

void setWordMap(WordMap &wordMap, map<char, int> &letterMap)
{
  ifstream infWord("words.txt");
  string word;

  while(getline(infWord, word))
    if (isLegal(word))
      wordMap.insert(WordMap::value_type(word, computeValue(word, letterMap)));

  infWord.close();
}//

int main(int argc, char const **argv)
{
  map<char, int> letterMap;
  setLetterMap(letterMap);

  WordMap wordMap;
  setWordMap(wordMap, letterMap);

  readTask(argv[1], wordMap, letterMap);

  return 0;
}//