#include "countDown.h"
#include "ui_CountDown.h"
#include "serialCommunication.h"
#include <QMessageBox>

#include <QTimer>

Countdown::Countdown(QWidget *parent, unsigned int remDur) :
   QDialog(parent), // Ändern Sie QWidget auf QDialog
  ui(new Ui::Countdown)
{
    //initialisiere Anzeige der Restdauer
    remainingDuration = remDur+1;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Countdown::showTimer);
    timer->start(1000);

    ui->setupUi(this);
    showTimer();

    connect(ui->Beenden, &QPushButton::clicked, this, &Countdown::stopWatering);  
}

void Countdown::stopWatering() {
    timer->stop(); // Stoppe den Timer
    SerialCom().sendData("90000");
    timer->stop();
    this->close();
}

void Countdown::showTimer() {
    remainingDuration--;
    QString data = "(";
    data.append(QString::number(remainingDuration/60));
    data.append(":");
    if(remainingDuration%60 < 10) {
        data.append("0");
    }
    data.append(QString::number(remainingDuration%60));
    data.append(")");

    //Beende die Bewässerung bei Ablauf der Bewässerungsdauer
    if(remainingDuration <= 0) {
        stopWatering();
    }

    //Update das label, welches den Timer darstellt
    ui->timerDisplay->setText(data);
}

Countdown::~Countdown() {
    delete ui;
    timer->stop();
}

