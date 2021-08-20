#include "ipmainwindow.h"
#include "mainwindow.h"
#include "Image_Processing.hpp"
#include "ui_ipmainwindow.h"
#include <iostream>
#include <opencv2/opencv.hpp>

#include <QFileDialog>
#include <QSlider>
#include <QButtonGroup>
#include <QImage>
#include <QMessageBox>

extern std::string InputImage_Folder;
extern std::string OutputImage_Folder;

extern QString IP_DEFAULT_IMAGE_GS;
extern QString IP_DEFAULT_IMAGE_RGB;


IO_TYPE io_type;

bool GS_AND_HE = false;

int image_sequence_position = 0;

double contrast_alpha = 0;
int brightness_beta = 0;

uint8_t blur_kernel_size = 3;
double std_dev = 0; //for gaussian blur only

uint8_t sharp_kernel_size = 3;
double k = 0; // for unsharp mask & high boost only

int noise_quant = 0;
double std_dev2 = 0; // for gaussian blur only

uint8_t edge_kernel_size = 3;
uint8_t morpho_kernel_size = 3;

QImage Qimg;
QImage Qhist_raw;
QImage Qhist_processed;


cv::Mat img;
cv::Mat im_processed;
cv::Mat hist_raw;
cv::Mat hist_processed;


std::vector<cv::Mat>  img_sequence;
std::vector<cv::Mat>::iterator it;

std::vector<cv::Mat>  processed_sequence;
std::vector<cv::Mat>::iterator pit;


IPmainwindow::IPmainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IPmainwindow){ui->setupUi(this);}


IPmainwindow::~IPmainwindow()
{
    delete ui;
}

void IPmainwindow::on_pushButton_clicked() // Image
{
    ui->rawIm->clear();
    ui->processedIm->clear();
    ui->histogram->clear();
    ui->histogram_2->clear();

  //  std::cout << "IMAGE CLICKED" << std::endl;
    // https://doc.qt.io/qt-5/qfiledialog.html#fileMode-prop
    io_type = SINGLE_IMAGE;
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg *.jpeg *.tiff)"));
    QStringList fileNames;
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setFileMode(QFileDialog::ExistingFile);
    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    if(!fileNames.size())
    {
        QMessageBox msgBox;
        msgBox.setText("Please select an image");
        msgBox.exec();
        return;
    }

    std::cout << fileNames.at(0).toLocal8Bit().constData() << std::endl;
    img = cv::imread(fileNames.at(0).toLocal8Bit().constData());
    if (img.empty())
    {
        std::cout << "Image could not read";
        return;
    }
    Qimg = QImage((const unsigned char*)(img.data),img.cols,img.rows,QImage::Format_RGB888);
    if (img.cols > 896 || img.rows > 896) // if image is too big, either we cant see the whole image in label, or the label gets too big causing a bad view
    {
        Qimg = Qimg.scaled(896,896,Qt::KeepAspectRatio);
    }
    ui->rawIm->setPixmap(QPixmap::fromImage(Qimg));
    //resize the label to fit the image
    ui->rawIm->resize(ui->rawIm->pixmap()->size());


    hist_raw = Histogram_Plot(img);
    Qhist_raw = QImage((const unsigned char*)(hist_raw.data),hist_raw.cols,hist_raw.rows,QImage::Format_RGB888);

    if (hist_raw.cols > 896 || hist_raw.rows > 896) // if image is too big, either we cant see the whole image in label, or the label gets too big causing a bad view
    {
        Qhist_raw = Qhist_raw.scaled(896,896,Qt::KeepAspectRatio);
    }
    ui->histogram->setPixmap(QPixmap::fromImage(Qhist_raw));
    //resize the label to fit the image
    ui->histogram->resize(ui->histogram->pixmap()->size());
}


void IPmainwindow::on_pushButton_2_clicked() // Image Sequence
{
    ui->rawIm->clear();
    ui->processedIm->clear();
    ui->histogram->clear();
    ui->histogram_2->clear();

    io_type = IMAGE_SEQUENCE;
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg *.jpeg *.tiff)"));
    QStringList fileNames;
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    it = img_sequence.begin();

    if(!fileNames.size())
    {
        QMessageBox msgBox;
        msgBox.setText("Please select at least 1 image");
        msgBox.exec();
        return;
    }

    for (int i = 0; i < fileNames.size(); ++i)
    {
            std::cout << fileNames.at(i).toLocal8Bit().constData() << std::endl;
            it = img_sequence.insert(it, cv::imread(fileNames.at(i).toLocal8Bit().constData()));
            it++;
            //below process is needed to determine processed_sequence size. After we can change x. position image without getting any size error
            pit = processed_sequence.insert(pit, cv::imread(fileNames.at(i).toLocal8Bit().constData()));
            pit++;
    }

    uint8_t total_images_loaded = img_sequence.size();

    std::cout<< total_images_loaded << "images  selected" << std::endl;

    QImage Qimg= QImage((const unsigned char*)(img_sequence.at(0).data),img_sequence.at(0).cols,img_sequence.at(0).rows,QImage::Format_RGB888);
    if (img_sequence.at(0).cols > 896 || img_sequence.at(0).rows > 896) // if image is too big, either we cant see the whole image in label, or the label gets too big causing a bad view
    {
        Qimg = Qimg.scaled(896,896,Qt::KeepAspectRatio);
    }
    ui->rawIm->setPixmap(QPixmap::fromImage(Qimg));
    //resize the label to fit the image
    ui->rawIm->resize(ui->rawIm->pixmap()->size());

    ui->sequence_iterator->setRange(0, total_images_loaded-1); // set the min max range of slider which is used for iterating over images in sequence

    hist_raw = Histogram_Plot(img_sequence.at(0));
    Qhist_raw = QImage((const unsigned char*)(hist_raw.data),hist_raw.cols,hist_raw.rows,QImage::Format_RGB888);

    if (hist_raw.cols > 896 || hist_raw.rows > 896) // if image is too big, either we cant see the whole image in label, or the label gets too big causing a bad view
    {
        Qhist_raw = Qhist_raw.scaled(896,896,Qt::KeepAspectRatio);
    }
    ui->histogram->setPixmap(QPixmap::fromImage(Qhist_raw));
    //resize the label to fit the image
    ui->histogram->resize(ui->histogram->pixmap()->size());


}

void IPmainwindow::on_pushButton_3_clicked() // Demo Image
{
    ui->rawIm->clear();
    ui->processedIm->clear();
    ui->histogram->clear();
    ui->histogram_2->clear();

     io_type = SINGLE_IMAGE;
     if(ui->RGB->isChecked())
     {
         std::cout << "here1" << std::endl;
         img = cv::imread(IP_DEFAULT_IMAGE_RGB.toLocal8Bit().constData());
         if (img.empty())
         {
             std::cout << "Image could not read";
             return;
         }
         Qimg = QImage((const unsigned char*)(img.data),img.cols,img.rows,QImage::Format_RGB888);

     }
     else if (ui->GS->isChecked())
     {
         std::cout << "here2" << std::endl;
         img = cv::imread(IP_DEFAULT_IMAGE_GS.toLocal8Bit().constData());
         if (img.empty())
         {
             std::cout << "Image could not read";
             return;
         }
         Qimg = QImage((const unsigned char*)(img.data),img.cols,img.rows,QImage::Format_RGB888); // even if the image grayscale, it doesnt work with Format_GrayScale because they are 3-channel again...
     }
     if (img.cols > 896 || img.rows > 896) // if image is too big, either we cant see the whole image in label, or the label gets too big causing a bad view
     {
         Qimg = Qimg.scaled(896,896,Qt::KeepAspectRatio);
     }
     ui->rawIm->setPixmap(QPixmap::fromImage(Qimg));
     //resize the label to fit the image
     ui->rawIm->resize(ui->rawIm->pixmap()->size());

     hist_raw = Histogram_Plot(img);
     Qhist_raw = QImage((const unsigned char*)(hist_raw.data),hist_raw.cols,hist_raw.rows,QImage::Format_RGB888);

     if (hist_raw.cols > 896 || hist_raw.rows > 896) // if image is too big, either we cant see the whole image in label, or the label gets too big causing a bad view
     {
         Qhist_raw = Qhist_raw.scaled(896,896,Qt::KeepAspectRatio);
     }
     ui->histogram->setPixmap(QPixmap::fromImage(Qhist_raw));
     //resize the label to fit the image
     ui->histogram->resize(ui->histogram->pixmap()->size());

}


void IPmainwindow::on_pushButton_4_clicked() // CAM
{
    ui->rawIm->clear();
    ui->processedIm->clear();
    ui->histogram->clear();
    ui->histogram_2->clear();

    io_type = SINGLE_IMAGE;
    img = open_camera(0);


    std::cout << img.depth() << img.channels() << std::endl;

    if (img.empty())
    {
        std::cout << "Couldnt take screenshot from CAM!";
        return;
    }
    cv::cvtColor(img, img, CV_BGR2RGB);

    Qimg = QImage((const unsigned char*)(img.data),img.cols,img.rows,QImage::Format_RGB888);
    if (img.cols > 896 || img.rows > 896) // if image is too big, either we cant see the whole image in label, or the label gets too big causing a bad view
    {
        Qimg = Qimg.scaled(896,896,Qt::KeepAspectRatio);
    }
    ui->rawIm->setPixmap(QPixmap::fromImage(Qimg));
    //resize the label to fit the image
    ui->rawIm->resize(ui->rawIm->pixmap()->size());


    hist_raw = Histogram_Plot(img);
    Qhist_raw = QImage((const unsigned char*)(hist_raw.data),hist_raw.cols,hist_raw.rows,QImage::Format_RGB888);

    if (hist_raw.cols > 896 || hist_raw.rows > 896) // if image is too big, either we cant see the whole image in label, or the label gets too big causing a bad view
    {
        Qhist_raw = Qhist_raw.scaled(896,896,Qt::KeepAspectRatio);
    }
    ui->histogram->setPixmap(QPixmap::fromImage(Qhist_raw));
    //resize the label to fit the image
    ui->histogram->resize(ui->histogram->pixmap()->size());
}

void IPmainwindow::on_sequence_iterator_valueChanged(int value)
{
    image_sequence_position = value;
    try {
        std::cout << value << std::endl;
        QImage Qimg= QImage((const unsigned char*)(img_sequence.at(value).data),img_sequence.at(value).cols,img_sequence.at(value).rows,QImage::Format_RGB888);
        if (img_sequence.at(value).cols > 896 || img_sequence.at(value).rows > 896) // if image is too big, either we cant see the whole image in label, or the label gets too big causing a bad view
        {
            Qimg = Qimg.scaled(896,896,Qt::KeepAspectRatio);
        }
        ui->rawIm->setPixmap(QPixmap::fromImage(Qimg));
        //resize the label to fit the image
        ui->rawIm->resize(ui->rawIm->pixmap()->size());



        hist_raw = Histogram_Plot(img_sequence.at(value));
        Qhist_raw = QImage((const unsigned char*)(hist_raw.data),hist_raw.cols,hist_raw.rows,QImage::Format_RGB888);

        if (hist_raw.cols > 896 || hist_raw.rows > 896) // if image is too big, either we cant see the whole image in label, or the label gets too big causing a bad view
        {
            Qhist_raw = Qhist_raw.scaled(896,896,Qt::KeepAspectRatio);
        }
        ui->histogram->setPixmap(QPixmap::fromImage(Qhist_raw));
        //resize the label to fit the image
        ui->histogram->resize(ui->histogram->pixmap()->size());



        QImage Qprocessed_img= QImage((const unsigned char*)(processed_sequence.at(value).data),processed_sequence.at(value).cols,processed_sequence.at(value).rows,QImage::Format_RGB888);
        if (processed_sequence.at(value).cols > 896 || processed_sequence.at(value).rows > 896) // if image is too big, either we cant see the whole image in label, or the label gets too big causing a bad view
        {
            Qprocessed_img = Qprocessed_img.scaled(896,896,Qt::KeepAspectRatio);
        }
        ui->processedIm->setPixmap(QPixmap::fromImage(Qprocessed_img));
        //resize the label to fit the image
        ui->processedIm->resize(ui->processedIm->pixmap()->size());

        hist_processed = Histogram_Plot(processed_sequence.at(value));
        Qhist_processed = QImage((const unsigned char*)(hist_processed.data),hist_processed.cols,hist_processed.rows,QImage::Format_RGB888);

        if (hist_processed.cols > 896 || hist_processed.rows > 896) // if image is too big, either we cant see the whole image in label, or the label gets too big causing a bad view
        {
            Qhist_processed = Qhist_processed.scaled(896,896,Qt::KeepAspectRatio);
        }

        ui->histogram_2->setPixmap(QPixmap::fromImage(Qhist_processed));
        //resize the label to fit the image
        ui->histogram_2->resize(ui->histogram_2->pixmap()->size());



    }
    catch (std::out_of_range) {
         std::cout << "Please load sequence images from Image Sequence button before using slider" << std::endl;
    }

}

void IPmainwindow::on_alpha_valueChanged(double arg1)
{
    contrast_alpha = arg1;
}



cv::Mat IPmainwindow::Apply_Changes(cv::Mat img)
{
    cv::Mat tmp;

    // contrast

    tmp = Change_Contrast(img, contrast_alpha);

    // brightness

    tmp = Change_Brightness(tmp, brightness_beta);

    // Noise adding

    if(ui->salt->isChecked())
    {
        tmp = Add_Noise(tmp, SALT, noise_quant, std_dev2);

    }
    if (ui->pepper->isChecked())
    {
        tmp = Add_Noise(tmp, PEPPER, noise_quant, std_dev2);
    }
    if (ui->gaussian2->isChecked())
    {
        tmp = Add_Noise(tmp, GAUSSIAN_NOISE, noise_quant, std_dev2);
    }

    // Blurring

    if(ui->gaussian->isChecked())
    {
        tmp = Image_Blur(tmp, GAUSSIAN, blur_kernel_size,std_dev);

    }
    if (ui->median->isChecked())
    {
        tmp = Image_Blur(tmp, AVERAGE, blur_kernel_size);
    }
    if (ui->average->isChecked())
    {
        tmp = Image_Blur(tmp, MEDIAN, blur_kernel_size);
    }

    // Sharpening

    if (ui->umandhb->isChecked())
    {
        tmp = Image_Sharpening(tmp, UNSHARP_MASK_AND_HIGH_BOOSTING, sharp_kernel_size, k);
    }

    // histogram equalization

    if(ui->hist_eq->isChecked())
    {
        tmp = Histogram_Equalization(tmp);
    }

    // sampling operations

    if(ui->upsampling->isChecked())
    {
        tmp = Sampling(tmp, UPSAMPLING);
    }
    if(ui->downsampling->isChecked())
    {
        tmp = Sampling(tmp, DOWNSAMPLING);
    }

    // edge detection operations

    if(ui->lap->isChecked())
    {
        tmp = Edge_Detection(tmp, LAPLACIEN, edge_kernel_size);
    }
    if(ui->sobel->isChecked())
    {
        tmp = Edge_Detection(tmp, SOBEL, edge_kernel_size);
    }
    if(ui->morpho->isChecked())
    {
        tmp = Edge_Detection(tmp, MORPHOLOGICAL, edge_kernel_size);
    }
    if(ui->scharr->isChecked())
    {
        tmp = Edge_Detection(tmp, SCHARR, edge_kernel_size);
    }

    // morphological operations

    if(ui->erosion->isChecked())
    {
        tmp = Morphological_Operations(tmp, EROSION, morpho_kernel_size);
    }
    if(ui->dilation->isChecked())
    {
        tmp = Morphological_Operations(tmp, DILATION, morpho_kernel_size);
    }
    if(ui->open->isChecked())
    {
        tmp = Morphological_Operations(tmp, OPEN, morpho_kernel_size);
    }
    if(ui->close->isChecked())
    {
        tmp = Morphological_Operations(tmp, CLOSE, morpho_kernel_size);
    }


    return tmp;
}



void IPmainwindow::on_Apply_clicked()
{

    switch(io_type)
    {
        case SINGLE_IMAGE:
        {
            im_processed = Apply_Changes(img);
            break;
        }
        case IMAGE_SEQUENCE:
        {
            std::cout << "IMAGE SEQ" << std::endl;
            if(ui->apply_obo->isChecked()) // applying the changes on only the selected image in sequence
            {
                std::cout << "ONE BY ONE" << std::endl;
                im_processed = Apply_Changes(img_sequence.at(image_sequence_position));

                processed_sequence.at(image_sequence_position) = im_processed;
            }
            else if(ui->apply_all->isChecked()) // applying all the changes on all the images in sequence
            {
                int i = 0;
                for (it = img_sequence.begin(); it != img_sequence.end(); it++)
                {
                    im_processed = Apply_Changes(it[0]);
                    processed_sequence.at(i) = im_processed;
                    i++;
                }

                im_processed = processed_sequence.at(image_sequence_position); // select the processed image to show on gui compatible with image sequence position
            }
            break;

        }
        default:
        {
            std::cout << "no io typee" << std::endl;
            break;
        }

    }
    if (GS_AND_HE)
    {
        Qimg = QImage((const unsigned char*)(im_processed.data),im_processed.cols,im_processed.rows,QImage::Format_Grayscale8);
        GS_AND_HE = false;
    }
    else
        Qimg = QImage((const unsigned char*)(im_processed.data),im_processed.cols,im_processed.rows,QImage::Format_RGB888);

    if (im_processed.cols > 896 || im_processed.rows > 896) // if image is too big, either we cant see the whole image in label, or the label gets too big causing a bad view
    {
        Qimg = Qimg.scaled(896,896,Qt::KeepAspectRatio);
    }
    ui->processedIm->setPixmap(QPixmap::fromImage(Qimg));
    //resize the label to fit the image
    ui->processedIm->resize(ui->processedIm->pixmap()->size());

    hist_processed = Histogram_Plot(im_processed);
    Qhist_processed = QImage((const unsigned char*)(hist_processed.data),hist_processed.cols,hist_processed.rows,QImage::Format_RGB888);

    if (hist_processed.cols > 896 || hist_processed.rows > 896) // if image is too big, either we cant see the whole image in label, or the label gets too big causing a bad view
    {
        Qhist_processed = Qhist_processed.scaled(896,896,Qt::KeepAspectRatio);
    }
    ui->histogram_2->setPixmap(QPixmap::fromImage(Qhist_processed));
    //resize the label to fit the image
    ui->histogram_2->resize(ui->histogram_2->pixmap()->size());
}



void IPmainwindow::on_kernel_size_valueChanged(int arg1)
{
    if (arg1 % 2 == 0)
            arg1++;
    blur_kernel_size = arg1;
}

void IPmainwindow::on_std_dev_valueChanged(double arg1)
{
    std_dev = arg1;
}

void IPmainwindow::on_kernel_size_2_valueChanged(int arg1)
{
    if (arg1 % 2 == 0)
            arg1++;
    sharp_kernel_size = arg1;
}

void IPmainwindow::on_k_valueChanged(double arg1)
{
    k = arg1;
}

void IPmainwindow::on_std_dev2_valueChanged(double arg1)
{
    std_dev2 = arg1;
}

void IPmainwindow::on_noise_quant_valueChanged(int value)
{
     noise_quant = value;
}

void IPmainwindow::on_edge_kernel_valueChanged(int arg1)
{
    edge_kernel_size = arg1;
}

void IPmainwindow::on_morpho_kernel_size_valueChanged(int arg1)
{
    morpho_kernel_size = arg1;
}


void IPmainwindow::on_pushButton_5_clicked() // save button
{
    std::string savepath = OutputImage_Folder;
    static int count = 0;
    std::string savename = savepath + std::to_string(count) + ".png";
    std::string savename_hist = savepath + std::to_string(count) + "_hist.png";
    if(save_image(im_processed, savename,OutputImage_Folder) && save_image(hist_processed, savename_hist, OutputImage_Folder))
    {
        QMessageBox msgBox;
        msgBox.setText("The images are saved successfully to");
        msgBox.setInformativeText(QString::fromStdString(OutputImage_Folder));
        msgBox.exec();
    }
    count++;
}

void IPmainwindow::on_pushButton_6_clicked() // clear button
{
    ui->alpha->setValue(0);
    ui->beta->setValue(0);

    ui->salt->setChecked(false);
    ui->pepper->setChecked(false);
    ui->gaussian2->setChecked(false);

    ui->gaussian->setChecked(false);
    ui->median->setChecked(false);
    ui->average->setChecked(false);

    ui->umandhb->setChecked(false);

    ui->hist_eq->setChecked(false);

    ui->upsampling->setChecked(false);
    ui->downsampling->setChecked(false);

    ui->lap->setChecked(false);
    ui->sobel->setChecked(false);
    ui->morpho->setChecked(false);
    ui->scharr->setChecked(false);

    ui->erosion->setChecked(false);
    ui->dilation->setChecked(false);
    ui->open->setChecked(false);
    ui->close->setChecked(false);

    ui->edge_kernel->setValue(3);
    ui->kernel_size->setValue(3);
    ui->kernel_size_2->setValue(3);
    ui->morpho_kernel_size->setValue(3);
    ui->std_dev->setValue(0);
    ui->std_dev2->setValue(0);
    ui->k->setValue(1);
    ui->noise_quant->setValue(0);


}

void IPmainwindow::on_pushButton_7_clicked() // backbutton
{
    hide();
    QWidget *parent = this->parentWidget();
    if (parent == nullptr)
        std::cout << "no parent" << std::endl;

    parent->show();
}

void IPmainwindow::on_beta_valueChanged(int arg1)
{
    brightness_beta = arg1;
}
