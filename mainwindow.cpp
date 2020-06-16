#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coli.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QComboBox>
#include <QSqlQuery>
#include <QSqlError>
#include <connexion.h>
#include <QSpinBox>
#include "qcustomplot.cpp"
#include "qcustomplot.h"
#include"QSqlRecord"
#include"QSqlQuery"
#include <QMap>
#include <QVector>
#include <QString>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QGridLayout>
#include <QDesktopWidget>
#include <QDebug>
#include "smtp.h"
#include "statistique.h"
#include <QtCore>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QDateTime>
#include <QTimer>
#include "ui_statistique.h"
#include <QTextStream>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
#include "mailing.h"
#include "login.h"
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include "parkingcode.h"
#include "stat_no.h"
#include "abonnementcode.h"
#include "physique.h"
#include "client.h"
#include "moral.h"

int i=1;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{    ui->setupUi(this);



 login loginpage;
 loginpage.setModal(true);
 loginpage.exec();



  timer=new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
  timer->start();

   ui->tablecoli->setModel(tcmp.affichercoli());
   ui->tablecourrier->setModel(tccmp.affichercourrier());

   ui->tableView1->setModel(a.afficher());
   ui->comboBox_11->setModel(a.afficherI());
   ui->tableView->setModel(c.afficherI());



}

  //ui->checkBox_2->setChecked(true);
  //   ui->checkBox->setChecked(true);
   /* ui->comboBox->addItem("en cours");*/

MainWindow::~MainWindow(){
   delete ui
            ;}

void MainWindow::on_ajoutercoli_clicked()
{//      ui->le_poids->setText(ui->spinBox->cleanText());
         int reference=ui->le_idcoli->text().toInt();
        // QString nom=ui->le_nom->text();
         QString nom=ui->comboBox_3->currentText();
         QString idclientdest=ui->le_nom_2->text();
         QString poids=ui->spinBox->cleanText();
         QString nbpiece=ui->le_nbpiece->text();
         QString etat=ui->comboBox->currentText();
         QString paiement=ui->comboBox_2->currentText();
         QString montant=ui->le_montant->text();
         QString adresseexp=ui->le_adresse_exp_2->text();
         QString adressedest=ui->le_adresse_dest_2->text();
         coli c(reference,nom,idclientdest,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);

         qDebug() << idclientdest ;
           QMessageBox msg;
          if(c.ajoutercoli())
           {    ui->tablecoli->setModel(tcmp.affichercoli());
               msg.setText("Ajout avec succès");
               msg.exec();}
          if(ui->checkBox_2->isChecked())
           {
               QMessageBox::information(this,"Agent","Vous êtes un agent respensable sur les colis");
           }
           else
           {
               QMessageBox::information(this,"Agent","Vous n'êtes pas un agent respensable sur les colis");
           }
}

void MainWindow::on_lirecoli_clicked()
{  //  ui->le_poids->setText(ui->spinBox->cleanText());
   int reference=ui->le_idcoli->text().toInt();
     QString nom=ui->comboBox_3->currentText();
   // QString nom=ui->le_nom->text();
    QString idclientdest=ui->le_nom_2->text();
    QString poids=ui->spinBox->text();
    QString nbpiece=ui->le_nbpiece->text();
    QString etat=ui->comboBox->currentText();
    QString paiement=ui->comboBox_2->currentText();
    QString montant=ui->le_montant->text();
    QString adresseexp=ui->le_adresse_exp_2->text();
    QString adressedest=ui->le_adresse_dest_2->text();

      coli c(reference,nom,idclientdest,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);
        QMessageBox msg;
        if(c.affichercoli())
        {   ui->tablecoli->setModel(tcmp.affichercoli());
            msg.setText("Voilà la liste des colis");
            msg.exec(); }}

void MainWindow::on_modifiercoli_clicked()
{  //  ui->le_poids->setText(ui->spinBox->cleanText());
    int reference=ui->le_idcoli->text().toInt();
      QString nom=ui->comboBox_3->currentText();
   // QString nom=ui->le_nom->text();
    QString idclientdest=ui->le_nom_2->text();
    QString poids=ui->spinBox->text();
    QString nbpiece=ui->le_nbpiece->text();
    QString etat=ui->comboBox->currentText();
    QString paiement=ui->comboBox_2->currentText();
    QString montant=ui->le_montant->text();
    QString adresseexp=ui->le_adresse_exp_2->text();
    QString adressedest=ui->le_adresse_dest_2->text();
      coli c(reference,nom,idclientdest,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);
        QMessageBox msg;
        if(c.modifiercoli(reference))
        {
            ui->tablecoli->setModel(tcmp.affichercoli());
            msg.setText("Modification avec succès");
            msg.exec(); }}

void MainWindow::on_suppcoli_clicked()
{
   int verifsupp=0;
    //ui->le_poids->setText(ui->spinBox->cleanText());
   int reference=ui->le_idcoli->text().toInt();
   // QString nom=ui->le_nom->text();
    QString nom=ui->comboBox_3->currentText();
    QString idclientdest=ui->le_nom_2->text();
    QString poids=ui->spinBox->text();
    QString nbpiece=ui->le_nbpiece->text();
    QString etat=ui->comboBox->currentText();
    QString paiement=ui->comboBox_2->currentText();
    QString montant=ui->le_montant->text();
    QString adresseexp=ui->le_adresse_exp_2->text();
    QString adressedest=ui->le_adresse_dest_2->text();
      coli c(reference,nom,idclientdest,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);
        QMessageBox msg;
        qDebug()<<reference;

        if(reference!=0)
        {
        verifsupp= QMessageBox::question( this, "Confimation De la Suppression", "Voulez Vous Supprmier Cette Coli ?", QMessageBox::No | QMessageBox::Yes  );
        if(verifsupp==16384)
        {
            c.supprimercoli(reference);
            ui->tablecoli->setModel(tcmp.affichercoli());
            msg.setText("suppression avec succès");
            msg.exec();
            QMessageBox::information(this,"Information","Coli qui a la reference "+QString::number(reference)+" a ete Supprimer");
        }
        if(verifsupp==65536)
        {
        QMessageBox::information(this,"Information","La Suppression du Coli qui a la reference "+QString::number(reference)+" a ete annulee  ");
        }
        }
        if(reference==0)
        {
        QMessageBox::warning(this,"Information","Il faut double click sur tableau Pour Supprimer du Coli");
        }


}

void MainWindow::on_tricroisscoli_clicked()
{// ui->le_poids->setText(ui->spinBox->cleanText());
    int reference=ui->le_idcoli->text().toInt();
    // QString nom=ui->le_nom->text();
      QString nom=ui->comboBox_3->currentText();
     QString idclientdest=ui->le_nom_2->text();
     QString poids=ui->spinBox->text();
     QString nbpiece=ui->le_nbpiece->text();
     QString etat=ui->comboBox->currentText();
     QString paiement=ui->comboBox_2->currentText();
     QString montant=ui->le_montant->text();
     QString adresseexp=ui->le_adresse_exp_2->text();
     QString adressedest=ui->le_adresse_dest_2->text();
       coli c(reference,nom,idclientdest,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);
         QMessageBox msg;
        if(c.affichertriccoli())
        {
            ui->tablecoli->setModel(tcmp.affichertriccoli());
           // ui->tablelivraisontric->setModel(tmp.affichertric());
            msg.setText("Voilà la liste des coli avec tri croissant selon l'id");
            msg.exec(); }
}
void MainWindow::on_tridecroissantcoli_clicked()
{// ui->le_poids->setText(ui->spinBox->cleanText());
    int reference=ui->le_idcoli->text().toInt();
    // QString nom=ui->le_nom->text();
      QString nom=ui->comboBox_3->currentText();
     QString idclientdest=ui->le_nom_2->text();
   QString poids=ui->spinBox->text();
     QString nbpiece=ui->le_nbpiece->text();
     QString etat=ui->comboBox->currentText();
     QString paiement=ui->comboBox_2->currentText();
     QString montant=ui->le_montant->text();
     QString adresseexp=ui->le_adresse_exp_2->text();
     QString adressedest=ui->le_adresse_dest_2->text();
       coli c(reference,nom,idclientdest,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);
         QMessageBox msg;
         if(c.affichertridcoli())
         {
             ui->tablecoli->setModel(tcmp.affichertridcoli());
            // ui->tablelivraisontric->setModel(tmp.affichertric());
             msg.setText("Voilà la liste des coli avec tri decroissant selon l'id");
             msg.exec(); }}
void MainWindow::on_rechcoli_clicked()
{
    QString input =ui->le_idcolirech->text();
    qDebug()<< input;


            if(ui->comboBox_rechercheColi->currentText()=="reference")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_ref(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="nom")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_nom(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="id_client_dest")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_idclientdest(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="poids")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_poid(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="nbpieces")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_nbpiece(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="etat")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_etat(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="paiment")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_paiment(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="montant")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_montant(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="adresse_exp")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_adresseed(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }
            if(ui->comboBox_rechercheColi->currentText()=="adresse_dest")
            {
                    QSqlQueryModel *model =tcmp.recherchercoli_adressee(input);
                    ui->recherchecoliview->show();
                    ui->recherchecoliview->setModel(model);

            }













    /*
    int numserieRech = model->data(model->index(0, 0)).toInt();
    if(reference == numserieRech)
    {
        ui->recherchecoliview->show();
        ui->recherchecoliview->setModel(model);
    }
     else
    {
        QMessageBox::critical(0, qApp->tr("Recherche"),
            qApp->tr("Client non trouvé"), QMessageBox::Ok);
         ui->recherchecoliview->hide();
    }*/

}



/*void MainWindow::on_tablecoli_activated(const QModelIndex &index)
{    QString val=ui->tablecoli->model()->data(index).toString();
    QSqlQuery qry;
qry.prepare("select * from coli where reference='"+val+"' or poids='"+val+" nbpiece='"+val+"' or etat='"+val+"' or paiement='"+val+"' '");
        ui->comboBox_3->setCurrentText(qry.value(0).toString());
        ui->spinBox->setSuffix(qry.value(1).toString());
        ui->le_nbpiece->setText(qry.value(2).toString());
        ui->comboBox->setCurrentText(qry.value(3).toString());
        ui->comboBox_2->setCurrentText(qry.value(4).toString());
      //  {    QMessageBox::critical(this,tr("error::"),qry.lastError().text()); }
}*/

/*void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{*/
    /*int reference=ui->le_idcoli->text().toInt();

     QString nom=ui->le_nom->text();
     QString poids=ui->spinBox->text();
     QString nbpiece=ui->le_nbpiece->text();
     QString etat=ui->comboBox->currentText();
     QString paiement=ui->comboBox_2->currentText();
     QString montant=ui->le_montant->text();
     QString adresseexp=ui->le_adresse_exp_2->text();
     QString adressedest=ui->le_adresse_dest_2->text();
     coli c(reference,nom,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);*/
      /* QMessageBox msg;
       if(c.ajoutercoli())
       {   ui->tablecoli->setModel(tcmp.affichercoli());
           msg.setText("Ajout avec succès");
           msg.exec(); }*/
 /*   QString nom=ui->comboBox_3->currentText();
    QSqlQuery qry;*/

   // qry.prepare("insert into coli(reference,nom,poids,nbpiece,etat,paiement,montant,adressexp,adressedest") values ('"+reference+"','"+nom+"','"+poids+"','"+nbpiece+"','"+etat+"','"+paiement+"','"+montant+"','"+adressexp+"','"+adressedest+"'');
/* qry.prepare("select * from coli where name='"+nom+"'");

 if(qry.exec()){
         ui->le_idcoli->setText(qry.value(0).toString());
         ui->le_nom->setText(qry.value(1).toString());
         ui->spinBox->setSuffix(qry.value(2).toString());
         ui->le_nbpiece->setText(qry.value(3).toString());
         ui->comboBox->setCurrentText(qry.value(4).toString());
         ui->comboBox_2->setCurrentText(qry.value(5).toString());
         ui->le_montant->setText(qry.value(6).toString());
         ui->le_adresse_exp_2->setText(qry.value(7).toString());
         ui->le_adresse_dest_2->setText(qry.value(8).toString());

     }else
 {
     QMessageBox::critical(this,tr("error::"),qry.lastError().text());
 }

}*/

/*void MainWindow::on_label_linkActivated(const QString &link)
{
    int ref3=ui->le_idcoli->text().toInt();
   // QString nomc=ui->comboBox_3->currentText();
     QString nom=ui->le_nom->text();
     QString poids=ui->spinBox->text();
     QString nbpiece=ui->le_nbpiece->text();
     QString etat=ui->comboBox->currentText();
     QString paiement=ui->comboBox_2->currentText();
     QString montant=ui->le_montant->text();
     QString adresseexp=ui->le_adresse_exp_2->text();
     QString adressedest=ui->le_adresse_dest_2->text();
     coli c(ref3,nom,poids,nbpiece,etat,paiement,montant,adresseexp,adressedest);
        QMessageBox msg;
        if(c.supprimercoli(ref3))
        {

            ui->tablecoli->setModel(tcmp.affichercoli());
            msg.setText("suppression avec succès");
            msg.exec(); }
}
*/
void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{QMessageBox msg;
    QString val=ui->comboBox_3->currentText();
    QSqlQuery qry;
    qry.prepare("select * from coli where nom='"+val+"'");
    if(qry.exec())
    {while(qry.next())
       {  ui->le_idcoli->setText(qry.value(0).toString());
          //  ui->le_nom->setText(qry.value(1).toString());
            ui->comboBox_3->setCurrentText(qry.value(1).toString());
            ui->le_nom_2->setText(qry.value(2).toString());
            ui->spinBox->setPrefix(qry.value(3).toString());
            ui->le_nbpiece->setPrefix(qry.value(4).toString());
            ui->comboBox->setCurrentText(qry.value(5).toString());
            ui->comboBox_2->setCurrentText(qry.value(6).toString());
            ui->le_montant->setText(qry.value(7).toString());
            ui->le_adresse_exp_2->setText(qry.value(8).toString());
            ui->le_adresse_dest_2->setText(qry.value(9).toString());}
            msg.setText("");
  }
}
void MainWindow::on_tablecoli_activated(const QModelIndex &index)
{QMessageBox msg;
    QString val=ui->tablecoli->model()->data(index).toString(); //take the selected index in tablecoli in transform it to val
    qDebug()<< val;
    QSqlQuery qry;
    qry.prepare("select * from coli where reference='"+val+"' or nom='"+val+"' or poids='"+val+"' or nbpiece='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
           { ui->le_idcoli->setText(qry.value(0).toString());
            ui->comboBox_3->setCurrentText(qry.value(1).toString());
             ui->le_nom_2->setText(qry.value(2).toString());
            ui->spinBox->setPrefix(qry.value(3).toString());
            ui->le_nbpiece->setPrefix(qry.value(4).toString());
            ui->comboBox->setCurrentText(qry.value(5).toString());
            ui->comboBox_2->setCurrentText(qry.value(6).toString());
            ui->le_montant->setText(qry.value(7).toString());
            ui->le_adresse_exp_2->setText(qry.value(8).toString());
            ui->le_adresse_dest_2->setText(qry.value(9).toString());}
            msg.setText("");
        }else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}
/**************************************************************************courrier********************************************************************/
void MainWindow::on_pushButton_aj_courrier_clicked()
{
    //ui->le_nbpiecej->setText(ui->spinBox_2->cleanText());
    int ref3=ui->le_ref3->text().toInt();
    QString nbpiecej=ui->spinBox_2->text();
     QString nom3=ui->comboBox_6->currentText();
     QString idclientdest3=ui->le_nom3_2->text();
     QString etat3=ui->comboBox_4->currentText();
     QString paiement3=ui->comboBox_5->currentText();
     QString montant3=ui->le_montant3->text();
     QString adressee=ui->le_adressee->text();
     QString adressed=ui->le_adressed->text();
       courrier co(ref3,nbpiecej,nom3,idclientdest3,etat3,paiement3,montant3,adressee,adressed);
        QMessageBox msg;
      if(co.ajoutercourrier())
      {
          ui->tablecourrier->setModel(tccmp.affichercourrier());
          msg.setText("Ajout avec succès");
          msg.exec(); }
   /*   if(ui->checkBox->isChecked())
      {
          QMessageBox::information(this,"Agent","Vous êtes un agent respensable sur les courriers");
      }
      else
      {
          QMessageBox::information(this,"Agent","Vous n'êtes pas un agent respensable sur les courriers");
      }*/}


void MainWindow::on_pushButton_affich_courrier_clicked()
{
  //  ui->le_nbpiecej->setText(ui->spinBox_2->cleanText());
        int ref3=ui->le_ref3->text().toInt();
        QString nbpiecej=ui->spinBox_2->cleanText();
         QString nom3=ui->le_nom3->text();
          QString idclientdest3=ui->le_nom3_2->text();
         QString etat3=ui->comboBox_4->currentText();
         QString paiement3=ui->comboBox_5->currentText();
         QString montant3=ui->le_montant3->text();
         QString adressee=ui->le_adressed->text();
         QString adressed=ui->le_adressed->text();
           courrier co(ref3,nbpiecej,nom3,idclientdest3,etat3,paiement3,montant3,adressee,adressed);
            QMessageBox msg;
           if(co.affichercourrier())
           {   ui->tablecourrier->setModel(tccmp.affichercourrier());
               msg.setText("Voilà la liste des courriers");
               msg.exec(); }
}

void MainWindow::on_pbmodifiercourrier_clicked()
{

   // ui->le_nbpiecej->setText(ui->spinBox_2->cleanText());
        int ref3=ui->le_ref3->text().toInt();
        QString nbpiecej=ui->spinBox_2->text();
        QString nom3=ui->comboBox_6->currentText();
          QString idclientdest3=ui->le_nom3_2->text();
         QString etat3=ui->comboBox_4->currentText();
         QString paiement3=ui->comboBox_5->currentText();
         QString montant3=ui->le_montant3->text();
         QString adressee=ui->le_adressee->text();
         QString adressed=ui->le_adressed->text();
           courrier co(ref3,nbpiecej,nom3,idclientdest3,etat3,paiement3,montant3,adressee,adressed);
            QMessageBox msg;
qDebug()<<ref3;
qDebug()<<nbpiecej;
qDebug()<<nom3;
qDebug()<<idclientdest3;
qDebug()<<montant3;
            if(co.modifiercourrier(ref3))
            {
                ui->tablecourrier->setModel(tccmp.affichercourrier());
                msg.setText("Modification avec succès");
                msg.exec();
            }
}



void MainWindow::on_supprimercourrier_clicked()
{
    int verifsupp=0;
    //ui->le_nbpiecej->setText(ui->spinBox_2->cleanText());
    int ref3=ui->le_ref3->text().toInt();
    QString nbpiecej=ui->spinBox_2->cleanText();
     QString nom3=ui->le_nom3->text();
     QString idclientdest3=ui->le_nom3_2->text();
     QString etat3=ui->comboBox_4->currentText();
     QString paiement3=ui->comboBox_5->currentText();
     QString montant3=ui->le_montant3->text();
     QString adressee=ui->le_adressed->text();
     QString adressed=ui->le_adressed->text();
       courrier co(ref3,nbpiecej,nom3,idclientdest3,etat3,paiement3,montant3,adressee,adressed);
        QMessageBox msg;

        qDebug()<<ref3;

        if(ref3!=0)
        {
        verifsupp= QMessageBox::question( this, "Confimation De la Suppression", "Voulez Vous Supprmier Cette Courrier ?", QMessageBox::No | QMessageBox::Yes  );
        if(verifsupp==16384)
        {
            co.supprimercourrier(ref3);
            ui->tablecourrier->setModel(tccmp.affichercourrier());
            msg.setText("suppression avec succès");
            msg.exec();
            QMessageBox::information(this,"Information","Courrier qui a la reference "+QString::number(ref3)+" a ete Supprimer");
        }
        if(verifsupp==65536)
        {
        QMessageBox::information(this,"Information","La Suppression du Courrier qui a la reference "+QString::number(ref3)+" a ete annulee  ");
        }
        }
        if(ref3==0)
        {
        QMessageBox::warning(this,"Information","Il faut double click sur tableau Pour Supprimer du Courrier");
        }

}

void MainWindow::on_tricroissantcourrier_clicked()
{//ui->le_nbpiecej->setText(ui->spinBox_2->cleanText());
    int ref3=ui->le_ref3->text().toInt();
    QString nbpiecej=ui->spinBox_2->cleanText();
     QString nom3=ui->le_nom3->text();
      QString idclientdest3=ui->le_nom3_2->text();
     QString etat3=ui->comboBox_4->currentText();
     QString paiement3=ui->comboBox_5->currentText();
     QString montant3=ui->le_montant3->text();
     QString adressee=ui->le_adressed->text();
     QString adressed=ui->le_adressed->text();
       courrier co(ref3,nbpiecej,nom3,idclientdest3,etat3,paiement3,montant3,adressee,adressed);
        QMessageBox msg;
        if(co.affichertriccourrier())
        {
            ui->tablecourrier->setModel(tccmp.affichertriccourrier());
           // ui->tablelivraisontric->setModel(tmp.affichertric());
            msg.setText("Voilà la liste des coli avec tri croissant selon l'id");
            msg.exec(); }
}

void MainWindow::on_tridecroisscourrier_clicked()
{
    QMessageBox msg;
    ui->tablecourrier->setModel(tccmp.affichertridcourrier());
           // ui->tablelivraisontric->setModel(tmp.affichertric());
            msg.setText("Voilà la liste des coli avec tri croissant selon l'id");
            msg.exec();

}

 void MainWindow::on_comboBox_6_currentIndexChanged(const QString &arg1)
{
    QMessageBox msg;
        QString val=ui->comboBox_6->currentText();
        QSqlQuery qry;
        qry.prepare("select * from courrier where nom3='"+val+"'");
        if(qry.exec())
        {while(qry.next())
           {
            ui->le_nom3->setText(qry.value(3).toString());
            ui->comboBox_4->setCurrentText(qry.value(4).toString());
            ui->comboBox_5->setCurrentText(qry.value(5).toString());
            ui->le_montant3->setText(qry.value(6).toString());
            ui->le_adressee->setText(qry.value(7).toString());
            ui->le_adressed->setText(qry.value(8).toString());}
            msg.setText("");
      }
}

void MainWindow::on_tablecourrier_activated(const QModelIndex &index)
{

    QMessageBox msg;
        QString val=ui->tablecourrier->model()->data(index).toString(); //take the selected index in tablecoli in transform it to val
        qDebug()<< val;
        QSqlQuery qry;
        qry.prepare("select * from courrier where ref3='"+val+"' or nbpiecej='"+val+"' or nom3='"+val+"' or etat3='"+val+"'");
        if(qry.exec())
        {
            {while(qry.next())
               {
                ui->le_ref3->setText(qry.value(0).toString());
                ui->spinBox_2->setPrefix(qry.value(1).toString());
                ui->comboBox_6->setCurrentText(qry.value(2).toString());
                ui->le_nom3_2->setText(qry.value(3).toString());
                ui->comboBox_4->setCurrentText(qry.value(4).toString());
                ui->comboBox_5->setCurrentText(qry.value(5).toString());
                ui->le_montant3->setText(qry.value(6).toString());
                ui->le_adressee->setText(qry.value(7).toString());
                ui->le_adressed->setText(qry.value(8).toString());}
                msg.setText("");
          }

            }else
        {
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }
}
void MainWindow::on_pbrechcourrier_clicked()
{
    QString ref3 =ui->le_rechcourrier->text();
    qDebug()<< ref3;

    if(ui->comboBox_7->currentText()=="reference")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_ref(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="id_client_exp")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_nom(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="nbpiece")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_nbpiece(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="id_client_dest")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_idclientdest(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="etat")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_etat(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="montant")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_montant(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="adresse_exp")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_adresseed(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="adresse_dest")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_adressee(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }

    if(ui->comboBox_7->currentText()=="paiment")
    {
    QSqlQueryModel *model =tccmp.recherchercourrier_paiment(ref3);
    ui->rechercheviewcourrier->show();
    ui->rechercheviewcourrier->setModel(model);
    }





}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    int i=0;
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));
    QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    regen->setAntialiased(false);
    regen->setStackingGap(1);
    regen->setName("Moyen de paiement");
    regen->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    regen->setBrush(QColor(111, 9, 176));
    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 ;
    labels << "en especes " << "par carte" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 8);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0,20);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
     ui->customPlot->yAxis->setLabel("Nombre de courriers");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> regenData;
int stat100;
int stat500;

QString var1="en especes";
QString var2="par carte";

QSqlQuery query1("select count(*) from courrier where paiement3='"+var1+"'");
while (query1.next()) {

                        stat100 = query1.value(0).toInt();

QSqlQuery query2("select count(*) from courrier where paiement3 ='"+var2+"'  ");
while (query2.next()) {
                           stat500 = query2.value(0).toInt();

                             }
    regenData << stat100 << stat500  ;
    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
}

void MainWindow::on_ExporterColis_clicked()
{
    QTableView *table;
   table = ui->tablecoli;


   QString filters("CSV files (*.csv);;All files (*.*)");
   QString defaultFilter("CSV files (*.csv)");
   QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                      filters, &defaultFilter);
   QFile file(fileName);

   QAbstractItemModel *model =  table->model();
   if (file.open(QFile::WriteOnly | QFile::Truncate)) {
       QTextStream data(&file);
       QStringList strList;
       for (int i = 0; i < model->columnCount(); i++) {
           if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
               strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
           else
               strList.append("");
       }
       data << strList.join(";") << "\n";
       for (int i = 0; i < model->rowCount(); i++) {
           strList.clear();
           for (int j = 0; j < model->columnCount(); j++) {

               if (model->data(model->index(i, j)).toString().length() > 0)
                   strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
               else
                   strList.append("");
           }
           data << strList.join(";") + "\n";
       }
       file.close();
       QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
   }
}

void MainWindow::on_ExporterCourriers_clicked()
{

    QTableView *table;
   table = ui->tablecourrier;


   QString filters("CSV files (*.csv);;All files (*.*)");
   QString defaultFilter("CSV files (*.csv)");
   QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                      filters, &defaultFilter);
   QFile file(fileName);

   QAbstractItemModel *model =  table->model();
   if (file.open(QFile::WriteOnly | QFile::Truncate)) {
       QTextStream data(&file);
       QStringList strList;
       for (int i = 0; i < model->columnCount(); i++) {
           if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
               strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
           else
               strList.append("");   }
       data << strList.join(";") << "\n";
       for (int i = 0; i < model->rowCount(); i++) {
           strList.clear();
           for (int j = 0; j < model->columnCount(); j++) {

               if (model->data(model->index(i, j)).toString().length() > 0)
                   strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
               else
                   strList.append("");
           }
           data << strList.join(";") + "\n";
       }
       file.close();
       QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
   }
}

/*void MainWindow::on_SendEmail_clicked()
{

    QString email=ui->email->text();
    //QString email="insaf921999@gmail.com";
    QString nom=ui->name->text();
    QString prenom=ui->lastname->text();
    QString subject=ui->subject->text();
    QString msg=ui->msg->toPlainText();
    qDebug()<< email;
    Smtp* smtp=new Smtp("insaf.elinkichari@esprit.tn","181JFT2762","smtp.gmail.com");
                   connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("", email ,subject,""+nom+" "+prenom+" "+msg+" ");

     if((nom=="") || (prenom=="") || (email=="") || (subject=="") || (msg==""))
     {
         QMessageBox::warning( 0, tr( "Qt Simple SMTP" ), tr( "il Ya un champ Vide!\n\n" ) );
     }

     if((nom!="") && (prenom!="") && (email!="") && (subject!="") && (msg!=""))
     {
     QMessageBox::information( 0, tr( "Qt Simple SMTP" ), tr( "Message sent!\n\n" ) );
     }

}
*/


void MainWindow::on_pushButton_2_clicked()
{
//mailing secdialog;
//secdialog.setModal(true);
//secdialog.exec();
    secdialog =new mailing(this);
    secdialog->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    int id= ui->ID->text().toInt();
   QString nom= ui->NOM->text();
    QString prenom= ui->PRENOM->text();
    QString role= ui->comboBox_8->currentText();;
    QString dated= ui->dateEdit_3->text();


  Agent x2(id,nom,prenom,role,dated);


  bool test=x2.ajouter();
  if((ui->NOM->text()=="")||(ui->PRENOM->text()==""))
   qDebug()<< "test";
   qDebug()<< id;
      qDebug()<< nom;
         qDebug()<< prenom;
            qDebug()<< role;
               qDebug()<< dated;



   test=false ;
  if(test)
{

      ui->tableView1->setModel(x2.afficher());//refresh
      ui->comboBox_11->setModel(a.afficherI());
      i++;
QMessageBox::information(nullptr, QObject::tr("Ajouter un agent"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  /*else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un agent"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);*/
  ui->tableView1->setModel(x2.afficher());//refresh
  ui->comboBox_11->setModel(a.afficherI());
}

void MainWindow::on_pushButton_4_clicked()
{
    int id=ui->ID->text().toInt();
    QString nom=ui->NOM->text();
    QString prenom=ui->PRENOM->text();
    QString role= ui->comboBox_8->currentText();;
    QString dated = ui->dateEdit_3->text();


    Agent p;
    bool atout=p.modifier(id,nom,prenom,role,dated);
    if(atout)
    {ui->tableView1->setModel(a.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier un agent"),
                                 QObject::tr("agent modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un agent"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    ui->tableView1->setModel(a.afficher());
}

void MainWindow::on_pushButton_5_clicked()
{
    int id=ui->lineEdit_6->text().toInt();

    ui->tableView1->setModel(a.cherchera(id));
}

void MainWindow::on_pushButton_14_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
      QPrintDialog dlg(&printer, this);
      if (dlg.exec() == QDialog::Accepted)
      {
          // calculate the total width/height table would need without scaling
          const int rows = ui->tableView1->model()->rowCount();
          const int cols = ui->tableView1->model()->columnCount();
          double totalWidth = 0.0;
          for (int c = 0; c < cols; ++c)
          {
              totalWidth += ui->tableView1->columnWidth(c);
          }
          double totalHeight = 0.0;
          for (int r = 0; r < rows; ++r)
          {
              totalHeight += ui->tableView1->rowHeight(r);
          }


          // redirect table's painting on a pixmap
          QPixmap pixmap(totalWidth, totalHeight);
          QPainter::setRedirected(ui->tableView1->viewport(), &pixmap);
          QPaintEvent event(QRect(0, 0, totalWidth, totalHeight));
          QApplication::sendEvent(ui->tableView1->viewport(), &event);
          QPainter::restoreRedirected(ui->tableView1->viewport());

          // print scaled pixmap
          QPainter painter(&printer);
          painter.drawPixmap(printer.pageRect(), pixmap, pixmap.rect());

  }
}

void MainWindow::on_pushButton_13_clicked()
{
     ui->tableView1->setModel(a.afficher());
       ui->comboBox_11->setModel(a.afficherI());//refresh

}

void MainWindow::on_pushButton_8_clicked()
{
    int id = ui->lineEdit_8->text().toInt();
    bool test=a.supprimer(id);
    if(test)
    {ui->tableView1->setModel(a.afficher());//refresh
        ui->comboBox_11->setModel(a.afficherI());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Etudiant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_comboBox_11_currentIndexChanged(const QString &arg1)
{
    QString nom=ui->comboBox_11->currentText();
}

void MainWindow::on_pushButton_9_clicked()
{
    {

        QString nom = ui->comboBox_11->currentText();
       QString Enconge= ui->comboBox_9->currentText();;
        QString type= ui->comboBox_10->currentText();
        QString dated=ui->dateEdit->text();
        QString datef=ui->dateEdit_2->text();



      Conge x3(i,nom,Enconge,type,dated,datef);
      bool test=x3.ajouter();
      i++;

      if((test)&&(datef>dated))
    {

          ui->tableView->setModel(x3.afficherI());//refresh
          ui->comboBox->setModel(a.afficherI());
    QMessageBox::information(nullptr, QObject::tr("Ajouter un conge"),
                      QObject::tr("congé ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
     /* else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un conge"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);*/
      ui->tableView->setModel(x3.afficherI());//refresh
      ui->comboBox->setModel(a.afficherI());
        }


}

void MainWindow::on_pushButton_11_clicked()
{
    int id=ui->lineEdit->text().toInt();

    ui->tableView->setModel(c.cherchera(id));
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->tableView->setModel(c.afficherI());
      ui->comboBox_11->setModel(a.afficherI());//refresh


}

void MainWindow::on_pushButton_12_clicked()
{
    int id = ui->lineEdit_2->text().toInt();
    bool test=c.supprimerI(id);
    if(test)
    {
        ui->tableView->setModel(c.afficherI());//refresh

        QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Etudiant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_15_clicked()
{
    if (ui->radioButton->isChecked()){
    ui->tableView->setModel(c.triea(1));}
    else if(ui->radioButton_2->isChecked()){
        ui->tableView->setModel(c.triea(0));}
    else if(ui->radioButton_3->isChecked()){
        ui->tableView->setModel(c.triea(2));}

}



void MainWindow::on_pushButton_6_clicked()
{
    ui->tableView1->setModel(a.triea(0));
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->tableView1->setModel(a.triea(2));
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    qDebug()<<index;
    if(index==0)
    {
        ui->tablecoli->setModel(tcmp.affichercoli());
    }
    if(index==1)
    {
        ui->tablecourrier->setModel(tccmp.affichercourrier());
    }
    if(index==2)
    {

      //  ui->tableView->setModel(x3.afficherI());//refresh
    }
    if(index==3)
    {
       ui->tab_afficher_client->setModel(tmpparking.afficher());

       ui->lineEditcin->setStyleSheet("color: red;");
       ui->lineEditprenom->setStyleSheet("color: red;");
    }
    if(index==4)
    {
       ui->tab_afficher_client_2->setModel(tmpabonnement.afficher());
        //affichage Abonnement
    }
    if(index==8)
    {

        afficher_carte(ui->tableWidget_tri);
        ui->tabsolde->setModel(tmpsolde.afficher());//refresh
        ui->comboBox_CS->setModel(tmpclient.afficher_liste_client());

        QSqlQuery query;
        query.prepare("SELECT ID_CLIENT FROM CLIENT ");
        query.exec();
        while (query.next())
        {
            QString ID_CLIENT = QString::number(query.value(0).toInt());
            ui->comboBox_CS->addItem(ID_CLIENT);

        }
    }
}

void MainWindow::on_pushButton_17_clicked()
{
    int id = ui->lineEditcin->text().toInt();
    QString prenom= ui->lineEditnumtel->text();
    int nbrplace= ui->lineEditprenom->text().toInt();
    int nbretage= ui->comboBox_12->currentText().toInt();
  parkingCode r(id,prenom,nbrplace,nbretage);
  bool test=r.ajouter();
  if(test)
{ui->tab_afficher_client->setModel(tmpparking.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un parking"),
                  QObject::tr("parking ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un parking"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_19_clicked()
{
    int id = ui->lineEdit_5->text().toInt();
    bool test= tmpparking.supprimer(id);
    if(test)
    {ui->tab_afficher_client->setModel( tmpparking.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un parking"),
                    QObject::tr("parking supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un parking"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_18_clicked()
{
    int num = ui->lineEdit_3->text().toInt();
    int qt_produit = ui->lineEdit_4->text().toInt();

     bool test= tmpparking.modifier(num,qt_produit);
    if(test)
    {ui->tab_afficher_client->setModel( tmpparking.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr(" parking modifié"),
                    QObject::tr("PARKING modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modification parking"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_RP_clicked()
{
    int id = ui->lineEdit_RP->text().toInt();
       bool test=tmpparking.testerPark(id);
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("parking existe"),
                        QObject::tr("parking existe.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_afficher_RP->setModel( tmpparking.afficherid(id));//refresh

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("abonnement n'existe pas"),
                        QObject::tr("abonnement n'existe pas !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_NBP_clicked()
{
    parkingCode park;
        QSqlQueryModel* p=park.Tri();


          ui->tab_afficher_triNBP->setModel(p);
}

void MainWindow::on_pushButton_NBE_clicked()
{

          parkingCode park;
              QSqlQueryModel* p=park.Tri2();


                ui->tab_afficher_triNBE->setModel(p);
}



void MainWindow::on_pushButton_S_clicked()
{
    stat_no statparking;
    statparking.setModal(true);
    statparking.exec();
}

void MainWindow::on_pushButton_S_2_clicked()
{

    ui->tabWidget->setCurrentIndex(2);
  //  ui->tabWidget->setCurrentWidget(2);

}

void MainWindow::on_ajouter_abon_clicked()
{
        int id = ui->lineEditid_abon->text().toInt();
        QString nom= ui->lineEditnom_abon->text();
        QString prenom= ui->lineEditprenom_abon->text();
         int numplace = ui->lineEditprenom_2_abon->text().toInt();
        QDate datenaiss = ui->dateEdit_2_abon->date();
       QDate datedeb=ui->dateEdit_3_abon->date();
        QDate datefin=ui->dateEdit_4_abon->date();

      abonnementCode c(id,nom,prenom,numplace,datenaiss,datedeb,datefin);
      bool test=c.ajouter();
      if((test)&&(id))
    {
          ui->tab_afficher_client_2->setModel(tmpabonnement.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                      QObject::tr("client ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_midifer_abon_clicked()
{
    int num = ui->lineEditprenom_3_abon->text().toInt();
        int qt_produit = ui->lineEditid_6_abon->text().toInt();

         bool test= tmpabonnement.modifier(num,qt_produit);
        if(test)
        {ui->tab_afficher_client_2->setModel( tmpabonnement.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr(" abonnement modifié"),
                        QObject::tr("abonnement modifié.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("modification abonnement"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_supp_abon_clicked()
{
    int id = ui->lineEditid_2_abon->text().toInt();
         bool test= tmpabonnement.supprimer(id);
         if(test)
         {ui->tab_afficher_client_2->setModel( tmpabonnement.afficher());//refresh
             QMessageBox::information(nullptr, QObject::tr("Supprimer un abonnement"),
                         QObject::tr("abonnement supprimé.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_R_clicked()
{
    int id = ui->lineEdit_r_abon->text().toInt();
       bool test=tmpabonnement.tester(id);
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("abonnement existe"),
                        QObject::tr("abonnement existe.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_rechercher_abonnement->setModel( tmpabonnement.afficherID(id));//refresh

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("abonnement n'existe pas"),
                        QObject::tr("abonnement n'existe pas !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_ajouterPH_clicked()
{


    int id_client = ui->lineEdit_idp->text().toInt();
    int cin =ui->lineEdit_cin->text().toInt();
    QString nom = ui->lineEdit_nomph->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString date_naissance =ui->dateEdit_naiss->text();
    QString adresse = ui->lineEdit_ad ->text();
    QString email = ui->lineEdit_email->text();
    qDebug()<<id_client;
    qDebug()<<id_client;
    physique ph (cin,nom,prenom,date_naissance,adresse,email,id_client);
    QMessageBox msg;
     if(ph.ajouter_physique(id_client))
     {

         msg.setText("Ajout client physique avec succes");
         afficher_physique(ui->tableWidget_tri_2);
         //ui->tabphysique->setModel(tmpphysique.afficherPH());

          msg.exec();

     }
     else
     {

          msg.setText("Echec de l'ajout du client physique");
          msg.exec();

     }

}

void MainWindow::on_pushButton_modifierPH_clicked()
{
   int CIN = ui->lineEdit_cin->text().toInt();
   tmpphysique.setAdresse(ui->lineEdit_ad->text());
   tmpphysique.setEmail(ui->lineEdit_email->text());


   bool test=tmpphysique.modifier(CIN);
   qDebug()<<"modifierphysique";
   qDebug()<<test;
   if(test)
   {
      afficher_physique(ui->tableWidget_tri_2);
       QMessageBox::information(this, "PAS D'ERREUR", " adresse ou/et Email modifier");
   }
   else
   {
       QMessageBox::critical(this, " ERREUR ", "Adresse ou/ et Email non modifié ");
   }


}
void MainWindow::afficher_physique(QTableWidget *t)
{
    QSqlQuery qry;
    int i;
    int j=0;
    qry.exec("select * from PHYSIQUE");
    while(qry.next()){
        j++;
    }
    t->setRowCount(j);
    t->setColumnCount(6);
    t->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    t->setHorizontalHeaderLabels(QString(" CIN ; NOM ; PRENOM ; DATE_NAISSANCE ; ADRESSE ; EMAIL  ").split(" ; "));
    i=1;
    qry.exec("select* from  PHYSIQUE");
    while(qry.next())
    {
               t->setItem(i-1,0,new QTableWidgetItem(qry.value(0).toString()));
               t->setItem(i-1,1,new QTableWidgetItem(qry.value(1).toString()));
               t->setItem(i-1,2,new QTableWidgetItem(qry.value(2).toString()));
               t->setItem(i-1,3,new QTableWidgetItem(qry.value(3).toString()));
               t->setItem(i-1,4,new QTableWidgetItem(qry.value(4).toString()));
               t->setItem(i-1,5,new QTableWidgetItem(qry.value(5).toString()));
               //t->setItem(i-1,6,new QTableWidgetItem(qry.value(6).toString()));


    i++;
    }
}

void MainWindow::on_pb_supprimerPH_clicked()
{
    long CIN = ui->lineEdit_supPH->text().toInt();
    bool test=tmpphysique.supprimerPH(CIN);
    if(test)
    {

         afficher_physique(ui->tableWidget_tri_2);


        QMessageBox::information(nullptr, QObject::tr("Supprimer un client physique"),
                    QObject::tr("client physique supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client physique"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_lineEdit_rechercherPH_textChanged(const QString &arg1)
{
    QString str=ui->lineEdit_rechercherPH->text();

    // afficher_physique(ui->tableWidget_tri_2);
    ui->tabphysique->setModel(tmpphysique.rechercher(arg1));
}

void MainWindow::on_comboBox_typeclient_activated(const QString &arg1)
{
    if(arg1=="Client physique")
    {

      ui->tabWidget_3->setCurrentIndex(0);
    }
    else
    {
     ui->tabWidget_3->setCurrentIndex(1);
    }
}
void MainWindow::triClientPH_CIN()
{
    QSqlQuery query;
    while(ui->tableWidget_tri_2->rowCount()>0)
    ui->tableWidget_tri_2->removeRow(0);
    query.exec("SELECT * FROM PHYSIQUE order by CIN ASC ");
        int p = -1;
        while (query.next())
        {

            p++;
            ui->tableWidget_tri_2->insertRow(p);
            for (int j=0; j<50; j++)
            {
                QTableWidgetItem *item1 = new QTableWidgetItem(QString(query.value(j).toString()));
                this->ui->tableWidget_tri_2->setItem(p,j,item1);

             }
          }
    }

void MainWindow::trie_nom()

{
    QSqlQuery query;
    while(ui->tableWidget_tri_2->rowCount()>0)
    ui->tableWidget_tri_2->removeRow(0);
    query.exec("select * from PHYSIQUE order by NOM ASC ");
        int c = -1;
        while (query.next())
        {

            c++;
            ui->tableWidget_tri_2->insertRow(c);
            for (int j=0; j<30; j++)
            {
                QTableWidgetItem *item1 = new QTableWidgetItem(QString(query.value(j).toString()));
                this->ui->tableWidget_tri_2->setItem(c,j,item1);

             }
          }
      }
void MainWindow::on_comboBox_13_activated(const QString &arg1)
{
    if(arg1=="Tri par CIN")
    {
        triClientPH_CIN();

    }
    else
    {
         trie_nom();
    }

}

void MainWindow::on_pushButton_afficherPH_clicked()
{
    ui->tabphysique->setModel(tmpphysique.afficherPH());
}

void MainWindow::on_tabWidget_3_currentChanged(int index)
{
    if(index==0)
    {
    ui->tabphysique->setModel(tmpphysique.afficherPH());
    afficher_physique(ui->tableWidget_tri_2);
    }
    if(index==1)
    {
         ui->tabMoral->setModel(tmpmoral.afficherM());
        afficher_moral(ui->tableWidget_tri_3);
    }
    if(index==2)
    {

        //stat
    }
}

void MainWindow::afficher_moral(QTableWidget *t)
 {
        QSqlQuery qry;
        int i;
        int j=0;
        qry.exec("select * from MORAL");
        while(qry.next()){
            j++;
        }
        t->setRowCount(j);
        t->setColumnCount(4);
        t->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        t->setHorizontalHeaderLabels(QString("RIB ; MATRICULE ; NOM_ENTREPRISE ; ID_CLIENT").split(" ; "));
        i=1;
        qry.exec("select* from Moral");
        while(qry.next())
        {
                   t->setItem(i-1,0,new QTableWidgetItem(qry.value(0).toString()));
                   t->setItem(i-1,1,new QTableWidgetItem(qry.value(1).toString()));
                   t->setItem(i-1,2,new QTableWidgetItem(qry.value(2).toString()));
                   t->setItem(i-1,3,new QTableWidgetItem(qry.value(3).toString()));

        i++;
        }
}


void MainWindow::on_pushButton_ajouterM_clicked()
{
    int id_client = ui->lineEdit_idcc->text().toInt();
   int RIB=ui->lineEdit_RIB->text().toInt();
   int matricule=ui->lineEdit_matri->text().toInt();
   QString nom_entreprise=ui->lineEdit_nom->text();

   moral m (RIB, matricule ,nom_entreprise,id_client);
   QMessageBox msg;
    if(m.ajouter_moral(id_client))
    {
         afficher_moral(ui->tableWidget_tri_3);
         msg.setText("Ajout de client moral avec succes");
         msg.exec();

    }
    else
    {

         msg.setText("Echec de l'ajout de client moral");
         msg.exec();

    }

}

void MainWindow::on_pb_supprimerM_clicked()
{
    long RIB = ui->lineEdit_supM->text().toInt();
    bool test=tmpmoral.supprimer(RIB);
    if(test)
    {
        afficher_moral(ui->tableWidget_tri_3);
        ui->tabMoral->setModel(tmpmoral.afficherM());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une entreprise"),
                    QObject::tr("compte entreprise supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un compte solde"),
                    QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_AfficherListe_clicked()
{
    ui->tabMoral->setModel(tmpmoral.afficherM());
}

void MainWindow::on_lineEdit_recherC_textChanged(const QString &arg1)
{
    QString rib = ui->lineEdit_recherC->text();
    ui->tabMoral->setModel((tmpmoral.recherche(arg1)));
}

void MainWindow::on_pushButton_20_clicked()
{
    statistique stat;
    stat.setModal(true);
    stat.exec();

    /*statistique *s = new statistique();
    s->show();*/
}

void MainWindow::afficher_carte(QTableWidget *t)
 {
        QSqlQuery qry;
        int i;
        int j=0;
        qry.exec("select * from CARTESOLDE");
        while(qry.next()){
            j++;
        }
        t->setRowCount(j);
        t->setColumnCount(4);
        t->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        t->setHorizontalHeaderLabels(QString("ID_COMPTES ; MONTANT ; DATE_OUVERTURE ; ID_CLIENT").split(" ; "));
        i=1;
        qry.exec("select* from  CARTESOLDE");
        while(qry.next())
        {
                   t->setItem(i-1,0,new QTableWidgetItem(qry.value(0).toString()));
                   t->setItem(i-1,1,new QTableWidgetItem(qry.value(1).toString()));
                   t->setItem(i-1,2,new QTableWidgetItem(qry.value(2).toString()));
                   t->setItem(i-1,3,new QTableWidgetItem(qry.value(3).toString()));

        i++;
        }
}


void MainWindow::on_pushButton_ajouter_clicked()
{
    QDate date_ouverture = QDate::currentDate();

    int id_client = ui->comboBox_CS->currentText().toInt();
    int id_compteS=ui->lineEdit_id2->text().toInt();
    int montant=ui->lineEdit_montant->text().toInt();

    cartesolde C (id_compteS, montant, date_ouverture);
    QMessageBox msg;
    if(C.ajouter_solde(id_client))
    {

        afficher_carte(ui->tableWidget_tri);
         ui->tabsolde->setModel(tmpsolde.afficher());//refresh
        msg.setText("Ajouter avec succés");
        msg.exec();
    }
    else
    {
        msg.setText("Echec de l'ajout");
        msg.exec();
    }
}

void MainWindow::on_pushButton_modifier_clicked()
{
    tmpsolde.setID_compteS(ui->lineEdit_id2->text().toInt());
     tmpsolde.set_Montant(ui->lineEdit_montant->text().toInt());



    bool test=tmpsolde.modifier();
    if(test)
    {
         afficher_carte(ui->tableWidget_tri);
        ui->tabsolde->setModel(tmpsolde.afficher());//refresh
        QMessageBox::information(this, "PAS D'ERREUR", " montant modifier");
    }
    else
    {
        QMessageBox::critical(this, " ERREUR ", "montant non modifié ");
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int id_compteS = ui->lineEdit_idd->text().toInt();
    bool test=tmpsolde.supprimer(id_compteS);
    if(test)
    {
         afficher_carte(ui->tableWidget_tri);
        ui->tabsolde->setModel(tmpsolde.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un compte solde"),
                    QObject::tr("compte solde supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un compte solde"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_chercher_clicked()
{
    QString str=ui->lineEdit_chercher_2->text();
    ui->tabsolde->setModel(tmpsolde.rechercher(str));
}

void MainWindow::on_lineEdit_chercher_2_textChanged(const QString &arg1)
{
    QString str=ui->lineEdit_chercher_2->text();

    // afficher_physique(ui->tableWidget_tri_2);
    ui->tabsolde->setModel(tmpsolde.rechercher(str));
}

void MainWindow::on_tabWidget_5_currentChanged(int index)
{
    if(index==0)
    {
        afficher_carte(ui->tableWidget_tri);
        ui->tabsolde->setModel(tmpsolde.afficher());//refresh
        ui->comboBox_CS->setModel(tmpclient.afficher_liste_client());

        QSqlQuery query;
        query.prepare("SELECT ID_CLIENT FROM CLIENT ");
        query.exec();
        while (query.next())
        {
            QString ID_CLIENT = QString::number(query.value(0).toInt());
            ui->comboBox_CS->addItem(ID_CLIENT);

        }
    }

}

void MainWindow::trie_id()

{
    QSqlQuery query;
    while(ui->tableWidget_tri->rowCount()>0)
    ui->tableWidget_tri->removeRow(0);
    query.exec("select * from CARTESOLDE order by ID_COMPTES   ASC ");
        int c = -1;
        while (query.next())
        {

            c++;
            ui->tableWidget_tri->insertRow(c);
            for (int j=0; j<30; j++)
            {
                QTableWidgetItem *item1 = new QTableWidgetItem(QString(query.value(j).toString()));
                this->ui->tableWidget_tri->setItem(c,j,item1);

             }
          }
      }

void MainWindow::trie_montant()

{
    QSqlQuery query;
    while(ui->tableWidget_tri->rowCount()>0)
    ui->tableWidget_tri->removeRow(0);
    query.exec("select * from CARTESOLDE order by MONTANT   ASC ");
        int c = -1;
        while (query.next())
        {

            c++;
            ui->tableWidget_tri->insertRow(c);
            for (int j=0; j<30; j++)
            {
                QTableWidgetItem *item1 = new QTableWidgetItem(QString(query.value(j).toString()));
                this->ui->tableWidget_tri->setItem(c,j,item1);

             }
          }
      }



void MainWindow::on_comboBox_14_activated(const QString &arg1)
{
    if(arg1=="Tri par ID")
    {
        trie_id();

    }
    else
    {
         trie_montant();
    }
}

void MainWindow::on_sendBtn_abon_clicked()
{
    //QString email=ui->rcpt_abon->text();
    QString email="insaf921999@gmail.com";
   // QString nom=ui->fullname->text();
    //QString prenom=ui->lastname->text();
    QString subject=ui->subject_abon->text();
    QString msg=ui->msg_abon->toPlainText();
    qDebug()<< email;
    Smtp* smtp=new Smtp("insaf.elinkichari@esprit.tn","181JFT2762","smtp.gmail.com");
                   connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("", email ,subject," "+msg+" ");
     if((email=="") || (subject=="") || (msg==""))
     {
         QMessageBox::warning( 0, tr( "Qt Simple SMTP" ), tr( "il Ya un champ Vide!\n\n" ) );
     }
     if((email!="") && (subject!="") && (msg!=""))
     {
     QMessageBox::information( 0, tr( "Qt Simple SMTP" ), tr( "Message sent!\n\n" ) );
     }
}

void MainWindow::on_envoyer_email_bott_clicked()
{
    //QString email=ui->khra->text();
    QString email="insaf921999@gmail.com";
   // QString nom=ui->fullname->text();
    //QString prenom=ui->lastname->text();
    QString subject="information";
    QString msg=ui->cp->toPlainText();
    qDebug()<< email;
    Smtp* smtp=new Smtp("insaf.elinkichari@esprit.tn","181JFT2762","smtp.gmail.com");
                   connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("", email ,subject," "+msg+" ");
     if((email=="") || (subject=="") || (msg==""))
     {
         QMessageBox::warning( 0, tr( "Qt Simple SMTP" ), tr( "il Ya un champ Vide!\n\n" ) );
     }
     if((email!="") && (subject!="") && (msg!=""))
     {
     QMessageBox::information( 0, tr( "Qt Simple SMTP" ), tr( "Message sent!\n\n" ) );
     }
}

void MainWindow::on_pushButton_afficherCarte_clicked()
{
    afficher_carte(ui->tableWidget_tri);
    ui->tabsolde->setModel(tmpsolde.afficher());//refresh
    ui->comboBox_CS->setModel(tmpclient.afficher_liste_client());

    QSqlQuery query;
    query.prepare("SELECT ID_CLIENT FROM CLIENT ");
    query.exec();
    while (query.next())
    {
        QString ID_CLIENT = QString::number(query.value(0).toInt());
        ui->comboBox_CS->addItem(ID_CLIENT);

    }
}

void MainWindow::on_pushButton_modifier_M_clicked()
{


int idclient=ui->lineEdit_idcc->text().toInt();
tmpmoral.setRIB(ui->lineEdit_RIB->text().toInt());
tmpmoral.setMatricule(ui->lineEdit_matri->text().toInt());
tmpmoral.setNom_entreprise(ui->lineEdit_nom->text());
   QMessageBox msg;
bool test=tmpmoral.modifier(idclient);
   if(test)
   {
       afficher_moral(ui->tableWidget_tri_3);
       msg.setText("Modification Client moral avec succes");
       msg.exec();

   }
   else
   {

        msg.setText("Echec de l'Modifier de client moral");
        msg.exec();

   }


}
