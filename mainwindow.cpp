#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stack>
#include <string>
#include<sstream>
#include<iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cstring>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_1_clicked()
{
    QString str = ui->lineEdit->text().append("1");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_2_clicked()
{
    QString str = ui->lineEdit->text().append("2");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_3_clicked()
{
    QString str = ui->lineEdit->text().append("3");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_0_clicked()
{
    QString str = ui->lineEdit->text().append("0");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_6_clicked()
{
    QString str = ui->lineEdit->text().append("6");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_5_clicked()
{
    QString str = ui->lineEdit->text().append("5");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_4_clicked()
{
    QString str = ui->lineEdit->text().append("4");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_9_clicked()
{
    QString str = ui->lineEdit->text().append("9");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_8_clicked()
{
    QString str = ui->lineEdit->text().append("8");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_7_clicked()
{
    QString str = ui->lineEdit->text().append("7");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_dot_clicked()
{
    QString str = ui->lineEdit->text().append(".");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_mod_clicked()
{
    QString str = ui->lineEdit->text().append("%");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_div_clicked()
{
    QString str = ui->lineEdit->text().append("/");
    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_mul_clicked()
{
    QString str = ui->lineEdit->text().append("*");

    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_m_clicked()
{
    QString str = ui->lineEdit->text().append("-");

    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_add_clicked()
{
    QString str = ui->lineEdit->text().append("+");

    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_left_c_clicked()
{
    QString str = ui->lineEdit->text().append("(");

    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_rigth_c_clicked()
{
    QString str = ui->lineEdit->text().append(")");

    ui->lineEdit->setText(str);
}

void MainWindow::on_Button_pow2_clicked()
{
    QString str = ui->lineEdit->text().append("^2");

    ui->lineEdit->setText(str);
}


void MainWindow::on_Button_sq_clicked()
{
    QString str = ui->lineEdit->text().append("sqrt");
    ui->lineEdit->setText(str);
}
vector<string> preParse(char *str)   //对中缀表达式进行预处理，分离出每个token
{
    vector<string> tokens;
    int len = strlen(str);
    char *p = (char *)malloc((len+1)*sizeof(char));  //注意不要用 char *p = (char *)malloc(sizeof(str))来申请空间
    int i=0,j=0;
    while(i<len)          //去除表达式中的空格
    {
        if(str[i]==' ')
        {
            i++;
            continue;
        }
        p[j++] = str[i++];
    }
    p[j]='\0';
    j=0;
    len = strlen(p);
    while(j<len)
    {
        char temp[2];
        string token;
        switch(p[j])
        {
            case '+':
            case '*':
            case '/':
            case '(':
            case ')':
                {
                    temp[0] =p[j];
                    temp[1] = '\0';
                    token=temp;
                    tokens.push_back(token);
                    break;
                }
            case '-':
                {
                    if(p[j-1]==')'||isdigit(p[j-1]))  //作为减号使用
                    {
                        temp[0] =p[j];
                        temp[1] = '\0';
                        token=temp;
                        tokens.push_back(token);
                    }
                    else    //作为负号使用
                    {
                        temp[0] ='#';
                        temp[1] = '\0';
                        token=temp;
                        tokens.push_back(token);
                    }
                    break;
                }
            default:     //是数字
                {
                    i = j;
                    while(isdigit(p[i])&&i<len)
                    {
                        i++;
                    }
                    char *opd = (char *)malloc(i-j+1);
                    strncpy(opd,p+j,i-j);
                    opd[i-j]='\0';
                    token=opd;
                    tokens.push_back(token);
                    j=i-1;
                    free(opd);
                    break;
                }
        }
        j++;
    }
    free(p);
    return tokens;
}

int getPriority(string opt)
{
    int priority;
    if(opt=="#")
        priority = 3;
    else if(opt=="*"||opt=="/")
        priority = 2;
    else if(opt=="+"||opt=="-")
        priority = 1;
    else if(opt=="(")
        priority = 0;
    return priority;
}


void calculate(stack<int> &opdStack,string opt)
{
    if(opt=="#")  //进行负号运算
    {
        int opd = opdStack.top();
        int result = 0-opd;
        opdStack.pop();
        opdStack.push(result);
        cout<<"操作符:"<<opt<<" "<<"操作数:"<<opd<<endl;
    }
    else if(opt=="+")
    {
        int rOpd = opdStack.top();
        opdStack.pop();
        int lOpd = opdStack.top();
        opdStack.pop();
        int result = lOpd + rOpd;
        opdStack.push(result);

        cout<<"操作符:"<<opt<<" "<<"操作数:"<<lOpd<<" "<<rOpd<<endl;
    }
    else if(opt=="-")
    {
        int rOpd = opdStack.top();
        opdStack.pop();
        int lOpd = opdStack.top();
        opdStack.pop();
        int result = lOpd - rOpd;
        opdStack.push(result);
        cout<<"操作符:"<<opt<<" "<<"操作数:"<<lOpd<<" "<<rOpd<<endl;
    }
    else if(opt=="*")
    {
        int rOpd = opdStack.top();
        opdStack.pop();
        int lOpd = opdStack.top();
        opdStack.pop();
        int result = lOpd * rOpd;
        opdStack.push(result);
        cout<<"操作符:"<<opt<<" "<<"操作数:"<<lOpd<<" "<<rOpd<<endl;
    }
    else if(opt=="/")
    {
        int rOpd = opdStack.top();
        opdStack.pop();
        int lOpd = opdStack.top();
        opdStack.pop();
        if(rOpd==0) {
            throw "除数不能为0";
        }
        int result = lOpd / rOpd;
        opdStack.push(result);
        cout<<"操作符:"<<opt<<" "<<"操作数:"<<lOpd<<" "<<rOpd<<endl;
    } else {
        throw "输入异常";
    }
}

int evaMidExpression(char *str)   //中缀表达式直接求值
{
    vector<string> tokens = preParse(str);
    int i=0;
    int size = tokens.size();

    stack<int> opdStack;     //存储操作数
    stack<string> optStack;   //存储操作符
    for(i=0;i<size;i++)
    {
        string token = tokens[i];
        if(token=="#"||token=="+"||token=="-"||token=="*"||token=="/")
        {
            if(optStack.size()==0)   //如果操作符栈为空
            {
                optStack.push(token);
            }
            else
            {
                int tokenPriority = getPriority(token);
                string topOpt = optStack.top();
                int topOptPriority = getPriority(topOpt);
                if(tokenPriority>topOptPriority)
                {
                    optStack.push(token);
                }
                else
                {
                    while(tokenPriority<=topOptPriority)
                    {
                        optStack.pop();
                        calculate(opdStack,topOpt);
                        if(optStack.size()>0)
                        {
                            topOpt = optStack.top();
                            topOptPriority = getPriority(topOpt);
                        }
                        else
                            break;
                    }
                    optStack.push(token);
                }
            }
        }
        else if(token=="(")
        {
            optStack.push(token);
        }
        else if(token==")")
        {
            while(optStack.top()!="(")
            {
                string topOpt = optStack.top();
                calculate(opdStack,topOpt);
                optStack.pop();
            }
            optStack.pop();
        }
        else   //如果是操作数，直接入操作数栈
        {
            opdStack.push(atoi(token.c_str()));
        }
    }
    while(optStack.size()!=0)
    {
        string topOpt = optStack.top();
        calculate(opdStack,topOpt);
        optStack.pop();
    }
    return opdStack.top();
}

void MainWindow::on_Button_eq_clicked()
{
    QString str = ui->lineEdit->text();
    try{
        std::string t = std::to_string(evaMidExpression((char*)str.toStdString().c_str()));
        ui->lineEdit->setText(QString(QString::fromLocal8Bit(t.c_str())));
    }catch(const char* msg) {
        ui->lineEdit->setText(msg);
    }
}

void MainWindow::on_Button_back_clicked()
{
    QString str2 = ui->lineEdit->text();
    try {
        string str3 = str2.toStdString().substr(0,str2.length()-1);
        ui->lineEdit->setText(QString(QString::fromLocal8Bit(str3.c_str())));
    } catch(...) {
        ui->lineEdit->setText("异常");
    }
}

void MainWindow::on_Button_ac_clicked()
{
    ui->lineEdit->setText("");
}
