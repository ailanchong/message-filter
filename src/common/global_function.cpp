#include "global_function.h"
#include <iostream>
#include <string>

wstring string_to_wstring(const string& str){
    wstring wstr;
    size_t size = str.size();
    size_t index = 0;
    while(index < size){
        if ((str[index] & 0xfc) == 0xfc){
            wstr += (str[index] & 0x1)<<30 | (str[index+1] & 0x3f) << 24 | (str[index+2] & 0x3f) << 18 |
                       (str[index+3] & 0x3f) << 12 | (str[index+4] & 0x3f) << 6| (str[index+5] & 0x3f);
            index += 6;
        }
        else if ((0xf8 & str[index]) == 0xf8)
		{
			wstr += (str[index] & 0x3) << 24 | (str[index + 1] & 0x3f) << 18 | (str[index + 2] & 0x3f) << 12
				| (str[index + 3] & 0x3f) << 6 | (str[index + 4] & 0x3f);
			index += 5;
		}
		else if ((0xf0 & str[index]) == 0xf0)
		{
			wstr += (str[index] & 0x7) << 18 | (str[index + 1] & 0x3f) << 12 | (str[index + 2] & 0x3f) << 6
				| (str[index + 3] & 0x3f);
			index += 4;
		}
		else if ((0xe0 & str[index]) == 0xe0)
		{
			wstr += (str[index] & 0xf) << 12 | (str[index + 1] & 0x3f) << 6 | (str[index + 2] & 0x3f);
			index += 3;
		}
		else if ((0xc0 & str[index]) == 0xc0)
		{
			wstr += (str[index] & 0x1f) << 6 | (str[index + 1] & 0x3f);
			index += 2;
		}
		else
		{
			wstr += str[index];
			index += 1;
		}
    }
    return wstr;
}

string wstring_to_string(const wstring& wstr){
	size_t size = wstr.size();
	string result;
	for (size_t i = 0; i < size; i++){
		if (wstr[i] <= 0x7f){
			result = result + (char)(wstr[i]);
		}
		else if (wstr[i] <= 0x7ff){
			result = result + (char)((wstr[i] >> 6 & 0x1f) | 0xc0) + (char)((wstr[i] & 0x3f) | 0x80);
		}
		else if (wstr[i] <= 0xffff)
		{
			result = result + char((wstr[i] >> 12 & 0xf) | 0xe0) + char((wstr[i] >> 6 & 0x3f) | 0x80) + char((wstr[i] & 0x3f) | 0x80);
		}
		else if (wstr[i] <= 0x1fffff)
		{
			result = result + char((wstr[i] >> 18 & 0x7) | 0xf0) + char((wstr[i] >> 12 & 0x3f) | 0x80) + char((wstr[i] >> 6 & 0x3f) | 0x80)
				+ char((wstr[i] & 0x3f) | 0x80);
		}
		else if (wstr[i] <= 0x3ffffff)
		{
			result = result + char((wstr[i] >> 24 & 0x3) | 0xf8) + char((wstr[i] >> 18 & 0x3f) | 0x80) + char((wstr[i] >> 12 & 0x3f) | 0x80)
				+ char((wstr[i] >> 6 & 0x3f) | 0x80) + char((wstr[i] & 0x3f) | 0x80);
		}
		else if (wstr[i] <= 0x7fffffff)
		{
			result = result + char((wstr[i] >> 30 & 0x1) | 0xfc) + char((wstr[i] >> 24 & 0x3f) | 0x80) + char((wstr[i] >> 18 & 0x3f) | 0x80)
				+ char((wstr[i] >> 12 & 0x3f) | 0x80) + char((wstr[i] >> 6 & 0x3f) | 0x80) + char((wstr[i] & 0x3f) | 0x80);
		}
	}
	return result;

}
/*
int main(){
	string a = "我爱中国";
	cout<< a<<a.size()<<endl;
	wstring b = string_to_wstring(a);
	string c = wstring_to_string(b);
	cout<< c <<c.size()<<endl;
	return 0;
}
*/


