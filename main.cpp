#include <iostream>

using namespace std;

//����������
class Date
{
public:
    void setdate(int newy,int newm,int newd);
    void printdate();
    int judgeyear();
    void plusoneday();
private:
    int year,month,day;
};

void Date::setdate(int newy,int newm,int newd)//�趨����
{
    year=newy;
    month=newm;
    day=newd;
}

inline void Date::printdate()//��ӡ����
{
    cout<<year<<"/"<<month<<"/"<<day<<endl;
}

int Date::judgeyear()//�ж��Ƿ�Ϊ���꣬�����򷵻�1�����򷵻�0
{
    if(year%100==0)
    {
        if(year%400==0)
            return 1;
        else
            return 0;
    }
    else
    {
        if(year%4==0)
            return 1;
        else
            return 0;
    }
}

void Date::plusoneday()//ʵ�ּ�һ�����
{
    int i;

    switch(month)
    {
    case 1://��31�����
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:


        {
            if(day==31)
            {
                day=1;
                month++;
            }
            else
                day++;
            break;
        }
    case 12:
        {
            if(day==31)//12/31,��ݼ�һ
            {
                day=1;
                month=1;
                year++;
            }
            break;
        }
    case 2://�����Ƿ�Ϊ�����ж�2���м���
        {
            i=judgeyear();
            if(i==1)
            {
                if(day==29)
                {
                    day=1;
                    month++;
                }
                else
                {
                    day++;
                }

            }
            else
            {
                if(day==28)
                {
                    day=1;
                    month++;
                }
                else
                {
                    day++;
                }
            }
            break;
        }
    case 4://��30�����
    case 6:
    case 9:
    case 11:
        {
            if(day==30)
            {
                day=1;
                month++;
            }
            else
            {
                day++;
            }
            break;
        }
    }

}

int main()
{
    Date d;
    int n,i,year,month,day;
    while(1)
    {
        cout<<"����������"<<endl;
        cin>>year>>month>>day;
        if(month>12||day>31)//������������
        {
            cout<<"�������������"<<endl;
            continue;
        }
        d.setdate(year,month,day);
        cout<<"����1�����2��һ�������3�ж��Ƿ�����"<<endl;
        cin>>n;
        switch(n)
        {
        case 1:
            {
                d.printdate();
                break;
            }
        case 2:
            {
                d.plusoneday();
                d.printdate();
                break;
            }
        case 3:
            {
                i=d.judgeyear();
                d.printdate();

                if(i==0)
                {
                    cout<<"��������"<<endl;
                }
                else
                {
                    cout<<"������"<<endl;
                }
                break;
            }
        }
        cout<<"����1�˳�,2����"<<endl;
        cin>>n;
        if(n==1)
            return 0;
        else
            continue;
    }
}
