#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:grey;");
    this->setCentralWidget(ui->textEdit);
    ui->textEdit->setStyleSheet("background-color:white;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    mFileName=="";
    ui->textEdit->setPlainText("");

}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionSave_triggered()
{
    QFile sFile(mFileName);
    if(mFileName=="")
    {
        QString file=QFileDialog::getSaveFileName(this,"Save a file");
        if(!file.isEmpty())
        {
            mFileName=file;
           on_actionSave_triggered();

        }

    }
    if(sFile.open((QFile::WriteOnly | QFile::Text)))
    {
        QTextStream out(&sFile);
        out<< ui->textEdit->toPlainText();
        sFile.flush();
        sFile.close();

    }


}
void MainWindow::on_actionSave_As_triggered()
{
    QString file=QFileDialog::getSaveFileName(this,"Save As a file");
    if(!file.isEmpty())
    {
        mFileName=file;
       on_actionSave_triggered();

    }


}

void MainWindow::on_actionOpen_triggered()
{
 QString file=QFileDialog::getOpenFileName(this,"Open a file");
 if(!file.isEmpty())
 {
     QFile sFile(file);
     if(sFile.open(QFile::ReadOnly|QFile::Text))
     {
         mFileName=file;
        QTextStream in(&sFile);
        QString txt=in.readAll();
        sFile.close();
        ui->textEdit->setPlainText(txt);


     }

 }
}



void MainWindow::on_actionCoppy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}



void MainWindow::on_actionAbout_triggered()
{

    About about;
    about.setModal(true);
    about.exec();
}
