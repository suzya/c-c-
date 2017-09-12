#include<iostream.h>
#include<windows.h>
#include<time.h>
void gb(int x,int y)
{
    COORD  c;         // 光标
    c.X =x;           
    c.Y =y;           
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);    
}

int main()
{
	int i,j;
	for(j=0;j<3;j++)
	{
	gb(0,0);   
    cout<<"■";}
	cout<<endl;
	srand(time(0));    // 随机数
       COORD  c;      // 光标
    c.X = rand() %50;           
    c.Y = rand() %50;           
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // 输出句柄
    SetConsoleCursorPosition(hOut, c);	   // 设置光标位置
    cout<<"☆"<<endl; 
	return 0;
}
