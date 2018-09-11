#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int tstamp(const char *filename)
{
    struct stat refbuff;
    struct stat tgtbuff;
    stat(filename,&refbuff);
    while(1)
    {
        stat(filename,&tgtbuff);
        if((int)tgtbuff.st_mtime!=(int)refbuff.st_mtime){
            return 0;
            break;
        }
    }
}

void xcall(const char *dir)
{
    int i;
    i = system(dir);
    if (i==(-1)){
        printf("ERR_OPEN_FILE\n");
        exit(EXIT_FAILURE);
    }
}
int main(int argc,char *argv[])
{

    char *filename = argv[1];
    if (argc>3){
        printf("TOO_MANY_ARGS\n");
        exit(EXIT_FAILURE);
    }
    
    //main proccess
    
    else if(argc==2){
        
        while(1){
        int i = tstamp(filename);    
        if(i==0);{
            sleep(1);
            xcall(filename);
            }
        }        
    }
    else if (argc==0){
        printf("NO_ARGS_GIVEN\n");
        exit(EXIT_FAILURE);
    }
    
    else{
        printf("NO_ARGS_GIVEN\n");

        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}
