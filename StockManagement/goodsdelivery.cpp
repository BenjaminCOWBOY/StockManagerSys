#include "goodsdelivery.h"
#include "ui_goodsdelivery.h"

GoodsDelivery::GoodsDelivery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoodsDelivery)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(),this->height());
    InitComboBoxFunc();
}

GoodsDelivery::~GoodsDelivery()
{
    delete ui;
}

void GoodsDelivery::on_pushButton_OutputGoods_clicked()
{
    //获取combo box控件里面的值
    QString StrCBId=ui->comboBox_id->currentText();

    //判断商品入库的数量是否为空
    if(ui->lineEdit_Amount->text().isEmpty())
    {
        QMessageBox::critical(this,"tips","商品入库数量不能为空");
        ui->lineEdit_Amount->setFocus();
        return;
    }


    //设计SQL查询语句条件
    QSqlQuery sqlquery;
    QString strid="StockId=";
    strid+=StrCBId;
    QString str=QString("select *from commoditydatatable where %1").arg(strid);
    sqlquery.exec(str);

    //获取数据表中的商品编号对应的数量
    QString strAmount;
    while(sqlquery.next())
    {
        strAmount=sqlquery.value(2).toString();
    }

    //将输入数量+数量表当中的数量
    int inputamount=ui->lineEdit_Amount->text().toInt();//用户输入数量
    int tableamount=strAmount.toUInt();//数据表里面的数量
    int sum=tableamount-inputamount;//实现相加

    QString strresult=QString::number(sum);

    //更新数据表中数量字段的值
    QString strdb=QString("update commoditydatatable set StockAmount=%1 where %2").arg(strresult).arg(strid);

    if(sqlquery.exec(strdb))
    {
        QMessageBox::information(this,"tips","恭喜你，商品出库成功");
    }
    else
    {
        QMessageBox::critical(this,"tips","商品出库失败");
    }


}

void GoodsDelivery::on_pushButton_Exit_clicked()
{
    close();
}

void GoodsDelivery::InitComboBoxFunc()
{
    int i=0;
    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT *FROM commoditydatatable");

    QString strId;
    while (sqlQuery.next()) {
        strId=sqlQuery.value(0).toString();
        ui->comboBox_id->insertItem(i,strId);
        i++;
    }
}

