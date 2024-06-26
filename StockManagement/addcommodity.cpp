#include "addcommodity.h"
#include "ui_addcommodity.h"

AddCommodity::AddCommodity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddCommodity)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    setFixedSize(900,600);


    ui->lineEdit_Id->setFocus();//设置焦点
}

AddCommodity::~AddCommodity()
{
    delete ui;
}

void AddCommodity::on_pushButton_Exit_clicked()
{
    close();
}

void AddCommodity::on_pushButton_Add_clicked()
{
    QSqlQuery sqlResult;
    QString strId,strName,strAmount,strUnitPrice,strSupplier,strDirector,strInputTime,strOutputTime,strRemarks;

    strId=ui->lineEdit_Id->text();
    strName=ui->lineEdit_Name->text();
    strUnitPrice=ui->lineEdit_UnitPrice->text();
    strSupplier=ui->lineEdit_Supplier->text();
    strDirector=ui->lineEdit_Director->text();
    strAmount=ui->lineEdit_Amount->text();

    QDateTime datetime=QDateTime::currentDateTime();
    QString strnowinputtime=datetime.toString("yyyy-MM-dd HH:mm:ss");

    strInputTime=strnowinputtime;
    strOutputTime=strnowinputtime;


    strRemarks=ui->textEdit_Remarks->toPlainText();

    if(ui->lineEdit_Id->text().isEmpty()){

        QMessageBox::critical(this,"tips","新增商品编号不能为空，请重新输入");
        ui->lineEdit_Id->setFocus();
        return;
    }

    QString sqlquery=QString("insert into commoditydatatable(Stockid,StockName,StockAmount,StockUnitPrice,Supplier,Director,WareHousTime,DeliveryTime,Remarks) "
                             "value('%1','%2','%3','%4','%5','%6','%7','%8','%9')")
            .arg(strId).arg(strName).arg(strAmount).arg(strUnitPrice).arg(strSupplier).arg(strDirector).arg(strInputTime).arg(strOutputTime).arg(strRemarks);

    if(sqlResult.exec(sqlquery)){
        QMessageBox::information(this,"Tips","恭喜你，商品记录插入成功");

    }
    else{
        QMessageBox::critical(this,"tips","插入失败");
        ui->lineEdit_Id->setFocus();
    }
}
