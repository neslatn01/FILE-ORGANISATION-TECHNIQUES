#include<stdio.h>
#include<string.h>

struct dirct{

        char dir[20],file[20][10];
        int findex;
};

void main(){

        int i, ch=1;
        struct dirct d;
        char ser[20];
        d.findex=0;
        printf("Enter the directory name ");
        scanf("%s",d.dir);
        
        do{
                
                printf("\n1<<<Create new file\t2<<<Delete a file\t3<<<Search a file\t\n4<<< List files\t\t0<<<Ezxit\n");
                printf("Enter your choice ");
                scanf("%d",&ch);
                
                switch(ch){

                        case 1: printf("\nEnter the file name ");
                                scanf("%s",d.file[d.findex++]);
                                printf("File created\n");
                                break;
                        case 2: printf("\nEnter the file to delete ");
                                scanf("%s",ser);
                                for(i=0;i<d.findex;i++){
                                        if(!strcmp(ser,d.file[i]))
                                        {
                                                printf("File removed \n");
                                                strcpy(d.file[i],d.file[d.findex-1]);
                                                d.findex--;
                                                break;
                                        }
                                }
                                if(i==d.findex)
                                        printf("No such file or directory\n");
                                break;
                                
                        case 3: printf("\nEnter the file to search ");
                                scanf("%s",ser);
                                for(i=0;i<d.findex;i++){
                                        if(!strcmp(ser,d.file[i]))
                                        {
                                                printf("\nSearch completed\nFile found at %d position\n",i+1);
                                                break;
                                        }
                                }
                                if(i==d.findex){
                                        printf("\nSearch completed\n");
                                        printf("No such file or directory\n");
                                }
                                break;
                                                       
                        case 4: printf("\nThe files in the directory %s are;\n",d.dir);
                                for(i=0;i<d.findex;i++)
                                        printf("%s\n", d.file[i]);
                                break;
                                    
                }
                
        }while(ch);
        printf("\n");
}
