#include "Widget.h"
#include "menu1.h"
#include "ui_widget.h"
#include <QPixmap>

#include <QtSql>
#include <QDebug>
#include <QFileInfo>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ACHRAF/Downloads/P C++/Login.png");
    ui->label_Picture2->setPixmap(pix);
    if (!connOpen())
        ui->label->setText("Failed to open the database");
    else
        ui->label->setText("Conneted...");


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString username = ui  -> lineEdit_Username -> text();
    QString password = ui  ->  lineEdit_Password -> text();

    if (!connOpen()){
        qDebug() <<"Failed to open database";
        return;}

    connOpen();
    QSqlQuery query;

    query.prepare("SELECT * FROM ADMIN WHERE Username = '"+username+"' AND Password = "+password );
    qDebug() << query.lastQuery();
    qDebug() << query.exec();


    if (sqlSize(query)!=0){
        qDebug() <<"LE MOT DE PASSE EST CORRECT";
        mydb.close();
        this->hide();
        Menu menu;
        menu.setModal(true);
        menu.exec();}
    else
        ui->label_Login->setText("Nom d'utilisateur ou mot de passe est incorect.");

}
