#ifndef WINDOW_H
#define WINDOW_H

#include<string>
#include<unordered_map> 
#include<iostream>
#include<set>
#include<queue>
using namespace std;

class window{
protected:
    window(){};
public:
    static window* instance();
    bool check(wstring msg, string usr_id);
private:  
    static window* p;
    set<wchar_t> m_special_word;
    unordered_map<wstring, int> m_advWordCount;
    unordered_map<wstring, int> m_notadvWordCount;
    queue<set<wstring>> m_msgRecord;
    queue<string> m_usrRecord;
    unordered_map<wstring, int> m_pairWordCount;
    unordered_map<wchar_t, int> m_wordCount;
    unordered_map<wstring, unordered_map<string, int>> m_pairUsrTotal;

};


#endif
