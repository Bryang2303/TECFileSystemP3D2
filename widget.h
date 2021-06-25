#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QMessageBox>
#include "socketcliente.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();



    /**
     * @brief sendMensaje Permite el envio de un mensaje especifico, al servidor
     */
    void sendMensaje();
    void sendMensaje2();
    //static void ShowData(string m1,string m2, string m3, string m);

private slots:
    /**
     * @brief printMensaje Para imprimir el mensaje en la interfaz, aunque no es necesario
     * @param msn El mensaje que el CLiente recibe del Servidor
     */
    void printMensaje(QString msn);
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_dial_sliderPressed();

private:
    Ui::Widget *ui;

    SocketCliente *conexion;
};

#endif // WIDGET_H
