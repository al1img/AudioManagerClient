#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QtDBus>

using namespace am;

#define DBUS_SERVICE "org.genivi.audiomanager"
#define DBUS_PATH "/org/genivi/audiomanager/commandinterface"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mDBusConnection(QDBusConnection::sessionBus()),
    mCmdItf(DBUS_SERVICE, DBUS_PATH, mDBusConnection, this)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onPushButton()
{
    qDebug() << Q_FUNC_INFO;

    QDBusReply<short> result;

    QList<am_MainConnectionType_s> listConnections;

    result = mCmdItf.GetListMainConnections(listConnections);

    if (!result.isValid())
    {
        qDebug() << "DBus error:" << result.error().message();

        return;
    }

    qDebug() << "GetListMainConnections result:" << result.value() << "count:"
             << listConnections.size();

    QList<am_SinkType_s> listMainSinks;

    result = mCmdItf.GetListMainSinks(listMainSinks);

    if (!result.isValid())
    {
        qDebug() << "DBus error:" << result.error().message();

        return;
    }

    qDebug() << "GetListMainSinks result:" << result.value() << "count:"
             << listMainSinks.size();

    QList<am_SourceType_s> listMainSources;

    result = mCmdItf.GetListMainSources(listMainSources);

    if (!result.isValid())
    {
        qDebug() << "DBus error:" << result.error().message();

        return;
    }

    qDebug() << "GetListMainSources result:" << result.value() << "count:"
             << listMainSources.size();

    QList<am_SinkClass_s> listSinkClasses;

    result = mCmdItf.GetListSinkClasses(listSinkClasses);

    if (!result.isValid())
    {
        qDebug() << "DBus error:" << result.error().message();

        return;
    }

    showSinkClasses(listSinkClasses);

    qDebug() << "GetListSinkClasses result:" << result.value() << "count:"
             << listSinkClasses.size();

    QList<am_SourceClass_s> listSourceClasses;

    result = mCmdItf.GetListSourceClasses(listSourceClasses);

    if (!result.isValid())
    {
        qDebug() << "DBus error:" << result.error().message();

        return;
    }

    qDebug() << "GetListSourceClasses result:" << result.value() << "count:"
             << listSourceClasses.size();

    showSourceClasses(listSourceClasses);
}

void MainWindow::showSinkClasses(QList<am_SinkClass_s> &listSinkClasses)
{
    for(auto sinkClass : listSinkClasses)
    {
        qDebug() << "Id:" << sinkClass.sinkClassID
                 << "name:" << sinkClass.name.c_str();
    }
}

void MainWindow::showSourceClasses(QList<am_SourceClass_s> &listSourceClasses)
{
    for(auto sourceClass : listSourceClasses)
    {
        qDebug() << "Id:" << sourceClass.sourceClassID
                 << "name:" << sourceClass.name.c_str();
    }
}
