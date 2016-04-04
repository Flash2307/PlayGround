#include "UserProfilPage.h"

#include <QtCore>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QPalette>
#include <QPushButton>
#include <QLineEdit>

#include "FileLoader.h"

void applyTexture( QWidget* pWidget, const QString& texturePath )
{
    QPalette p;
    QPixmap bg( texturePath );
    p.setBrush(QPalette::Background, bg);
    pWidget->setAutoFillBackground(true);
    pWidget->setPalette(p);
}

UserProfilPage::UserProfilPage( size_t gamepadIndex ) :
    pUserNameLabel( nullptr ),
    unactivatedMessage( "Manette " + QString().setNum( gamepadIndex ) + " non activé"  ),
    activated( false ),
    ready( false )
{
    pUserNameLabel = new QLabel( unactivatedMessage );

    pConnectToProfilBtn = new QPushButton( "Connexion" );
    pConnectToProfilBtn->hide();
    QObject::connect( pConnectToProfilBtn, SIGNAL( clicked() ), this, SLOT( userConnect() ) );

    pUserNameEditor = new QLineEdit();
    pUserNameEditor->hide();

    QVBoxLayout* pVBox = new QVBoxLayout();
    pVBox->addWidget( pUserNameLabel );
    pVBox->addWidget( pUserNameEditor );
    pVBox->addWidget( pConnectToProfilBtn );
    pVBox->setAlignment( Qt::AlignTop );

    this->setLayout( pVBox );
    this->setStyleSheet( readFiles( QStringList() << "css/GameProfil.css" ) );
    applyTexture( this, "./img/ProfilPage.jpg" );
}

void UserProfilPage::updateUsenameText( bool increment )
{
    int cursoPosition = pUserNameEditor->cursorPosition();
    QString text = pUserNameEditor->text();

    if( text.size() == cursoPosition )
    {
        text.append( 'a' );
    }
    else
    {
        char value = text[ cursoPosition ].toLatin1();

        if( increment )
        {
            if( value + 1 > '9' && value < 'a' )
            {
                text[ cursoPosition ] = 'a';
            }
            else if( value + 1 > 'z' )
            {
               text[ cursoPosition ] = '0';
            }
            else
            {
                text[ cursoPosition ] = ++value;
            }
        }
        else
        {
            if(value  - 1 < '0')
            {
                text[ cursoPosition ] = 'z';
            }
            else if( value - 1 <  'a' && value > '9' )
            {
               text[ cursoPosition ] = '9';
            }
            else
            {
                text[ cursoPosition ] = --value;
            }
        }
    }

    pUserNameEditor->setText( text );
    pUserNameEditor->setCursorPosition( cursoPosition );
}

void UserProfilPage::process( GamePadMsgType message_ )
{
    bool newActivatedState = !isGamepadShutdown( message_ );
qDebug() << "uparrow" << message_.acc.other;
    if( activated != newActivatedState)
    {
        activated = newActivatedState;

        if( activated )
        {
            pUserNameLabel->setText( "Entrer votre nom d'utilisateur:" );
            pUserNameEditor->clear();
            pUserNameEditor->show();
            pConnectToProfilBtn->show();
        }
        else
        {
            pUserNameLabel->setText( unactivatedMessage );
            pUserNameEditor->hide();
            pUserNameEditor->clear();
            pConnectToProfilBtn->hide();
            ready = false;
        }
    }
    else if( isGamepadABtn( message_ ) )
    {
        if( connectUser() )
        {
            pConnectToProfilBtn->animateClick();
        }
    }
    else if( isGamepadLeftArrow( message_ ) )
    {
        pUserNameEditor->cursorBackward( false );
    }
    else if( isGamepadRigthArrow( message_ ) )
    {
        pUserNameEditor->cursorForward( false );
    }
    else if( isGamepadUpArrow( message_ ) )
    {
        updateUsenameText( true );
    }
    else if( isGamepadDownArrow( message_ ) )
    {
        updateUsenameText( false );
    }
    else if( isGamepadBBtn( message_ ) )
    {
        pUserNameEditor->backspace();
    }
}

bool UserProfilPage::connectUser()
{
    qDebug() << "Db call to connextuser";
    qDebug() << "Show user statistic?";
    return true;
}

void UserProfilPage::sendGameStatistic( const GameStatistic& statistic_ )
{
    qDebug() << "Send statistic for game " << statistic_.gameName;
}

void UserProfilPage::userConnect()
{
    this->ready = true;
    emit readyToPlay();
}

bool UserProfilPage::isReady() const
{
    return this->ready;
}

bool UserProfilPage::isActivated() const
{
    return this->activated;
}

QString UserProfilPage::getUsername() const
{
    return this->pUserNameEditor->text();
}

