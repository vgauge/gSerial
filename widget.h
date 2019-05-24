#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void openSerialPort();

    void on_btnSend_clicked();

private:
    Ui::Widget *ui;

    QSerialPort *m_serial = nullptr;
};

#endif // WIDGET_H
