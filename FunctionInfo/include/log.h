#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <stdarg.h> 
#include <string.h>

#ifndef  LOG_TAG
#define  LOG_TAG "wangyongqing"
enum LogLevel {
	LOG_DEBUG,
	LOG_TRACE,
	LOG_INFO,
	Log_BYTE,
	LOG_NONE,
	LOG_WARN,
	LOG_ERROR,
};


#define  LOG_LEVEL  LOG_DEBUG
#define  LOG_FILE 1
#define  LOG_FILE_PATH "./backend.log"
#define  LOGD(format, ...)  Log::getLog()->__function_log_print(LOG_DEBUG,LOG_TAG, __FILE__, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)
#define  LOGT(format, ...)  Log::getLog()->__function_log_print(LOG_TRACE,LOG_TAG, __FILE__, __FUNCTION__, __LINE__,format, ##__VA_ARGS__)
#define  LOGI(format, ...)  Log::getLog()->__function_log_print(LOG_INFO,LOG_TAG, __FILE__, __FUNCTION__, __LINE__,format, ##__VA_ARGS__)
#define  LOGB(format, ...)  Log::getLog()->__function_log_print(Log_BYTE,LOG_TAG, __FILE__, __FUNCTION__, __LINE__,format, ##__VA_ARGS__)
#define  LOGW(format, ...)  Log::getLog()->__function_log_print(LOG_WARN,LOG_TAG, __FILE__, __FUNCTION__, __LINE__,format, ##__VA_ARGS__)
#define  LOGE(format, ...)  Log::getLog()->__function_log_print(LOG_ERROR,LOG_TAG, __FILE__, __FUNCTION__, __LINE__,format, ##__VA_ARGS__)
#define  LOGF(format, ...)  Log::getLog()->_function_log_file(LOG_FILE, LOG_TAG, __FILE__, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)
class Log
{
public:
	void __function_log_print(LogLevel lvl, const char * tag, const char *fileName, const char * funcName, unsigned int line, const char * format, ...);

	void _function_log_file(int log_file, const char * tag, const char *fileName, const char * funcName, unsigned int line, const char * format, ...);

	static Log* getLog() {
		return log;
	}
private:
	Log();
	//把复制构造函数和=操作符也设为私有,防止被复制
	Log(const Log&);
	Log& operator=(const Log&);
private:
	static Log *log;
	FILE *stream;
};
#endif