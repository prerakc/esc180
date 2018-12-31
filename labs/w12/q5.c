#include<stdio.h>
#include<stdlib.h>

int g(char **f, int size);

int g(char **f, int size) {
   (*f) = (char *)malloc(sizeof(char)*size);
}
