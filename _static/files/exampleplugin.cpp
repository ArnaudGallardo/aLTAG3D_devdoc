#include "exampleplugin.h"

#include <QtWidgets>
#include <QMessageBox>

QString
ExamplePlugin::author() const
{
    //Auteur du plugin
    return QString("Archeovision");
}

QString
ExamplePlugin::version() const
{
    //Version du plugin
    return QString("v1.0");
}

QString
ExamplePlugin::title() const
{
    //Nom du plugin
    return QString("JPEG/JPG plugin example");
}

QStringList
ExamplePlugin::exportableData() const
{
    //La liste des données renvoyées par le plugin
    QStringList list;
    //Données "Fichier"
    list << tr("Chemin du fichier");
    list << tr("Créateur");
    list << tr("Date du fichier");
    list << tr("Format du fichier");
    list << tr("Empreinter ORI");
    //Données spécifique au JPEG
    //EXIF par exemple
    return list;
}

QStringList
ExamplePlugin::formats() const
{
    //Les formats que le plugin traite
    QStringList list;
    list << "jpg";
    list << "jpeg";
    return list;
}

QJsonObject
ExamplePlugin::extractData(const QString &filename, const QStringList &dataToExtract, QWidget *parent)
{
    QJsonObject object;
    QFileInfo fi = QFileInfo(filename);
    if (dataToExtract.contains("cheminFichier"))
    {
        object["cheminFichier"] = filename;
    }
    if (dataToExtract.contains("createur"))
    {
        object["createur"] = fi.owner();
    }
    if (dataToExtract.contains("formatFichier"))
    {
        //fi.completeSuffix().toUpper() en principe mais pas ici : "jpg" != "jpeg"
        object["formatFichier"] = "JPEG";
    }
    if (dataToExtract.contains("dateFichier"))
    {
        object["dateFichier"] = fi.created().toString();
    }
    if (dataToExtract.contains("empreinteOri"))
    {
        QString hash = QString("MD5@");
        QByteArray hashHex = fileChecksum(filename,QCryptographicHash::Md5);
        hash += QString::fromUtf8(hashHex);
        object["empreinteOri"] = hash;
    }
    //On retourne l'objet JSON
    return object;
}

QString
ExamplePlugin::fileDescription() const
{
    //"Un fichier <type> au format ..."
    return QString("image");
}
