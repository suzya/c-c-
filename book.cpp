#include<iostream.h>
#include<iomanip.h>
#include<string.h>
const int M=10;

class date      
{ private:
    int year,month,day;    //�ꡢ�¡�������˽�г�Ա
  public: 
	date(void)
	{ year=1980;month=1;day=1;}
    void set_date(int y,int m,int d)
	{
		year=y;
		month=m;
		day=d;
	}                           //��ɳ�Ա�����Ķ���
	int get_year(void)
	{  return year;             }          //��ɳ�Ա�����Ķ���
	int get_month(void)
	{    return month;        }          //��ɳ�Ա�����Ķ���
	int get_day(void) 
	{     return day;     }          //��ɳ�Ա�����Ķ���
};

//person��Ķ��壺������person.h��
class person
{ protected:
    char name[11];
	char sex[2];
	date birthday;
  public:
    person(void);   //�޲ι��캯��
    void set_person(char *na,char *s,int y,int m,int d);
	char *get_name(void)
	{  return name;    }           //��ɳ�Ա�����Ķ���
	char *get_sex(void)
	{     return sex;}           //��ɳ�Ա�����Ķ���
	int get_year(void)
	{      return birthday.get_year();  }           //��ɳ�Ա�����Ķ���
	int get_month(void)
	{return  birthday.get_month();}
int get_day (void)	
{        birthday.get_day();    }           //��ɳ�Ա�����Ķ���
void print(void);
};
person::person(void)   //�޲ι��캯��
{ strcpy(name,"������");
  strcpy(sex,"��");
  birthday.set_date(1980,1,1);
}
void person::set_person(char *na,char *s,int y,int m,int d)
{  strcpy(name,na);
strcpy(sex,s);
birthdaay.set_date(y,m,d);
}           //��ɳ�Ա�����Ķ���
void person::print(void)
{ cout<<"����:"<<name<<endl;
  cout<<"�Ա�:"<<sex<<endl;
  cout<<"��������:"<<birthday.get_year()<<"��";
  cout<<birthday.get_month()<<"��";
  cout<<birthday.get_day()<<"��"<<endl;
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
	{  return id;}           //��ɳ�Ա�����Ķ���
	char *get_department(void)
	{  return department;         }           //��ɳ�Ա�����Ķ���
	int get_enteryear(void)
	{   return enterdate.get_year();  }           //��ɳ�Ա�����Ķ���
	int get_entermonth(void)
	{   return enterdate.get_month();}           //��ɳ�Ա�����Ķ���
	int get_enterday(void)
	{   return  enterdate.get_day();    }           //��ɳ�Ա�����Ķ���
	void print(void);
	void print_base();
};

student::student(void)
{ strcpy(name,"������");
  strcpy(sex,"��");
  birthday.set_date(1980,1,1);
  id=0;
  strcpy(department,"�����");
  enterdate.set_date(2000,9,1);
}
void student::set_student(int n ,char *s,int y,int m,int d)
//n��s��y��m��d�ֱ�Ϊid��department��enterdate�ṩֵ
{  id=n;
strcpy(department,s);
 }           //��ɳ�Ա�����Ķ���

void student::print(void)
{ cout<<"ѧ��:"<<id<<endl;
  person::print();             
  cout <<"ϵ(רҵ):"<<department<<endl;
  cout<<"��У����:"<< enterdate.get_year()<<"��";
  cout<<enterdate.get_month()<<"��";
  cout<<enterdate.get_day()<<"��"<<endl;
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
	score(void);             //�޲ι��캯��
    void set_score(float x[],int n);  //�ṩ�ɼ�
	float get_score(int i)            //�õ���i�Ƴɼ�
	{            }           //��ɳ�Ա�����Ķ���
    float get_aver(void)            //�õ�ƽ���ɼ�
	{            }           //��ɳ�Ա�����Ķ���
	void print(void);
	void print_score(void);
};


score::score(void)                     //�޲ι��캯��
{ 
  strcpy(name,"������");
  strcpy(sex,"��");
  birthday.set_date(1980,1,1);
  id=0;
  strcpy(department,"�����");
  enterdate.set_date(2000,9,1);
  int i;
  m=M;
  for(i=0;i<m;i++)
    sc[i]=0;
  aver=0;
}
void score::set_score(float x[],int n)  //�ṩ�ɼ�:��ɳ�Ա�����Ķ���
{ int i;float sum=0;
  m=n;
  for(i=0;i<m;i++)
  {             }
  aver=sum/m;
}
void score::print(void)       //�������print()
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
//�ɼ�������򣺱�����exp_603.cpp��

void input_base(score *p,int n);  //ѧ��������������
void input_score(score *p,int n,int m);  //ѧ���ɼ�����
void print_base(score *p,int n);  //ѧ�������������
void print_score(score *p,int n,int m);  //ѧ���ɼ����
score &average(score *p,int n,int m);  //��ͨ������ƽ���ɼ�����
void sort(score *p,int n,int m);//��ͨ��������ƽ���ɼ�����

void input_base(score *p,int n)  //ѧ��������������
{ int i,id,y1,m1,d1,y2,m2,d2;
  char name[11],sex[3],dpt[20];
  cout<<"\n  ������ѧ����������:";
  for(i=0;i<n;i++)
  { cout<<"��"<<i+1<<"��ѧ��:\n";
    cout<<"ѧ��:";cin>>id;
	cout<<"����:";cin>>name;
    cout<<"�Ա�:";cin>>sex;
	cout<<"������:";cin>>y1;
    cout<<"������:";cin>>m1;
	cout<<"������:";cin>>d1;
	cout<<"����ϵ:";cin>>dpt;
	cout<<"��ѧ��:";cin>>y2;
    cout<<"��ѧ��:";cin>>m2;
	cout<<"��ѧ��:";cin>>d2;	
	p[i].set_person(           );//��ɺ����ĵ���
    p[i].set_student(          );//��ɺ����ĵ���
  }
}
void input_score(score *p,int n,int m)     
{ int i,j;float x[M];
  for(i=0;i<n;i++)
  { cout<<p[i].get_id()<<p[i].get_name()<<"�ĳɼ���"<<endl;
    for(j=0;j<m;j++)
	{ cout<<"��"<<j+1<<"�Ƴɼ���";
	  cin>>x[j];
	}
	p[i].set_score(       );//��ɺ����ĵ���
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
score &average(score *p,int n,int m) //�÷������õķ���
{ int i,j;  float s[M]={0};
  static score aver;       //���صĶ�������Ǿ�̬��
  for(j=0;j<m;j++)
  { for(i=0;i<n;i++)
      s[j]=s[j]+p[i].get_score(j);
    s[j]=s[j]/n;
  }
  aver.set_person("ƽ���ɼ�"," ",0,0,0);
  aver.set_score(       );//��ɺ����ĵ���
  return aver;
}
void sort(score *p,int n,int m)//ѡ��������ɿհ״�������
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
  cout<<"ѧ��������";cin >>n;
  cout<<"���Կ�����";cin>>m;
  score *p,aver;     
  p=new score[n];  //��̬�����ڴ浥Ԫ--��̬����
  if(p==NULL)
  { cout<<"�ڴ����ʧ��"<<endl;
    return ;
  }
 int ch;
 do 
  {
    cout<<"\n\n     ��ѡ��:\n";
	cout<<"  1. ����ѧ����������\n";
	cout<<"  2. ����ѧ���ɼ�\n";
	cout<<"  3. ����γ�ƽ���ɼ�\n";
	cout<<"  4. ���ѧ����������\n";
	cout<<"  5. ���ѧ���ɼ�\n";
	cout<<"  6. ��ƽ���ɼ�����\n";
	cout<<"  0. �˳�\n";
	cout<<"\n    �������ѡ��:";
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
  delete []p;          //�ͷ��ڴ�
}