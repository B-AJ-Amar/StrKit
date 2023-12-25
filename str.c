#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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



void strFree(str* s) {
    free(s->data);
}


// ? ====================================================================================
// ? Array of strings
// ? ====================================================================================


strArray strArrayCreate(int length) {
    strArray s;
    s.length = length;
    s.data = malloc(sizeof(str) * length);
    for (int i = 0; i < length; i++) {
        s.data[i] = strCreate(NULL);
    }
    return s;
}

void strArrayPrint(strArray s) {
    printf("[");
    for (int i = 0; i < s.length; i++) {
        printf("'%s', ", strGet(s.data[i]));
    }
    printf("]\n");
}
void strArraySet(strArray* s, int index, const char* strIn) {
    if (index < s->length) {
        strSet(&s->data[index], strIn);
    }
}

str strArrayGet(strArray s, int index) {
    if (index < s.length) {
        return s.data[index];
    }
    return strCreate(NULL);
}

int strArraySize(strArray s) {
    return s.length;
}

void strArrayAppend(strArray* s, char* c) {
    s->data = realloc(s->data, sizeof(str) * (s->length + 1));
    s->data[s->length] = strCreate(c);
    s->length++;
}

void strArrayInsert(strArray* myStr, char* InStr, int index) {
    if (index < myStr->length) {
        myStr->data = realloc(myStr->data, sizeof(str) * (myStr->length + 1));
        memmove(myStr->data + index + 1, myStr->data + index, (myStr->length - index) * sizeof(str));
        myStr->data[index] = strCreate(InStr);
        myStr->length++;
    }
}

void strArrayPush(strArray* s, char* c) {
    strArrayInsert(s, c, 0);
}

str strArrayPop(strArray* s) {
    str temp = strArrayGet(*s, 0);
    memmove(s->data, s->data + 1, (s->length - 1) * sizeof(str));
    s->length--;
    return temp;
}
void strArrayFree(strArray* s) {
    for (int i = 0; i < s->length; i++) {
        strFree(&s->data[i]);
    }
    free(s->data);
}

