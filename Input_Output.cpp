#include "Input_Output.hpp"

std::string InputImage_Folder= "C:\\Users\\aktas\\Desktop\\Image_Processing_GUI\\Input_Images\\";
std::string OutputImage_Folder= "C:\\Users\\aktas\\Desktop\\Image_Processing_GUI\\Output_Images\\";


QString IP_DEFAULT_IMAGE_GS= "C:\\Users\\aktas\\Desktop\\Image_Processing_GUI\\Input_Images\\cameraman.png";
QString IP_DEFAULT_IMAGE_RGB= "C:\\Users\\aktas\\Desktop\\Image_Processing_GUI\\Input_Images\\cube1.png";

bool show_image_from_path(std::string image_path, uint32_t time)
{
    static int count = 0;

    std::string window_name = "Image" + std::to_string(count);

    cv::Mat image = cv::imread(image_path);
    if (image.empty())
    {
        std::cout << "Image could not read";
        return false;
    }

    cv::namedWindow(window_name);

    cv::imshow(window_name,image);

    cv::waitKey(time);

    count++;
    return true;
}


void show_image(cv::Mat image, uint32_t time)
{
    static int count = 0;

    std::string window_name = "Image" + std::to_string(count);

    cv::namedWindow(window_name);

    cv::imshow(window_name,image);

    cv::waitKey(time);

    count++;
}

bool save_image(cv::Mat image, std::string save_name, std::string save_path)
{
   if(imwrite(save_name, image))
       std::cout << "Image saved to " << save_path << std::endl;
   else
   {
       std::cout << "Image could not be saved" << std::endl;
       return false;
   }
   return true;
}


cv::Mat open_camera(uint32_t duration) // if duration is 0, we will use second mode (press q to quit)
{
    cv::VideoCapture cap(0); // open the default camera
    cv::Mat frame;

    if(!cap.isOpened())  // check if we succeeded
    {
        std::cout << "Camera could not open" << std::endl;
        return frame;
    }

    static int count = 0;

    std::string window_name = "Cam" + std::to_string(count);

    cv::namedWindow(window_name);


    if (duration)
    {


        time_t start_time = clock();
        time_t end_time = 0;


        while (end_time < start_time + duration) {
            if (cap.read(frame))
                cv::imshow(window_name, frame);

            end_time = clock();

            cv::waitKey(10); // just for preventing the camera frames get stuck
        }
     }
     else
     {
        int key=0;
        while (key != 'q') {
            if (cap.read(frame))
                cv::imshow(window_name, frame);
            key = cv::waitKey(10); // just for preventing the camera frames get stuck
        }
     }



    // When everything done, release the video capture objec
    cv::imshow("The Picture taken", frame);
    cv::waitKey(1000);
    cap.release();
    cv::destroyAllWindows();
    return frame;
}

void open_video(std::string video_path, VIDEO_SPEED mode)
{
    // Open the video file
    cv::VideoCapture capture(video_path);
    // check if video successfully opened
    if(!capture.isOpened())  // check if we succeeded
    {
        std::cout << "Video could not open" << std::endl;
        return;
    }

    cv::Mat frame; // current video frame
    cv::namedWindow("Extracted Frame");
    double fps;

    switch(mode)
    {
        case DEFAULT:
            fps = capture.get(CV_CAP_PROP_FPS);
            break;
        case SLOW_MO:
            fps = capture.get(CV_CAP_PROP_FPS);
            fps = fps / 2;
            break;
        case FAST_MO:
            fps = capture.get(CV_CAP_PROP_FPS);
            fps = fps * 2;
            break;
    }

    std::cout << fps;

    std::string window_text = "FPS : " + std::to_string(int(fps));

    int delay= 1000/fps;

    // for all frames in video
    while (true) {
        // read next frame if any
        if (!capture.read(frame))
        {
            if (frame.empty()) // End of the Video
                break;
            continue;
        }
        cv::putText(frame, window_text, cvPoint(15,15),  cv::FONT_HERSHEY_SIMPLEX, 0.4, cvScalar(200,200,250), 1, CV_AA);
        cv::imshow("Extracted Frame",frame);

        cv::waitKey(delay);
    }
    capture.release();
    cv::destroyAllWindows();
}




