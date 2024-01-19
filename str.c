#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// TODO : (str){-1, "string"} ==> calculate length
str strCreate(const char* strIn) {
    str s;

    if (strIn != NULL) {
        s.length = strlen(strIn);
        s.data = malloc(s.length + 1);
        strcpy(s.data, strIn);
    } else {
        s.length = 0;
        s.data = malloc(1);
        s.data[0] = '\0';
    }

    return s;
}

str Str(const char* strIn){
    str s;

    if (strIn != NULL) {
        s.length = strlen(strIn);
        s.data = malloc(s.length + 1);
        strcpy(s.data, strIn);
    } else {
        s.length = 0;
        s.data = malloc(1);
        s.data[0] = '\0';
    }

    return s;

}

int Int(const char* strIn){
    str strInt = Str(strIn);
    int sum=0;
    if (!strIsDigit(strInt))
    {
        printf("Error: %s is not an int\n",strGet(strInt));
        exit(EXIT_FAILURE);   
    }
    for (int i = 0; i < strSize(strInt) ; i++)
    {
        sum += (strInt.data[i] - '0') * pow(10, strSize(strInt) - i - 1);
    }
    return sum; 
    
}

double Float(const char* strIn){
    str strDouble = strCreate(strIn);
    double sum = 0;

    if (!strIsNum(strDouble))
    {
        printf("Error: %s is not a float\n",strGet(strDouble));
        exit(EXIT_FAILURE);   
        
    }
    int dotIndex = indexOf(strDouble, ".");

    // part one (beore dot)
    for (int i = 0; i < dotIndex; i++)
    {
        sum += (strDouble.data[i] - '0') * pow(10, dotIndex - i - 1);
    }
    // part two (after dot)
    for (int i = dotIndex + 1; i < strSize(strDouble); i++)
    {
        sum += (strDouble.data[i] - '0') * pow(10, dotIndex - i);
    }
    return sum;
    
}

void strSet(str* s, const char* strIn) {
    if (strIn != NULL) {
        s->length = strlen(strIn);
        s->data = realloc(s->data, s->length + 1);
        strcpy(s->data, strIn);
    } else {
        s->length = 0;
        s->data = realloc(s->data, 1);
        s->data[0] = '\0';
    }
}

char* strGet(str s) {
    return s.data;
}

int strSize(str s) {
    return s.length;
}

void strExtend(str* s, char* c) {
    int len = strlen(c);
    s->data = realloc(s->data, s->length + len + 1);
    strcat(s->data, c);
    s->length += len;
    s->data[s->length] = '\0';
}

void strInsert(str* myStr, char* InStr, int index) {
    int len = strlen(InStr);
    myStr->data = realloc(myStr->data, myStr->length + len + 1);
    memmove(myStr->data + index + len, myStr->data + index, myStr->length - index + 1);
    memcpy(myStr->data + index, InStr, len);
    myStr->length += len;
    myStr->data[myStr->length] = '\0';
}


// ? ====================================================================================

str strSub(str s, int start, int end) {
    if (start < 0) start = s.length + start; 
    if (end < 0) end = s.length + end;      
    //! rais out of index error
    if (end > s.length || start > s.length) {
        printf("Error: index out of range\n");
        exit(EXIT_FAILURE);
    }
    if (start > end) return strCreate(NULL);
    int new_len = end -start;

    char* new_data = malloc(new_len + 1);
    new_data[new_len] = '\0';
    memcpy(new_data, s.data + start, new_len);
    // printf("%s\n", new_data);

    return strCreate(new_data);
    
}


// ? ====================================================================================

str strUpper(str s) {
    str temp = s;
    for (int i = 0; i < temp.length; i++) {
        if (temp.data[i] >= 'a' && temp.data[i] <= 'z') {
            temp.data[i] -= 32;
        }
    }
    return temp;
}

str strLower(str s) {
    str temp = s;
    for (int i = 0; i < temp.length; i++) {
        if (temp.data[i] >= 'A' && temp.data[i] <= 'Z') {
            temp.data[i] += 32;
        }
    }
    return temp;
}

str strReverse(str s) {
    str temp = s;
    if (!s.length) return temp;
    if (s.length%2 == 0){
        for (int i = 0; i < temp.length/2; i++) {
            char c = temp.data[i];
            temp.data[i] = temp.data[temp.length - i - 1];
            temp.data[temp.length - i - 1] = c;
        }
    } 
    else {
        for (int i = 0; i < (temp.length - 1)/2; i++) {
            char c = temp.data[i];
            temp.data[i] = temp.data[temp.length - i - 1];
            temp.data[temp.length - i - 1] = c;
        }
    }

    return temp;
}

str strTrim(str s) {
    str temp = s;
    int i = 0;
    while (temp.data[i] == ' ' || temp.data[i] == '\t' || temp.data[i] == '\n') {
        i++;
    }
    int j = temp.length - 1;
    while (temp.data[j] == ' ' || temp.data[j] == '\t' || temp.data[j] == '\n') {
        j--;
    }
    temp.data = realloc(temp.data, j - i + 2);
    memmove(temp.data, temp.data + i, j - i + 1);
    temp.data[j - i + 1] = '\0';
    temp.length = j - i + 1;
    return temp;
}

// ? ====================================================================================


int indexOf(str s, char* c) {
    int len = strlen(c);
    for (int i = 0; i < s.length - len + 1; i++) {
        if (!strncmp(s.data + i, c, len)) {
            return i;
        }
    }
    return -1;
}

int strEndsWith(str s, char* c) {
    int len = strlen(c);
    if (s.length < len) return 0;
    return !strcmp(s.data + s.length - len, c);
}

int strStartsWith(str s, char* c) {
    int len = strlen(c);
    if (s.length < len) return 0;
    return !strncmp(s.data, c, len);
}
// ? =================================================================



int strIsDigit(str s){
    for (int i = 0; i < s.length; i++) {
        if (s.data[i] < '0' || s.data[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int strIsNum(str s){
    int dotCount = 0;
    for (int i = 0; i < s.length; i++) {
        if (s.data[i] == '.') {
            dotCount++;
        } else if (s.data[i] < '0' || s.data[i] > '9') {
            return 0;
        }
    }
    if (dotCount > 1) {
        return 0;
    }
    return 1;
}

int strIsAlpha(str s){
    for (int i = 0; i < s.length; i++) {
        if ((s.data[i] < 'a' || s.data[i] > 'z') && (s.data[i] < 'A' || s.data[i] > 'Z')) {
            return 0;
        }
    }
    return 1;
}

int strIsAlphaNum(str s){
    for (int i = 0; i < s.length; i++) {
        if ((s.data[i] < 'a' || s.data[i] > 'z') && (s.data[i] < 'A' || s.data[i] > 'Z') && (s.data[i] < '0' || s.data[i] > '9')) {
            return 0;
        }
    }
    return 1;
}

int strIsSpace(str s){
    for (int i = 0; i < s.length; i++) {
        if (s.data[i] != ' ' && s.data[i] != '\t' && s.data[i] != '\n') {
            return 0;
        }
    }
    return 1;
}

int strIsUpper(str s){
    for (int i = 0; i < s.length; i++) {
        if (s.data[i] < 'A' || s.data[i] > 'Z') {
            return 0;
        }
    }
    return 1;
}

int strIsLower(str s){
    for (int i = 0; i < s.length; i++) {
        if (s.data[i] < 'a' || s.data[i] > 'z') {
            return 0;
        }
    }
    return 1;
}


int strIsPrintable(str s){
    for (int i = 0; i < s.length; i++) {
        if (s.data[i] < 32 || s.data[i] > 126) {
            return 0;
        }
    }
    return 1;
}
// ? ====================================================================================

void strFree(str* s) {
    free(s->data);
}

// ? ====================================================================================
// ? Array of strings
// ? ====================================================================================


strArr strArrCreate(int length) {
    strArr s;
    s.length = length;
    s.data = malloc(sizeof(str) * length);
    for (int i = 0; i < length; i++) {
        s.data[i] = strCreate(NULL);
    }
    return s;
}

void strArrPrint(strArr s) {
    printf("[");
    for (int i = 0; i < s.length; i++) {
        printf("'%s', ", strGet(s.data[i]));
    }
    printf("]\n");
}
void strArrSet(strArr* s, int index, const char* strIn) {
    if (index < s->length) {
        strSet(&s->data[index], strIn);
    }
}

str strArrGet(strArr s, int index) {
    if (index < s.length) {
        return s.data[index];
    }
    return strCreate(NULL);
}

int strArrSize(strArr s) {
    return s.length;
}

void strArrAppend(strArr* s, char* c) {
    s->data = realloc(s->data, sizeof(str) * (s->length + 1));
    s->data[s->length] = strCreate(c);
    s->length++;
}

void strArrInsert(strArr* myStr, char* InStr, int index) {
    if (index < myStr->length) {
        myStr->data = realloc(myStr->data, sizeof(str) * (myStr->length + 1));
        memmove(myStr->data + index + 1, myStr->data + index, (myStr->length - index) * sizeof(str));
        myStr->data[index] = strCreate(InStr);
        myStr->length++;
    }
}

void strArrPush(strArr* s, char* c) {
    strArrInsert(s, c, 0);
}

str strArrPop(strArr* s) {
    str temp = strArrGet(*s, 0);
    memmove(s->data, s->data + 1, (s->length - 1) * sizeof(str));
    s->length--;
    return temp;
}

// join array
str strArrJoin(strArr s,char* delimiter){
    int newLen;
    str temp = strCreate(NULL);
    str sDelimiter = strCreate(delimiter);
    for (int i = 0; i < s.length; i++) {
        newLen += s.data[i].length;
    }
    newLen += sDelimiter.length * (s.length - 1);
    temp.data = realloc(temp.data, newLen + 1);
    temp.length = newLen;
    temp.data[newLen] = '\0';
    for (int i = 0; i < s.length; i++) {
        strcat(temp.data, s.data[i].data);
        if (i != s.length - 1) {
            strcat(temp.data, sDelimiter.data);
        }
    }
    return temp;
}

strArr strSplit(str s, char* delimiter) {
    strArr temp = strArrCreate(0);
    int start = 0;
    int end = 0;
    int len = strlen(delimiter);
    while (end < s.length) {
        // if (s.data[end:end+len(delemiter)] == delimiter)
        if (!strncmp(s.data + end, delimiter, len)) {
            strArrAppend(&temp, strGet(strSub(s, start, end)));
            end += len;
            start = end;
        } else {
            end++;
        }
    }
    strArrAppend(&temp, strGet(strSub(s, start, end)));
    return temp;
}

void strArrFree(strArr* s) {
    for (int i = 0; i < s->length; i++) {
        strFree(&s->data[i]);
    }
    free(s->data);
}

