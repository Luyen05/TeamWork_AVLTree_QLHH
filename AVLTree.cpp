#include "AVLTree.h"

#include <QtGlobal> // Dùng hàm qABs()
#include <QDir>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QTableWidget>
#include <QMap>
#include "Node.h"

AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::~AVLTree() {
    delete_tree(root);
}

int AVLTree::height(){
    return root->height;
}

bool AVLTree::isAVLTree() {
    if (root == nullptr)
        return true;

    return root->isBalanced();
}

void AVLTree::delete_tree(Node* node) {
    if (node) {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}



// thêm một sản phẩm vào cây
void AVLTree::insert(const Product& p) {
    if (root == nullptr) {
        root = new Node(p);
    } else {
        root = root->insert_node(p);
    }
}

// Hàm xóa một node với id
void AVLTree::delete_node(int id) {
    if (root != nullptr) {
        root = root->delete_node(id);
    }
}

// Kiểm tra cây rỗng
bool AVLTree::is_empty() const {
    return root == nullptr;
}

// Sắp xếp cây theo thứ tự tăng dần và hiển thị lên QTableWidget
void AVLTree::sort_ascending(QTableWidget* table) {
    if (root) {
        root->lnr_trav(table);
    }
}

void AVLTree::sort_decending(QTableWidget* table) {
    if (root) {
        root->rnl_trav(table);
    }
}

// nhập dữ liệu từ file vào cây
void AVLTree::input_from_file(const QString& filename) {
    // QFile file("G:\\My Drive\\Data Structure & Algorithms\\BTN_BST\\data.txt");  // Mở file

    QString fullPath = QDir::currentPath()
        , file_path;

    int index = fullPath.indexOf("build");

    if (index != -1) {
        file_path = fullPath.left(index);
    }

    file_path += filename;
    qDebug() << "Duong dan file: " << file_path;
    QFile file(file_path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening file:" << filename << "Error:" << file.errorString();
        emit file_is_not_open();  // Gửi đi 1 signal nếu file không được mở thành công
        return;
    }

    QTextStream in(&file);  // Tạo một QTextStream để đọc file

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList data = line.split(',');  // Đọc từng dòng của file, tách thành string list bằng dấu ','

        // Thêm sản phẩm vào cây
        this->insert(Product(data[0].toInt(), data[1], data[2].toInt(), data[3].toInt(), data[4],
                             data[5], QDate::fromString(data[6], "dd/MM/yyyy"), QDate::fromString(data[7], "dd/MM/yyyy")));
    }

    file.close();  // Đóng file sau khi đọc xong
}
void AVLTree::count_product_types() {
    QMap<QString, int> type_mp;
    if (root != nullptr){
        root->nrl_trav([&type_mp](Node* node) {
            if (node) {
                type_mp[node->data.category]++;
            }
        });
    }

    emit type_count(type_mp);  // Gửi thống kê qua signal
}



