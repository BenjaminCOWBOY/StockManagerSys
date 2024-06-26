#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
//操作数据库的头文件
#include<QSqlDatabase>
#include<QSql>
#include<QSqlError>
#include<QMessageBox>
#include<QtDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;

public:
    void ConnectMYSQLDBFunc();//连接MySQL数据库

};
#endif // MAINWIDGET_H
