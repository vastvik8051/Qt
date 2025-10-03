#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
using namespace std;

// ----------------- PASSWORD CLASS -----------------
class password
{
    string userID;
    string password;
    string encPass;
    string encData[55] = {"1","!","2","@","3","#","4","$","5","%","6","^","7","&","8","*","9","(",")","0","-","_","=","+","~","<",">","?","/","|","t","u","i","d","f","g","q","d","v","h","j","t","x","d","f","g","l","q","z","x","c","n","+","G","H"};
    string decData[55] = {"q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","j","k","l","z","x","c","v","b","n","m","Q","W","E","R","T","Y","U","I","O","P","A","S","D","F","G","H","J","K","L","Z","X","C","V","B","N","M","@","-","_"};
    const int MAX_size = sizeof(encData) / sizeof(encData[0]);

    public:

    void setUserID(const string& id)
        {
            userID = id;
        }

    void setPass(const string& pass)
        {
            password = pass;
        }
    void encryption()
        {
        encPass.clear(); // remove garbage

        for(char ch : password) // for searching
        {
            bool found = false;
            for(int i = 0; i < MAX_size; i++)
            {
                if(decData[i][0] == ch)
                {
                    encPass += encData[i]; // switchLetters
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                encPass += ch; // keep og
            }
        }
        };


    string getEncryptedPass()
    {
        return encPass;
    }
};
// --------------------------------------------------

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->LineEditUserID->setStyleSheet("background: black;"); // colour
    ui->LineEditPassword->setStyleSheet("background: black"); // colour

    //label color
    ui->LableEncrypted->setStyleSheet("color: green; background: black");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PushButtonEncrypt_clicked()
{
    password p;
    QString id = ui->LineEditUserID->text(); // reading input for id
    QString pass = ui->LineEditPassword->text();  // same for pass

    p.setUserID(id.toStdString());
    p.setPass(pass.toStdString());
    p.encryption();

    QString output = "UserID             ->>  " +id+ "\n"
                     "Password           ->>  " +pass+ "\n"
                     "Encrypted Password ->>  " +(QString::fromStdString(p.getEncryptedPass()));

    ui->LableEncrypted->setText(output);
    ui->LineEditUserID->clear();
    ui->LineEditPassword->clear();
}

