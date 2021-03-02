#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void next(char *p, int *next)
{
     int i, j;
     i = 0;
     j = -1;
     next[0] = -1;
     while (p[i] != '\0')
     {
          if (j < 0 || p[i] == p[j])
          {
               i++;
               j++;
               next[i] = j;
          }
          else
               j = next[j];
     }
}

void kmp(char *s, char *p, int *next)
{
     int m, n;
     int i, j;
     m = strlen(s);
     n = strlen(p);
     i = 0;
     j = 0;
     while (i < m && j < n)
     {
          if (j < 0 || s[i] == p[j])
          {
               i++;
               j++;
          }
          else
               j = next[j];
          if (j == n)
          {
               printf("Match! %d\n", i - n);
               j = next[j];
          }
     }
}