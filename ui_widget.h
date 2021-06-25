/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QOpenGLWidget *openGLWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QOpenGLWidget *openGLWidget_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QDial *dial;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(479, 441);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(138, 226, 52, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(127, 127, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(170, 170, 170, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush5(QColor(62, 99, 132, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        Widget->setPalette(palette);
        openGLWidget = new QOpenGLWidget(Widget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(10, 40, 461, 141));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 80, 321, 31));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 80, 111, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush7(QColor(114, 159, 207, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush7);
        QBrush brush8(QColor(196, 225, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush8);
        QBrush brush9(QColor(155, 192, 231, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        QBrush brush10(QColor(57, 79, 103, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush10);
        QBrush brush11(QColor(76, 106, 138, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush12(QColor(184, 207, 231, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        pushButton->setPalette(palette1);
        QFont font;
        font.setPointSize(13);
        pushButton->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 161, 41));
        QPalette palette2;
        QBrush brush13(QColor(252, 233, 79, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush13);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush14(QColor(17, 58, 78, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label->setPalette(palette2);
        QFont font1;
        font1.setFamily(QStringLiteral("Uroob"));
        font1.setPointSize(26);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        openGLWidget_2 = new QOpenGLWidget(Widget);
        openGLWidget_2->setObjectName(QStringLiteral("openGLWidget_2"));
        openGLWidget_2->setGeometry(QRect(10, 190, 461, 241));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 200, 161, 41));
        QPalette palette3;
        QBrush brush15(QColor(239, 41, 41, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush15);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush15);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label_2->setPalette(palette3);
        label_2->setFont(font1);
        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 230, 321, 31));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 230, 111, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush8);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        pushButton_2->setPalette(palette4);
        pushButton_2->setFont(font);
        plainTextEdit_2 = new QPlainTextEdit(Widget);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(20, 120, 441, 51));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 0, 241, 51));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label_3->setPalette(palette5);
        QFont font2;
        font2.setFamily(QStringLiteral("Uroob"));
        font2.setPointSize(29);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        lineEdit_3 = new QLineEdit(Widget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 290, 141, 31));
        lineEdit_4 = new QLineEdit(Widget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(170, 290, 141, 31));
        lineEdit_5 = new QLineEdit(Widget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(320, 290, 141, 31));
        lineEdit_6 = new QLineEdit(Widget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(140, 350, 191, 31));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 270, 131, 21));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label_4->setPalette(palette6);
        QFont font3;
        font3.setFamily(QStringLiteral("Uroob"));
        font3.setPointSize(17);
        font3.setBold(true);
        font3.setWeight(75);
        label_4->setFont(font3);
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(180, 270, 131, 21));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label_5->setPalette(palette7);
        label_5->setFont(font3);
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(330, 270, 131, 21));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label_6->setPalette(palette8);
        label_6->setFont(font3);
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(210, 320, 151, 41));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label_7->setPalette(palette9);
        QFont font4;
        font4.setFamily(QStringLiteral("Uroob"));
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        label_7->setFont(font4);
        dial = new QDial(Widget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(90, 340, 41, 51));
        QPalette palette10;
        QBrush brush16(QColor(58, 111, 76, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush16);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush16);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush16);
        dial->setPalette(palette10);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "Index Books", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "CeROBOT", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "CeSEARCH", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "Search", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "TEC File System", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "PART 1", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "PART 2", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "PART 3", Q_NULLPTR));
        label_7->setText(QApplication::translate("Widget", "BOOK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
