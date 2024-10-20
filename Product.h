#ifndef PRODUCT_H
#define PRODUCT_H


#include<QDateTime>

struct Product {
    int id;
    QString name;
    int price;
    int quantity;        // Số lượng có sẵn
    QString category;
    QString manufacturer;
    QDate createdAt;    // Ngày thêm
    QDate expDate;      // Ngày hết hạn


    // Truyền tham số bằng QLineEdit thông qua ->text()  (trả về QString)
    //                                         ->toInt() (chuyển chuỗi thành số nguyên)

    Product(int id, QString name, int price, int quantity, QString category, QString manufacturer, QDate createdat, QDate expdate){
        this->id = id;
        this->name = name;
        this->category = category;
        this->price = price;
        this->quantity = quantity;
        this->manufacturer = manufacturer;
        this->createdAt = createdat;
        this->expDate = expdate;
    }
};

#endif // PRODUCT_H
