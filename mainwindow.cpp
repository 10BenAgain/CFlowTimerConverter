#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "constants.h"
#include "timer.h"
#include "common.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::get_frame_rate() {
    int console = ui->comboBox_consoleSelect->currentIndex();
    double rate = 0;
    const double rates[] = { GBA_FPS, NDS_FPS, NEW3DS, OLD3DS, FPS60 };

    if (console >= 0 && console < sizeof(rates) / sizeof(rates[0])) {
        rate = rates[console];
    }
    return rate;
}

void MainWindow::on_pushButton_calculate_clicked()
{
    timer currentTimer(
        (unsigned int)ui->spinBox_EncounterAdv->value(),
        (unsigned int)ui->spinBox_IntroTimer->value(),
        get_frame_rate()
    );

    ui->spinBox_TotalAdvancesResult->setValue((int)currentTimer.get_ms_advances());
    ui->spinBox_TotalTimeResult->setValue((int)currentTimer.get_total_time());
}

void MainWindow::on_pushButton_calculate_adv2ms_clicked()
{
    int adv2ms_result = adv_to_ms(
        get_frame_rate(),
        ui->spinBox_Adv2MS_Input->value()
        );

    ui->spinBox_Adv2MS_Result->setValue(adv2ms_result);
}


void MainWindow::on_pushButton_calculate_ms2adv_clicked()
{
    int adv2ms_result = ms_to_adv(
        get_frame_rate(),
        ui->spinBox_MStoAdv_Input->value()
        );

    ui->spinBox_MStoAdv_Result->setValue(adv2ms_result);
}


void MainWindow::on_comboBox_consoleSelect_currentIndexChanged(int index)
{
    QString fr = QString::number(get_frame_rate());
    ui->lineEdit_fps_display->setText(fr);
}

