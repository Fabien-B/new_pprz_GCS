#include "strip.h"
#include "ui_strip.h"
#include "pprz_dispatcher.h"
#include "ui_dispatcher.h"
#include <iostream>

using namespace std;

Strip::Strip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Strip)
{
    ui->setupUi(this);
    connect(UiDispatcher::get(), SIGNAL(ac_selected(int)), this, SLOT(changeColor(int)));
}

Strip::~Strip()
{
    delete ui;
}

void Strip::changeColor(int ac_id) {
    ui->ac_id_label->setText(QString::number(ac_id));
}
