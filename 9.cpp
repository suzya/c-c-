#include<iostream.h>
#include<windows.h>
#include<time.h>
void gb(int x,int y)
{
    COORD  c;         // ���
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
    cout<<"��";}
	cout<<endl;
	srand(time(0));    // �����
       COORD  c;      // ���
    c.X = rand() %50;           
    c.Y = rand() %50;           
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // ������
    SetConsoleCursorPosition(hOut, c);	   // ���ù��λ��
    cout<<"��"<<endl; 
	return 0;
}
