#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>

using namespace std;
//using namespace cv;

int main()
{
    //Read the image file
    cv::Mat img = imread("images/rgb1.jpeg",cv::IMREAD_COLOR);

    //Check for failure
    if (img.empty())
    {
        cout<<"Could not find the file"<<endl;
        cin.get();
        return -1;
    }

    string wind_name = "Image Display";

    cv::namedWindow(wind_name,cv::WINDOW_AUTOSIZE);

    cv::imshow(wind_name,img);
    
    cv::Mat img1;
    cv::cvtColor(img,img1,cv::COLOR_BGR2RGB);

    cv::Mat channels[3];
    cv::split(img1,channels);

    namedWindow("Red",cv::WINDOW_AUTOSIZE);
    cv::imshow("Red",channels[0]);

    namedWindow("Green",cv::WINDOW_AUTOSIZE);
    cv::imshow("Green",channels[1]);

    namedWindow("Blue",cv::WINDOW_AUTOSIZE);
    cv::imshow("Blue",channels[2]);

    cv::waitKey(0);

    cv::destroyAllWindows();

    //cout<<channels[0]<<endl;

    return 0;
}