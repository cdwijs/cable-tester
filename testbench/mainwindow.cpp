#include "mainwindow.h"
#include "ui_mainwindow.h"

extern "C"
{
    #include "../unity/unity.h"
    #include "../../cable-tester/sampler-test.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    UNITY_BEGIN();
    RUN_TEST(samplerTest);
    int unityresult = UNITY_END();
}

MainWindow::~MainWindow()
{
    delete ui;
}

