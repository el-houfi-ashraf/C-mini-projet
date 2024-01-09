 #ifndef Widget_H
#define Widget_H


#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QFileInfo>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <menu1.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);

    }
    bool connOpen(){

        mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/ACHRAF/Downloads/P C++/Database/Database.db");

    if (!mydb.open()){
        qDebug() << "Failed to open the database";
        return false;}
    else{
        qDebug()<<"Conneted...";
        return true;}
}
    int sqlSize(QSqlQuery query)
    {
        int initialPos = query.at();
        // Very strange but for no records .at() returns -2
        int pos = 0;
        if (query.last())
            pos = query.at() + 1;
        else
            pos = 0;
        // Important to restore initial pos
        query.seek(initialPos);
        return pos;
    }

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // Widget_H
