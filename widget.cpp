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
void Widget::printMensaje(QString msn)
{
    ui->plainTextEdit->setPlainText(msn);
}
void Widget::on_pushButton_clicked()
{
    sendMensaje();
}
