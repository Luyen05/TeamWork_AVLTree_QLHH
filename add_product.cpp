#include "add_product.h"
#include "ui_add_product.h"

add_product::add_product(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::add_product)
{
    ui->setupUi(this);
}

add_product::~add_product()
{
    delete ui;
}
