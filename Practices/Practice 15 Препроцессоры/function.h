#pragma once

void FillArrayByRandomsInt(int array[], int size);
void FillArrayByRandomsDouble(double array[], int size);
void FillArrayByRandomsChar(char array[], int size);

void ShowArrayInt(int array[], int size);
void ShowArrayDouble(double array[], int size);
void ShowArrayChar(char array[], int size);

int FindMinInt(int array[], int size);
double FindMinDouble(double array[], int size);
char FindMinChar(char array[], int size);

int FindMaxInt(int array[], int size);
double FindMaxDouble(double array[], int size);
char FindMaxChar(char array[], int size);

void SortArrayInt(int array[], int size);
void SortArrayDouble(double array[], int size);
void SortArrayChar(char array[], int size);

void EditArrayInt(int array[], int size, int index, int value);
void EditArrayDouble(double array[], int size, int index, double value);
void EditArrayChar(char array[], int size, int index, char value);

#ifdef MY_INTEGER
#define Type int
#define FillArrayByRandoms FillArrayByRandomsInt
#define ShowArray ShowArrayInt
#define FindMin FindMinInt
#define FindMax FindMaxInt
#define SortArray SortArrayInt
#define EditArray EditArrayInt
#endif
#ifdef MY_DOUBLE
#define Type double
#define FillArrayByRandoms FillArrayByRandomsDouble
#define ShowArray ShowArrayDouble
#define FindMin FindMinDouble
#define FindMax FindMaxDouble
#define SortArray SortArrayDouble
#define EditArray EditArrayDouble
#endif
#ifdef MY_CHAR
#define Type char
#define FillArrayByRandoms FillArrayByRandomsChar
#define ShowArray ShowArrayChar
#define FindMin FindMinChar
#define FindMax FindMaxChar
#define SortArray SortArrayChar
#define EditArray EditArrayChar
#endif