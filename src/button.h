#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>

namespace Ui {
class Button;
}

class Button : public QWidget
{
    Q_OBJECT

public:
    explicit Button(int n, QWidget *parent = 0);
    ~Button();

private slots:
    void on_pushButton_clicked();
    void on_actionRemove_triggered();

signals:
    void remove(Button* button);
private:
    Ui::Button *ui;
};

#endif // BUTTON_H
