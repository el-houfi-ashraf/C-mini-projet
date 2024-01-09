#include "menu1.h"
#include "ui_menu1.h"
#include "Widget.h"
#include <QMessageBox>
#include <menu2.h>
#include <QPixmap>

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ACHRAF/Downloads/P C++/Plan.png");
    ui->label_Picture->setPixmap(pix);
    QIcon ajouterIcon("C:/Users/ACHRAF/Downloads/P C++/ajouter.png");
    QIcon modifierIcon("C:/Users/ACHRAF/Downloads/P C++/modifier.png");
    QIcon supprimerIcon("C:/Users/ACHRAF/Downloads/P C++/supprimer.png");
    QIcon afficherIcon("C:/Users/ACHRAF/Downloads/P C++/afficher.png");
    QIcon noteIcon("C:/Users/ACHRAF/Downloads/P C++/note.png");

    ui->pushButton->setIcon(noteIcon);
    ui->pushButton_ajouter->setIcon(ajouterIcon);
    ui->pushButton_ajouter_2->setIcon(ajouterIcon);
    ui->pushButton_ajouter_3->setIcon(ajouterIcon);
    ui->pushButton_modifier->setIcon(modifierIcon);
    ui->pushButton_modifier_2->setIcon(modifierIcon);
    ui->pushButton_modifier_3->setIcon(modifierIcon);
    ui->pushButton_supprimer->setIcon(supprimerIcon);
    ui->pushButton_supprimer_2->setIcon(supprimerIcon);
    ui->pushButton_supprimer_3->setIcon(supprimerIcon);
    ui->pushButton_afficher->setIcon(afficherIcon);
    ui->pushButton_afficher_2->setIcon(afficherIcon);
    ui->pushButton_afficher_3->setIcon(afficherIcon);
    Widget conn;
    if (!conn.connOpen())
        ui->label_menu->setText("Failed to open the database");
    else
        ui->label_menu->setText("Conneted...");

}

Menu::~Menu()
{
    delete ui;
}



void Menu::on_pushButton_ajouter_clicked()
{
    Widget conn;
    QString CNE = ui  -> texte_CNE -> text();
    QString Nom = ui  ->  texte_Nom-> text();
    QString Prenom = ui  ->  texte_prenom-> text();
    QDate DN = ui  ->  DN -> date();
    QString Birthday=DN.toString();

    if (!conn.connOpen()){
        qDebug() <<"Failed to open database";
        return;}

    conn.connOpen();
    QSqlQuery query;

    query.exec("create table Etudiant(CNE Varchar(20) primary key, "
               "Nom varchar(20), Prénom varchar(20),Date_de_naissance int)");
        query.prepare("insert into Etudiant values('"+CNE+"','"+Nom+"','"+Prenom+"','"+Birthday+"');");
    qDebug() << query.lastQuery();


    if (query.exec()){
        QMessageBox msgBox;
        msgBox.setText("L'étudiant a bien été engregistrer!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        conn.connClose();}

    else
        QMessageBox::critical(this,tr("EREUR"),tr("EREURR"));



}


//--------------------------------------------------------------------------
void Menu::on_pushButton_modifier_clicked()
{
    Widget conn;
    QString CNE = ui  -> texte_CNE -> text();
    QString Nom = ui  ->  texte_Nom-> text();
    QString Prenom = ui  ->  texte_prenom-> text();
    QDate DN = ui  ->  DN -> date();
    QString Birthday=DN.toString();

    if (!conn.connOpen()){
        qDebug() <<"Failed to open database";
        return;}

    conn.connOpen();
    QSqlQuery query;

    query.prepare("UPDATE Etudiant SET CNE ='"+CNE+"',Nom='"+Nom+"',Prénom='"+Prenom+"',Date_de_naissance='"+Birthday+"' WHERE CNE ='"+CNE+"';");
        qDebug() << query.lastQuery();


    if (query.exec()){
        QMessageBox msgBox;
        msgBox.setText("L'étudiant a bien été modifier!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        conn.connClose();}

    else
        QMessageBox::critical(this,tr("EREUR"),tr("EREURR"));


}
//-----------------------------------------------------------------
void Menu::on_pushButton_supprimer_clicked()
{
    Widget conn;
    QString CNE = ui  -> texte_CNE -> text();
    QString Nom = ui  ->  texte_Nom-> text();
    QString Prenom = ui  ->  texte_prenom-> text();
    QDate DN = ui  ->  DN -> date();
    QString Birthday=DN.toString();

    if (!conn.connOpen()){
        qDebug() <<"Failed to open database";
        return;}

    conn.connOpen();
    QSqlQuery query;
    query.prepare("DELETE FROM Etudiant WHERE CNE ='"+CNE+"';");
    qDebug() << query.lastQuery();


    if (query.exec()){
        QMessageBox msgBox;
        msgBox.setText("L'étudiant a bien été supprimer!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        conn.connClose();}

    else
        QMessageBox::critical(this,tr("ERREUR"),tr("ERREUR"));

}
//-------------------------------------------------------------
void Menu::on_pushButton_afficher_clicked()
{
    Widget conn;
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *query = new QSqlQuery(conn.mydb);
    query->prepare("SELECT * FROM Etudiant");
    query->exec();

    Modal->setQuery(*query);
    ui -> tableView->setModel(Modal);



}

//*******************************************************************

void Menu::on_pushButton_ajouter_2_clicked()
{
    Widget conn;
    QString CNI = ui  -> texte_CIN_2 -> text();
    QString Nom = ui  ->  texte_Nom_2-> text();
    QString Prenom = ui  ->  texte_prenom_2-> text();
    QString Telephone = ui  ->  texte_Telephone_2-> text();

    if (!conn.connOpen()){
        qDebug() <<"Failed to open database";
        return;}

    conn.connOpen();
    QSqlQuery query;
   // query.exec("create table Professeur(CNE int primary key, "
    //           "Nom varchar(20), Prénom varchar(20),Telephone int)");

    query.prepare("insert into Professeur values("+CNI+",'"+Nom+"','"+Prenom+"',"+Telephone+");");
    qDebug() << query.lastQuery();


    if (query.exec()){
        QMessageBox msgBox;
        msgBox.setText("Le professeur a bien été engregistrer!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        conn.connClose();}

    else
        QMessageBox::critical(this,tr("ERREUR"),tr("ERREURR"));
}

void Menu::on_pushButton_modifier_2_clicked()
{
    Widget conn;
    QString CNI = ui  -> texte_CIN_2 -> text();
    QString Nom = ui  ->  texte_Nom_2-> text();
    QString Prenom = ui  ->  texte_prenom_2-> text();
    QString Telephone = ui  ->  texte_Telephone_2-> text();

    if (!conn.connOpen()){
        qDebug() <<"Failed to open database";
        return;}

    conn.connOpen();
    QSqlQuery query;
    //query.exec("create table Student(CNE int primary key, "
    //       "Nom varchar(20), Prénom varchar(20),Date_de_naissance int)");

    //query.exec("SELECT CNE,Nom,Prénom,Date_de_naissance FROM Student WHERE CNE="+CNE+";");
    //qDebug() << query.lastQuery();
    query.prepare("UPDATE Professeur SET CNE ="+CNI+",Nom='"+Nom+"',Prénom='"+Prenom+"',Date_de_naissance="+Telephone+" WHERE CNE ="+CNI+";");
        qDebug() << query.lastQuery();


    if (query.exec()){
        QMessageBox msgBox;
        msgBox.setText("Le professeur a bien été modifier!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        conn.connClose();}

    else
        QMessageBox::critical(this,tr("ERREUR"),tr("ERREURR"));

}

void Menu::on_pushButton_supprimer_2_clicked()
{
    Widget conn;
    QString CNI = ui  -> texte_CIN_2 -> text();
    QString Nom = ui  ->  texte_Nom_2-> text();
    QString Prenom = ui  ->  texte_prenom_2-> text();
    QString Telephone = ui  ->  texte_Telephone_2-> text();

    if (!conn.connOpen()){
        qDebug() <<"Failed to open database";
        return;}

    conn.connOpen();
    QSqlQuery query;
    //query.exec("create table Student(CNE int primary key, "
    //       "Nom varchar(20), Prénom varchar(20),Date_de_naissance int)");

    //query.exec("SELECT CNE,Nom,Prénom,Date_de_naissance FROM Student WHERE CNE="+CNE+";");
    //qDebug() << query.lastQuery();
    query.prepare("DELETE FROM Professeur WHERE CNE ="+CNI+";");
    qDebug() << query.lastQuery();


    if (query.exec()){
        QMessageBox msgBox;
        msgBox.setText("le professeur a bien été supprimer!");
         msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        conn.connClose();}

    else
        QMessageBox::critical(this,tr("ERREUR"),tr("ERREURR"));

}

//-------------------------------------------------------------------------
void Menu::on_pushButton_afficher_2_clicked()
{
    Widget conn;
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *query = new QSqlQuery(conn.mydb);
    query->prepare("SELECT * FROM Professeur");
    query->exec();
    Modal->setQuery(*query);
    ui -> tableView->setModel(Modal);

}

//*****************************************************************************
void Menu::on_pushButton_ajouter_3_clicked()
{
    Widget conn;
    QString ID = ui  -> texte_ID -> text();
    QString Libelle = ui  ->  texte_Libelle-> text();
    QString Coeff = ui  ->  texte_Coeff-> text();
    QString CIN = ui  ->  texte_CIN_3-> text();

    if (!conn.connOpen()){
        qDebug() <<"Failed to open database";
        return;}

    conn.connOpen();
    QSqlQuery query;
    //query.exec("create table Matiere(CNE int primary key, "
    //           "Nom varchar(20), Prénom varchar(20),Date_de_naissance int)");

    query.prepare("insert into Matiere values("+ID+",'"+Libelle+"','"+Coeff+"','"+CIN+"');");
    qDebug() << query.lastQuery();


    if (query.exec()){
        QMessageBox msgBox;
        msgBox.setText("Matiere a bien été engregistrer!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        conn.connClose();}

}


void Menu::on_pushButton_modifier_3_clicked()
{
    Widget conn;
    QString ID = ui  -> texte_ID -> text();
    QString Libelle = ui  ->  texte_Libelle-> text();
    QString Coeff = ui  ->  texte_Coeff-> text();
    QString CIN = ui  ->  texte_CIN_3-> text();

    if (!conn.connOpen()){
        qDebug() <<"Failed to open database";
        return;}

    conn.connOpen();
    QSqlQuery query;
    //query.exec("create table Student(CNE int primary key, "
    //       "Nom varchar(20), Prénom varchar(20),Date_de_naissance int)");

    //query.exec("SELECT CNE,Nom,Prénom,Date_de_naissance FROM Student WHERE CNE="+CNE+";");
    //qDebug() << query.lastQuery();
    query.prepare("UPDATE Matiere SET Id_matiere ="+ID+",Libelle='"+Libelle+"',Coeff='"+Coeff+"',CIN="+CIN+" WHERE CNE ="+ID+";");
    qDebug() << query.lastQuery();


    if (query.exec()){
        QMessageBox msgBox;
        msgBox.setText("Matiere a bien été modifier!");
         msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        conn.connClose();}

    else
        QMessageBox::critical(this,tr("ERREUR"),tr("ERREURR"));
}

void Menu::on_pushButton_supprimer_3_clicked()
{
    Widget conn;
    QString ID = ui  -> texte_ID -> text();
    QString Libelle = ui  ->  texte_Libelle-> text();
    QString Coeff = ui  ->  texte_Coeff-> text();
    QString CIN = ui  ->  texte_CIN_3-> text();

    if (!conn.connOpen()){
        qDebug() <<"Failed to open database";
        return;}

    conn.connOpen();
    QSqlQuery query;
    //query.exec("create table Student(CNE int primary key, "
    //       "Nom varchar(20), Prénom varchar(20),Date_de_naissance int)");

    //query.exec("SELECT CNE,Nom,Prénom,Date_de_naissance FROM Student WHERE CNE="+CNE+";");
    //qDebug() << query.lastQuery();
    query.prepare("DELETE FROM Matiere WHERE Id_matiere ="+ID+";");
    qDebug() << query.lastQuery();


    if (query.exec()){
        QMessageBox msgBox;
        msgBox.setText("Matiere a bien été supprimer!");
         msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        conn.connClose();}

    else
        QMessageBox::critical(this,tr("ERREUR"),tr("ERREURR"));

}

void Menu::on_pushButton_afficher_3_clicked()
{
    Widget conn;
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *query = new QSqlQuery(conn.mydb);
    query->prepare("SELECT * FROM Matiere");
    query->exec();
    Modal->setQuery(*query);
    ui -> tableView->setModel(Modal);
}

void Menu::on_pushButton_clicked()
{
    Note_Abs NoteAbs ;
    NoteAbs.setModal(true);
    NoteAbs.exec();
}
