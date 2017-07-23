#include "buttonstack.h"
#include "ui_buttonstack.h"

ButtonStack::ButtonStack(QWidget *parent) :
    QWidget(parent),total_buttons(0),
    ui(new Ui::ButtonStack)
{
    ui->setupUi(this);
}

ButtonStack::~ButtonStack()
{
    delete ui;
}

void ButtonStack::on_addButton_clicked()
{
    Button* button(new Button(total_buttons++));
    ui->qvboxlayout->insertWidget(0,button);
    connect(button,SIGNAL(remove(Button*)),this,SLOT(remove(Button*)));
}

void ButtonStack::remove(Button* button)
{
    ui->qvboxlayout->removeWidget(button);
    delete button;
}
