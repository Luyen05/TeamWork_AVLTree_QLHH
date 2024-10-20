#ifndef AVLTREE_H
#define AVLTREE_H

#include <QObject>
#include <QMap>
#include <QTableWidget>
#include "Product.h"
#include "Node.h"

class AVLTree : public QObject
{
    Q_OBJECT

private:

    Node* root;

    void delete_tree(Node* node);

public:

    AVLTree();
    ~AVLTree();

    int height();
    bool isAVLTree();
    void insert(const Product& p);
    void delete_node(int id);
    bool is_empty() const;
    void sort_ascending(QTableWidget* table);
    void sort_decending(QTableWidget* table);
    void input_from_file(const QString& filename);
    void count_product_types();

signals:

    void file_is_not_open();
    void type_count(QMap<QString, int> mp);
};


#endif // AVLTREE_H
