#include "algorithm_manager.h"

CAlgorithmManager*  CAlgorithmManager::p = new CAlgorithmManager();

CAlgorithmManager* CAlgorithmManager::instance(){
	return p;
}

CAlgorithmManager::CAlgorithmManager()
{

}

CAlgorithmManager::~CAlgorithmManager()
{

}

void CAlgorithmManager::addAllChatCount(const std::string& uid)
{
	++m_all_chat_count[uid];
}

void CAlgorithmManager::addLengthLessThan3ChatCount(const std::string& uid)
{
	++m_length_less_than3_chat_count[uid];
}

void CAlgorithmManager::addIntoWindowCount(const std::string& uid)
{
	++m_into_window_count[uid];
}

void CAlgorithmManager::addAdCountByPinyinCheck(const std::string& uid)
{
	++m_ad_count_by_pinyin_check[uid];
}

void CAlgorithmManager::addAdCountByWindowCheck(const std::string& uid)
{
	++m_ad_count_by_window_check[uid];
}

int CAlgorithmManager::getAllChatCount(const std::string& uid)
{
	return m_all_chat_count[uid];
}

int CAlgorithmManager::getLengthLessThan3ChatCount(const std::string& uid)
{
	return m_length_less_than3_chat_count[uid];
}

int CAlgorithmManager::getIntoWindowCount(const std::string& uid)
{
	return m_into_window_count[uid];
}

int CAlgorithmManager::getAdCountByPinyinCheck(const std::string uid)
{
	return m_ad_count_by_pinyin_check[uid];
}

int CAlgorithmManager::getAdCountByWindowCheck(const std::string& uid)
{
	return m_ad_count_by_window_check[uid];
}

double CAlgorithmManager::getIsAdvUserRate(const std::string& uid)
{
	return m_all_chat_count[uid] > 20 ? (m_ad_count_by_pinyin_check[uid] + m_ad_count_by_window_check[uid]) / m_all_chat_count[uid] : 0;
}
