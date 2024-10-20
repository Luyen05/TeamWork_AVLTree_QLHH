#include "widget.h"
#include "statistical.h"
#include "ui_widget.h"
#include "addproduct.h"
#include "AVLTree.h"
#include <QMessageBox>
#include <QFont>

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget), avltree()
{
    ui->setupUi(this);
    setupTable(); // Gọi hàm để thiết lập bảng;
    setupButton();

    connect(&avltree, &AVLTree::file_is_not_open, this, &Widget::error_read_file_message);
    // connect(&AddProduct, &AddProduct::create_product, this, &Widget::add_product);

    // Thêm một số nút vào cây AVL để bắt đầu
    // Giả sử avltree đã được khởi tạo đúng cách
    // avltree.insert(Product(1, "Hàng 1", 100, 10, "Loại A", "Nhà sản xuất A", QDate(2024, 10, 11), QDate(2025, 12, 31)));
    // avltree.insert(Product(2, "Hàng 2", 100, 10, "Loại B", "Nhà sản xuất B", QDate(2024, 10, 11), QDate(2025, 12, 31)));
    // avltree.insert(Product(3, "Hàng 3", 100, 10, "Loại C", "Nhà sản xuất C", QDate(2024, 10, 11), QDate(2025, 12, 31)));

    avltree.input_from_file("data.txt");


    qDebug() << "Chieu cao cua cay: " << avltree.height();

    if(avltree.isAVLTree())
        qDebug() << "Day la cay AVL";

    avltree.sort_ascending(ui->tableWidget);

    qDebug() << "Hang hien tai: " << ui->tableWidget->currentRow();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setupTable()
{
    ui->tableWidget->setColumnCount(8);

    // Định dạng font chữ cho tiêu đề
    QFont headerFont;
    headerFont.setBold(true);          // Đặt chữ in đậm
    headerFont.setPointSize(10);       // Đặt kích thước font

    //setTableBackground(ui->tableWidget, "D:\\New folder\\BaiTapNhom\\e0b3778b6438ca669329.jpg");

    // Tắt thanh trượt ngang
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Mỗi lần click sẽ chọn 1 dòng thay vì 1 ô riêng lẻ
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection); // Chọn 1 dòng tại 1 thời điểm

    // Tắt tiêu đề dọc mặc định của table (Đánh số dòng bên trái)
    ui->tableWidget->verticalHeader()->setVisible(false);

    // Áp dụng font cho tiêu đề
    ui->tableWidget->horizontalHeader()->setFont(headerFont);

    QStringList headers = {"ID", "Tên Hàng", "Giá", "Số Lượng", "Loại Hàng", "Nhà Cung Cấp", "Ngày Nhập Kho", "Hạn Sử Dụng"};

    //đặt tiêu đề cho các cột của bảng
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Tắt điều chỉnh kích thước cột tự động
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    // Đặt kích thước cột (width), ví dụ:
    ui->tableWidget->setColumnWidth(0, 95);   // ID
    ui->tableWidget->setColumnWidth(1, 200);  // Tên Hàng
    ui->tableWidget->setColumnWidth(2, 95);   // Giá
    ui->tableWidget->setColumnWidth(3, 95);   // Số Lượng
    ui->tableWidget->setColumnWidth(4, 100);  // Loại Hàng
    ui->tableWidget->setColumnWidth(5, 150);  // Nhà Cung Cấp
    ui->tableWidget->setColumnWidth(6, 125);  // Ngày Nhập Kho
    ui->tableWidget->setColumnWidth(7, 125);  // Hạn SD

    //ui->tableWidget->clearSelection();
}

void Widget::setupButton(){
    connect(ui->tableWidget->selectionModel(), &QItemSelectionModel::selectionChanged, this, [=](){
        bool hasSelection = ui->tableWidget->selectionModel()->hasSelection();
        ui->DelButton->setEnabled(hasSelection);
    });
}

void Widget::initAVLTree() {

}

void Widget::setTableBackground(QTableWidget* tableWidget, const QString& imagePath) {
    QPixmap background(imagePath);

    // Kiểm tra nếu QPixmap có nội dung
    if (background.isNull()) {
        qDebug() << "Image not loaded:" << imagePath;
        return; // Thoát nếu hình ảnh không được tải
    }

    // Thiết lập QPalette cho tableWidget
    QPalette palette = tableWidget->palette();
    palette.setBrush(QPalette::Window, background);
    tableWidget->setPalette(palette);
    tableWidget->setAutoFillBackground(true); // Đảm bảo tự động lấp đầy
}

void Widget::error_read_file_message(){
    QMessageBox::critical(this, "Lỗi đọc file", // Tiêu đề
                          "Không thể mở file. Vui lòng kiểm tra lại.", // Nội dung
                          QMessageBox::Ok); // Nút ok để đóng hộp thoại
    return;
}

void Widget::delButtonclicked()
{

}



void Widget::on_searchButton_clicked()
{

}


void Widget::on_comboBox_activated(int index)
{

}

void Widget::add_product(Product &product){
    avltree.insert(product);
    setupTable();
    updateTable();
}

void Widget::on_AddButton_clicked()
{
    AddProduct *addProductForm = new AddProduct();
    connect(addProductForm, &AddProduct::create_product, this, &Widget::add_product);
    addProductForm->show();
}



void Widget::updateTable(){
    // ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    avltree.sort_ascending(ui->tableWidget);
}

void Widget::on_DelButton_clicked()
{
    int currentRow = ui->tableWidget->currentRow(); // Lấy số dòng hiện tại
    int id = ui->tableWidget->item(currentRow, 0)->text().toInt();

    avltree.delete_node(id);
    updateTable();
}


void Widget::on_ThongKeBox_activated(int index)
{
    statistical types = statistical();
    switch(index) {
    case 0:


        break;
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    }
}

