#ifndef __ALGORITHM_MANAGER_H__
#define __ALGORITHM_MANAGER_H__

#include <string> 
#include<unordered_map> 
using namespace std;
class CAlgorithmManager 
{
public:
	CAlgorithmManager();
	~CAlgorithmManager();

	void addAllChatCount(const std::string& uid);
	void addLengthLessThan3ChatCount(const std::string& uid);
	void addIntoWindowCount(const std::string& uid);
	void addAdCountByPinyinCheck(const std::string& uid);
	void addAdCountByWindowCheck(const std::string& uid);

	int getAllChatCount(const std::string& uid);
	int getLengthLessThan3ChatCount(const std::string& uid);
	int getIntoWindowCount(const std::string& uid);
	int getAdCountByPinyinCheck(const std::string uid);
	int getAdCountByWindowCheck(const std::string& uid);

	double getIsAdvUserRate(const std::string& uid);

	static CAlgorithmManager* instance();

private:
	unordered_map<std::string, int> m_all_chat_count;
	unordered_map<std::string, int> m_length_less_than3_chat_count;
	unordered_map<std::string, int> m_into_window_count;
	unordered_map<std::string, int> m_ad_count_by_pinyin_check;
	unordered_map<std::string, int> m_ad_count_by_window_check;
	static CAlgorithmManager* p; 
};

#endif
