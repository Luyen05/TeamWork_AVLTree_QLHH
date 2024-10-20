#include "statistical.h"
#include "ui_statistical.h"

statistical::statistical(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::statistical)
{
    ui->setupUi(this);
}

statistical::~statistical()
{
    delete ui;
}
