#ifndef SKIN_H
#define SKIN_H

#include <QObject>
#include <QWidget>
#include <QLCDNumber>
#include <QtWidgets>

class Skin: public  QWidget
{
    Q_OBJECT
private:
    QLCDNumber* FirstPlayerScore;
    QLCDNumber* SecondPlayerScore;
    QRadioButton* B0;
    QRadioButton* B1;
    QRadioButton* B2;
    QRadioButton* A0;
    QRadioButton* A1;
    QRadioButton* A2;
    QPushButton* reset;
    QPushButton* turn;


    void F1();
    void F2();
    void S1();
    void S2();
    void win1();
    void win2();
    void a1();
    void a2();
    void a3();

public:
    Skin(QWidget* pwgt = 0);
public slots:
    void a0();
    void resetall();
};

#endif // SKIN_H
