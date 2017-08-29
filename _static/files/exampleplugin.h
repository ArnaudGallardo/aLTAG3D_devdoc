#ifndef EXAMPLEPLUGIN_H
#define EXAMPLEPLUGIN_H

#include <interfaces.h>

#include <QObject>
#include <QtPlugin>
#include <QStringList>
#include <QFileInfo>
#include <QByteArray>
#include <QCryptographicHash>
#include <QString>
#include <QDateTime>

class ExamplePlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "fr.cnrs.archeovision.aLTAG3d.PluginInterface" FILE "pluginsfilters.json")
    Q_INTERFACES(PluginInterface)

public:
    QString author() const override;
    QString version() const override;
    QString title() const override;
    QStringList exportableData() const override;
    QStringList formats() const override;
    QJsonObject extractData(const QString &filename, const QStringList &dataToExtract, QWidget *parent) override;
    QString fileDescription() const override;

private:
    QByteArray fileChecksum(const QString &filename,
                            QCryptographicHash::Algorithm hashAlgorithm)
    {
        //Permet de générer une empreinte pour un fichier (Attention aux gros fichiers)
        QFile f(filename);
        if (f.open(QFile::ReadOnly)) {
            QCryptographicHash hash(hashAlgorithm);
            if (hash.addData(&f)) {
                return hash.result().toHex();
            }
        }
        return QByteArray();
    }
};

#endif // EXAMPLEPLUGIN_H
