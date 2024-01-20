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

str Str(const char* strIn);

int Int(const char* strIn);

double Float(const char* strIn);

void strSet(str* s, const char* strIn);

char* strGet(str s);

int strSize(str s);

void strExtend(str* s, char* c);

void strInsert(str* myStr, char* InStr, int index);

void strFree(str* s);

// ? ====================================================================================

str strSub(str s, int start, int end);

// ? ====================================================================================

str strUpper(str s);

str strLower(str s);

str strReverse(str s);

str strReplace(str s, char* old, char* new);

str strTrim(str s);

// ? ====================================================================================
int indexOf(str s, char* c);

int strEndsWith(str s, char* c);

int strStartsWith(str s, char* c) ;

// ? ====================================================================================
int strIsDigit(str s);

int strIsAlpha(str s);

int strIsNum(str s);

int strIsAlphaNum(str s);

int strIsSpace(str s);

int strIsUpper(str s);

int strIsLower(str s);

int strIsPrintable(str s);


// TODO : strReplace , strRemove , strSubstr , strFind , strSplit  


// ? ====================================================================================
// ? Arr of strings
// ? ====================================================================================

typedef struct strArr {
    int length;
    str* data;
} strArr;

strArr strArrCreate(int length);

void strArrSet(strArr* s, int index, const char* strIn); 

void strArrPrint(strArr s);

str strArrGet(strArr s, int index);

int strArrSize(strArr s);

void strArrAppend(strArr* s, char* c);

void strArrInsert(strArr* myStr, char* InStr, int index);

void strArrPush(strArr* s, char* c);

str strArrPop(strArr* s);

str strArrJoin(strArr s,char* delimiter);

strArr strSplit(str s, char* delimiter);

void strArrFree(strArr* s);
#endif