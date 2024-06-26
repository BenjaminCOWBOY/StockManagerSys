#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    ConnectMYSQLDBFunc();
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor("#b0ff1c"));
    this->setPalette(palette);

    //禁止最大化窗口
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);

    setGeometry(800, 500, 2000, 1000);
    //禁止用户拖拉窗口改变大小
    setFixedSize(this->width(),this->height());

    TableWidgetListDataFunc();

    InitTableWidgetFunc();
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

 //调用新增商品对话框
#include"addcommodity.h"
void MainWidget::on_pushButton_AddGoods_clicked()
{
    AddCommodity *adddlg=new AddCommodity();
    adddlg->show();
}

//删除商品
void MainWidget::on_pushButton_DeleteGoods_clicked()
{

}

//商品入库
#include"goodwarehousing.h"
void MainWidget::on_pushButton_GoodsWareHousing_clicked()
{
    GoodWarehousing *gwhdlg=new GoodWarehousing();
    gwhdlg->show();
}

//商品出库
void MainWidget::on_pushButton_GoodsDelivery_clicked()
{
    GoodsDelivery *gddlg=new GoodsDelivery();
    gddlg->show();
}

//导出数据
void MainWidget::on_pushButton_LoadData_clicked()
{

}

//数据汇总及备份
void MainWidget::on_pushButton_DataSummury_clicked()
{

}


void MainWidget::on_pushButton_DataSearch_clicked()
{

    //先清除表格控件数据
    ui->tableWidget_ListData->clear();


    QSqlQuery sqlquery;
    QString strid="StockId=";
    strid=strid+ui->lineEdit_GoodsNumble->text();


    QString str=QString("select *from commoditydatatable where %1").arg(strid);


    sqlquery.exec(str);


    int i=0;
    while (sqlquery.next()) {
        QString strId=sqlquery.value(0).toString();
        QString strName=sqlquery.value(1).toString();
        QString strAmount=sqlquery.value(2).toString();
        QString strUnitPrice=sqlquery.value(3).toString();
        QString strSupplier=sqlquery.value(4).toString();
        QString strDirector=sqlquery.value(5).toString();
        QString strWareHouseTime=sqlquery.value(6).toString();
        QString strDeliveryTime=sqlquery.value(7).toString();
        QString strRemarks=sqlquery.value(8).toString();


        //将字符串显示到表格控件当中
        ui->tableWidget_ListData->setItem(i,0,new QTableWidgetItem(strId));
        ui->tableWidget_ListData->setItem(i,1,new QTableWidgetItem(strName));
        ui->tableWidget_ListData->setItem(i,2,new QTableWidgetItem(strAmount));
        ui->tableWidget_ListData->setItem(i,3,new QTableWidgetItem(strUnitPrice));
        ui->tableWidget_ListData->setItem(i,4,new QTableWidgetItem(strSupplier));
        ui->tableWidget_ListData->setItem(i,5,new QTableWidgetItem(strDirector));
        ui->tableWidget_ListData->setItem(i,6,new QTableWidgetItem(strWareHouseTime));
        ui->tableWidget_ListData->setItem(i,7,new QTableWidgetItem(strDeliveryTime));
        ui->tableWidget_ListData->setItem(i,8,new QTableWidgetItem(strRemarks));
    }

}

void MainWidget::TableWidgetListDataFunc()
{
    //编号 名称 数量 单价 供应商家 负责人 入库时间 出库时间 备注
    //设置表格控件200行9列
    ui->tableWidget_ListData->setColumnCount(9);
    ui->tableWidget_ListData->setRowCount(200);

    //设置表格控件标题
    QStringList headers;
    headers << "编号" << "名称" << "数量" << "单价" << "供应商家" << "负责人" << "入库时间" << "出库时间" << "备注";
    ui->tableWidget_ListData->setHorizontalHeaderLabels(headers);
}

void MainWidget::InitTableWidgetFunc()//表格控件列宽度初始化
{
    ui->tableWidget_ListData->setColumnWidth(0,80);
    ui->tableWidget_ListData->setColumnWidth(1,150);
    ui->tableWidget_ListData->setColumnWidth(2,80);
    ui->tableWidget_ListData->setColumnWidth(3,80);
    ui->tableWidget_ListData->setColumnWidth(4,300);
    ui->tableWidget_ListData->setColumnWidth(5,80);
    ui->tableWidget_ListData->setColumnWidth(6,200);
    ui->tableWidget_ListData->setColumnWidth(7,200);
    ui->tableWidget_ListData->setColumnWidth(8,180);


    QSqlQuery sqlquery;
    sqlquery.exec("select *from commoditydatatable");


    int i=0;
    while (sqlquery.next()) {
        QString strId=sqlquery.value(0).toString();
        QString strName=sqlquery.value(1).toString();
        QString strAmount=sqlquery.value(2).toString();
        QString strUnitPrice=sqlquery.value(3).toString();
        QString strSupplier=sqlquery.value(4).toString();
        QString strDirector=sqlquery.value(5).toString();
        QString strWareHouseTime=sqlquery.value(6).toString();
        QString strDeliveryTime=sqlquery.value(7).toString();
        QString strRemarks=sqlquery.value(8).toString();


        //将字符串显示到表格控件当中
        ui->tableWidget_ListData->setItem(i,0,new QTableWidgetItem(strId));
        ui->tableWidget_ListData->setItem(i,1,new QTableWidgetItem(strName));
        ui->tableWidget_ListData->setItem(i,2,new QTableWidgetItem(strAmount));
        ui->tableWidget_ListData->setItem(i,3,new QTableWidgetItem(strUnitPrice));
        ui->tableWidget_ListData->setItem(i,4,new QTableWidgetItem(strSupplier));
        ui->tableWidget_ListData->setItem(i,5,new QTableWidgetItem(strDirector));
        ui->tableWidget_ListData->setItem(i,6,new QTableWidgetItem(strWareHouseTime));
        ui->tableWidget_ListData->setItem(i,7,new QTableWidgetItem(strDeliveryTime));
        ui->tableWidget_ListData->setItem(i,8,new QTableWidgetItem(strRemarks));
        i++;
    }
}


