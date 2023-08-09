#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString filePath;
    QString configLine;
    QString configKey;
    QString configValue;
    QString configDelimiter;
    QMap <QString, QString> configMap;
    int widthWindow;
    int heightWindow;
};
#endif // MAINWINDOW_H
