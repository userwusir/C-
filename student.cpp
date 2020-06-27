#include <algorithm>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#define maxsize 1000 //允许录入1000名学生
#define sp 32
using namespace std;
class student
{
private:
    string name;              //学生姓名
    string sub_name[50];      //课程名
    vector<double> sub_score; //课程分数
    string lev;               //语文级别
    double average;           //平均成绩

public:
    student() : name(""), sub_score(50, 0), lev(""), average(0.0)
    {
        for (int i = 0; i < 50; i++)
            sub_name[i] = "";
    }
    friend void chinese_level(student a[]); //求语文级别
    friend void level(student a[]);
    friend void avg(student a[]);      //求平均成绩
    friend void max(student a[]);      //求最好成绩
    friend void min(student a[]);      //求最差成绩
    friend void get(student a[]);      //录入函数
    friend void sort_avg(student a[]); //平均分排序
    friend void display(student a[]);  //显示函数
};
void avg(student a[])
{
    string s;
    cout << "\t\t请输入想要查看平均分的学生姓名：";
    cin >> s;
    int j = 0;
    while (a[j].name != "")
        if (a[j].name == s)
        {
            double sum = 0.0;
            int i = 0;
            auto it = a[j].sub_score.begin();
            while (*it != -1)
            {
                sum += *it++;
                i++;
            }
            sum /= i;
            cout << "\t\t" << a[j].name << "的平均成绩为：" << sum << endl;
            j++;
        }
        else
            j++;
    system("pause");
}
void max(student a[])
{
    string s;
    cout << "\t\t请输入想要查看科目最高分的学生姓名：";
    cin >> s;
    int i = 0;
    while (a[i].name != "")
        if (a[i].name == s)
        {
            vector<double>::const_iterator iter;
            iter = max_element(a[i].sub_score.begin(), a[i].sub_score.end());
            cout << "\t\t" << a[i].name << "的最高分为：" << *iter << endl;
            i++;
        }
        else
            i++;
    system("pause");
}
void min(student a[])
{
    string s;
    cout << "\t\t请输入想要查看科目最高分的学生姓名：";
    cin >> s;
    int i = 0;
    while (a[i].name != "")
        if (a[i].name == s)
        {
            vector<double>::const_iterator iter;
            auto it = a[i].sub_score.begin();
            while (*it != -1)
                it++;
            iter = min_element(a[i].sub_score.begin(), it);
            cout << "\t\t" << a[i].name << "的最差成绩为：" << *iter << endl;
            i++;
        }
        else
            i++;
    system("pause");
}
void chinese_level(student a[])
{
    string x;
    int k = 0;
    cout << "\t\t请输入想要查看语文等级的学生姓名：";
    cin >> x;
    while (a[k].name != "")
        if (a[k].name == x)
        {
            string s = a[k].sub_name[0];
            int i = 0;
            while (s != "-1")
            {
                if (s == "语文")
                    break;
                s = a[k].sub_name[++i];
            }
            if (a[k].sub_score[i] >= 90 && a[k].sub_score[i] <= 100)
                a[k].lev = "优秀";
            else if (a[k].sub_score[i] >= 75 && a[k].sub_score[i] <= 89)
                a[k].lev = "良好";
            else if (a[k].sub_score[i] >= 60 && a[k].sub_score[i] <= 74)
                a[k].lev = "及格";
            else if (a[k].sub_score[i] < 60)
                a[k].lev = "不及格";
            cout << "\t\t" << a[k].name << "的语文等级为：" << a[k].lev << endl;
            k++;
        }
        else
            k++;
    system("pause");
}
void display(student a[])
{
    int k = 0;
    while (a[k].name != "")
    {
        cout << "\t\t"
             << "学生姓名：" << a[k].name << endl;
        cout << "\t\t"
             << "课程名：";
        string s = a[k].sub_name[0];
        int i = 0;
        while (s != "-1")
        {
            cout << s << '\t';
            s = a[k].sub_name[++i];
        }
        cout << endl
             << "\t\t"
             << "课程分数：";
        auto it = a[k].sub_score.begin();
        while (*it != -1)
            cout << *it++ << "\t";
        cout << endl;
        k++;
    }
    system("pause");
}
void level(student a[])
{
    int k = 0;
    vector<int> sum(6, 0);
    while (a[k].name != "")
    {
        auto it = a[k].sub_score.begin();
        while (*it != -1)
        {
            if (*it == 100)
                sum[0] += 1;
            else if (*it >= 90 && *it <= 99)
                sum[1] += 1;
            else if (*it >= 80 && *it <= 89)
                sum[2] += 1;
            else if (*it >= 70 && *it <= 79)
                sum[3] += 1;
            else if (*it >= 60 && *it <= 69)
                sum[4] += 1;
            else if (*it < 60)
                sum[5] += 1;
            it++;
        }
        k++;
    }
    cout << "\t\t100分的人数为：" << sum[0] << endl;
    cout << "\t\t90-99分的人数为：" << sum[1] << endl;
    cout << "\t\t80-89分的人数为：" << sum[2] << endl;
    cout << "\t\t70-79分的人数为：" << sum[3] << endl;
    cout << "\t\t60-69分的人数为：" << sum[4] << endl;
    cout << "\t\t低于60分的人数为：" << sum[5] << endl;
    system("pause");
}
void get(student a[])
{
    int k = 0;
    while (1)
    {
        string x;
        cout << "是否录入？（是Y否N）";
        cin >> x;
        if (x == "Y")
        {
            int i = 0, j = 0, num = 0;
            string s;
            cout << "\t\t请输入学生姓名（回车终止）：";
            cin >> s;
            a[k].name = s;
            cout << "\t\t请输入课程名(输入-1终止)：";
            while (s != "-1")
            {
                cin >> s;
                a[k].sub_name[i++] = s;
            }
            cout << "\t\t请输入各科成绩（输入-1终止）：";
            while (num != -1)
            {
                cin >> num;
                a[k].sub_score[j++] = num;
            }
            k++;
        }
        else
            break;
    }
}
bool compare(double a, double b)
{
    return a > b;
}
void sort_avg(student a[])
{
    int j = 0;
    while (a[j].name != "")
    {
        double sum = 0.0;
        int i = 0;
        auto it = a[j].sub_score.begin();
        while (*it != -1)
        {
            sum += *it++;
            i++;
        }
        sum /= i;
        a[j].average = sum;
        j++;
    }
    vector<double> x;
    int i = 0;
    while (a[i].name != "")
        x.push_back(a[i++].average);
    sort(x.begin(), x.end(), compare);
    auto it = x.begin();
    cout << "\t\t"
         << "学生各科平均分排序为：";
    while (it != x.end())
        cout << *it++ << "  ";
    cout << endl;
    system("pause");
}
void printfchar(unsigned int x, char y) //输出指定个数的符号
{
    for (; x > 0; x--)
        printf("%c ", y);
    if (y != sp)
        printf("\n");
}
void enter() //密码登入系统
{
    char key[7] = {"123456"}, admin[11] = {"admin"}; //设置六位密码
    system("color 5f");
    char adminx[11], keyx[7];
    while (1)
    {
        printf("\n\n\n\n");
        printfchar(17, sp);
        printfchar(23, '*');
        printfchar(17, sp);
        printf("%c                                           %c\n", '*', '*');
        printfchar(17, sp);
        printf("%c                学生成绩系统               %c\n", '*', '*');
        printfchar(17, sp);
        printf("%c                                           %c\n", '*', '*');
        printfchar(17, sp);
        printfchar(23, '*');
        printfchar(17, sp);
        printf("用户名(默认为admin):");
        scanf("%s", adminx);
        printfchar(17, sp);
        printf("密码(默认为123456):");
        scanf("%s", keyx);
        if ((strcmp(admin, adminx) == 0) && (strcmp(key, keyx) == 0))
            break;
        else
        {
            printf("\n");
            printfchar(17, sp);
            printf("用户名或密码输入错误，按任意键重新输入！");
            getch();
            system("cls");
        }
    }
}
void Desktop() //界面设计
{
    printf("\n\n");
    printfchar(17, sp);
    printfchar(21, '*');
    printfchar(17, sp);
    printf("%c                                       %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c             成绩管理系统              %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c                                       %c\n", '*', '*');
    printfchar(17, sp);
    printfchar(21, '*');
    printfchar(17, sp);
    printf("%c             1.录入信息                %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c                                       %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c             2.输出信息                %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c                                       %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c             3.查询学生平均分          %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c                                       %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c             4.学生平均分排序          %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c                                       %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c             5.学生最高成绩            %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c                                       %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c             6.学生最低成绩            %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c                                       %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c             7.学生语文等级            %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c                                       %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c             8.分数区段人数            %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c                                       %c\n", '*', '*');
    printfchar(17, sp);
    printf("%c             0.返回用户登录界面        %c\n", '*', '*');
    printfchar(17, sp);
    printfchar(21, '*');
    printfchar(18, sp);
    printf("输入所需要的功能对应的序号:");
}
int main()
{
    student arr[maxsize];
    bool en = true;
    int sw;
    while (en)
    {
        system("cls");
        enter();
        while (1)
        {
            system("color 5f");
            system("cls");
            Desktop();
            cin >> sw;
            system("cls");
            switch (sw)
            {
            case 1:
                get(arr);
                continue;
            case 2:
                display(arr);
                continue;
            case 3:
                avg(arr);
                continue;
            case 4:
                sort_avg(arr);
                continue;
            case 5:
                max(arr);
                continue;
            case 6:
                min(arr);
                continue;
            case 7:
                chinese_level(arr);
                continue;
            case 8:
                level(arr);
                continue;
            case 0:
                sw = 1;
                break;
            default:
                printf("输入错误，请按任意键重新输入!");
                getch();
                break;
            }
            if (sw == 0)
                continue;
            else if (sw == 1)
                break;
        }
    }
    system("pause");
    return 0;
}