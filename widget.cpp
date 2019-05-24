#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_serial(new QSerialPort(this))
{
    ui->setupUi(this);

    openSerialPort();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::openSerialPort()
{
    m_serial->setPortName("ttyUSB0");
    m_serial->setBaudRate(QSerialPort::Baud9600);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if(m_serial->open(QIODevice::ReadWrite)){
        qDebug() << "open success";
    }else{
        qDebug() << "open fail";
    }
}

void Widget::on_btnSend_clicked()
{
    m_serial->write("TEST");
}
