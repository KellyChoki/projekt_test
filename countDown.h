#ifndef COUNTDOWN_H
#define COUNTDOWN_H


#include <QDialog>
#include <QTimer>

namespace Ui {
class Countdown;
}

class Countdown : public QDialog { // Ändern Sie QWidget auf QDialog
    Q_OBJECT

public:
    explicit Countdown(QWidget *parent = nullptr, unsigned int remDur = 0);
    ~Countdown();
    void stopWatering();

private:
    Ui::Countdown *ui;
    unsigned int remainingDuration;
    QTimer *timer;
    void showTimer();
};

#endif // COUNTDOWN_H
