#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc,char **argv) {

    char textfile[1024];

    FILE *fp;
    if(argc > 1) {
        strcpy(textfile,argv[1]);
    }
    else {
        printf("error options\n");
        exit(1);
    }


    fp = fopen(textfile, "r");
    if(fp == NULL) {
        fprintf(stderr, "fopen error %s\n",textfile);
        exit(1);
    }

    char line[4096];
    char *str[4096];
    int idx=0;
    while(fgets(line,4096,fp) != NULL) {
        int len = strlen(line);

        for(int i=0;i<len;i++) {
            if(isalpha(line[i])) {
                if(isupper(line[i])){
                    line[i] = tolower(line[i]);
                }
            }
        }

        str[idx] = malloc(sizeof(char) * len);
        strcpy(str[idx++],line);
    }
    fclose(fp);

    fp = fopen(textfile, "w");
    for(int i=0;i<idx;i++) fputs(str[i],fp);
    fclose(fp);

    return 0;
}
