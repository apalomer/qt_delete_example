#include "button.h"
#include "ui_button.h"

Button::Button(int n, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Button)
{
    ui->setupUi(this);
    ui->pushButton->setText("Remove button "+QString::number(n));
    addAction(ui->actionRemove);
    connect(ui->actionRemove,SIGNAL(triggered()),this,SLOT(removeRequested()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(removeRequested()));
}

Button::~Button()
{
    delete ui;
}

void Button::removeRequested()
{
    emit remove(this);
}
