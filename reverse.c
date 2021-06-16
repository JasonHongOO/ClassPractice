#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc,char **argv) {

    char textfile[1024];
    char line[4096];

    FILE *fp;
    if(argc > 1) {
        if(strcmp(argv[1],"reverse") == 0) {
            strcpy(textfile,argv[2]);
        }
        else {
            printf("error options\n");
            exit(1);
        }
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

    char *str[4096];
    int idx=0;
    int check = 0;
    while(fgets(line,4096,fp) != NULL) {
        int len = strlen(line);
        if(check == 0) {
            if(line[len-1] == '\n') {line[len-1] = '\0';len--;}
            check = 1;
        }

        char temp[4096] = {0};
        int n=0;
        for(int i=len-1;i>=0;i--) temp[n++] = line[i];

        int strlong = strlen(temp);
        str[idx] = malloc(sizeof(char) * strlong);
        strcpy(str[idx++],temp);
    }
    fclose(fp);

    fp = fopen(textfile, "w");
    for(int i=idx-1;i>=0;i--) {
        fputs(str[i],fp);
    }
    fclose(fp);

    for(int i=idx-1;i>=0;i--) free(str[i]);
    return 0;
}
