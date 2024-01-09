#ifndef MENU1_H
#define MENU1_H

#include <QDialog>
#include <Widget.h>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:

    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:


    void on_pushButton_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_modifier_2_clicked();

    void on_pushButton_supprimer_2_clicked();

    void on_pushButton_afficher_2_clicked();

    void on_pushButton_ajouter_3_clicked();

    void on_pushButton_modifier_3_clicked();

    void on_pushButton_supprimer_3_clicked();

    void on_pushButton_afficher_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU1_H

