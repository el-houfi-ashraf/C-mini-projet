#include "menu2.h"
#include "Widget.h"
#include <QMessageBox>
#include "ui_menu2.h"

Note_Abs::Note_Abs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Note_Abs)
{
    ui->setupUi(this);
    QIcon ajouterIcon("C:/Users/ACHRAF/Downloads/P C++/ajouter.png");
    QIcon modifierIcon("C:/Users/ACHRAF/Downloads/P C++/modifier.png");
    QIcon supprimerIcon("C:/Users/ACHRAF/Downloads/P C++/supprimer.png");
    QIcon afficherIcon("C:/Users/ACHRAF/Downloads/P C++/afficher.png");

    ui->pushButton_ajouter_4->setIcon(ajouterIcon);
    ui->pushButton_modifier_4->setIcon(modifierIcon);
    ui->pushButton_supprimer_4->setIcon(supprimerIcon);
    ui->pushButton_afficher_4->setIcon(afficherIcon);
}

Note_Abs::~Note_Abs()
{
    delete ui;
}

void Note_Abs::on_pushButton_ajouter_4_clicked()
{
    Widget conn;
    QString CNE = ui  -> texte_CNE_Note -> text();
    QString Id_matiere = ui  ->  texte_Id_Note-> text();
    QString Note = ui  ->  texte_Note-> text();
    if (!conn.connOpen()){
             qDebug() <<"Failed to open database";
             return;}

conn.connOpen();
QSqlQuery query;

query.exec("CREATE TABLE Evaluation (CNE VARCHAR(20)	NOT NULL , "
       "Id_matiere INTEGER  NOT NULL , Note INTEGER,PRIMARY KEY (CNE,Id_matiere));");
query.prepare("insert into Evaluation values('"+CNE+"',"+Id_matiere+","+Note+");");
qDebug() << query.lastQuery();


if (query.exec()){
    QMessageBox msgBox;
    msgBox.setText("La note a bien été engregistrer!");
     msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
    conn.connClose();}

else
    QMessageBox::critical(this,tr("ERREUR"),tr("ERREURR"));
}

void Note_Abs::on_pushButton_afficher_4_clicked()
{
    Widget conn;
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *query = new QSqlQuery(conn.mydb);
    query->prepare("SELECT * FROM Evaluation");
    query->exec();
    Modal->setQuery(*query);
    ui -> tableView->setModel(Modal);
}


void Note_Abs::on_pushButton_modifier_4_clicked()
{
    Widget conn;
    QString CNE = ui  -> texte_CNE_Note -> text();
    QString Id_matiere = ui  ->  texte_Id_Note-> text();
    QString Note = ui  ->  texte_Note-> text();
    if (!conn.connOpen()){
             qDebug() <<"Failed to open database";
             return;}

    if (!conn.connOpen()){
             qDebug() <<"Failed to open database";
             return;}

conn.connOpen();
QSqlQuery query;

query.prepare("UPDATE Evaluation SET CNE ='"+CNE+"',Id_matiere="+Id_matiere+",Note="+Note+" WHERE CNE ='"+CNE+"' AND Id_matiere="+Id_matiere+" ;");
qDebug() << query.lastQuery();


if (query.exec()){
    QMessageBox msgBox;
    msgBox.setText("La note a bien été modifier!");
     msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
    conn.connClose();}

else
    QMessageBox::critical(this,tr("ERREUR"),tr("ERREURR"));
}

void Note_Abs::on_pushButton_supprimer_4_clicked()
{
    Widget conn;
    QString CNE = ui  -> texte_CNE_Note -> text();
    QString Id_matiere = ui  ->  texte_Id_Note-> text();
    QString Note = ui  ->  texte_Note-> text();
    if (!conn.connOpen()){
             qDebug() <<"Failed to open database";
             return;}

conn.connOpen();
QSqlQuery query;



query.prepare("DELETE FROM Evaluation WHERE CNE ='"+CNE+"';");
qDebug() << query.lastQuery();


if (query.exec()){
    QMessageBox msgBox;
    msgBox.setText("La note a bien été supprimer!");
     msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
    conn.connClose();}

else
    QMessageBox::critical(this,tr("ERREUR"),tr("ERREURR"));
}
