// despite of Warning due to Variable length Array 
// it still Runs on VSCode //
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void defined_words(char def_word[6][15]);
void input_words(int n,char in_word[n][15]);
void displaywords(int n,char display[][15]);
void creategrid(int row,int column,char grid[row][column]);
void displaygrid(int row,int column,char grid[row][column]);
//Task 5/6 functions
void placewords(int row,int column,int place,char placing[place][15],int direction[100],int xd[100],int yd[100]);
void placeword(int wordsize,char word[wordsize][15],int row,int column,int direction[100],int xd[100],int yd[100],char grid[row][column]);
 void Re_placewords(int i,int row,int column,int wordsize,char word[wordsize][15],int direction[100],int xd[100],int yd[100]);
 int checkwordwillfit(int i,int rows,int columns,int wordsize,int direction[100],char word[wordsize][15],char grid[rows][columns],int xd[100],int yd[100]);
 void gridrandomfill(int row,int column,char grid[row][column]);

int main()
{
  srand(time(NULL));
    int ch,n,d,m,h,w,s;
     char def_words[6][15];
      char in_word[100][15];
      char grid[100][100];
      int direction[100];
      int xd[100],yd[100];

    printf("1.pre-defined words\n2.input words");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:  defined_words(def_words);
         printf("Display word\t\t1.Yes\t2.No");
    scanf("%d",&d);
    if(d==1)
    {
         displaywords(6,def_words);
    }
    else{
        printf("chutti kr\n");
    }
     printf("enter height of grid: ");
    scanf("%d",&h);
    printf("enter the width: ");
    scanf("%d",&w);
    creategrid(w,h,grid);
    printf("Display grid: 1.Yes\t2.No\n");
    scanf("%d",&s);
    if(s==1)
    {
        displaygrid(w,h,grid);
        printf("\n");
    }
   
    for(int i=0;i<6;i++)
    {
         placewords(w,h,i,def_words,direction,xd,yd);/*direction and start position*/
    }
   
    
    placeword(6,def_words,w,h,direction,xd,yd,grid);
   gridrandomfill(w,h, grid);
    displaygrid(w,h,grid);
    printf("\n");
    displaywords(6,def_words);
      
   
        break;
        case 2:  printf("enter no of words to add: ");
        scanf("%d",&n);
         input_words( n,in_word );
          printf("Display word\t\t1.Yes\t2.No");
    scanf("%d",&d);
    if(d==1)
    {
         displaywords(n,in_word);
    }
    
     printf("enter height of grid: ");
    scanf("%d",&h);
    printf("enter the width: ");
    scanf("%d",&w);
    creategrid(w,h,grid);
    printf("Display grid: 1.Yes\t2.No\n");
    scanf("%d",&s);
    if(s==1)
    {
        displaygrid(w,h,grid);
        printf("\n");
    }
    
   for(int i=0;i<6;i++)
    {
         placewords(w,h,i,in_word,direction,xd,yd);/*direction and start position*/
    }
   
   
    
    placeword(n,in_word,w,h,direction,xd,yd,grid);
   gridrandomfill(w,h, grid);
    displaygrid(w,h,grid);
    printf("\n");
     displaywords(n,in_word);
        break;
        default: printf("wrong entry\n");
    }
   
    
    return 0;
}
void defined_words(char def_word[6][15])
{
    char temp[6][15]= {
{'h','a','p','p','y'},
{'c','h','e','e','r','f','u','l'},
{'c','h','i','p','p','e','r'},
{'e','f','f','e','r','v','e','s','c','e','n','t'},
{'j','a','u','n','t','y'},
{'j','o','l','l','y'}
};

for(int i=0;i<6;i++)
{
    for(int j=0;j<15;j++)
    {
        def_word[i][j]=temp[i][j];
    }
}

}
void input_words(int n,char in_word[n][15])
{
    printf("enter the words\n");
    for(int i=0;i<n;i++)
    {
      scanf("%s",&in_word[i]);
    }
}
void displaywords(int n,char display[n][15])
{
    for(int i=0;i<n;i++)
    {
       printf("%s",display[i]);
       printf("\n");
    }
}
void creategrid(int row,int column,char grid[row][column])
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            grid[i][j]='-';
        }
        printf("\n");
    }
}
void displaygrid(int row,int column,char grid[row][column])
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            printf("%c ",grid[i][j]);
        }
        printf("\n");
    }
}
void placewords(int row,int column,int place,char placing[place][15],int direction[100],int xd[100],int yd[100])
{
    
    int len,x,y;
    
   int i=place;
      
        len=strlen(placing[i]);
        //check if the entered word fits in the grid dimensions
        for(int i=0;i<place;i++)
    {
        if(len>row &&len>column)  
        {
            printf("Please enter the correct grid dimension\n");
            exit(0);
        }
    }
    // Random direction generator
        direction[i]=rand()%4;
       
        if(direction[i]==0)      //For horizontal (Right)
        {
             y = rand() % (column - len); //column=height
            x = rand() % row;             //row=width
            yd[i]=y;
            xd[i]=x;
            

        }
        else if(direction[i]==1) { // Vertical (down)
            // Get random position

            y = rand() % column;
            x = rand() % (row - len);
            yd[i]=y;
            xd[i]=x;
            
        }
        else if(direction[i]==2)   //for horizontal (left)
        {
            y=(rand()%(column-len))+len;
            x=rand()%row;
            yd[i]=y;
            xd[i]=x;
            
        }
        else if(direction[i]==3)   //vertical (upwards)
        {
            y=rand()%column;
            x=(rand()%(row-len))+len;
            yd[i]=y;
            xd[i]=x;
            
            
        }
    
       
}
// Next function*****
void placeword(int wordsize,char word[wordsize][15],int row,int column,int direction[100],int xd[100],int yd[100],char grid[row][column])
{
    int len,x,y;
    int count=0,stop=0,check;
    int overlap[6]={};
    again:
    stop+=1;
    for(int k=0;k<wordsize;k++)
    {
        overlap[k]=0;
    }
    for(int i=0;i<wordsize;i++)
    {
        if(direction[i]==0)  //horizontal right
        {
            x=xd[i];
            y=yd[i];
            check=checkwordwillfit(i, row,column,wordsize, direction,word, grid,xd, yd);
        
        if(check==1)
        {
            
            for(int j=0;j<strlen(word[i]);j++)
            {
                grid[xd[i]][yd[i]+j]=word[i][j];
            }
        }
        else if(check==0)
        {
           
            overlap[i]=i;
            count++;
        }
    }//direction[i]==0
         if(direction[i]==1)  //vertical down
        {
            x=xd[i];
            y=yd[i];
            check=checkwordwillfit(i, row,column,wordsize, direction,word, grid,xd, yd);
        
        if(check==1)//no overalp So place on grid
        {
           
            for(int j=0;j<strlen(word[i]);j++)
            {
                grid[xd[i]+j][yd[i]]=word[i][j];
            }
        }
        else if(check==0)
        {
           
            overlap[i]=i;
            count++;
        }
    }//direction[i]==1
    
     if(direction[i]==2)  //horizontal left
        {
            x=xd[i];
            y=yd[i];
            check=checkwordwillfit(i, row,column,wordsize, direction,word, grid,xd, yd);
        
        if(check==1)
        {
           
            for(int j=0;j<strlen(word[i]);j++)
            {
                grid[xd[i]][yd[i]-j]=word[i][j];
            }
        }
        else if(check==0)
        {
           
            overlap[i]=i;
            count++;
        }
    }//direction[i]==2
    
     if(direction[i]==3)  //vertical up
        {
            x=xd[i];
            y=yd[i];
            check=checkwordwillfit(i, row,column,wordsize, direction,word, grid,xd, yd);
        
        if(check==1)
        {
           
            for(int j=0;j<strlen(word[i]);j++)
            {
                grid[xd[i]-j][yd[i]]=word[i][j];
            }
        }
        else if(check==0)
        {
         
            overlap[i]=i;
            count++;
        }
    }//direction[i]==3
    
    
    }
    //Now again positions for the Overlapped words
    
    int rep=0;//reposition
    while(1)
    {
        while(overlap[rep]==0)
        {
            rep++;
        }
        if(rep>(wordsize-1))
        {
            break;
        }
       Re_placewords(overlap[rep], row, column,wordsize, word, direction, xd,yd);
       
       check=checkwordwillfit(overlap[rep], row,column,wordsize, direction ,word, grid,xd, yd);
       if(check==1)
       {
           rep++;
       }
       if(rep>(wordsize-1))
       {
           break;
       }
    }
    
     if (stop<=2)
          {
           creategrid( row, column, grid);
          goto again;}
          
        
   
}
    
    

void Re_placewords(int i,int row,int column,int wordsize,char word[wordsize][15],int direction[100],int xd[100],int yd[100])
{
    int x,y;
    int len=strlen(word[i]);
   
    direction[i]=rand()%4;
   
        if(direction[i]==0)      //For horizontal (Right)
        {
             y = rand() % (column - len); //column=height
            x = rand() % row;             //row=width
            yd[i]=y;
            xd[i]=x;
            

        }
        else if(direction[i]==1) { // Vertical (down)
            // Get random position

            y = rand() % column;
            x = rand() % (row - len);
            yd[i]=y;
            xd[i]=x;
           
        }
        else if(direction[i]==2)   //for horizontal (left)
        {
            y=(rand()%(column-len))+len;
            x=rand()%row;
            yd[i]=y;
            xd[i]=x;
            
        }
        else if(direction[i]==3)   //vertical (upwards)
        {
            y=rand()%column;
            x=(rand()%(row-len))+len;
            yd[i]=y;
            xd[i]=x;
            
            
        }
    
}

checkwordwillfit(int i,int rows,int columns,int wordsize,int direction[100],char word[wordsize][15],char grid[rows][columns],int xd[100],int yd[100])
{
    int len=strlen(word[i]);
    if(direction[i]==0)
    {
        for(int j=0;j<len;j++)
        {
            if(grid[xd[i]][yd[i]+j]!='-')
            {
                return 0;
            }
        }
        return 1;
    }
    
    if(direction[i]==1)
    {
        for(int j=0;j<len;j++)
        {
            if(grid[xd[i]+j][yd[i]]!='-')
            {
                return 0;
            }
        }
        return 1;
    }
    
    if(direction[i]==2)
    {
        for(int j=0;j<len;j++)
        {
            if(grid[xd[i]][yd[i]-j]!='-')
            {
                return 0;
            }
        }
        return 1;
    }
    
    if(direction[i]==3)
    {
        for(int j=0;j<len;j++)
        {
            if(grid[xd[i]-j][yd[i]]!='-')
            {
                return 0;
            }
        }
        return 1;
    }
}

void gridrandomfill(int row,int column,char grid[row][column])
{
    int r;
    srand(time(NULL));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(grid[i][j]=='-')
            {
                r=(rand()%26)+97;
                grid[i][j]=r;
            }
        }
    }
}