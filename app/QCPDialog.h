#ifndef QCPDIALOG_H
#define QCPDIALOG_H

#include "QCPDialog_global.h"

#include <QAbstractPrintDialog>

class QPrinter;
class QGridLayout;
class Tabs;
class Root;
class Preview;
class Controls;

struct _FrontendObj;
using FrontendObj = _FrontendObj;

struct _GMainLoop;
using GMainLoop = _GMainLoop;

struct _PrinterObj;
using PrinterObj = _PrinterObj;

using gpointer = void *;

class CPDSHARED_EXPORT QCPDialog : public QAbstractPrintDialog
{
    Q_OBJECT
public:
    QCPDialog(QPrinter *printer, QWidget *parent = Q_NULLPTR);
    void init_backend();
    void addPrinter(const char *printer);
    void clearPrinters();
    void addPrinterSupportedMedia(char *media) {}
    void clearPrintersSupportedMedia() {}
    void addMaximumPrintCopies(int copies) {}
    void addJobHoldUntil(char *startJobOption) {}
    void addPagesPerSize(char *pages) {}
    void updateAllOptions(const QString &printer);
    void parse_commands(gpointer user_data);
    QString information();
    int exec() override
    {
        return QDialog::exec();
    }

public Q_SLOTS:
    void tabBarIndexChanged(qint32 index);
    void swipeViewIndexChanged(qint32 index);
    void cancelButtonClicked();
    void newPrinterSelected(const QString &printer);
    void remotePrintersToggled(const QString &enabled);

private:
    FrontendObj *f;
    Tabs *tabs;
    Root *root;
    Preview *preview;
    Controls *controls;
    QGridLayout *masterLayout;
};

#endif // QCPDIALOG_H