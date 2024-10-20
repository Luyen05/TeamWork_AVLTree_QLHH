#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidget>

#include "AVLTree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void delButtonclicked();

    void error_read_file_message();

    void add_product(Product &product);

    void on_searchButton_clicked();

    void on_comboBox_activated(int index);

    void on_AddButton_clicked();

    void on_DelButton_clicked();

    void on_ThongKeBox_activated(int index);

private:
    Ui::Widget *ui;
    AVLTree avltree;

    void setupTable();
    void updateTable();
    void setupButton();
    void setTableBackground(QTableWidget* tableWidget, const QString& imagePath);
    void initAVLTree();
};
#endif // WIDGET_H
