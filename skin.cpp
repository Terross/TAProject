#include "skin.h"

Skin::Skin(QWidget* pwgt): QWidget(pwgt)
{
    FirstPlayerScore = new QLCDNumber(1);
    SecondPlayerScore = new QLCDNumber(1);
    
    FirstPlayerScore ->setMinimumSize(150,50);
    SecondPlayerScore ->setMinimumSize(150, 50);

    QVBoxLayout* pvl = new QVBoxLayout;

    QGroupBox* firstPlayer = new QGroupBox("&Первый игрок");
    B0 = new QRadioButton("&Туз буби");
    B1 = new QRadioButton("&Туз пик");
    B2 = new QRadioButton("&Двойка пик");
    B0->setChecked(true);

    QGroupBox* secondPlayer = new QGroupBox("&Второй игрок");
    A0 = new QRadioButton("&Туз бубен");
    A1 = new QRadioButton("&Туз пик");
    A2 = new QRadioButton("&Двойка Буби");
    A0->setChecked(true);

    reset = new QPushButton("&Обнулить счет");
    turn = new QPushButton("&Ход");

    /*turn->setStyleSheet("border: 2px dashed #000;"
                        "background: #ff0000;"
                        "border-radius: 50px;"
                         );

    FirstPlayerScore->setStyleSheet("background: #800000;"
                                    "color: yellow");*/

    QHBoxLayout* sc = new QHBoxLayout;
    sc->addWidget(FirstPlayerScore);
    sc->addWidget(SecondPlayerScore);

    QHBoxLayout* hB = new QHBoxLayout;
    hB->addWidget(B0);
    hB->addWidget(B1);
    hB->addWidget(B2);
    firstPlayer->setLayout(hB);

    QHBoxLayout* hA = new QHBoxLayout;
    hA->addWidget(A0);
    hA->addWidget(A1);
    hA->addWidget(A2);

    secondPlayer->setLayout(hA);

    pvl->addLayout(sc);
    pvl->addWidget(secondPlayer);
    pvl->addWidget(firstPlayer);
    pvl->addWidget(turn);
    pvl->addWidget(reset);


    setLayout(pvl);
    connect(turn, SIGNAL(clicked()), SLOT(a0()));
    //connect(turn, SIGNAL(), SLOT(state0()));
    connect(reset, SIGNAL(clicked()), SLOT(resetall()));
}
void Skin::F1()
{
    FirstPlayerScore->display(FirstPlayerScore->intValue() +1);
    if(FirstPlayerScore->intValue()>=6)
        win1();
}
void Skin::F2()
{
    FirstPlayerScore->display(FirstPlayerScore->intValue() +2);
    if(FirstPlayerScore->intValue()>=6)
        win1();
}
void Skin::S1()
{
    SecondPlayerScore->display(SecondPlayerScore->intValue() +1);
    if(SecondPlayerScore->intValue()>=6)
        win2();
}
void Skin::S2()
{
    SecondPlayerScore->display(SecondPlayerScore->intValue() +2);
    if(SecondPlayerScore->intValue()>=6)
        win2();
}
void Skin::win1()
{
    QMessageBox * fwin = new QMessageBox(QMessageBox::Information,"Message Box","Первый игрок победил!", QMessageBox::Ok);
    fwin->open();
    //delete fwin;
    FirstPlayerScore->display(0);
    SecondPlayerScore->display(0);
}
void Skin::win2()
{
    QMessageBox * swin = new QMessageBox(QMessageBox::Information,"Message Box","Второй игрок победил!", QMessageBox::Ok);
    swin->open();
    //delete swin;
    FirstPlayerScore->display(0);
    SecondPlayerScore->display(0);
}
void Skin::a1()
{
    int secondChoice;
    if(A0->isChecked()) secondChoice = 0;
    if(A1->isChecked()) secondChoice = 1;
    if(A2->isChecked()) secondChoice = 2;
    switch (secondChoice) {
    case 0:
        F1();
        break;
    case 1:
        S1();
        break;
    case 2:
        F2();
        break;
    }
}
void Skin::a2()
{
    int secondChoice;
    if(A0->isChecked()) secondChoice = 0;
    if(A1->isChecked()) secondChoice = 1;
    if(A2->isChecked()) secondChoice = 2;
    switch (secondChoice) {
    case 0:
        S1();
        break;
    case 1:
        F1();
        break;
    case 2:
        S1();
        break;
    }

}
void Skin::a3()
{
    int secondChoice;
    if(A0->isChecked()) secondChoice = 0;
    if(A1->isChecked()) secondChoice = 1;
    if(A2->isChecked()) secondChoice = 2;
    switch (secondChoice) {
    case 0:
        S2();
        break;
    case 1:
        F1();
        break;
    case 2:
        S2();
        break;
    }
}
void Skin::a0()
{
    int firstChoice;
    if(B0->isChecked()) firstChoice = 0;
    if(B1->isChecked()) firstChoice = 1;
    if(B2->isChecked()) firstChoice = 2;


    switch (firstChoice) {
        case 0:
            a1();
        break;
        case 1:
            a2();
        break;
        case 2:
            a3();
        break;
    }
}

void Skin::resetall()
{
    FirstPlayerScore->display(0);
    SecondPlayerScore->display(0);
}
