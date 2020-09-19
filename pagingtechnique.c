#include <stdio.h>
void main(){
    int memory_size,page_size,number_of_frames,ch1,ch2,rem_frames,number_of_pages;
    int ps,id,i,n=0,c=0,f=0,rp;
    int p[50][2];
    printf("Enter memory size of processor");
    scanf("%d",&memory_size);
    printf("Enter page size ");
    scanf("%d",&page_size);
    number_of_frames=memory_size/page_size;
    printf("Number of frames:%d\n",number_of_frames);
    printf("Enter 1 to continue and 0 to exit");
    scanf("%d",&ch1);
    rem_frames=number_of_frames; 
    while(ch1!=0){
        printf("Enter 1 to insert and 2 to delete");
        scanf("%d",&ch2);
        if(ch2==1)
        {
             if(rem_frames!=0){
            printf("Enter id");
            scanf("%d",&id);
            printf("Enter size");
            scanf("%d",&ps);
            number_of_frames=(ps)/page_size;
            if(number_of_frames<=rem_frames )
            {
                if(ps%page_size==0)
                    rp=0;
                else
                {
                    rp=1;
                }
                rem_frames=rem_frames-number_of_frames-rp;
                p[n][0]=id;
                p[n++][1]=number_of_frames+rp;
                printf("Memory allocated successfully");

                printf("\nNumber of frames available:%d",rem_frames);
            }
            else{
                printf("Error:Memory size not available");
            }
        }
        else
        {
          printf("Error:Memory Full:Unable to insert");
        }
        }
        else if(ch2==2){
            printf("Enter id");
            scanf("%d",&id);
            for(i=0;i<n;i++){
                if(id==p[i][0])
                {
                    f=1;
                    break;
                }
            }
            if(f==1 && p[i][1]!=0){
                rem_frames=rem_frames+p[i][1];  
                printf("Memory deallocated");
                printf("\nNumber of frames available:%d",rem_frames);
                p[i][1]=0;
            }
            else{
                printf("Error:ID not found");
            }
        }
        else
        {
            printf("Invalid choice");
        }
        
         printf("\nEnter 1 to continue and 0 to exit");
         scanf("%d",&ch1);
    }
}