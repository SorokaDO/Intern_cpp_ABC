#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	std::string text = "Text";
	int baseline = 0;
	cv::Size text_size = cv::getTextSize(text, cv::FONT_ITALIC, 3, 3, &baseline);
	cv::Point p;
	cv::Scalar clr(100,100,100);
	cv::Mat frame, image_res;
	cv::VideoCapture cap(0);
	double frame_width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
	if (!cap.isOpened())
	{
		std::cout << "Error!" << std::endl;
	}
	else
	{
		while (true)
		{
			cap.read(frame);
			cv::cvtColor(frame, image_res, cv::COLOR_BGR2GRAY);
			p.x = frame_width- text_size.width-10;
			p.y = text_size.height + 10;
			cv::putText(image_res, text, p, cv::FONT_ITALIC, 3, clr, 3, cv::LINE_8);
			cv::imshow("Camera", image_res);
			int x = cv::waitKey(1);
			if (x == 32)
			{
				cv::imwrite(Path_to_img, image_res);
			}
			else if (x == 27)
			{
				break;
			}
		}
	}
	return 0;
}