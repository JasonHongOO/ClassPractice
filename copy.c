#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc,char **argv) {

    char textfile1[1024];
    char textfile2[1024];

    FILE *fp;
    if(argc > 1) {
        strcpy(textfile1,argv[1]);
        strcpy(textfile2,argv[2]);
    }
    else {
        printf("error options\n");
        exit(1);
    }


    fp = fopen(textfile1, "r");
    if(fp == NULL) {
        fprintf(stderr, "fopen error %s\n",textfile1);
        exit(1);
    }

    char line[4096];
    char *str[4096];
    int idx=0;
    while(fgets(line,4096,fp) != NULL) {
        int len = strlen(line);

        str[idx] = malloc(sizeof(char) * len);
        strcpy(str[idx++],line);
    }
    fclose(fp);

    fp = fopen(textfile2, "w");
    for(int i=0;i<idx;i++) fputs(str[i],fp);
    fclose(fp);

    for(int i=0;i<idx;i++) free(str[i]);
    return 0;
}
