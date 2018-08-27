/*************************************************************************
	> File Name: log.cpp
	> Author: jetming
	> Mail: puzhiming@migu.cn
	> Created Time: Mon 23 Apr 2018 02:04:33 AM PDT
    > Description: description
 ************************************************************************/
#include "../include/log.h"

Log* Log::log = new Log();

Log::Log() {
	stream = fopen(LOG_FILE_PATH, "w");
}

Log::Log(const Log&) {

}

Log & Log::operator=(const Log &)
{
}

void Log::_function_log_file(int log_file, const char * tag, const char *fileName, const char * funcName, unsigned int line, const char * format, ...) {
	if (!log_file) {
		return;
	}
	va_list ap;
	va_start(ap, format);
	char buf[1024];
	memset(buf, '\0', sizeof(buf));
	vsprintf(buf, format, ap);
	va_end(ap);

	if (stream) {
		fprintf(stream, "%s: LINE %d: %s\n", funcName, line, buf);
	}
}


void Log::__function_log_print(LogLevel lvl, const char * tag, const char *fileName, const char * funcName, unsigned int line, const char * format, ...) {
	if (lvl < LOG_LEVEL) {
		return;
	}
	va_list ap;
	va_start(ap, format);
	char buf[1024];
	memset(buf, '\0', sizeof(buf));
	vsprintf(buf, format, ap);
	va_end(ap);
	switch (lvl) {
	case LOG_TRACE:
		fprintf(stdout, "[TRACE] %s: LINE %d: %s\n", funcName, line, buf);
		break;
	case LOG_INFO:
		fprintf(stdout, "%s\n", buf);
		break;
	case LOG_ERROR:
		fprintf(stdout, "[ERROR] %s: LINE %d: %s\n", funcName, line, buf);
		break;
	case LOG_DEBUG:
		fprintf(stdout, "[DEBUG] %s: LINE %d: %s\n", funcName, line, buf);
		break;
	case LOG_WARN:
		fprintf(stdout, "[WARN] %s: LINE %d: %s\n", funcName, line, buf);
		break;
	case Log_BYTE:
		fprintf(stdout, "%s\n", buf);
		break;
	case LOG_NONE:
		break;
	}
}