#ifndef STATISTICAL_H
#define STATISTICAL_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class statistical : public QWidget {
    Q_OBJECT

public:
    explicit statistical(QWidget *parent = nullptr) : QWidget(parent) {
        // Khởi tạo label và layout
        QLabel *label = new QLabel("Thống kê", this);
        label->setAlignment(Qt::AlignCenter);  // Căn giữa label

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(label);
        setLayout(layout);
    }
};

#endif // STATISTICAL_H
