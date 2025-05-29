#include <stdio.h>
#include <stdlib.h>

#include "src/mdl.h"

int main(int argc, char* argv[])
{
        mdl_LOG_DEBUG("\n", "This is debug.");
        mdl_LOG_INFO("\n", "This is info.");
        mdl_LOG_SUCCESS("\n", "This is success.");
        mdl_LOG_ERROR("\n", "This is error.");
        mdl_LOG_FAILURE("\n", "This is failure.");
        mdl_LOG_WARNING("\n", "This is warning.");
        mdl_LOG_GENERIC("\n", "This is generic.");

        return 0;
}