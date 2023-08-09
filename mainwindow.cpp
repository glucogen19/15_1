#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>

#define WINDOW_WIDTH "windowwidth"
#define WINDOW_HEIGHT "windowheight"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Test QMap v15.1");
    filePath = "../test/config.ini";
    configDelimiter = "=";
    configMap.insert(WINDOW_WIDTH, "555");
    configMap.insert(WINDOW_HEIGHT, "333");
    QFile configFile(filePath);

    configFile.open(QFile::ReadOnly);
    while (!configFile.atEnd()) {
        configLine = configFile.readLine();
        int posDelimiter = configLine.indexOf(configDelimiter);
        configKey = configLine.right(configLine.size() - posDelimiter - 1);
        configValue = configLine.right(configLine.size() - posDelimiter - 1);
        qDebug() << "Config Line: " << configLine;
        qDebug() << "Config Key: " << configKey;
        qDebug() << "ConfigValue: " << configValue;
        if (configMap.count(configKey) > 0) {
            configMap[configKey] = configValue;
        }
    }
    qDebug() << "Config Map Width"  << configMap[WINDOW_WIDTH];
    qDebug() << "Config Map Height" << configMap[WINDOW_HEIGHT];
    widthWindow = configMap[WINDOW_WIDTH].toInt();
    heightWindow = configMap[WINDOW_HEIGHT].toInt();
    resize(widthWindow, heightWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

