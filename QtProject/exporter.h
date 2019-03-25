#ifndef EXPORTER_H
#define EXPORTER_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class exporter;
}

class exporter : public QDialog
{
    Q_OBJECT

public:
    explicit exporter(QWidget *parent = nullptr);
    ~exporter();

private:
    Ui::exporter *ui;
    QList<QString> listeFonctionExports;
    QStringListModel *model;
    QList<QString> listeStatsExport;

private slots :
    void annuler();
    void valider();
    void ajouterExportAListe();
    void viderListe();
};

#endif // EXPORTER_H
