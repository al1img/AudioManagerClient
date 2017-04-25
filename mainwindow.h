#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "CommandInterfaceProxy.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QDBusConnection mDBusConnection;
    CommandInterface mCmdItf;

    void showSinkClasses(QList<am::am_SinkClass_s> &listSinkClasses);
    void showSourceClasses(QList<am::am_SourceClass_s> &listSourceClasses);

private slots:
    void onPushButton();
};

#endif // MAINWINDOW_H
