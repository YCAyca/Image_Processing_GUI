#ifndef IMAGE_PROCESSING_HPP
#define IMAGE_PROCESSING_HPP

#include "Input_Output.hpp"

typedef enum
{
    GRAYSCALE,
    RGB,
    NOT_DETECTED,
}IMAGE_TYPE;

typedef enum
{
    UINT8,
    UINT16,
    INT8,
    INT16,
}PIXEL_TYPE;

typedef enum
{
    GAUSSIAN,
    AVERAGE, // Mean Filter as the 2. name
    MEDIAN,
}BLUR_TYPE;

typedef enum
{
    UNSHARP_MASK_AND_HIGH_BOOSTING,
}SHARPENING_TYPE;


typedef enum
{
    SALT,
    PEPPER,
    SALT_AND_PEPPER,
    GAUSSIAN_NOISE,
}NOISE_TYPE;

typedef enum
{
    UPSAMPLING,
    DOWNSAMPLING,
}SAMPLING_TYPE;


typedef enum
{
    EROSION,
    DILATION,
    OPEN,
    CLOSE,
}MORPHOLOGIE_TYPE;

typedef enum
{
    SOBEL,
    PREWITT,
    SCHARR,
    LAPLACIEN,
    MORPHOLOGICAL,
}EDGE_DETECTION_TYPE;

cv::Mat Change_Contrast(cv::Mat, double); // alpha > 1 for increase, 0 < alpha < 1 for decrease the contrast
cv::Mat Change_Brightness(cv::Mat, int); // beta > 0 for increase, < 0 for decrease the brightness
cv::Mat Image_Blur(cv::Mat, BLUR_TYPE, uint8_t kernel_size=3, double std_deviation= 0); // std_deviation is just for Gaussian Blur
cv::Mat Image_Sharpening(cv::Mat, SHARPENING_TYPE, uint8_t , double k=1);
cv::Mat Histogram_Plot(cv::Mat);
cv::Mat Add_Noise(cv::Mat, NOISE_TYPE, int, float std_deviation=5.0); // last parameter is the std deviation and is just for Gaussian Noise
cv::Mat Sampling(cv::Mat, SAMPLING_TYPE);
cv::Mat Morphological_Operations(cv::Mat, MORPHOLOGIE_TYPE, uint8_t kernel_size = 3);
cv::Mat Edge_Detection(cv::Mat, EDGE_DETECTION_TYPE, uint8_t kernel_size=3);
std::vector<float>  Get_Histogram_Info(cv::Mat);
IMAGE_TYPE Check_Image_Type(cv::Mat);
cv::Mat Histogram_Equalization(cv::Mat);


#endif // IMAGE_PROCESSING_HPP
