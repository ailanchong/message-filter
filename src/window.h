#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <iostream>
using namespace std;

class window{
protected:
    window(){};
public:
    static window* instance();
    bool check(wstring msg, string usr_id)
private:  
    static window* p;
    

}
window* window::p = new window;
window* window::instance(){
    return p;
}



#endif
