#include "GameSelection.h"

GameSelection::GameSelection() :
    scene(),
    view( &scene )
{
    scene.addText("Hello, world!");

    QObject::connect( &currentGame, SIGNAL( finished(int, QProcess::ExitStatus) ), this, SLOT( gameFinished(int, QProcess::ExitStatus) ) );
    QObject::connect( &currentGame, SIGNAL( readyReadStandardError() ), this, SLOT( readyReadStandardError() ) );
    QObject::connect( &currentGame, SIGNAL( readyReadStandardOutput() ), this, SLOT( readyReadStandardOutput() ) );
    QObject::connect( &currentGame, SIGNAL( started() ), this, SLOT( started() ) );
}

QWidget* GameSelection::getView()
{
    return &this->view;
}

void GameSelection::gameFinished(int exitCode, QProcess::ExitStatus exitStatus)
{

}

void GameSelection::readyReadStandardError()
{

}

void GameSelection::readyReadStandardOutput()
{

}

void GameSelection::started()
{

}

