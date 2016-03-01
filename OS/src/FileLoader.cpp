#include "FileLoader.h"

#include <QTextStream>
#include <QFile>

QString readFiles( const QStringList& files )
{
    QString result;

    foreach (QString file, files)
    {
        QFile f(file);
        if (!f.open(QFile::ReadOnly | QFile::Text)) break;
        QTextStream in(&f);
        result.append( in.readAll() );
    }

    return result;
}


