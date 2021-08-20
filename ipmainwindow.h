#ifndef IPMAINWINDOW_H
#define IPMAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <opencv2/opencv.hpp>

namespace Ui {
class IPmainwindow;
}

class IPmainwindow : public QMainWindow
{
    Q_OBJECT

public:
    IPmainwindow(QWidget *parent = nullptr);
    ~IPmainwindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_sequence_iterator_valueChanged(int value);

    void on_alpha_valueChanged(double arg1);

    void on_Apply_clicked();

    void on_kernel_size_valueChanged(int arg1);

    void on_std_dev_valueChanged(double arg1);

    void on_kernel_size_2_valueChanged(int arg1);

    void on_k_valueChanged(double arg1);

    void on_std_dev2_valueChanged(double arg1);

    void on_noise_quant_valueChanged(int value);

    void on_edge_kernel_valueChanged(int arg1);

    void on_morpho_kernel_size_valueChanged(int arg1);

    cv::Mat Apply_Changes(cv::Mat);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_beta_valueChanged(int arg1);

private:
    Ui::IPmainwindow *ui;
};

#endif // IPMAINWINDOW_H
