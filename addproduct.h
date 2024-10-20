#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QWidget>
#include "Product.h"

namespace Ui {
class AddProduct;
}

class AddProduct : public QWidget
{
    Q_OBJECT

public:
    explicit AddProduct(QWidget *parent = nullptr);
    ~AddProduct();

private slots:

    void on_addButton_clicked();

private:
    Ui::AddProduct *ui;

signals:
    void create_product(Product &product);
};

#endif // ADDPRODUCT_H
