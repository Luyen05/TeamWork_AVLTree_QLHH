#ifndef NODE_H
#define NODE_H

#include<QTableWidget>
#include<QMap>
#include<QString>
#include<functional>
#include "Product.h"
struct Node {
    Product data;
    Node* left;
    Node* right;
    int height;

    Node(const Product& p) : data(p), left(nullptr), right(nullptr), height(1) {}

    void update_height() {
        height = 1 + std::max((left ? left->height : 0), (right ? right->height : 0));
    }

    int balance_factor() const {
        return (left ? left->height : 0) - (right ? right->height : 0);
    }

    bool isBalanced() {
        int leftHeight = left ? left->height : 0;
        int rightHeight = right ? right->height : 0;

        if (qAbs(leftHeight - rightHeight) > 1)
            return false;

        bool leftBalanced = left ? left->isBalanced() : true;
        bool rightBalanced = right ? right->isBalanced() : true;

        return leftBalanced && rightBalanced;
    }

    Node* min_node() {
        Node* current = this;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* left_rotate() {
        Node* newRoot = this->right;
        this->right = newRoot->left;
        newRoot->left = this;

        this->update_height();
        newRoot->update_height();

        return newRoot;
    }

    Node* right_rotate() {
        Node* newRoot = this->left;
        this->left = newRoot->right;
        newRoot->right = this;

        this->update_height();
        newRoot->update_height();

        return newRoot;
    }

    Node* re_balance() {

        this->update_height();

        int balFactor = this->balance_factor();

        if (balFactor > 1 && left->balance_factor() >= 0) {
            return right_rotate();
        }

        if (balFactor < -1 && right->balance_factor() <= 0) {
            return left_rotate();
        }

        if (balFactor > 1 && left->balance_factor() < 0) {
            left = left->left_rotate();
            return right_rotate();
        }

        if (balFactor < -1 && (right->balance_factor() > 0)) {
            right = right->right_rotate();
            return left_rotate();
        }

        return this;
    }

    Node* insert_node(const Product& p) {
        if (p.id < this->data.id) {
            if (this->left == nullptr) {
                this->left = new Node(p);
            }

            else {
                this->left = this->left->insert_node(p);
            }
        }
        else if (p.id > this->data.id) {

            if (this->right == nullptr) {
                this->right = new Node(p);
            }

            else {
                this->right = this->right->insert_node(p);
            }
        }

        return this->re_balance();
    }

    Node* delete_node(int id) {
        if (id < this->data.id) {
            if (this->left != nullptr) {
                this->left = this->left->delete_node(id);
            }
        } else if (id > this->data.id) {
            if (this->right != nullptr) {
                this->right = this->right->delete_node(id);
            }
        } else {

            if (this->left == nullptr && this->right == nullptr) {
                delete this;
                return nullptr;
            }

            if (this->left == nullptr) {
                Node* temp = this->right;
                delete this;
                return temp;
            } else if (this->right == nullptr) {
                Node* temp = this->left;
                delete this;
                return temp;
            }

            Node* temp = this->right->min_node();
            this->data = temp->data;
            this->right = this->right->delete_node(temp->data.id);
        }

        return this->re_balance();
    }

    QStringList ToString(){
        QStringList liststring;
        liststring << QString::number(this->data.id) << this->data.name << QString::number(this->data.price)
               << QString::number(this->data.quantity) << this->data.category << this->data.manufacturer
               << this->data.createdAt.toString("dd/MM/yyyy") << this->data.expDate.toString("dd/MM/yyyy");
        return liststring;
    }

    //  QString::number Phương thức tạo QString từ số

    void lnr_trav(QTableWidget* table){
        if (this->left != nullptr)          // Duyệt cây con bên trái
            this->left->lnr_trav(table);

        int row = table->rowCount();    // Lấy số hàng hiện tại
        table->insertRow(row);          // Thêm hàng mới
        QStringList data = this->ToString(); // Chuyển Node thành QStringList
        table->setRowHeight(row, 22); // Cố định chiều cao của dòng
        for (int col = 0; col < data.size(); col++){
            table->setItem(row, col, new QTableWidgetItem(data[col])); // Đưa dữ liệu được tạo bởi QTableWidgetITem
        }                                                              // vào ô thứ col của dòng thứ row

        if (this->right != nullptr)         // Duyệt cây con bên phải
            this->right->lnr_trav(table);
    }

    void rnl_trav(QTableWidget* table){
        if (this->right != nullptr)
            this->right->rnl_trav(table);

        int row = table->rowCount();
        table->insertRow(row);
        QStringList data = this->ToString();
        table->setRowHeight(row, 22);
        for (int col = 0; col < data.size(); col++){
            table->setItem(row, col, new QTableWidgetItem(data[col]));
        }

        if (this->left != nullptr)
            this->left->rnl_trav(table);
    }

    QMap<QString, int> ThongKeTheoLoai(){
        QMap<QString, int> mp;

        return mp;
    }

    void nrl_trav(std::function<void(Node*)> func){
        func(this);
        if (this->left != nullptr)
            this->left->nrl_trav(func);
        if (this->right != nullptr)
            this->right->nrl_trav(func);
    }


};

#endif // NODE_H
