#include <stdio.h>
#include <stdlib.h>
struct list{
    int info;
    struct list *next;
};
struct list *new1,*node,*ptr,*next;
void create(){
    int i,n;
    printf("Enter the number: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        new1=(struct list *)malloc(sizeof(struct list));
        if(new1==NULL)
            printf("Node not created");
        else{
            int item;
            printf("Enter the item: ");
            scanf("%d",&item);
            new1->info=item;
            new1->next=NULL;
            if(node==NULL)
                node=new1;
            else{
                ptr=node;
                while(ptr->next!=NULL)
                    ptr=ptr->next;
                ptr->next=new1;
            }
        }
    }
}
void first_insert(){
    new1=(struct list *)malloc(sizeof(struct list));
    if(new1==NULL)
        printf("Overflow");
    else{
        int item;
        printf("Enter the item: ");
        scanf("%d",&item);
        new1->info=item;
        new1->next=node;
        node=new1;
    }
}
void insert(){
    new1=(struct list *)malloc(sizeof(struct list));
    if(new1==NULL)
        printf("Overflow");
    else{
        int item,loc;
        printf("Enter the item to insert: ");
        scanf("%d",&item);
        printf("Enter the location of insertion: ");
        scanf("%d",&loc);
        new1->info=item;
        int i=1;
        ptr=node;
        while(i!=loc-1){
            ptr=ptr->next;
            i++;
        }
        new1->next=ptr->next;
        ptr->next=new1;
    }
}
void first_deletel(){
    int temp;
    if(node==NULL)
        printf("Underflow");
    else{
        temp=node->info;
        node=node->next;
    }
}
void deletel(){
    struct list *save;
    ptr=node;
    save=node->next;
    if(node==NULL)
        printf("Underflow");
    int loc;
    printf("Enter the location of deletion: ");
    scanf("%d",&loc);
    int i=1;
    while(i!=loc-1){
        ptr=ptr->next;
        save=save->next;
        i++;
    }
    ptr->next=save->next;
}
void search(){
    int i=1,search,flag;
    ptr=node;
    if(node==NULL)
        printf("Empty list");
    else{
        printf("Enter the item to search: ");
        scanf("%d",&search);
        while(ptr->next !=NULL){
            if(ptr->info==search){
                printf("Item found at location: %d\n",i);
                flag=0;
            }
            i++;
            ptr=ptr->next;
        }
        if(flag==1)
            printf("Item not found");
    }
}
void display(){
    int j=1;
    while(node!=NULL){
        printf("%d item: %d\n",j,node->info);
        node=node->next;
        j++;
    }
}
int main(){
    struct list *node;
    create();
    printf("0 mean: first insertion\n");
    printf("1 mean: insert\n");
    printf("2 mean: first_deletel\n");
    printf("3 mean: delete\n");
    printf("4 mean: search\n");
    int n;
    printf("Enter the number which you want to choose: ");
    scanf("%d",&n);
    switch(n){
        case 0:
            first_insert();
            display();
            break;
        case 1:
            insert();
            display();
            break;
        case 2:
            first_deletel();
            display();
            break;
        case 3:
            deletel();
            display();
            break;
        case 4:
            search();
            break;
    }
    return 0;
}