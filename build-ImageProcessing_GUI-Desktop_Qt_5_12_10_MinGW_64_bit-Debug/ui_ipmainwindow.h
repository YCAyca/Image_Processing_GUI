/********************************************************************************
** Form generated from reading UI file 'ipmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IPMAINWINDOW_H
#define UI_IPMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IPmainwindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *rawIm;
    QLabel *processedIm;
    QScrollBar *sequence_iterator;
    QWidget *layoutWidget;
    QVBoxLayout *rgbgs;
    QRadioButton *RGB;
    QRadioButton *GS;
    QWidget *layoutWidget1;
    QVBoxLayout *apply_type;
    QRadioButton *apply_all;
    QRadioButton *apply_obo;
    QDoubleSpinBox *alpha;
    QTextEdit *textEdit;
    QPushButton *Apply;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QSpinBox *kernel_size;
    QDoubleSpinBox *std_dev;
    QTextEdit *textEdit_4;
    QSpinBox *kernel_size_2;
    QDoubleSpinBox *k;
    QGroupBox *sharpe_type;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *umandhb;
    QLabel *histogram;
    QLabel *histogram_2;
    QCheckBox *hist_eq;
    QTextEdit *textEdit_5;
    QGroupBox *sharpe_type_2;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *salt;
    QCheckBox *pepper;
    QCheckBox *gaussian2;
    QDoubleSpinBox *std_dev2;
    QDial *noise_quant;
    QCheckBox *upsampling;
    QCheckBox *downsampling;
    QTextEdit *textEdit_6;
    QGroupBox *sharpe_type_3;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *lap;
    QCheckBox *sobel;
    QCheckBox *scharr;
    QCheckBox *morpho;
    QSpinBox *edge_kernel;
    QTextEdit *textEdit_7;
    QSpinBox *morpho_kernel_size;
    QGroupBox *sharpe_type_4;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *erosion;
    QCheckBox *dilation;
    QCheckBox *open;
    QCheckBox *close;
    QGroupBox *blur_type;
    QVBoxLayout *verticalLayout;
    QCheckBox *gaussian;
    QCheckBox *median;
    QCheckBox *average;
    QPushButton *pushButton_4;
    QTextEdit *textEdit_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QSpinBox *beta;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *IPmainwindow)
    {
        if (IPmainwindow->objectName().isEmpty())
            IPmainwindow->setObjectName(QString::fromUtf8("IPmainwindow"));
        IPmainwindow->resize(1800, 1600);
        IPmainwindow->setMaximumSize(QSize(16777215, 16777215));
        centralwidget = new QWidget(IPmainwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 70, 121, 51));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 70, 121, 51));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(290, 70, 121, 51));
        rawIm = new QLabel(centralwidget);
        rawIm->setObjectName(QString::fromUtf8("rawIm"));
        rawIm->setGeometry(QRect(590, 20, 481, 481));
        rawIm->setTextFormat(Qt::AutoText);
        rawIm->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        rawIm->setWordWrap(false);
        rawIm->setMargin(10);
        processedIm = new QLabel(centralwidget);
        processedIm->setObjectName(QString::fromUtf8("processedIm"));
        processedIm->setGeometry(QRect(1170, 20, 481, 481));
        processedIm->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        sequence_iterator = new QScrollBar(centralwidget);
        sequence_iterator->setObjectName(QString::fromUtf8("sequence_iterator"));
        sequence_iterator->setGeometry(QRect(130, 30, 161, 21));
        sequence_iterator->setMaximum(5);
        sequence_iterator->setPageStep(1);
        sequence_iterator->setSliderPosition(0);
        sequence_iterator->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(300, 130, 90, 49));
        rgbgs = new QVBoxLayout(layoutWidget);
        rgbgs->setObjectName(QString::fromUtf8("rgbgs"));
        rgbgs->setContentsMargins(0, 0, 0, 0);
        RGB = new QRadioButton(layoutWidget);
        RGB->setObjectName(QString::fromUtf8("RGB"));

        rgbgs->addWidget(RGB);

        GS = new QRadioButton(layoutWidget);
        GS->setObjectName(QString::fromUtf8("GS"));
        GS->setChecked(true);

        rgbgs->addWidget(GS);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(150, 130, 127, 49));
        apply_type = new QVBoxLayout(layoutWidget1);
        apply_type->setObjectName(QString::fromUtf8("apply_type"));
        apply_type->setContentsMargins(0, 0, 0, 0);
        apply_all = new QRadioButton(layoutWidget1);
        apply_all->setObjectName(QString::fromUtf8("apply_all"));
        apply_all->setChecked(false);

        apply_type->addWidget(apply_all);

        apply_obo = new QRadioButton(layoutWidget1);
        apply_obo->setObjectName(QString::fromUtf8("apply_obo"));
        apply_obo->setChecked(true);

        apply_type->addWidget(apply_obo);

        alpha = new QDoubleSpinBox(centralwidget);
        alpha->setObjectName(QString::fromUtf8("alpha"));
        alpha->setGeometry(QRect(200, 190, 81, 31));
        alpha->setSingleStep(0.250000000000000);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 190, 281, 71));
        Apply = new QPushButton(centralwidget);
        Apply->setObjectName(QString::fromUtf8("Apply"));
        Apply->setGeometry(QRect(480, 820, 93, 28));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 270, 281, 71));
        textEdit_3 = new QTextEdit(centralwidget);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(10, 350, 281, 141));
        kernel_size = new QSpinBox(centralwidget);
        kernel_size->setObjectName(QString::fromUtf8("kernel_size"));
        kernel_size->setGeometry(QRect(190, 390, 42, 22));
        kernel_size->setMinimum(3);
        kernel_size->setMaximum(31);
        kernel_size->setValue(3);
        std_dev = new QDoubleSpinBox(centralwidget);
        std_dev->setObjectName(QString::fromUtf8("std_dev"));
        std_dev->setGeometry(QRect(190, 460, 62, 22));
        textEdit_4 = new QTextEdit(centralwidget);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(10, 500, 371, 121));
        kernel_size_2 = new QSpinBox(centralwidget);
        kernel_size_2->setObjectName(QString::fromUtf8("kernel_size_2"));
        kernel_size_2->setGeometry(QRect(280, 540, 42, 22));
        kernel_size_2->setMinimum(3);
        kernel_size_2->setMaximum(31);
        kernel_size_2->setSingleStep(2);
        kernel_size_2->setValue(3);
        k = new QDoubleSpinBox(centralwidget);
        k->setObjectName(QString::fromUtf8("k"));
        k->setGeometry(QRect(270, 590, 62, 22));
        k->setDecimals(2);
        k->setMinimum(1.000000000000000);
        k->setValue(1.000000000000000);
        sharpe_type = new QGroupBox(centralwidget);
        sharpe_type->setObjectName(QString::fromUtf8("sharpe_type"));
        sharpe_type->setGeometry(QRect(20, 540, 221, 51));
        verticalLayout_2 = new QVBoxLayout(sharpe_type);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        umandhb = new QCheckBox(sharpe_type);
        umandhb->setObjectName(QString::fromUtf8("umandhb"));
        umandhb->setIconSize(QSize(20, 50));
        umandhb->setAutoExclusive(false);

        verticalLayout_2->addWidget(umandhb);

        histogram = new QLabel(centralwidget);
        histogram->setObjectName(QString::fromUtf8("histogram"));
        histogram->setGeometry(QRect(590, 490, 481, 481));
        histogram->setTextFormat(Qt::AutoText);
        histogram->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        histogram->setWordWrap(false);
        histogram->setMargin(10);
        histogram_2 = new QLabel(centralwidget);
        histogram_2->setObjectName(QString::fromUtf8("histogram_2"));
        histogram_2->setGeometry(QRect(1170, 490, 481, 481));
        histogram_2->setTextFormat(Qt::AutoText);
        histogram_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        histogram_2->setWordWrap(false);
        histogram_2->setMargin(10);
        hist_eq = new QCheckBox(centralwidget);
        hist_eq->setObjectName(QString::fromUtf8("hist_eq"));
        hist_eq->setGeometry(QRect(310, 360, 161, 20));
        textEdit_5 = new QTextEdit(centralwidget);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));
        textEdit_5->setGeometry(QRect(300, 190, 271, 151));
        sharpe_type_2 = new QGroupBox(centralwidget);
        sharpe_type_2->setObjectName(QString::fromUtf8("sharpe_type_2"));
        sharpe_type_2->setGeometry(QRect(310, 220, 111, 91));
        verticalLayout_3 = new QVBoxLayout(sharpe_type_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        salt = new QCheckBox(sharpe_type_2);
        salt->setObjectName(QString::fromUtf8("salt"));
        salt->setChecked(false);
        salt->setAutoExclusive(false);

        verticalLayout_3->addWidget(salt);

        pepper = new QCheckBox(sharpe_type_2);
        pepper->setObjectName(QString::fromUtf8("pepper"));
        pepper->setAutoExclusive(false);

        verticalLayout_3->addWidget(pepper);

        gaussian2 = new QCheckBox(sharpe_type_2);
        gaussian2->setObjectName(QString::fromUtf8("gaussian2"));
        gaussian2->setIconSize(QSize(20, 50));
        gaussian2->setAutoExclusive(false);

        verticalLayout_3->addWidget(gaussian2);

        std_dev2 = new QDoubleSpinBox(centralwidget);
        std_dev2->setObjectName(QString::fromUtf8("std_dev2"));
        std_dev2->setGeometry(QRect(450, 310, 62, 22));
        std_dev2->setDecimals(2);
        std_dev2->setMinimum(0.000000000000000);
        std_dev2->setValue(0.000000000000000);
        noise_quant = new QDial(centralwidget);
        noise_quant->setObjectName(QString::fromUtf8("noise_quant"));
        noise_quant->setGeometry(QRect(450, 210, 50, 64));
        noise_quant->setMaximum(5000);
        upsampling = new QCheckBox(centralwidget);
        upsampling->setObjectName(QString::fromUtf8("upsampling"));
        upsampling->setGeometry(QRect(310, 390, 161, 20));
        downsampling = new QCheckBox(centralwidget);
        downsampling->setObjectName(QString::fromUtf8("downsampling"));
        downsampling->setGeometry(QRect(310, 420, 161, 20));
        textEdit_6 = new QTextEdit(centralwidget);
        textEdit_6->setObjectName(QString::fromUtf8("textEdit_6"));
        textEdit_6->setGeometry(QRect(390, 460, 191, 201));
        sharpe_type_3 = new QGroupBox(centralwidget);
        sharpe_type_3->setObjectName(QString::fromUtf8("sharpe_type_3"));
        sharpe_type_3->setGeometry(QRect(400, 500, 151, 121));
        verticalLayout_6 = new QVBoxLayout(sharpe_type_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lap = new QCheckBox(sharpe_type_3);
        lap->setObjectName(QString::fromUtf8("lap"));
        lap->setIconSize(QSize(10, 20));
        lap->setChecked(false);
        lap->setAutoExclusive(false);

        verticalLayout_6->addWidget(lap);

        sobel = new QCheckBox(sharpe_type_3);
        sobel->setObjectName(QString::fromUtf8("sobel"));
        sobel->setIconSize(QSize(20, 50));
        sobel->setAutoExclusive(false);

        verticalLayout_6->addWidget(sobel);

        scharr = new QCheckBox(sharpe_type_3);
        scharr->setObjectName(QString::fromUtf8("scharr"));
        scharr->setIconSize(QSize(20, 50));
        scharr->setAutoExclusive(false);

        verticalLayout_6->addWidget(scharr);

        morpho = new QCheckBox(sharpe_type_3);
        morpho->setObjectName(QString::fromUtf8("morpho"));
        morpho->setIconSize(QSize(20, 50));
        morpho->setAutoExclusive(false);

        verticalLayout_6->addWidget(morpho);

        edge_kernel = new QSpinBox(centralwidget);
        edge_kernel->setObjectName(QString::fromUtf8("edge_kernel"));
        edge_kernel->setGeometry(QRect(480, 630, 41, 21));
        edge_kernel->setMinimum(3);
        edge_kernel->setMaximum(31);
        edge_kernel->setSingleStep(2);
        edge_kernel->setValue(3);
        textEdit_7 = new QTextEdit(centralwidget);
        textEdit_7->setObjectName(QString::fromUtf8("textEdit_7"));
        textEdit_7->setGeometry(QRect(10, 630, 191, 201));
        morpho_kernel_size = new QSpinBox(centralwidget);
        morpho_kernel_size->setObjectName(QString::fromUtf8("morpho_kernel_size"));
        morpho_kernel_size->setGeometry(QRect(80, 790, 41, 21));
        morpho_kernel_size->setMinimum(3);
        morpho_kernel_size->setMaximum(31);
        morpho_kernel_size->setValue(3);
        sharpe_type_4 = new QGroupBox(centralwidget);
        sharpe_type_4->setObjectName(QString::fromUtf8("sharpe_type_4"));
        sharpe_type_4->setGeometry(QRect(20, 660, 151, 121));
        verticalLayout_7 = new QVBoxLayout(sharpe_type_4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        erosion = new QCheckBox(sharpe_type_4);
        erosion->setObjectName(QString::fromUtf8("erosion"));
        erosion->setIconSize(QSize(10, 20));
        erosion->setChecked(false);
        erosion->setAutoExclusive(false);

        verticalLayout_7->addWidget(erosion);

        dilation = new QCheckBox(sharpe_type_4);
        dilation->setObjectName(QString::fromUtf8("dilation"));
        dilation->setAutoExclusive(false);

        verticalLayout_7->addWidget(dilation);

        open = new QCheckBox(sharpe_type_4);
        open->setObjectName(QString::fromUtf8("open"));
        open->setIconSize(QSize(20, 50));
        open->setAutoExclusive(false);

        verticalLayout_7->addWidget(open);

        close = new QCheckBox(sharpe_type_4);
        close->setObjectName(QString::fromUtf8("close"));
        close->setIconSize(QSize(20, 50));
        close->setAutoExclusive(false);

        verticalLayout_7->addWidget(close);

        blur_type = new QGroupBox(centralwidget);
        blur_type->setObjectName(QString::fromUtf8("blur_type"));
        blur_type->setGeometry(QRect(20, 390, 141, 76));
        verticalLayout = new QVBoxLayout(blur_type);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gaussian = new QCheckBox(blur_type);
        gaussian->setObjectName(QString::fromUtf8("gaussian"));
        gaussian->setChecked(false);
        gaussian->setAutoExclusive(false);

        verticalLayout->addWidget(gaussian);

        median = new QCheckBox(blur_type);
        median->setObjectName(QString::fromUtf8("median"));
        median->setAutoExclusive(false);

        verticalLayout->addWidget(median);

        average = new QCheckBox(blur_type);
        average->setObjectName(QString::fromUtf8("average"));
        average->setAutoExclusive(false);

        verticalLayout->addWidget(average);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(420, 70, 121, 51));
        textEdit_8 = new QTextEdit(centralwidget);
        textEdit_8->setObjectName(QString::fromUtf8("textEdit_8"));
        textEdit_8->setGeometry(QRect(430, 130, 111, 51));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(350, 820, 93, 28));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(210, 820, 93, 28));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(1500, 920, 93, 28));
        beta = new QSpinBox(centralwidget);
        beta->setObjectName(QString::fromUtf8("beta"));
        beta->setGeometry(QRect(220, 280, 42, 22));
        beta->setMinimum(-150);
        beta->setMaximum(150);
        beta->setSingleStep(10);
        IPmainwindow->setCentralWidget(centralwidget);
        textEdit_3->raise();
        textEdit->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        rawIm->raise();
        processedIm->raise();
        sequence_iterator->raise();
        layoutWidget->raise();
        layoutWidget1->raise();
        alpha->raise();
        Apply->raise();
        textEdit_2->raise();
        kernel_size->raise();
        std_dev->raise();
        blur_type->raise();
        textEdit_4->raise();
        kernel_size_2->raise();
        k->raise();
        sharpe_type->raise();
        histogram->raise();
        histogram_2->raise();
        hist_eq->raise();
        textEdit_5->raise();
        sharpe_type_2->raise();
        std_dev2->raise();
        noise_quant->raise();
        upsampling->raise();
        downsampling->raise();
        textEdit_6->raise();
        sharpe_type_3->raise();
        edge_kernel->raise();
        textEdit_7->raise();
        morpho_kernel_size->raise();
        sharpe_type_4->raise();
        pushButton_4->raise();
        textEdit_8->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        beta->raise();
        menubar = new QMenuBar(IPmainwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1800, 26));
        IPmainwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(IPmainwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        IPmainwindow->setStatusBar(statusbar);

        retranslateUi(IPmainwindow);

        QMetaObject::connectSlotsByName(IPmainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *IPmainwindow)
    {
        IPmainwindow->setWindowTitle(QApplication::translate("IPmainwindow", "Image Processing", nullptr));
        pushButton->setText(QApplication::translate("IPmainwindow", "Image", nullptr));
        pushButton_2->setText(QApplication::translate("IPmainwindow", "Image Sequence", nullptr));
        pushButton_3->setText(QApplication::translate("IPmainwindow", "Demo Image", nullptr));
        rawIm->setText(QApplication::translate("IPmainwindow", "Raw Image", nullptr));
        processedIm->setText(QApplication::translate("IPmainwindow", "Processed Image", nullptr));
        RGB->setText(QApplication::translate("IPmainwindow", "RGB", nullptr));
        GS->setText(QApplication::translate("IPmainwindow", "Gray Scale", nullptr));
        apply_all->setText(QApplication::translate("IPmainwindow", "Apply to All", nullptr));
        apply_obo->setText(QApplication::translate("IPmainwindow", "Apply one by one", nullptr));
        textEdit->setHtml(QApplication::translate("IPmainwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Adjust Contrast <br />(<span style=\" font-size:8pt; color:#008000;\">alpha</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">&gt;</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">1</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">for</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">increase,<br /></span><span style=\" font-"
                        "size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">0</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">&lt;</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">alpha</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">&lt;</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">1</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">for</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">decrease</span>)</p></body></html>", nullptr));
        Apply->setText(QApplication::translate("IPmainwindow", "Apply", nullptr));
        textEdit_2->setHtml(QApplication::translate("IPmainwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Adjust Brightness <br />(<span style=\" font-size:8pt; color:#008000;\">beta</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">&gt;</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#509a02;\">0</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">for</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">increase,</span><span style=\" font-size:"
                        "8pt; color:#c0c0c0;\"> <br /></span><span style=\" font-size:8pt; color:#008000;\">&lt;</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#509a02;\">0</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">for</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#008000;\">decrease</span>)</p></body></html>", nullptr));
        textEdit_3->setHtml(QApplication::translate("IPmainwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Blurring Image</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		 kernel size</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-r"
                        "ight:0px; -qt-block-indent:0; text-indent:0px;\">		standard deviation<br />		(for gaussian only)</p></body></html>", nullptr));
        textEdit_4->setHtml(QApplication::translate("IPmainwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Image Sharpening</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">                                                                kernel size</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style="
                        "\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		     	         k</p></body></html>", nullptr));
        umandhb->setText(QApplication::translate("IPmainwindow", "UNSHARP MASK & HIGH BOOST", nullptr));
        histogram->setText(QApplication::translate("IPmainwindow", "Histogram of Raw Image", nullptr));
        histogram_2->setText(QApplication::translate("IPmainwindow", "Histogram of Processed Image", nullptr));
        hist_eq->setText(QApplication::translate("IPmainwindow", "Histogram Equalization", nullptr));
        textEdit_5->setHtml(QApplication::translate("IPmainwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Add Noise                      quantity </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">                                  </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-t"
                        "ype:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">                                   standard deviation</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	          (for gaussian noise only)	</p></body></html>", nullptr));
        salt->setText(QApplication::translate("IPmainwindow", "SALT", nullptr));
        pepper->setText(QApplication::translate("IPmainwindow", "PEPPER", nullptr));
        gaussian2->setText(QApplication::translate("IPmainwindow", "GAUSSIAN", nullptr));
        upsampling->setText(QApplication::translate("IPmainwindow", "UPSAMPLING", nullptr));
        downsampling->setText(QApplication::translate("IPmainwindow", "DOWNSAMPLING", nullptr));
        textEdit_6->setHtml(QApplication::translate("IPmainwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Detect Edges</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">                                                                </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph"
                        "-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -"
                        "qt-block-indent:0; text-indent:0px;\">kernel size</p></body></html>", nullptr));
        lap->setText(QApplication::translate("IPmainwindow", "LAPLACIAN", nullptr));
        sobel->setText(QApplication::translate("IPmainwindow", "SOBEL", nullptr));
        scharr->setText(QApplication::translate("IPmainwindow", "SCHARR", nullptr));
        morpho->setText(QApplication::translate("IPmainwindow", "MORPHOLOGICAL", nullptr));
        textEdit_7->setHtml(QApplication::translate("IPmainwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Morphological Operations</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">                                                                </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-"
                        "qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-"
                        "right:0px; -qt-block-indent:0; text-indent:0px;\">kernel size</p></body></html>", nullptr));
        erosion->setText(QApplication::translate("IPmainwindow", "EROSION", nullptr));
        dilation->setText(QApplication::translate("IPmainwindow", "DILATION", nullptr));
        open->setText(QApplication::translate("IPmainwindow", "OPEN", nullptr));
        close->setText(QApplication::translate("IPmainwindow", "CLOSE", nullptr));
        gaussian->setText(QApplication::translate("IPmainwindow", "GAUSSIAN", nullptr));
        median->setText(QApplication::translate("IPmainwindow", "MEDIAN", nullptr));
        average->setText(QApplication::translate("IPmainwindow", "AVERAGE", nullptr));
        pushButton_4->setText(QApplication::translate("IPmainwindow", "CAM", nullptr));
        textEdit_8->setHtml(QApplication::translate("IPmainwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Press 'q' to take a picture and quit</span></p></body></html>", nullptr));
        pushButton_5->setText(QApplication::translate("IPmainwindow", "Save", nullptr));
        pushButton_6->setText(QApplication::translate("IPmainwindow", "Clear", nullptr));
        pushButton_7->setText(QApplication::translate("IPmainwindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IPmainwindow: public Ui_IPmainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IPMAINWINDOW_H
