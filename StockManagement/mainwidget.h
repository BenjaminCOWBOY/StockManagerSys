#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
//操作数据库的头文件
#include<QSqlDatabase>
#include<QSql>
#include<QSqlError>
#include<QMessageBox>
#include<QtDebug>

#include<QTableWidget>
#include<QTableWidgetItem>
#include<QString>
#include<QSqlQuery>
#include"goodsdelivery.h"
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

    void TableWidgetListDataFunc();//表格控件格式初始化

    void InitTableWidgetFunc();//表格控件列宽度初始化



private slots:
    void on_pushButton_AddGoods_clicked();
    void on_pushButton_DeleteGoods_clicked();
    void on_pushButton_GoodsWareHousing_clicked();
    void on_pushButton_GoodsDelivery_clicked();
    void on_pushButton_LoadData_clicked();
    void on_pushButton_DataSummury_clicked();
    void on_pushButton_DataSearch_clicked();
};
#endif // MAINWIDGET_H
