#include <QApplication>         // Khởi tạo ứng dụng Qt
#include <QDateTime>            // Làm việc với ngày tháng
#include <algorithm>
#include <QStringList>          // Làm việc với các đối tượng QString
#include <QPalette>
#include <QPixmap>
#include <QFile>                // Làm việc với file
#include <QTextStream>          // Đọc ghi file

#include "widget.h"
#include "Product.h"
#include "Node.h"
#include "AVLTree.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
