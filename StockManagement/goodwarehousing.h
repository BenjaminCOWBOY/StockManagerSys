#ifndef GOODWAREHOUSING_H
#define GOODWAREHOUSING_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QtDebug>
#include<QMessageBox>
#pragma execution_character_set("utf-8");
namespace Ui {
class GoodWarehousing;
}

class GoodWarehousing : public QWidget
{
    Q_OBJECT

public:
    explicit GoodWarehousing(QWidget *parent = nullptr);
    ~GoodWarehousing();

private slots:
    void on_pushButton_InputGoods_clicked();

    void on_pushButton_Exit_clicked();

private:
    Ui::GoodWarehousing *ui;

public:
    void InitComboBoxFunc();
};

#endif // GOODWAREHOUSING_H
