#ifndef GOODSDELIVERY_H
#define GOODSDELIVERY_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QtDebug>
#include<QMessageBox>
namespace Ui {
class GoodsDelivery;
}

class GoodsDelivery : public QWidget
{
    Q_OBJECT

public:
    explicit GoodsDelivery(QWidget *parent = nullptr);
    ~GoodsDelivery();

private slots:
    void on_pushButton_OutputGoods_clicked();

    void on_pushButton_Exit_clicked();

private:
    Ui::GoodsDelivery *ui;
public:
    void InitComboBoxFunc();
};

#endif // GOODSDELIVERY_H
