#include "JuDebug.h"

#include <stdio.h>
#include <stdarg.h>

void juPrint(const char *fileName, const char *funcName, const char *format, ...) {
	va_list args;

	printf("%s::%s :: ", fileName, funcName);

	if (format != NULL) {
		va_start(args, format);
		vprintf(format, args);
		va_end(args);
	}

	printf("\n");
}
