/* File: Node.c
 * Name: Paulo Lemus
 * Date: 
 * Team:
 */

#include <string.h>
#include "Node.h"

enum City getEnum(const char* cityStr) {

    if(strcmp(cityStr, "san_francisco")       == 0) return SAN_FRAN;
    else if(strcmp(cityStr, "las_vegas")      == 0) return LAS_VEGAS;
    else if(strcmp(cityStr, "tuscon")         == 0) return TUSCON;
    else if(strcmp(cityStr, "salt_lake_city") == 0) return SALT_LAKE;
    else if(strcmp(cityStr, "chicago")        == 0) return CHICAGO;
    else if(strcmp(cityStr, "nashville")      == 0) return NASHVILLE;
    else if(strcmp(cityStr, "indianapolis")   == 0) return INDIANAPOLIS;
    else if(strcmp(cityStr, "new_york")       == 0) return NEW_YORK;
    else                                            return CITY_ERROR;
}
