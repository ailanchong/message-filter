#include "algorithm_window.h"
#include "global_function.h"
#include <fstream>
#include "cJSON.h"
#include "chatmonitor.h"

using namespace std;

int main0()
{
	initialize("server.properties");
	ifstream ifs("test", ifstream::binary);
	string str;
	while (getline(ifs, str))
	{
		cJSON* json = cJSON_Parse(str.c_str());
// 		const char* developer_id = cJSON_GetObjectItem(json, "develop_id")->valuestring;
// 		const char* game_id = cJSON_GetObjectItem(json, "game_id")->valuestring;
// 		const char* server_id = cJSON_GetObjectItem(json, "server_id")->valuestring;
// 		const char* user_id = cJSON_GetObjectItem(json, "user_id")->valuestring;
		const char* user_id = "123";
// 		const char* time_stamp = cJSON_GetObjectItem(json, "time")->valuestring;
		const char* time_stamp = "1500000000";
// 		const char* channel = cJSON_GetObjectItem(json, "channel")->valuestring;
// 		const char* user_name = cJSON_GetObjectItem(json, "user_name")->valuestring;
// 		const char* chat_content = cJSON_GetObjectItem(json, "msg")->valuestring;
		const char* chat_content = str.c_str();
		//cmstring cmstr = string_to_cmstring(chat_content);
		//bool ret = CAlgorithmWindow::getInstance().check(cmstr, user_id);
		string xxx = "";
		check(user_id, atoi(time_stamp), chat_content, xxx);
		cJSON_Delete(json);
	}
	ifs.close();
	return 0;
}

