#include <stdlib.h>
#include <stdio.h>

int lengthOfLongestSubstring(char *s){
  if (!s) return -1;
  int head, tail, sLen=0;
  head=tail=0;
  int i, lenMax=0;
  int cSet[512];
  for(i=0;i<512;i++) cSet[i]=-1;
  //for(i=0;i<512;i++) printf("cSet[%d]=>%d\t", i, cSet[i]);
  char* ts=s;
  while(*ts){  //for(ts=s;ts;ts++) sLen++;
    sLen++;
    ts++;
  }
  printf("\nsLen=>%d\n", sLen);
  
  for(i=0;i<sLen;i++){
    if( (cSet[s[i]] != -1) && ( cSet[s[i]] >= head) ) {
      head = cSet[s[i]]+1;
    }
    cSet[s[i]] = i;
    if(lenMax<(i-head+1)) lenMax = i-head+1;
  }
  return lenMax;
}


int main(int argc, char** argv){
  char *str1 = "abcabcbb";
  char *str2 = "bbbbb";
  char *str3 = "pwwkew";
  int x = lengthOfLongestSubstring(str1);
  printf("str1: %s\n", str1);
  printf("lengthOfLongestSubstring is: %d\n", x);
  x = lengthOfLongestSubstring(str2);
  printf("lengthOfLongestSubstring is: %d\n", x);
  printf("str2: %s\n", str2);
  x = lengthOfLongestSubstring(str3);
  printf("lengthOfLongestSubstring is: %d\n", x);
  printf("str3: %s\n", str3);
  return 0;
}
