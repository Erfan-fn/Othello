#include <iostream>
#include <fstream>
using namespace std;
const int size=8;
int savecheck;
int put[2][64]={{0}};
int turncount=0;
char plus='+';
int total1 = 0;
char minus='-';
int total2 = 0;
int legalshomar=0;
int satr2,sootoon2;
int last10counter=0;
void lastgamesave(char board[8][8],int turncount)
{
    ofstream lastgame("ardi.txt");

    for(int i=0 ; i<9 ;i++)
    {
        for(int j=0 ; j<9 ;j++)
        {   if(board[i][j]==' '){lastgame<<'z';}
            else
            {lastgame<<board[i][j];}
        }}
    lastgame<<turncount;
    lastgame.close();
}
int lastgameload(char board[][size],int turncount)
{   int nobat=0,countera=0;
    char jadval[70];
    ifstream lastgame2("ardi.txt");
            lastgame2>>jadval;
            for(int i=0; i<9 ; i++)
            {
                for(int j=0 ; j<9 ;j++)
                {
                   if(jadval[countera]=='z'){board[i][j]=' ';}else{
                       board[i][j]=jadval[countera];}
                   countera++;
                }
            }
        nobat=jadval[65]-48;
         lastgame2.close();
turncount=nobat;
return turncount;}
int getScore1(char board[8][8]){
    int total1 = 0;
    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < 8; ++j)
            if(board[i][j] =='+')
                total1 += 1;

    return total1;
}
int getScore2(char board[8][8]){
    int total2 = 0;
    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < 8; ++j)
            if(board[i][j] == '-')
                total2 += 1;

    return total2;
}
int turnavalie(int turncount)
{
    turncount++;
    return turncount;
}
void last10games(int total1,int total2)
{   int last10p[100]={0},last10m[100]={0};
    char last10pchar[101],last10mchar[100];
    ofstream last10("dalghak.txt");
    if(last10counter==0){last10p[0]=44;last10m[0]=20;last10p[1]=34;last10m[1]=30;last10p[2]=24;last10m[2]=40;last10p[3]=46;last10m[3]=18;last10p[4]=44;last10m[4]=20;last10p[5]=19;last10m[5]=45;last10p[6]=47;last10m[6]=19;last10p[7]=20;last10m[7]=44;last10p[8]=30;last10m[8]=34;last10p[9]=24;last10m[9]=40;last10counter++;
       for(int i=0 ; i<10 ;i++){
           cout<<"plus:"<<last10p[i]<<" "<<"minus:"<<last10m[i]<<'\n';
       }}
    if(total1+total2==64)
    {
        for(int i=0 ; i<9 ;i++)
        {
            last10p[i]=last10p[i+1];
            last10m[i]=last10m[i+1];
        }
    }
    last10p[9]=total1;
    last10m[9]=total2;
     for(int i=0 ; i<10 ;i++)
     {
         last10<<last10p[i];
     }
     last10<<'#';
    for(int i=0 ; i<10 ;i++)
    {
        last10<<last10m[i];
    }
    last10.close();
    ifstream last10load("dalghak.txt");
    if(last10counter==100)
    {for(int i=0 ; i<10 ;i++)
    {while(last10pchar[i]!='#'){last10load>>last10pchar[i];}}
     for(int i=0 ; i<10 ;i++)
     {last10load>>last10mchar;}

     for(int i=0 ; i<10 ;i++)
     {
         last10mchar[i]=last10mchar[i+1];
     }
     last10load.close();}
}
int legalMovesrec(char board[][size],int turncount)
{    int legalmovecount=0;
     int legalshomar=0;
      int p_mat=0;
      for(int i=0 ; i<size ;i++)
      {
          for(int j=0  ; j<size ;j++)
          {
              legalmovecount=0;
              if(board[i][j]==' ')
              {   if(turncount%2!=0)
                  {
                      for(int x=j+1 ; x<size ;x++)    //check the right side
                      {
                          if(board[i][x]==' '){break;}
                          if(board[i][x]=='+'){break;}
                          if(board[i][x]=='-'){
                              if(board[i][x+1]=='+'){legalmovecount++;
                                  break;}}
                      }
                      for(int x=j-1 ; x>=0 ;x--)      //check the left side
                      {
                          if(board[i][x]==' '){break;}
                          if(board[i][x]=='+'){break;}
                          if(board[i][x]=='-'){
                              if(board[i][x-1]=='+'){legalmovecount++;
                                  break;}}
                      }
                      for(int x=i+1; x<size ;x++)    //check down
                      {
                          if(board[x][j]==' '){break;}
                          if(board[x][j]=='+'){break;}
                          if(board[x][j]=='-'){
                              if(board[x+1][j]=='+'){legalmovecount++;
                                  break;}}
                      }
                      for(int x=i-1 ; x>=0 ;x--)     //check up
                      {
                          if(board[x][j]==' '){break;}
                          if(board[x][j]=='+'){break;}
                          if(board[x][j]=='-'){
                              if(board[x-1][j]=='+'){legalmovecount++;
                                  break;}}
                      }
                      for(int x=i+1,y=j+1 ; x<size&&y<size ;x++,y++)   //check south east
                      {
                          if(board[x][y]==' '){break;}
                          if(board[x][y]=='+'){break;}
                          if(board[x][y]=='-'){
                              if(board[x+1][y+1]=='+'){legalmovecount++;
                                  break;}}
                      }
                      for(int x=i-1,y=j-1 ; x>=0&&y>=0 ;x--,y--)   //check north west
                      {
                          if(board[x][y]==' '){break;}
                          if(board[x][y]=='+'){break;}
                          if(board[x][y]=='-'){
                              if(board[x-1][y-1]=='+'){legalmovecount++;
                                  break;}}
                      }
                      for(int x=i+1,y=j-1 ; x<size&&y>=0 ;x++,y--)   //check south west
                      {
                          if(board[x][y]==' '){break;}
                          if(board[x][y]=='+'){break;}
                          if(board[x][y]=='-'){
                              if(board[x+1][y-1]=='+'){legalmovecount++;
                                  break;}}
                      }
                      for(int x=i-1,y=j+1 ; x>=0&&y<size ;x--,y++)   //check north east
                      {
                          if(board[x][y]==' '){break;}
                          if(board[x][y]=='+'){break;}
                          if(board[x][y]=='-'){
                              if(board[x-1][y+1]=='+'){legalmovecount++;
                                  break;}}
                      }
                      if(legalmovecount!=0){
                          cout<<"plus "<<"legal move:"<<"("<<i<<","<<j<<")"<<"  ";
                          legalshomar++;
                     put[0][p_mat]=i; put[1][p_mat]=j;p_mat++; }
                  }
                  if(turncount%2==0){
                      for(int x=j+1 ; x<size ;x++)    //check the right side
                      {
                          if(board[i][x]==' '){break;}
                          if(board[i][x]=='-'){break;}
                          if(board[i][x]=='+'){
                              if(board[i][x+1]=='-'){legalmovecount++;
                                  break;}}
                      }
                      for(int x=j-1 ; x>=0 ;x--)      //check the left side
                      {
                          if(board[i][x]==' '){break;}
                          if(board[i][x]=='-'){break;}
                          if(board[i][x]=='+'){
                              if(board[i][x-1]=='-'){legalmovecount++;
                                  break;}}
                      }
                      for(int x=i+1; x<size ;x++)    //check down
                      {
                          if(board[x][j]==' '){break;}
                          if(board[x][j]=='-'){break;}
                          if(board[x][j]=='+'){
                              if(board[x+1][j]=='-'){legalmovecount++;
                                  break;}}
                      }
                      for(int x=i-1 ; x>=0 ;x--)     //check up
                      {
                          if(board[x][j]==' '){break;}
                          if(board[x][j]=='-'){break;}
                          if(board[x][j]=='+'){
                              if(board[x-1][j]=='-'){legalmovecount++;
                                  break;}}
                      }
                      for(int x=i+1,y=j+1 ; x<size&&y<size ;x++,y++)   //check south east
                      {
                          if(board[x][y]==' '){break;}
                          if(board[x][y]=='-'){break;}
                          if(board[x][y]=='+'){
                              if(board[x+1][y+1]=='-'){legalmovecount++;
                                  break;}}
                      }
                      for(int x=i-1,y=j-1 ; x>=0&&y>=0 ;x--,y--)   //check north west
                      {
                          if(board[x][y]==' '){break;}
                          if(board[x][y]=='-'){break;}
                          if(board[x][y]=='+'){
                              if(board[x-1][y-1]=='-'){legalmovecount++;
                                  break;}}
                      }
                      for(int x=i+1,y=j-1 ; x<size&&y>=0 ;x++,y--)   //check south west
                      {
                          if(board[x][y]==' '){break;}
                          if(board[x][y]=='-'){break;}
                          if(board[x][y]=='+'){
                              if(board[x+1][y-1]=='-'){legalmovecount++;
                                  break;}}
                      }
                      for(int x=i-1,y=j+1 ; x>=0&&y<size ;x--,y++)   //check north east
                      {
                          if(board[x][y]==' '){break;}
                          if(board[x][y]=='-'){break;}
                          if(board[x][y]=='+'){
                              if(board[x-1][y+1]=='-'){legalmovecount++;
                                  break;}}
                      }
                      if(legalmovecount!=0){
                          cout<<"minus "<<"legal move:"<<"("<<i<<","<<j<<")"<<"  ";
                          legalshomar++;
                      put[0][p_mat]=i; put[1][p_mat]=j;p_mat++;}
                  }
              }
          }
      }
       if(legalshomar==0)
           cout<<"You don't have move"<<endl;
return legalshomar;}
void dispBoard(char board[size][size]){
    cout << endl;
    cout << "    ";
    for(int col = 0; col < size; col++){
        cout << col << "    ";
    }

    cout << endl;
    for(int row = 0; row < size; row++)
    {
        cout << "   ";
        for(int col = 0; col < size; col++)
        {
            cout << ("-----");
        }
        cout << endl;
        cout << row  << "  ";

        for(int col = 0; col < size; col++)
        {
            cout << ("| ");

            if(board[row][col] == ' ')
                cout << "   ";
            else
                cout << board[row][col] << "  ";
        }
        cout << "|" << endl;
    }

    cout << "   ";

    for(int col = 0; col < size; col++)
    {
        cout << "-----";
    }

    cout << endl;
    cout << endl;


}
void paksazi()
{   for(int i=0 ; i<2 ;i++)
    for(int j=0;j<64 ;j++)
    {
        put[i][j]=0;
    }
}
void change(char board[][size],int satr,int sootoon,int turncount)
{
    if(turncount%2!=0)
    {    board[satr][sootoon]='+';
        for(int j=sootoon+1; j<size ;j++)      //change right of +
        {
            if(board[satr][j]=='-'){continue;}
            if(board[satr][j]=='+')
            {
                for(int x=j ; x>sootoon ;x--)
                {
                    board[satr][x]='+';
                }
             break;}
            if(board[satr][j]==' '){break;}
        }
        for(int j=sootoon-1; j>=0 ;j--)      //change left of +
        {
            if(board[satr][j]=='-'){continue;}
            if(board[satr][j]=='+')
            {
                for(int x=j ; x<sootoon ;x++)
                {
                    board[satr][x]='+';
                }
             break;}
             if(board[satr][j]==' '){break;}
       }
        for(int j=satr-1; j>=0 ;j--)      //change up of +
        {
            if(board[j][sootoon]=='-'){continue;}
            if(board[j][sootoon]=='+')
            {
                for(int x=j ; x<satr ;x++)
                {
                    board[x][sootoon]='+';
                }
             break;}
             if(board[j][sootoon]==' '){break;}
        }
        for(int j=satr+1; j<size ;j++)      //change down of +
        {
            if(board[j][sootoon]=='-'){continue;}
            if(board[j][sootoon]=='+')
            {
                for(int x=j ; x>satr ;x--)
                {
                    board[x][sootoon]='+';
                }
             break;}
            if(board[j][sootoon]==' '){break;}
        }

        for(int i=satr+1,j=sootoon+1 ; i<size&&j<size ;i++,j++)         //change south east +
        {
            if(board[i][j]=='-'){continue;}
            if(board[i][j]=='+')
            {
             for(int x=i,y=j; x>satr&&y>sootoon ;x--,y--)
             {
                 board[x][y]='+';
             }
              break;}
            if(board[i][j]==' '){break;}
        }
        for(int i=satr-1,j=sootoon-1 ; i>=0&&j>=0 ;i--,j--)         //change north west +
        {
            if(board[i][j]=='-'){continue;}
            if(board[i][j]=='+')
            {
             for(int x=i,y=j; x<satr&&y<sootoon ;x++,y++)
             {
                 board[x][y]='+';
             }
              break;}
            if(board[i][j]==' '){break;}
        }
        for(int i=satr-1,j=sootoon+1 ; i>=0&&j<size ;i--,j++)         //change north east +
        {
            if(board[i][j]=='-'){continue;}
            if(board[i][j]=='+')
            {
             for(int x=i,y=j; x<satr&&y>sootoon ;x++,y--)
             {
                 board[x][y]='+';
             }
              break;}
             if(board[i][j]==' '){break;}
        }
        for(int i=satr+1,j=sootoon-1 ; i<size&&j>=0 ;i++,j--)         //change south west +
        {
            if(board[i][j]=='-'){continue;}
            if(board[i][j]=='+')
            {
             for(int x=i,y=j; x>satr&&y<sootoon ;x--,y++)
             {
                 board[x][y]='+';
             }
              break;}
             if(board[i][j]==' '){break;}
        }}
    if(turncount%2==0)
    {    board[satr][sootoon]='-';
        for(int j=sootoon+1; j<size ;j++)      //change right of -
        {
            if(board[satr][j]=='+'){continue;}
            if(board[satr][j]=='-')
            {
                for(int x=j ; x>sootoon ;x--)
                {
                    board[satr][x]='-';
                }
             break;}
            if(board[satr][j]==' '){break;}
        }
        for(int j=sootoon-1; j>=0 ;j--)      //change left of -
        {
            if(board[satr][j]=='+'){continue;}
            if(board[satr][j]=='-')
            {
                for(int x=j ; x<sootoon ;x++)
                {
                    board[satr][x]='-';
                }
             break;}
             if(board[satr][j]==' '){break;}
       }
        for(int j=satr-1; j>=0 ;j--)      //change up of -
        {
            if(board[j][sootoon]=='+'){continue;}
            if(board[j][sootoon]=='-')
            {
                for(int x=j ; x<satr ;x++)
                {
                    board[x][sootoon]='-';
                }
             break;}
             if(board[j][sootoon]==' '){break;}
        }
        for(int j=satr+1; j<size ;j++)      //change down of -
        {
            if(board[j][sootoon]=='+'){continue;}
            if(board[j][sootoon]=='-')
            {
                for(int x=j ; x>satr ;x--)
                {
                    board[x][sootoon]='-';
                }
             break;}
            if(board[j][sootoon]==' '){break;}
        }

        for(int i=satr+1,j=sootoon+1 ; i<size&&j<size ;i++,j++)         //change south east -
        {
            if(board[i][j]=='+'){continue;}
            if(board[i][j]=='-')
            {
             for(int x=i,y=j; x>satr&&y>sootoon ;x--,y--)
             {
                 board[x][y]='-';
             }
              break;}
            if(board[i][j]==' '){break;}
        }
        for(int i=satr-1,j=sootoon-1 ; i>=0&&j>=0 ;i--,j--)         //change north west -
        {
            if(board[i][j]=='+'){continue;}
            if(board[i][j]=='-')
            {
             for(int x=i,y=j; x<satr&&y<sootoon ;x++,y++)
             {
                 board[x][y]='-';
             }
              break;}
            if(board[i][j]==' '){break;}
        }
        for(int i=satr-1,j=sootoon+1 ; i>=0&&j<size ;i--,j++)         //change north east -
        {
            if(board[i][j]=='+'){continue;}
            if(board[i][j]=='-')
            {
             for(int x=i,y=j; x<satr&&y>sootoon ;x++,y--)
             {
                 board[x][y]='-';
             }
              break;}
             if(board[i][j]==' '){break;}
        }
        for(int i=satr+1,j=sootoon-1 ; i<size&&j>=0 ;i++,j--)         //change south west -
        {
            if(board[i][j]=='+'){continue;}
            if(board[i][j]=='-')
            {
             for(int x=i,y=j; x>satr&&y<sootoon ;x--,y++)
             {
                 board[x][y]='-';
             }
              break;}
             if(board[i][j]==' '){break;}
        }}
lastgamesave(board,turncount);
}
int main()
{
    char board[size][size];
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            board[i][j] = ' ';
    board[3][3] = '-';
    board[3][4] = '+';
    board[4][3] = '+';
    board[4][4] = '-';
    last10games(total1,total2);
    cout<<"last game is unfinished\n"<<"load it with 1 or ignore it with 2:";
    int taed;
    cin>>taed;
    if(taed==1){lastgameload(board,turncount);}
    lastgamesave(board,turncount);
    while(total1+total2<=64) {
        turncount=turnavalie(turncount);
        total1=getScore1(board);
    cout<<"plus point is:"<<total1<<endl;
    total2=getScore2(board);
    cout<<"minus point is:"<<total2<<endl;
    dispBoard(board);
    legalshomar=legalMovesrec(board,turncount);
    cout<<endl;
    int inpcount=0;
        int satr,sootoon;
        if(legalshomar==0)
        {    if(total1+total2==64){cout<<"bazi tamoom shod boro khoonatoon;)"<<endl;
                if(total1>total2)
                {cout<<"plus is winner with score:"<<total1<<endl;}
                if(total1<total2)
                {cout<<"minus is winner with score:"<<total2<<endl;}
                if(total1==total2)
                {cout<<"game ended with draw scores: "<<"plus:"<<total1<<"  minus:"<<total2<<endl;}
                return 0;}
            turncount=turnavalie(turncount);
            legalshomar=legalMovesrec(board,turncount);
        if(legalshomar==0){
            cout<<"game is over"<<endl;
            if(total1>total2)
            {cout<<"plus is winner with score:"<<total1<<endl;}
            if(total1<total2)
            {cout<<"minus is winner with score:"<<total2<<endl;}
            if(total1==total2)
            {cout<<"game ended with draw scores: "<<"plus:"<<total1<<"  minus:"<<total2<<endl;}
            return 0;
        }}
        while(inpcount==0)
       { cout<<"enter satr:";
        cin>>satr;
        cout<<endl<<"enter sootoon:";
        cin>>sootoon;
        for(int x=0 ; x<=64 ;x++)
        {
            if(put[0][x]==satr&&put[1][x]==sootoon)
            {
                inpcount++;
                cout<<"it's legal:"<<endl;
            }
            if(x==64&&inpcount==0)
            {
                cout<<"illegal move havaset kojast!"<<endl;
            }
        }
        }
        paksazi();
    change(board,satr,sootoon,turncount);
      }
    return 0;
}
