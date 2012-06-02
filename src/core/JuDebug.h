#ifndef _JU_DEBUG_H_
#define _JU_DEBUG_H_

#define JUDEBUG(...) \
	juPrint(__FILE__, __func__, __VA_ARGS__)

void juPrint(const char *fileName, const char *funcName, const char *format, ...);

#endif
