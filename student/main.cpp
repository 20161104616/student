#include"iostream"
#include <fstream>
#include "sstream"
#include "string"
#include "vector"
using namespace std;
struct student {
    string name;
    string sex;
    string classnum;
    string projectname;
    string projectkind;
    string num;
    int score;
};
typedef student elemtype;

typedef struct
{
    elemtype elem[100];
    int last;
}actornumber;

struct jury {
    char nane;
    char sex;
    int age;
};
typedef jury jurys;

typedef struct
{
    jurys jur[10];
    int counter;
    int lasttwo;
}jurenumber;


void Playerinformation(actornumber* l)
{
    int i, j;
    cout << "增加的选手数量" << endl;
    cin >> j;
    ofstream outfile;
    outfile.open("//Users//a20161104616//Desktop//student//information.csv",ios::app);
  //  ofstream outfile("/Users/a20161104616/Desktop/student/information.csv",ios::app);
    for (i = 0; i<j; i++)
    {
        cout << "新增第" << i + 1 << "位" ;
        cout << "姓名" << endl;
        cin >> l->elem[i].name;
        outfile<<l->elem[i].name<<',';
        cout << "性别" << endl;
        cin >> l->elem[i].sex;
        outfile<<l->elem[i].sex<<',';
        cout << "班级" << endl;
        cin >> l->elem[i].classnum;
        outfile<<l->elem[i].classnum<<',';
        cout << "项目名称" << endl;
        cin >> l->elem[i].projectname;
        outfile<<l->elem[i].projectname<<',';
        cout << "项目类型" << endl;
        cin >> l->elem[i].projectkind;
        outfile<<l->elem[i].projectkind<<',';
        cout << "电话号码" << endl;
        cin >> l->elem[i].num;
        outfile<<l->elem[i].num<<','<<endl;
        l->last++;
    }
    
    
    
    
    
    
}

void grademark(jurenumber* k)
{
    
    cout << "输入评委数量（3--10)" << endl;
    cin >> k->counter;
}


void scoremark(actornumber* l, jurenumber* k)//´ò·Ö
{
    int x, sum;
    double y;
    int mymax = 0, mymin = 10;
    for (int i = 1; i <= l->last; i++)
    {
        for (x = 1, sum = 0; x <= k->counter; x++) {
            cout << "第"<< x << "位评委打分：" << endl;
            cin >> y;
            sum = sum + y;
            if (y>mymax)
                mymax = y;
            if (y<mymin)
                mymin = y;
        }
        sum = (sum - mymax - mymin) / (k->counter - 2);
        l->elem[i - 1].score = sum;
    }
}

void sort(actornumber *l)
{
   // cout << l->elem[0].score;
    int i, j;
    elemtype chan;
    for (i = 0; i <= l->last; i++)
    {
        for (j = 0; j<l->last - i - 1; j++)
        {
            if (l->elem[j].score>l->elem[j + 1].score)
            {
                chan = l->elem[j];
                l->elem[j] = l->elem[j + 1];
                l->elem[j + 1] = chan;
            }
        }
        
    }
    for (i = 0; i < l->last; i++)
        cout << "第" << i + 1 << "位，" << "姓名" << l->elem[i].name << ",性别" << l->elem[i].sex
        << ",项目名称" << l->elem[i].projectname << ",项目种类" << l->elem[i].projectkind
        << ",号码" << l->elem[i].num << ",班级" << l->elem[i].classnum << ",成绩" << l->elem[i].score << endl;
    cout << "已排序" << endl;
}

void read(actornumber* l)
{
    cout<<"______________________"<<endl;
    int i=0;
    ifstream fin("//Users//a20161104616//Desktop//student//information.csv");
    string line;
    while(getline(fin,line))
    {
        i++;
        cout<<"第"<<i<<"位选手："<<endl;
        cout<<"姓名，性别，节目名称，节目类型，电话号码，班级"<<endl<<line<<endl;
    }
}

void scoreout(actornumber* l)
{
    ofstream outfile;
    outfile.open("//Users//a20161104616//Desktop//student//scores.csv",ios::app);
    outfile<<"name"<<','<<"score"<<endl;
    for(int i=0;i<l->last;i++)
    {
        outfile<<l->elem[i].name<<','<<l->elem[i].score<<endl;
    }
    
    
}



int main(){
    actornumber* l;
    jurenumber* k;
    l = (actornumber *)malloc(sizeof(actornumber));
    k=(jurenumber *)malloc(sizeof(jurenumber));
    l->last=0;
    Playerinformation(l);
    grademark(k);
    scoremark(l,k);
    sort(l);
    scoreout(l);
    read(l);
}
