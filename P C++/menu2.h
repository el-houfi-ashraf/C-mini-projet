#ifndef MENU2_H
#define MENU2_H

#include <QDialog>

namespace Ui {
class Note_Abs;
}

class Note_Abs : public QDialog
{
    Q_OBJECT

public:
    explicit Note_Abs(QWidget *parent = nullptr);
    ~Note_Abs();

private slots:


    void on_pushButton_ajouter_4_clicked();

    void on_pushButton_afficher_4_clicked();

    void on_pushButton_modifier_4_clicked();

    void on_pushButton_supprimer_4_clicked();

private:
    Ui::Note_Abs *ui;
};

#endif // MENU2_H
