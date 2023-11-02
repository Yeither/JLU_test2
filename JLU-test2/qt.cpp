//
// Created by Administrator on 2023/10/14.
//

// You may need to build the project (run Qt uic code generator) to get "ui_qt.h" resolved

#include "qt.h"
#include "ui_qt.h"


qt::qt(QWidget *parent) :
        QWidget(parent), ui(new Ui::qt) {
    ui->setupUi(this);
}

qt::~qt() {
    delete ui;
}
