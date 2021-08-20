#ifndef INPUT_OUTPUT_HPP


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <ctime>
#include <string>
#include <QString>

#define INPUT_OUTPUT_HPP

typedef enum{
SLOW_MO,
DEFAULT,
FAST_MO
}VIDEO_SPEED;


typedef enum{
CAM, //the operation will be applied on the frames coming from webcam
IMAGE_SEQUENCE, //the operation will be applied on image sequences coming from this folder
IMAGE_FOLDER, // sanırım sequence ile değişmesi lazım
SINGLE_IMAGE,  // the operation will be applied on a single image
VIDEO, // the operation will be applied on the frames coming from a video
USER_FOLDER,
}IO_TYPE;

#define WAITKEY 1000
#define WAITKEY_OF 100

extern std::string OutputImage_Folder;

bool show_image_from_path(std::string, uint32_t); // // takes 2 parameter, the image path and the duration of showing
void show_image(cv::Mat, uint32_t); // takes 2 parameter, the image and the duration of showing
cv::Mat open_camera(uint32_t); // takes 1 parameter, to determine the time that camera stays open (in ms)
void open_video(std::string, VIDEO_SPEED=DEFAULT); // takes 2 parameter, the path of the video to open and additional delay for adjusting frame speeds if desired
bool save_image(cv::Mat, std::string, std::string=OutputImage_Folder);



#endif // INPUT_OUTPUT_HPP





