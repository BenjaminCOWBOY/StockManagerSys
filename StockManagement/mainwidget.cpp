#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    ConnectMYSQLDBFunc();
}

MainWidget::~MainWidget()
{
    delete ui;
}

 void MainWidget::ConnectMYSQLDBFunc()//连接MySQL数据库
 {
     QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
     db.setHostName("127.0.0.1");//odbc数据源配置的ip一致
     db.setPort(3306);//mysql的端口号
     db.setDatabaseName("stockmangerDB");//ODBC数据源配置的名称
     db.setPassword("root");

     bool bok=db.open();
     if(!bok)
     {
         QMessageBox::critical(this,"提示","mysql数据库连接失败");
         return;
     }

 }
