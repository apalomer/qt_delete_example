#ifndef BUTTONSTACK_H
#define BUTTONSTACK_H

#include <QWidget>
#include "button.h"

namespace Ui {
class ButtonStack;
}

class ButtonStack : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonStack(QWidget *parent = 0);
    ~ButtonStack();

private slots:
    void on_addButton_clicked();
    void remove(Button* button);

private:
    Ui::ButtonStack *ui;
    int total_buttons;
};

#endif // BUTTONSTACK_H
