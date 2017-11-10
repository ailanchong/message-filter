#include "window.h"

bool window::check(wstring msg, string usr_id){
    msg.push_back(0);
    wchar_t pre, next;
    pre = next = 0;
    set<wstring> new_word_set;
    for (size_t i = 0; i < msg.size(); i++){
        if (msg[i] == 12288 || msg[i] == 32){
            continue;
        }
        if (msg[i] >= 65281 && msg[i] <= 65374){
            next = msg[i] - 65248;
        }
        else{
            next = msg[i];
        }
        wstring curr_word;
        curr_word.push_back(pre);
        curr_word.push_back(next);
        pre = next;
        new_word_set.insert(curr_word);
    }
    /**先固定阈值，后期再利用单例模块改为变动的阈值*/
    int corret_pairWordNum = 0;
    set<wstring>::iterator iter = new_word_set.begin();
    for(; iter != new_word_set.end(); iter++){
        unordered_map<wstring, int>::iterator it_ad = m_advWordCount.find(*iter);
        int advWordCount = (it_ad != m_advWordCount.end() ? it_ad->second : 0);
        unordered_map<wstring, int>::iterator it_notad = m_notadvWordCount.find(*iter);
        int notadvWordCount = (it_notad != m_notadvWordCount.end()? it_notad->second : 0);
        if (advWordCount > 0 && advWordCount > 0.05 * (advWordCount + notadvWordCount))
            corret_pairWordNum++;
    }
    bool mark_through_pair = false;
    if (corret_pairWordNum >= 2){
        //用户经过滑动窗被判别为广告数加1
        //进行用户条件判断
        return true;
    }
    //更新数据结构字典
    m_msgRecord.push(new_word_set);
    m_usrRecord.push(usr_id);
    for (iter = new_word_set.begin(); iter != new_word_set.end(); iter++){
        m_pairWordCount[*iter] ++;
        m_wordCount[iter->at(0)] ++;
        m_pairUsrTotal[*iter][usr_id] ++;  
    }
    if (m_msgRecord.size() <= 1000)
        return false;
    // 跳出队列队列第一条内容
    set<wstring> old_word_set = m_msgRecord.front();
    string old_usr_id = m_usrRecord.front();
    // 更新数据结构字典
    m_msgRecord.pop();
    m_usrRecord.pop();
    for (iter = old_word_set.begin(); iter != old_word_set.end(); iter++){
        m_pairWordCount[*iter] --;
        m_wordCount[iter->at(0)] --;
        m_pairUsrTotal[*iter][old_usr_id] --;
        if (m_pairUsrTotal[*iter][old_usr_id] == 0)
            m_pairUsrTotal[*iter].erase(old_usr_id);
    }
    corret_pairWordNum = 0;
    //添加词对到词对模块
    set<wstring> add_pair_model;
    for(iter = new_word_set.begin(); iter != new_word_set.end(); iter++){
        if (m_pairWordCount[*iter] > 0.2 * m_wordCount[iter->at(0)] 
            && (*iter)[0] != (*iter)[1]
            && m_pairWordCount[*iter] > 3 * (m_pairUsrTotal[*iter].size())
            ){
                corret_pairWordNum ++;
                add_pair_model.insert(*iter);

            }
            // 忽略了特殊字符的限制条件
    }       
    
    if (corret_pairWordNum >= 2){
        //忽略用户条件
        for (iter = add_pair_model.begin(); iter != add_pair_model.end(); iter++){
            m_advWordCount[*iter] ++;
        }

    }
    else{
        for (iter = new_word_set.begin(); iter != new_word_set.end(); iter++){
            m_notadvWordCount[*iter] ++;
        }
    }
}

