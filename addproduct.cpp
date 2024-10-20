#include <QDate>
#include "Product.h"
#include "addproduct.h"
#include "ui_addproduct.h"

AddProduct::AddProduct(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddProduct)
{
    ui->setupUi(this);

    // Con trỏ trỏ vào LineEdit ID khi khởi tạo
    ui->id->setFocus();

    // Tắt chức năng mở full màn hình
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
}

AddProduct::~AddProduct()
{
    delete ui;
}

void AddProduct::on_addButton_clicked()
{
    Product newProduct = Product(ui->id->text().toInt(),
                                 ui->name->text(),
                                 ui->price->text().toInt(),
                                 ui->quantity->text().toInt(),
                                 ui->category->text(),
                                 ui->manufacturer->text(),
                                 QDate::currentDate(),
                                 ui->expDate->date());

    emit create_product(newProduct);
    this->close();
}

