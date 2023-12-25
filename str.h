#ifndef str_h
#define str_h

#include <stdlib.h>

// ? ====================================================================================
// ? String
// ? ====================================================================================
typedef struct str {
    int length;
    char* data;
} str;

str strCreate(const char* strIn);

void strSet(str* s, const char* strIn);

char* strGet(str s);

int strSize(str s);

void strExtend(str* s, char* c);

void strInsert(str* myStr, char* InStr, int index);

void strFree(str* s);

// TODO : strReplace , strRemove , strSubstr , strFind , strSplit  , strReverse , strTrim


// ? ====================================================================================
// ? Array of strings
// ? ====================================================================================

typedef struct strArray {
    int length;
    str* data;
} strArray;

strArray strArrayCreate(int length);

void strArraySet(strArray* s, int index, const char* strIn); 

void strArrayPrint(strArray s);
str strArrayGet(strArray s, int index);

int strArraySize(strArray s);

void strArrayAppend(strArray* s, char* c);

void strArrayInsert(strArray* myStr, char* InStr, int index);

void strArrayPush(strArray* s, char* c);

str strArrayPop(strArray* s);

void strArrayFree(strArray* s);
#endif