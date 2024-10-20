#ifndef ADD_PRODUCT_H
#define ADD_PRODUCT_H

#include <QWidget>

namespace Ui {
class add_product;
}

class add_product : public QWidget
{
    Q_OBJECT

public:
    explicit add_product(QWidget *parent = nullptr);
    ~add_product();

private:
    Ui::add_product *ui;
};

#endif // ADD_PRODUCT_H
