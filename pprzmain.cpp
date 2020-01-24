#include "pprzmain.h"
#include "ui_gcs.h"
#include <iostream>
#include "pprz_dispatcher.h"
#include "ui_dispatcher.h"

using namespace std;

PprzMain::PprzMain(int width, int height, QWidget* centralWidget, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui_Gcs)
{
    ui->setupUi(this, width, height, centralWidget);
    //connect(ui->pushButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    //connect(ui->select_btn, SIGNAL(clicked()), this, SLOT(select_ac()));
}

//void PprzMain::setupUi(int width, int height, QWidget* centralWidget) {
//    centralWidget->setParent(this);
//    ui->setupUi(this, width, height, centralWidget);
//}

PprzMain::~PprzMain()
{
    delete ui;
}


