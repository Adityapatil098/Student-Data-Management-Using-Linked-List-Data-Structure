#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stu
{
    int rollno;
    char name[20];
    float percentage;
    struct stu* next;
}student;
student*head=0;
void add_new(void);
void delete(void);
void show(void);
void del_roll(int);
void modify(void);
void roll_modify(int);
void save(void);
void sort(void);
void reverse(void);
void del_all(void);
void my_exit(void);
void main()
{
    char choice;
    while(1)
    {
        printf("\n\n\n");
    printf("*****STUDENT RECORD MENU*****\n");
    
    printf("a/A:add new record\n");
    printf("d/D:delete a record\n");
    printf("s/S:show the list\n");
    printf("m/M:modify a record\n");
    printf("v/V:save\n");
    printf("e/E:exit\n");
    printf("t/T:sort the list\n");
    printf("l/L:delete all the records\n");
    printf("r/R:reverse the list\n");
    printf("NOTE : DATA WILL BE STORED IN DATA NAMED FILE(when you save)\n");
    printf("Enter your choice\n");
    scanf(" %c",&choice);
    printf("\n\n\n");
  
    switch(choice)
    {
      case 'a':
      case 'A': add_new();
          break;
      case 'd':
      case 'D': delete();
          break;
      case 's':
      case 'S': show();
          break;

      case 'm':
      case 'M': modify();
          break;
      case 'v':
      case 'V':save();         
          break;
      case 'e':
      case 'E':my_exit();
               break;
      case 't':
      case 'T':sort();
         break;
      case 'r':
      case 'R':reverse();
               break;

        case'l':
       case'L':del_all();
              break;

default:printf("invalid input\n");
        break;
    }
 }
}
void add_new(void)
  {
      
      static int i=1;
      int flag=0;
      student*new,*temp=head,*check=head;  
     if(head!=0)
     while(temp->next!=0)
     {
     temp=temp->next;
     }
     if(flag==0)
     {
     while(check)
     {
         if(check->name[0]==' ')
         {
             printf("Enter name percentage\n");
             scanf("%s %f",check->name,&check->percentage);
             flag=1;
             break;
         }
         else
         {
             check=check->next;
         }
     }
     }
     if(flag==0)
     {
     new=malloc(sizeof(student));
     new->rollno=i;
     i++;
     printf("Enter  name  percentage\n");
     scanf("%s %f",new->name,&new->percentage);    
     if(head==0)
     {
         head=new;
         temp=new;
         new->next=0;
     }
     else
     {
         temp->next=new;
         new->next=0;
         temp=new;
     }    
  }
 }
void delete(void)
{
    int data=0,rn,count=0,co=0;
    char rno[20],i,c;
  student*check=head,*prev=0;
   if(head==0)
   {
       printf("no node found\n");
    return;
   }
  printf("What you want\n");
  printf("R/r:by roll no to delete\n");
  printf("N/n:by name to delete\n");
  printf("Enter you choice\n");
  scanf(" %c",&c);
  switch(c)
  {
      case 'n':
      case 'N':
          {
             char rno[20];
             printf("Enter name \n");
             scanf(" %s",rno);
             while(check)
             {
               if(strcmp(check->name,rno)==0)
                {
                   data++;
                  printf("%d %s %f\n",check->rollno,check->name,check->percentage);
                }
                 check=check->next;
             }
             check=head;
             if(data==0)
              {
                printf("no name available \n");
                return;
              }
              if(data==1)
             {
               
                 while(check)
                 {
                     if((strcmp(check->name,rno)==0))
                     {
                         i=0;
                         while(check->name[i])
                         {
                             check->name[i]=' ';
                             i++;
                         }
                         check->percentage=0;
                         printf("data deleted\n");
                         return;
                     }
                     else
                     {
                         check=check->next;
                     }
                 }
             }
              else
              {
                 printf("enter roll no to delete\n");
                  scanf("%d",&rn);
                  del_roll(rn);
                  printf("data deleted\n");
              }
              break;
          }

      case 'r':
      case 'R':{
                   int i,rnu,count=0;
                   printf("Enter  roll no\n");
                   scanf("%d",&rnu);
                   del_roll(rnu);
                   break;

               }
  }
}
void show(void)
{
    student*ptr=head;
    if(head==0)
    {
        printf("no node found \n");
        return;

    }
    while(ptr)
    { if(ptr->name[0]==' ')
       {
            printf("%d\n",ptr->rollno);
       }
       else
        printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
        
ptr=ptr->next;
    }
}
void del_roll(int num)
{
   if(head==0)
   {
       printf("no data present\n");
       return;
   }
    student*check=head;
    int c=0,i=0;
    while(check)
    {
        if(check->rollno==num)
        {
           while(check->name[i]!='\0')
           {
               check->name[i]=' ';
               i++;
           }
           check->percentage=0;
           break;
        }
        else
        {
        check=check->next;
        }
        
    }
}
void modify(void)
{
    char ch;
    int rn,c=0;
    printf("enter which record to search for modification\n");
    printf("R/r : to search rollno\n");
    printf("N/n :to search a name \n");
    printf("P/p :percentage based\n");  
    scanf(" %c",&ch);

    switch(ch)
    {
        case 'r':
        case 'R':{
                     student*check=head;
                     if(head==0)
                     {
                         printf("no data found\n");
                         break;
                     }

                     printf("enter the roll no\n");
                     scanf("%d",&rn);
                     while(check)
                     {
                         if(check->rollno==rn)
                         {
                          roll_modify(rn);
                          break;
                         }

                         else
                             check=check->next;
                         
                     }
                     printf("%d modifed \n",rn);
                 }
                 break;
        case 'N':
       case  'n':{
                     char a[20];
                     student*check=head;
                     printf("Enter name\n");
                     scanf("%s",a);
                     while(check)
                     {
                        if(strcmp(check->name,a)==0)
                        {
                             c++;
                             printf("%d %s %f\n",check->rollno,check->name,check->percentage);
                        }
                        check=check->next;
                     }
                     check=head;
                     if(c==0)
                     {
                         printf("no node found\n");
                     }
                     if(c==1)
                     { 
                        while(check)
                        {
                            if(strcmp(check->name,a)==0)
                            {
                                roll_modify(check->rollno);
                                break;
                            }
                            else
                                check=check->next;

                        }
                     }
                     else
                     {
                         printf("according to which roll no you want to modify\n");
                         scanf("%d",&rn);
                         roll_modify(rn);
                         printf("modified\n");
                     }

                 }
                 break;
       case 'P':
       case 'p':{
                    student*check=head;   
                    float m;
                    int c=0;
                    printf("Enter percentage\n");
                    scanf("%f",&m);

                    while(check)
                    {
                        if(check->percentage==m)
                        { 
                          c++;
                          printf("%d %s %f\n",check->rollno,check->name,check->percentage);
                        }
                        check=check->next;
                    }
                    check=head;
                    if(c==0)
                       {
                           printf("no percentage found\n");
                           return;
                       }
                    if(c==1)
                    {
                        while(check)
                        {
                            if(check->percentage==m)
                            {
                               roll_modify(check->rollno);
                            }
                            else
                                check=check->next;
                        }
                    }
                    else
                    {
                        printf("Enter roll no\n");
                        scanf("%d",&rn);
                        roll_modify(rn);
                        printf("modified");
                    }

                }
                break;
       }
    
}


void roll_modify(int rollno)
{
  int choice,n;
  student*check=head;
  while(check)
  {
      if(check->rollno==rollno)
      {
          printf("What you want to modify\n");
              
              printf("1)rollno\n2)name\n3)percentage\n4)everything\n");
              scanf("%d",&choice);
            if(choice==1)
            {
               m:
               printf("Enter the rollo\n");
               scanf("%d",&check->rollno);
                while(check)
                {
                   if(check->rollno==rollno)
                   {
                   printf("roll no should not be same\n");
                   goto m;
                   }
                   else
                   {
                       check=check->next;
                   }

                }
               
                break;
            }
            else if(choice==2)
           {
               printf("Enter new name\n");
               scanf("%s",check->name);
               break;
           }
            else if(choice==3)
            {
                printf("Enter percentage\n");
                scanf("%f",&check->percentage);
                break;
            }
            else
            {
                printf("Enter name percentages\n");
                scanf("%s %f",check->name,&check->percentage);
                break;
                }
            }
       
       
      else
      {
          check=check->next;
      }
  }
}
  

void save()
{
    student* check=head;
    FILE*fp=fopen("data","w");
    if(head==0)
    {
        printf("no node found\n");
    }
    while(check)
    {
         fprintf(fp,"%d %s %f\n",check->rollno,check->name,check->percentage);
         check=check->next;
    }
    fclose(fp);
}
void sort()
{
    char choice;
    printf("N/n:sort with name\n");
    printf("P/p:sort with percentage\n");
        printf("Enter your choice\n");
    scanf(" %c",&choice);

    switch(choice)
    {
        case 'p':
        case 'P':
            {
           int i,c=0;
      int temp;
      char s[20];
      float p;
      student*check=head,*prev=head;
    check=head;
        for(prev;prev!=NULL;prev=prev->next)
        {
            for(check=prev->next;check!=NULL;check=check->next)
            {
               if(prev->percentage>check->percentage)
               {
                    temp=prev->rollno;
                    prev->rollno=check->rollno;
                    check->rollno=temp;

                 
                    strcpy(s,prev->name);
                    strcpy(prev->name,check->name);
                    strcpy(check->name,s);

                    p=prev->percentage;
                    prev->percentage=check->percentage;
                    check->percentage=p;
               }
            }
        }
       show();
       save();
       break;
        }
    
        case 'n':
        case 'N':
            {
                int temp;
                char s[20];
                float p;
                student*check=head,*prev=head;
                for(prev;prev!=NULL;prev=prev->next)
                {
                    for(check=prev->next;check!=NULL;check=check->next)
                    {
                           if(strcmp(prev->name,check->name)>0)
                           {
                                temp=prev->rollno;
                     prev->rollno=check->rollno;
                     check->rollno=temp;


                     strcpy(s,prev->name);
                     strcpy(prev->name,check->name);
                     strcpy(check->name,s);

                     p=prev->percentage;
                     prev->percentage=check->percentage;
                     check->percentage=p;
                          
                         }
                    }
                }
                show();
                save();
            }
            break;
}
}
void del_all(void)
{
  student*last=head,*prev=head;
  while(last)
  {
  last=last->next;
  head=prev->next;
  free(prev);
  prev=last;
  }
  printf("all deleted\n");
}


void reverse(void)
{
   student*ptr=head,*prev=NULL,*next=head;
   while(next)
   {
       next=ptr->next;
       ptr->next=prev;
       prev=ptr;
       ptr=next;      
   }
   head=prev;
   show();
}
void my_exit(void)
{
    char choice;
    printf("S/s Save and exxit\n");
   printf("E/e exit without save\n");
   printf("Enter the choice\n");
   scanf(" %c",&choice);
    switch(choice)
    {
        case 'E':
        case 'e': exit(0);
                 break;
        case 'S':
        case 's':save();
                 exit(0);
                 break;
        default:printf("command not found\n");
                break;
    }
}
