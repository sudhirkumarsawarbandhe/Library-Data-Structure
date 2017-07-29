#include<stdio.h>
#include<conio.h>
#include<string.h>

#define MAX 200

typedef struct books
{
    char book_name[50];
    char aut_name[50];
    int pub_year;
    int no_copy;
}book;
book lib[MAX];
int no_of_books=0;

void insert(book[],int*);
void bubble_sort(book[],int);
int search(book[],char[],char[],int,int);
int deletes(book[],int*);
int empty(book[],int);
int full(book[],int);
void unique(book[],int*);
void union_fun(book[],book[],book[],int,int,int*);
void intersection(book[],book[],book[],int,int,int*);
void difference(book[],book[],book[],int,int,int*);
void symm_difference(book[],book[],book[],int,int,int*);

int main()
{

   int choice,loop,status,l1=0,l2=0,l3=0,pyear,copy;
   book list1[MAX],list2[MAX],list3[MAX];
   char c;
   char aname[30],bname[30];
   FILE *fp1;
   //________________________//making list1 , list2 and list3

            fp1=fopen("file1.txt","r+");

                l1=0;
                while(fgetc(fp1)!=EOF)
                {
                    fscanf(fp1,"%s%s%d%d",aname,bname,&pyear,&copy);
                    strcpy(list1[l1].aut_name,aname);
                    strcpy(list1[l1].book_name,bname);
                           list1[l1].pub_year = pyear;
                           list1[l1].no_copy = copy;
                    l1++;
                }

                l1--;
                //printf("no is %d\n",l1);
                bubble_sort(list1,l1+1);
                fclose(fp1);

                 fp1=fopen("file2.txt","r+");

                l1=0;
                while(fgetc(fp1)!=EOF)
                {
                    fscanf(fp1,"%s%s%d%d",aname,bname,&pyear,&copy);
                    strcpy(list1[l1].aut_name,aname);
                    strcpy(list1[l1].book_name,bname);
                           list1[l1].pub_year = pyear;
                           list1[l1].no_copy = copy;
                    l1++;
                }

                l1--;
                bubble_sort(list1,l1+1);
                fclose(fp1);
                //
                fp1=fopen("file3.txt","r+");

                l2=0;
                while(fgetc(fp1)!=EOF)
                {
                    fscanf(fp1,"%s%s%d%d",aname,bname,&pyear,&copy);
                    strcpy(list2[l2].aut_name,aname);
                    strcpy(list2[l2].book_name,bname);
                           list2[l2].pub_year = pyear;
                           list2[l2].no_copy = copy;
                    l2++;
                }

                l2--;
                bubble_sort(list2,l2+1);
                fclose(fp1);

   //____________________//

   while(1)
   {
    choice=0;
   printf("1.Insert  2.Delete  3.getNumRecords  4.isEmpty     5.isFull \n");
   printf("6.Unique  7.union   8.Intersection   9.difference  10.Symm_difference\n");
   fflush(stdin);
   scanf("%d",&choice);
   switch(choice)
   {
       case 1:
           {
               insert(lib,&no_of_books);
               bubble_sort(lib,no_of_books);
               break;
           }
       case 2:
            {
              status=deletes(lib,&no_of_books);
              if(status==1)
              {
                  printf("Delete is successful\n");
                  no_of_books--;
              }
              else
              {
                  printf("Error in Delete...Data Is not present\n");
              }
              break;
            }
        case 3:
            {
                printf("Total No. of Books = %d\n",no_of_books);
                printf("Author \t Book_name \t copy \t year\n");
                for(loop=0;loop < no_of_books;loop++)
                {
                    printf("%s \t %s \t    %d \t %d\n",lib[loop].aut_name,lib[loop].book_name,lib[loop].no_copy,lib[loop].pub_year);
                }
                break;
            }

        case 4:
           {
               status=empty(lib,no_of_books);
                 if(status == 1)
                  printf("Database Is Empty\n");
               break;
           }
        case 5:
           {
               status=full(lib,no_of_books);
               if(status == 1)
                 printf("Database is full\n");
                 break;
           }
        case 6:
            {
                unique(list1,&l1);
                    printf("Author   Book  Pyear    copy\n");
                for(loop=0;loop <=l1;loop++)
                 printf("   %s     %s      %d       %d\n",list1[loop].aut_name,list1[loop].book_name,list1[loop].pub_year,list1[loop].no_copy);
                fclose(fp1);
                break;
            }
       case 7:
           {
                union_fun(list1,list2,list3,l1,l2,&l3);
                 bubble_sort(list3,l3+1);
                printf("Union List is\n");
                printf("Author   Book  Pyear    copy\n");
                for(loop=0;loop <=l3;loop++)
                 printf("   %s     %s      %d       %d\n",list3[loop].aut_name,list3[loop].book_name,list3[loop].pub_year,list3[loop].no_copy);
             break;
           }
     case 8:
          {
              intersection(list1,list2,list3,l1,l2,&l3);
              bubble_sort(list3,l3+1);
              printf("Intersection List is\n");
              printf("Author   Book  Pyear    copy\n");
                for(loop=0;loop <=l3;loop++)
                 printf("   %s     %s      %d       %d\n",list3[loop].aut_name,list3[loop].book_name,list3[loop].pub_year,list3[loop].no_copy);
             break;

          }
     case 9:
          {

              difference(list1,list2,list3,l1,l2,&l3);
              bubble_sort(list3,l3+1);
              printf("Difference list is\n");
              printf("Author   Book  Pyear    copy\n");
                for(loop=0;loop <=l3;loop++)
                 printf("   %s     %s      %d       %d\n",list3[loop].aut_name,list3[loop].book_name,list3[loop].pub_year,list3[loop].no_copy);
             break;
          }
     case 10:
          {

              symm_difference(list1,list2,list3,l1,l2,&l3);
              printf("Symmetric_Difference List is\n");
              printf("Author   Book  Pyear    copy\n");
                for(loop=0;loop <=l3;loop++)
                 printf("   %s     %s      %d       %d\n",list3[loop].aut_name,list3[loop].book_name,list3[loop].pub_year,list3[loop].no_copy);
             break;
          }
    default:
       {
          printf("wrong choice\n");
          break;
       }

    }
    if(choice==0)
    break;
  }
 getch();

}


void insert(book lib[],int* no_of_books)
{
    char bname[30],aname[30];
    int pyear,copy,pos=-1,low=0,high;
    printf("enter author_name ,book_name ,publ_year, copy\n");
    fflush(stdin);
    scanf("%s%s%d%d",aname,bname,&pyear,&copy);
    if(*no_of_books != MAX)
      {
         high=*no_of_books - 1;
        pos=search(lib,aname,bname,low,high);
        if(pos== -1)  //not found Insert
        {
            strcpy(lib[*no_of_books].aut_name,aname);
            strcpy(lib[*no_of_books].book_name,bname);
            lib[*no_of_books].pub_year = pyear;
            lib[*no_of_books].no_copy  = copy;
            (*no_of_books)++;
            printf("no of books %d\n",*no_of_books);
        }
        else if(pos!= -1) //update ,increase no. of copy
        {
            lib[pos].pub_year = pyear;
            lib[pos].no_copy  = copy;
        }
      }

}

int search(book lib[],char aname[],char bname[],int low,int high)
{
    int pos=-1,k=-2;

    if(low<=high)
    {
        pos= (low + high)/2;
        if((strcmp(lib[pos].aut_name,aname)==0)&&(strcmp(lib[pos].book_name,bname)==0))
           return pos;
        else
         {
            k=strcmp(lib[pos].aut_name,aname);
             if((k>0))
             {
               high=pos-1;
               pos=search(lib,aname,bname,low,high);
             }
             else if((k<0))
             {
               low=pos+1;
               pos=search(lib,aname,bname,low,high);
             }
             else if(k==0)  //if author name is same
             {
                  k=strcmp(lib[pos].book_name,bname);
                         if((k>0))
                         {
                           high=pos-1;
                           pos=search(lib,bname,aname,low,high);
                         }
                         else if((k<0))
                         {
                           low=pos+1;
                           pos=search(lib,bname,aname,low,high);
                         }
             }

         }
    }
    return pos;
}

void bubble_sort(book lib[],int no_of_books)
{
    int i,j,size,sort=0,tem;
    char temp[30];
    size=no_of_books -1;
    for(i=0;i<size && sort==0;i++)
    {
        sort=1;
        for(j=0;j<size-i;j++)
        {
            if(strcmp(lib[j].aut_name,lib[j+1].aut_name)>0)
            {
                strcpy(temp,lib[j].aut_name);
                strcpy(lib[j].aut_name,lib[j+1].aut_name);
                strcpy(lib[j+1].aut_name,temp);

                strcpy(temp,lib[j].book_name);
                strcpy(lib[j].book_name,lib[j+1].book_name);
                strcpy(lib[j+1].book_name,temp);

                tem=lib[j].no_copy;
                lib[j].no_copy=lib[j+1].no_copy;
                lib[j+1].no_copy=tem;

                tem=lib[j].pub_year;
                lib[j].pub_year=lib[j+1].pub_year;
                lib[j+1].pub_year=tem;

                sort=0;
            }//end of if
        else if(strcmp(lib[j].aut_name,lib[j+1].aut_name)==0 && strcmp(lib[j].book_name,lib[j+1].book_name))
                {   //no. sort by book_name
                    strcpy(temp,lib[j].book_name);
                    strcpy(lib[j].book_name,lib[j+1].book_name);
                    strcpy(lib[j+1].book_name,temp);

                    tem=lib[j].no_copy;
                    lib[j].no_copy=lib[j+1].no_copy;
                    lib[j+1].no_copy=tem;

                    tem=lib[j].pub_year;
                    lib[j].pub_year=lib[j+1].pub_year;
                    lib[j+1].pub_year=tem;

                    sort=0;
                }
        }
    }
}

int deletes(book lib[],int* no_of_books)
{
    int pos,low=0,high,loop,status=-1,tem;
    char temp[30],aname[30],bname[30];
    printf("Enter Author_name and Book_name\n");
    fflush(stdin);
    scanf("%s%s",aname,bname);

 if(*no_of_books != 0)
 {
    high = *no_of_books - 1;
    pos=search(lib,aname,bname,low,high);
    if(pos == -1)
    {
        printf("Data is Not Present\n");
        status=0;
    }
    else
    {
        for(loop=pos;loop<*no_of_books-1;loop++)
        {
                strcpy(temp,lib[loop+1].aut_name);
                strcpy(lib[loop].aut_name,lib[loop+1].aut_name);
                strcpy(lib[loop+1].aut_name,temp);

                strcpy(temp,lib[loop].book_name);
                strcpy(lib[loop].book_name,lib[loop+1].book_name);
                strcpy(lib[loop+1].book_name,temp);

                tem=lib[loop].no_copy;
                lib[loop].no_copy=lib[loop+1].no_copy;
                lib[loop+1].no_copy=tem;

                tem=lib[loop].pub_year;
                lib[loop].pub_year=lib[loop+1].pub_year;
                lib[loop+1].pub_year=tem;
        }
        status=1;
    }
 }
    return status;
}

int empty(book list[],int l1)
{
    int flag=1;
     if(l1!=0)
      flag=0;
    return flag;
}

int full(book list[],int l1)
{
    int flag=1;
     if(l1!=MAX)
      flag=0;
    return flag;
}

void unique(book list1[],int* size)
{
   int i=0,j=0,loop=0,flag=0;

     for(i=0;i<*size;i++)
       {  flag=0;
        for(j=i+1;j<=*size;j++)
         {
          if(flag==1) //now have to search, one step backward
               j--;
          if((strcmp(list1[i].aut_name,list1[j].aut_name)==0) && (strcmp(list1[i].book_name,list1[j].book_name)==0))
            {
             for(loop=j;loop<*size;loop++)
             {
                strcpy(list1[loop].aut_name,list1[loop+1].aut_name);

                strcpy(list1[loop].book_name,list1[loop+1].book_name);

                list1[loop].no_copy=list1[loop+1].no_copy;

                list1[loop].pub_year=list1[loop+1].pub_year;
             }
             flag=1;// now decrease j, to check at next index
             (*size)--;
            }
            else
                {
                    flag=0;
                }
        }
    }
}

void union_fun(book list1[],book list2[],book list3[],int l1,int l2,int* l3)
{
    int size,loop,pos;
    size = (*l3);
      for(loop=0;loop<=l1;loop++)
      {
                strcpy(list3[size].aut_name,list1[loop].aut_name);

                strcpy(list3[size].book_name,list1[loop].book_name);

                list3[size].no_copy=list1[loop].no_copy;

                list3[size].pub_year=list1[loop].pub_year;
                size++;
      }
      size--;
      for(loop=0;loop<=l2;loop++)
      {
         pos=search(list3,list2[loop].aut_name,list2[loop].book_name,0,size);
          if(pos== -1)  //not found Insert
            {
                size++;
                strcpy(list3[size].aut_name,list2[loop].aut_name);
                strcpy(list3[size].book_name,list2[loop].book_name);

                list3[size].pub_year = list2[loop].pub_year;
                list3[size].no_copy  = list2[loop].no_copy;
            }
            else if(pos!= -1) //update ,increase no. of copy
            {
                if(list3[pos].pub_year < list2[loop].pub_year)
                {
                    list3[pos].pub_year = list2[loop].pub_year;
                    list3[pos].no_copy  = list2[loop].no_copy;
                }
            }
      }
      *l3=size-1;
}

void intersection(book list1[],book list2[],book list3[],int l1,int l2,int* l3)
{
    int loop,pos,size=0;

   for(loop=0;loop<=l1;loop++)
   {
      pos=search(list2,list1[loop].aut_name,list1[loop].book_name,0,l2);
      if(pos != -1)//found
      {
                strcpy(list3[size].aut_name,list1[loop].aut_name);

                strcpy(list3[size].book_name,list1[loop].book_name);

                 if(list1[loop].no_copy >= list2[pos].no_copy)
                 {
                     list3[size].pub_year=list1[loop].pub_year;
                     list3[size].no_copy=list1[loop].no_copy;
                 }
                 else
                 {
                     list3[size].pub_year=list2[pos].pub_year;
                     list3[size].no_copy=list2[pos].no_copy;
                 }
                size++;
      }
   }
   *l3=size-1;
}

void difference(book list1[],book list2[],book list3[],int l1,int l2,int* l3)
{
     int loop,pos,size=0;
// List1 - List2
   for(loop=0;loop<=l1;loop++)
   {
      pos=search(list2,list1[loop].aut_name,list1[loop].book_name,0,l2);
      if(pos == -1)
      {
                strcpy(list3[size].aut_name,list1[loop].aut_name);

                strcpy(list3[size].book_name,list1[loop].book_name);

                list3[size].no_copy=list1[loop].no_copy;

                list3[size].pub_year=list1[loop].pub_year;
                size++;
      }
   }
   *l3=size-1;
}


void symm_difference(book list1[],book list2[],book list3[],int l1,int l2,int* l3)
{
     int loop,pos,size=0;
// List1 - List2
   for(loop=0;loop<=l1;loop++)
   {
      pos=search(list2,list1[loop].aut_name,list1[loop].book_name,0,l2);
      if(pos == -1)
      {
                strcpy(list3[size].aut_name,list1[loop].aut_name);

                strcpy(list3[size].book_name,list1[loop].book_name);

                list3[size].no_copy=list1[loop].no_copy;

                list3[size].pub_year=list1[loop].pub_year;
                size++;
      }
   }


   // List2 - List1
   for(loop=0;loop<=l1;loop++)
   {
      pos=search(list1,list2[loop].aut_name,list2[loop].book_name,0,l1);
      if(pos == -1)
      {
                strcpy(list3[size].aut_name,list2[loop].aut_name);

                strcpy(list3[size].book_name,list2[loop].book_name);

                list3[size].no_copy=list2[loop].no_copy;

                list3[size].pub_year=list2[loop].pub_year;
                size++;
      }
   }
   *l3=size-1;
   size--;
   bubble_sort(list3,size);
}
