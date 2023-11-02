//
// Created by Administrator on 2023/10/14.
//

#ifndef 启动_QT_H
#define 启动_QT_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class qt; }
QT_END_NAMESPACE

class qt : public QWidget {
    Q_OBJECT

public:
    explicit qt(QWidget *parent = nullptr);

    ~qt() override;

private:
    Ui::qt *ui;
};


#endif //启动_QT_H
