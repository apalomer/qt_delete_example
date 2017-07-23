#include "button.h"
#include "ui_button.h"

Button::Button(int n, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Button)
{
    ui->setupUi(this);
    ui->pushButton->setText("Remove button "+QString::number(n));
    addAction(ui->actionRemove);
}

Button::~Button()
{
    delete ui;
}

void Button::on_pushButton_clicked()
{
    emit remove(this);
}

void Button::on_actionRemove_triggered()
{
    emit remove(this);
}
