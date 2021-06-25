#include "widget.h"
#include "ui_widget.h"

#include "iostream"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <bits/stdc++.h>

#include <typeinfo>
#include <algorithm>
QString n1,n2,n3,n;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    conexion = new SocketCliente;
    if(!conexion->connectar())
        QMessageBox::critical(this,"Error","Error al conectar con el servidor",QMessageBox::Ok);

    connect(conexion,SIGNAL(NewMensaje(QString)),SLOT(printMensaje(QString)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::sendMensaje()
{
    conexion->setMensaje(ui->lineEdit->text().toStdString().c_str());

}
void Widget::sendMensaje2()
{
    conexion->setMensaje(ui->lineEdit_2->text().toStdString().c_str());

}
void Widget::printMensaje(QString msn)
{
    ui->plainTextEdit_2->setPlainText(msn);
}
void Widget::on_pushButton_clicked()
{
    sendMensaje();
}

void Widget::on_pushButton_2_clicked()
{
    sendMensaje2();
}
void ShowData(string m1, string m2, string m3, string m){

}

void Widget::on_dial_sliderPressed()
{
    ifstream f1;
    string txt1;
    f1.open("Cc1.text",ios::in);
    getline(f1,txt1);
    ui->lineEdit_3->setText(QString::fromStdString(txt1));
    f1.close();
    ifstream f2;
    string txt2;
    f2.open("Cc2.text",ios::in);
    getline(f2,txt2);
    ui->lineEdit_4->setText(QString::fromStdString(txt2));
    f2.close();
    ifstream f3;
    string txt3;
    f3.open("Cc3.text",ios::in);
    getline(f3,txt3);
    ui->lineEdit_5->setText(QString::fromStdString(txt3));
    f3.close();
    ifstream f;
    string txt;
    f.open("Cc.text",ios::in);
    getline(f,txt);
    ui->lineEdit_6->setText(QString::fromStdString(txt));
    f.close();

}
