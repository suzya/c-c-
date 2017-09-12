#include<iostream.h>
#include<iomanip.h>
#include<string.h>
const int M=10;

class date      
{ private:
    int year,month,day;    //年、月、日三个私有成员
  public: 
	date(void)
	{ year=1980;month=1;day=1;}
    void set_date(int y,int m,int d)
	{
		year=y;
		month=m;
		day=d;
	}                           //完成成员函数的定义
	int get_year(void)
	{  return year;             }          //完成成员函数的定义
	int get_month(void)
	{    return month;        }          //完成成员函数的定义
	int get_day(void) 
	{     return day;     }          //完成成员函数的定义
};

//person类的定义：保存在person.h中
class person
{ protected:
    char name[11];
	char sex[2];
	date birthday;
  public:
    person(void);   //无参构造函数
    void set_person(char *na,char *s,int y,int m,int d);
	char *get_name(void)
	{  return name;    }           //完成成员函数的定义
	char *get_sex(void)
	{     return sex;}           //完成成员函数的定义
	int get_year(void)
	{      return birthday.get_year();  }           //完成成员函数的定义
	int get_month(void)
	{return  birthday.get_month();}
int get_day (void)	
{        birthday.get_day();    }           //完成成员函数的定义
void print(void);
};
person::person(void)   //无参构造函数
{ strcpy(name,"无名氏");
  strcpy(sex,"男");
  birthday.set_date(1980,1,1);
}
void person::set_person(char *na,char *s,int y,int m,int d)
{  strcpy(name,na);
strcpy(sex,s);
birthdaay.set_date(y,m,d);
}           //完成成员函数的定义
void person::print(void)
{ cout<<"姓名:"<<name<<endl;
  cout<<"性别:"<<sex<<endl;
  cout<<"出生日期:"<<birthday.get_year()<<"年";
  cout<<birthday.get_month()<<"月";
  cout<<birthday.get_day()<<"日"<<endl;
}

class student :public person      
{ public :
    int id;
    char department[20];
	date enterdate;
  public :
	student(void);
	void set_student(int n ,char *s,int y,int m,int d);
    int get_id(void) 
	{  return id;}           //完成成员函数的定义
	char *get_department(void)
	{  return department;         }           //完成成员函数的定义
	int get_enteryear(void)
	{   return enterdate.get_year();  }           //完成成员函数的定义
	int get_entermonth(void)
	{   return enterdate.get_month();}           //完成成员函数的定义
	int get_enterday(void)
	{   return  enterdate.get_day();    }           //完成成员函数的定义
	void print(void);
	void print_base();
};

student::student(void)
{ strcpy(name,"无名氏");
  strcpy(sex,"男");
  birthday.set_date(1980,1,1);
  id=0;
  strcpy(department,"计算机");
  enterdate.set_date(2000,9,1);
}
void student::set_student(int n ,char *s,int y,int m,int d)
//n、s、y、m、d分别为id、department、enterdate提供值
{  id=n;
strcpy(department,s);
 }           //完成成员函数的定义

void student::print(void)
{ cout<<"学号:"<<id<<endl;
  person::print();             
  cout <<"系(专业):"<<department<<endl;
  cout<<"进校日期:"<< enterdate.get_year()<<"年";
  cout<<enterdate.get_month()<<"月";
  cout<<enterdate.get_day()<<"日"<<endl;
}
void student::print_base()
{ cout<<setw(8)<<get_id();
  cout<<setw(12)<<get_name();
  cout<<setw(4)<<get_sex();
  cout<<setw(6)<<get_year()<<"-"<<get_month()<<"-"<<get_day();
  cout<<setw(20)<<get_department();
  cout<<setw(6)<<get_enteryear()<<"-"<<get_entermonth();
  cout<<"-"<<get_enterday()<<endl;
}

class score:public student
{ private:
    float sc[M],aver;
	int m;
  public:
	score(void);             //无参构造函数
    void set_score(float x[],int n);  //提供成绩
	float get_score(int i)            //得到第i科成绩
	{            }           //完成成员函数的定义
    float get_aver(void)            //得到平均成绩
	{            }           //完成成员函数的定义
	void print(void);
	void print_score(void);
};


score::score(void)                     //无参构造函数
{ 
  strcpy(name,"无名氏");
  strcpy(sex,"男");
  birthday.set_date(1980,1,1);
  id=0;
  strcpy(department,"计算机");
  enterdate.set_date(2000,9,1);
  int i;
  m=M;
  for(i=0;i<m;i++)
    sc[i]=0;
  aver=0;
}
void score::set_score(float x[],int n)  //提供成绩:完成成员函数的定义
{ int i;float sum=0;
  m=n;
  for(i=0;i<m;i++)
  {             }
  aver=sum/m;
}
void score::print(void)       //重载输出print()
{ student::print();
  int i;
  for(i=0;i<m;i++)
	cout<<"  "<<sc[i];
  cout<<"  "<<aver<<endl; 
}
void score::print_score(void)
{ int j;
  cout<<setw(8)<<get_id();
  cout<<setw(12)<<get_name();
  for(j=0;j<m;j++)
    cout<<setw(6)<<get_score(j);
  cout<<" "<<setw(6)<<get_aver()<<endl;
}
//成绩处理程序：保存在exp_603.cpp中

void input_base(score *p,int n);  //学生基本数据输入
void input_score(score *p,int n,int m);  //学生成绩输入
void print_base(score *p,int n);  //学生基本数据输出
void print_score(score *p,int n,int m);  //学生成绩输出
score &average(score *p,int n,int m);  //普通函数：平均成绩计算
void sort(score *p,int n,int m);//普通函数：按平均成绩排序

void input_base(score *p,int n)  //学生基本数据输入
{ int i,id,y1,m1,d1,y2,m2,d2;
  char name[11],sex[3],dpt[20];
  cout<<"\n  请输入学生基本数据:";
  for(i=0;i<n;i++)
  { cout<<"第"<<i+1<<"个学生:\n";
    cout<<"学号:";cin>>id;
	cout<<"姓名:";cin>>name;
    cout<<"性别:";cin>>sex;
	cout<<"出生年:";cin>>y1;
    cout<<"出生月:";cin>>m1;
	cout<<"出生日:";cin>>d1;
	cout<<"所在系:";cin>>dpt;
	cout<<"入学年:";cin>>y2;
    cout<<"入学月:";cin>>m2;
	cout<<"入学日:";cin>>d2;	
	p[i].set_person(           );//完成函数的调用
    p[i].set_student(          );//完成函数的调用
  }
}
void input_score(score *p,int n,int m)     
{ int i,j;float x[M];
  for(i=0;i<n;i++)
  { cout<<p[i].get_id()<<p[i].get_name()<<"的成绩："<<endl;
    for(j=0;j<m;j++)
	{ cout<<"第"<<j+1<<"科成绩：";
	  cin>>x[j];
	}
	p[i].set_score(       );//完成函数的调用
  }
}
void print_base(score *p,int n)
{ int i;
  for(i=0;i<n;i++)
    p[i].print_base();
  cout<<endl;
}
void print_score(score *p,int n,int m)
{ int i;
  for(i=0;i<n;i++)
    p[i].print_score();
}
score &average(score *p,int n,int m) //用返回引用的方法
{ int i,j;  float s[M]={0};
  static score aver;       //返回的对象必须是静态的
  for(j=0;j<m;j++)
  { for(i=0;i<n;i++)
      s[j]=s[j]+p[i].get_score(j);
    s[j]=s[j]/n;
  }
  aver.set_person("平均成绩"," ",0,0,0);
  aver.set_score(       );//完成函数的调用
  return aver;
}
void sort(score *p,int n,int m)//选择法排序：完成空白处的内容
{ score t;float a;
  int i,j,k;
  for(i=0;i<n-1;i++)
  { a=p[i].get_aver();k=i;
    for(j=i+1;j<n;j++)
	  if(         )
	  { a=p[j].get_aver();k=j;}
	if(            )
	{ t=p[i];p[i]=p[k];p[k]=t;}
  }
}

void main()
{ int n,m;
  cout<<"学生人数：";cin >>n;
  cout<<"考试科数：";cin>>m;
  score *p,aver;     
  p=new score[n];  //动态分配内存单元--动态数组
  if(p==NULL)
  { cout<<"内存分配失败"<<endl;
    return ;
  }
 int ch;
 do 
  {
    cout<<"\n\n     请选择:\n";
	cout<<"  1. 输入学生基本数据\n";
	cout<<"  2. 输入学生成绩\n";
	cout<<"  3. 计算课程平均成绩\n";
	cout<<"  4. 输出学生基本数据\n";
	cout<<"  5. 输出学生成绩\n";
	cout<<"  6. 按平均成绩排序\n";
	cout<<"  0. 退出\n";
	cout<<"\n    输入你的选择:";
	cin>>ch;
	switch(ch)
	{ case 1 : input_base(p,n);break;
	  case 2 : input_score(p,n,m);break;
	  case 3 : aver=average(p,n,m);break;
	  case 4 : print_base(p,n);break;
      case 5 : print_score(p,n,m);aver.print_score();break;
	  case 6 : sort(p,n,m);break;
	  case 0 : break;
	}
  }
  while(ch);
  delete []p;          //释放内存
}