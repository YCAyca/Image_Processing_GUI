#include "Image_Processing.hpp"
#include <vector>
#include <cstdint>
#include <chrono>
#include <random>

PIXEL_TYPE pixel_type = UINT8;

extern bool GS_AND_HE;

std::ostream& operator<<(std::ostream& out, IMAGE_TYPE type){
    if (type == 0)
        return out << "GRAYSCALE";
    if (type == 1)
        return out << "RGB";
    return out << "NOT_DETECTED";
}

cv::Mat Change_Contrast(cv::Mat image, double alpha)
{
    if( alpha == 0)
        return image;

    cv::Mat output_image;
    image.convertTo(output_image, -1, alpha, 0);
    return output_image;
}

cv::Mat Change_Brightness(cv::Mat image, int beta)
{
    cv::Mat output_image;
    image.convertTo(output_image, -1, 1, beta);
    return output_image;
}

cv::Mat Image_Blur(cv::Mat image, BLUR_TYPE blur_type, uint8_t kernel_size,  double std_deviation)
{
    cv::Mat image_blurred;
    if (kernel_size % 2 == 0) // opencv kernels only works with odd kernel size
        kernel_size++;

    switch(blur_type)
    {
        case GAUSSIAN:
        {
            GaussianBlur(image, image_blurred, cv::Size(kernel_size, kernel_size), std_deviation);
            break;
        }
        case AVERAGE:
        {
            blur(image, image_blurred, cv::Size(kernel_size, kernel_size));
            break;
        }
        case MEDIAN:
        {
            medianBlur(image, image_blurred, kernel_size);
            break;
        }
    }

    return image_blurred;
}


cv::Mat Image_Sharpening(cv::Mat image, SHARPENING_TYPE sharpening_type, uint8_t kernel_size, double k)
{
    cv::Mat image_sharpened;

    switch(sharpening_type)
    {
        case UNSHARP_MASK_AND_HIGH_BOOSTING:
        {
            cv::Mat unsharp_mask, image_blurred;
            GaussianBlur(image, image_blurred, cv::Size(kernel_size, kernel_size),0);
            cv::subtract(image,image_blurred,unsharp_mask);
            add(image, k * unsharp_mask, image_sharpened);
            break;
            //addWeighted(image, 1 + amount, unsharp_mask, -amount, 0, sharp);
        }
    }
    return image_sharpened;
}

cv::Mat Add_Noise(cv::Mat image, NOISE_TYPE noise_type, int quantity, float std_deviation)
{
    cv::Mat noisy_image = image;

    std::vector<cv::Mat> planes;
    split(noisy_image, planes);
    cv::Size size = planes[0].size();
    int row_size = size.height;
    int column_size = size.width;

    switch(noise_type)
    {
        case SALT:
        {
            for (int k = 0; k < quantity; k++)
            {              
                int i= rand() % column_size;
                int j= rand() % row_size;

                if (noisy_image.channels() == 1)
                { // gray-level image
                    planes[0].at<uint8_t>(j,i)= 255;
                }
                else if (image.channels() == 3)
                { // color image
                    planes[0].at<uint8_t>(j,i)= 255;
                    planes[1].at<uint8_t>(j,i)= 255;
                    planes[2].at<uint8_t>(j,i)= 255;
                }
                merge(planes,noisy_image);
            }
            break;
        }
        case PEPPER:
        {
            for (int k = 0; k < quantity; k++)
            {
                int i= rand() % column_size;
                int j= rand() % row_size;

                if (noisy_image.channels() == 1)
                { // gray-level image
                    planes[0].at<uint8_t>(j,i)= 0;
                }
                else if (image.channels() == 3)
                { // color image
                    planes[0].at<uint8_t>(j,i)= 0;
                    planes[1].at<uint8_t>(j,i)= 0;
                    planes[2].at<uint8_t>(j,i)= 0;
                }
                merge(planes,noisy_image);
            }
            break;
        }
        case SALT_AND_PEPPER: // wont use in gui. It can be selected salt and pepper together anyway...
        {
            for (int k = 0; k < quantity/2; k++)
            {
                int i= rand() % column_size;
                int j= rand() % row_size;

                if (noisy_image.channels() == 1)
                { // gray-level image
                    planes[0].at<uint8_t>(j,i)= 255;
                }
                else if (image.channels() == 3)
                { // color image

                    planes[0].at<uint8_t>(j,i)= 255;
                    planes[1].at<uint8_t>(j,i)= 255;
                    planes[2].at<uint8_t>(j,i)= 255;
                }
            }

            for (int k = quantity/2; k < quantity; k++)
            {
                int i= rand() % column_size;
                int j= rand() % row_size;

                if (noisy_image.channels() == 1)
                {
                    planes[0].at<uint8_t>(j,i)= 0;
                }
                else if (image.channels() == 3)
                {
                    planes[0].at<uint8_t>(j,i)= 0;
                    planes[1].at<uint8_t>(j,i)= 0;
                    planes[2].at<uint8_t>(j,i)= 0;
                }
                merge(planes,noisy_image);
            }
            break;
        }
        case GAUSSIAN_NOISE:
        {
             unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
             std::default_random_engine generator (seed);
             std::normal_distribution<double> distribution (0.0,std_deviation);

             for (int k = 0; k < quantity; k++)
             {
                 int i= rand() % column_size;
                 int j= rand() % row_size;

                 float noise = distribution(generator);
                 std::cout << noise << std::endl;
                 if (noisy_image.channels() == 1)
                 { // gray-level image
                     planes[0].at<uint8_t>(j,i) += noise;
                 }
                 else if (image.channels() == 3)
                 { // color image
                     planes[0].at<uint8_t>(j,i) += noise;
                     planes[1].at<uint8_t>(j,i) += noise;
                     planes[2].at<uint8_t>(j,i) += noise;
                 }
                 merge(planes,noisy_image);
            }
            break;
        }
        default:
            std::cout << "No matching noise type!";
            break;
    }
    return noisy_image;
}

cv::Mat Sampling(cv::Mat image, SAMPLING_TYPE mode)
{
    cv::Mat image_sampled;
    switch(mode)
    {
        case UPSAMPLING:
        {
            pyrUp(image, image_sampled, cv::Size(image.cols*2, image.rows*2));
            break;
        }
        case DOWNSAMPLING:
        {
            pyrDown(image, image_sampled, cv::Size(image.cols/2, image.rows/2));
            break;
        }
        default:
        {
                std::cout << "undefined sampling type" << std::endl;
                break;
        }
    }

    return image_sampled;
}

std::vector<float> Get_Histogram_Info(cv::Mat image)
{
    std::vector<float> info; // [range1, range2] and histogram bin size

    switch(image.depth())
    {
        case 0: // CV_8U
            info.push_back(0.0);
            info.push_back(255.0);
            info.push_back(256.0);
            pixel_type = UINT8;
            break;
        case 1: // CV_8S
            info.push_back(-128);
            info.push_back(127);
            info.push_back(256);
            pixel_type = INT8;
            break;
        case 2: // CV_16U
            info.push_back(0);
            info.push_back(65535);
            info.push_back(65536);
            pixel_type = UINT16;
            break;
        case 3: // CV_16S
            info.push_back(-32768);
            info.push_back(32767);
            info.push_back(65536);
            pixel_type = INT16;
            break;
        default:
            std::cout << "OTHER";
            break;
    }

    return info;
}


IMAGE_TYPE Check_Image_Type(cv::Mat image)
{
    IMAGE_TYPE im_type = NOT_DETECTED;

    switch(image.channels())
    {
        case 1:
        {
            im_type = GRAYSCALE;
            std::cout << "This image is:" << im_type << std::endl;
            break;
        }
        case 3:
        {
            std::vector<cv::Mat> bgr_planes;
            split(image, bgr_planes);
            cv::Size size = bgr_planes[0].size();
            int row_size = size.height;
            int column_size = size.width;

            switch(pixel_type)
            {
                case UINT8:
                {
                    for (int i = 0; i < row_size; i++)
                    {
                      for (int k = 0; k < column_size; k++)
                      {
                          if (bgr_planes[0].at<uint8_t>(i,k) !=  bgr_planes[1].at<uint8_t>(i,k) or bgr_planes[0].at<uint8_t>(i,k) != bgr_planes[2].at<uint8_t>(i,k))
                          {
                                im_type = RGB;
                                std::cout << "This image is:" << im_type << std::endl;
                                return im_type;
                         }
                      }
                    }
                    im_type = GRAYSCALE;
                    std::cout << "This image is:" << im_type << std::endl;
                    break;
                }
                case UINT16:
                {
                     for (int i = 0; i < row_size; i++)
                     {
                        for (int k = 0; k < column_size; k++)
                        {
                            if (bgr_planes[0].at<uint16_t>(i,k) !=  bgr_planes[1].at<uint16_t>(i,k) or bgr_planes[0].at<uint16_t>(i,k) != bgr_planes[2].at<uint16_t>(i,k))
                            {
                                 im_type = RGB;
                                 std::cout << "This image is:" << im_type << std::endl;
                                 return im_type;
                            }
                         }
                    }
                    im_type = GRAYSCALE;
                    std::cout << "This image is:" << im_type << std::endl;
                    break;
                }
                case INT8:
                {
                    for (int i = 0; i < row_size; i++)
                    {
                       for (int k = 0; k < column_size; k++)
                       {
                            if (bgr_planes[0].at<int8_t>(i,k) !=  bgr_planes[1].at<int8_t>(i,k) or bgr_planes[0].at<int8_t>(i,k) != bgr_planes[2].at<int8_t>(i,k))
                            {
                               im_type = RGB;
                               std::cout << "This image is:" << im_type << std::endl;
                               return im_type;
                            }
                       }
                    }
                    im_type = GRAYSCALE;
                    std::cout << "This image is:" << im_type << std::endl;
                    break;
                }
                case INT16:
                {
                    for (int i = 0; i < row_size; i++)
                    {
                         for (int k = 0; k < column_size; k++)
                         {
                              if (bgr_planes[0].at<int16_t>(i,k) !=  bgr_planes[1].at<int16_t>(i,k) or bgr_planes[0].at<int16_t>(i,k) != bgr_planes[2].at<int16_t>(i,k))
                              {
                                  im_type = RGB;
                                  std::cout << "This image is:" << im_type << std::endl;
                                  return im_type;
                              }
                          }
                    }
                    im_type = GRAYSCALE;
                    std::cout << "This image is:" << im_type << std::endl;
                    break;
                }
                default:
                {
                    std::cout << "Image pixel type could not be detected!";
                    break;
                }
            }
            break;
        }
        default:
        {
            std::cout << "Image Channel could not be detected!";
            break;
        }
    }
    return im_type;
}

cv::Mat Histogram_Plot(cv::Mat image)
{

     std::vector<float> histogram_info = Get_Histogram_Info(image);

     float histRange[2] = {histogram_info.at(0), histogram_info.at(1)};
     int histSize = histogram_info.at(2);
     const float* range = { histRange };

     std::cout << "Histogram Info : " << histRange[0] << " " << histRange[1] << " " << histSize << std::endl;

     std::vector<cv::Mat> planes;
     split(image, planes);
     bool uniform = true, accumulate = false;

     switch(Check_Image_Type(image))
     {
        case RGB:
        {
             cv::Mat b_hist, g_hist, r_hist;
             calcHist(&planes[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &range, uniform, accumulate );
             calcHist(&planes[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &range, uniform, accumulate );
             calcHist(&planes[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &range, uniform, accumulate );


             int hist_w = 512, hist_h = 400;
             int bin_w = cvRound( (double) hist_w/histSize );
             cv::Mat histImage( hist_h, hist_w, CV_8UC3, cv::Scalar( 255,255,255));
             normalize(b_hist, b_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
             normalize(g_hist, g_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
             normalize(r_hist, r_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
             for( int i = 1; i < histSize; i++ )
             {
                  line(histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ),
                         cv::Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                         cv::Scalar( 255, 0, 0), 2, 8, 0  );
                  line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ),
                        cv::Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                        cv::Scalar( 0, 255, 0), 2, 8, 0  );
                  line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ),
                        cv::Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                        cv::Scalar( 0, 0, 255), 2, 8, 0  );
             }
             return histImage;
        }
        case GRAYSCALE:
        {
             cv::Mat hist;
             calcHist(&planes[0], 1, 0, cv::Mat(), hist, 1, &histSize, &range, uniform, accumulate );

             int hist_w = 512, hist_h = 400;
             int bin_w = cvRound( (double) hist_w/histSize );
             cv::Mat histImage( hist_h, hist_w, CV_8UC3, cv::Scalar( 255,255,255) );
             normalize(hist, hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );

             for( int i = 1; i < histSize; i++ )
             {
                 line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(hist.at<float>(i-1)) ),
                       cv::Point( bin_w*(i), hist_h - cvRound(hist.at<float>(i)) ),
                       cv::Scalar(0, 0, 0), 2, 8, 0);
             }
             return histImage;
        }
        default:
        {
            cv::Mat tmp;
            std::cout << "Undefined Image Type!" << std::endl;
            return tmp;
        }
      }
}

cv::Mat Morphological_Operations(cv::Mat image, MORPHOLOGIE_TYPE type, uint8_t kernel_size)
{
    cv::Mat operated;
    cv::Mat element(kernel_size,kernel_size,CV_8U,cv::Scalar(1)); // creating structure element (it can be a parameter later)
    switch(type)
    {
        case EROSION:
        {
            cv::erode(image,operated,element);
            break;
        }
        case DILATION:
        {
            cv::dilate(image,operated,element);
            break;
        }
        case OPEN:
        {
            cv::morphologyEx(image,operated,cv::MORPH_OPEN,element);
            break;
        }
        case CLOSE:
        {
            cv::morphologyEx(image,operated,cv::MORPH_CLOSE,element);
            break;
        }
        default:
        {
            std::cout << "Undefined morphology operation!" << std::endl;
            break;
        }
        std::cout <<  "structural element "  << element << std::endl;
    }

    return operated;
}

cv::Mat Edge_Detection(cv::Mat image, EDGE_DETECTION_TYPE type, uint8_t kernel_size)
{
    cv::Mat Edge_detected_im;

    cv::Mat grad_x, grad_y;
    switch(type)
    {
        case SOBEL:
        {
            cv::Sobel(image,grad_x,CV_8U,1,0, kernel_size);
            cv::Sobel(image,grad_y,CV_8U,0,1, kernel_size);
            cv::add(grad_x, grad_y, Edge_detected_im);

            break;
        }
        case SCHARR:
        {
            cv::Scharr(image,grad_x,CV_8U,1,0,kernel_size);
            cv::Scharr(image,grad_y,CV_8U,0,1,kernel_size);
            cv::add(grad_x, grad_y, Edge_detected_im);
            break;
        }
        case LAPLACIEN:
        {
            Laplacian(image, Edge_detected_im, image.depth(), kernel_size);
            break;
        }
        case MORPHOLOGICAL: // morphological gradient
        {
            cv::morphologyEx(image,Edge_detected_im,cv::MORPH_GRADIENT,cv::Mat());
            cv::threshold(Edge_detected_im, Edge_detected_im, 50, 255, cv::THRESH_BINARY); // but for this one, its better we improve the visualizing the edges with binary threshold
            break;
        }
        default:
        {
           std::cout << "Undefined morphology operation!" << std::endl;
           break;
        }
    }    
    return Edge_detected_im;
}


cv::Mat Histogram_Equalization(cv::Mat image)
{
    cv::Mat hist_equalized_image;
    switch(Check_Image_Type(image))
    {
        case RGB:
        {
            cvtColor(image, hist_equalized_image, cv::COLOR_BGR2YCrCb);
            std::vector<cv::Mat> vec_channels;
            split(hist_equalized_image, vec_channels);
            equalizeHist(vec_channels[0], vec_channels[0]);
            merge(vec_channels, hist_equalized_image);
            cvtColor(hist_equalized_image, hist_equalized_image, cv::COLOR_YCrCb2BGR);
            break;

        }
        case GRAYSCALE:
        {
            GS_AND_HE = true;
            if (image.channels() == 3)
            {
                cv::cvtColor(image, image, CV_BGR2GRAY);
            }

            equalizeHist(image, hist_equalized_image);
            break;
        }
        default:
        {
            std::cout << "Image Channel could not be detected!";
            break;
        }
    }
    return hist_equalized_image;
}


