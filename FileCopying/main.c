#include<stdio.h>
#include<stdlib.h>
#define Block_Size 4096
int main(int argc,char*argv[])
{
    if(argc!=3){
        printf("the invalid parameters,must be 3 \n");
        exit(0);
    }
    FILE *src;
    FILE *dest;

    src=fopen(argv[1],"rb");
    if(src==NULL)
    {
        printf("unable to open the  %s file \n",argv[1]);
        exit(0);
    }

    dest=fopen(argv[2],"wb");
    if(dest==NULL)
    {
        printf("unable to open the %s file ,may be wrong write permissions granted \n",argv[2]);
        exit(0);
    }

    char* buffer=(char*)malloc(sizeof(char)*Block_Size);
    if(buffer==NULL){
        printf("unable to provide the buffere size\n");
        exit(0);
    }

    fseek(src,0l,2);
    long rem_size=ftell(src);
    fseek(src,0l,0);

    while(rem_size>0){
        long readbyte=0;
        if(rem_size<Block_Size){
            readbyte=fread((void *)buffer,sizeof(char),rem_size,src);
        }
        else{
            readbyte=fread((void *)buffer,sizeof(char),Block_Size,src);
        }
        fwrite((void *)buffer,sizeof(char),readbyte,dest);
        rem_size-=readbyte;
    }

    fclose(src);
    fclose(dest);
    printf("file coopied successfully");
    return 0;
}
