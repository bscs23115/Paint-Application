#ifndef SHAPE
#define SHAPE
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;

class shape
{
private:
	int thickness;
	cv::Scalar clr;
	cv::Point start;
	cv::Point end;
public:

	virtual void draw(cv::Mat& wname) = 0;
	void setthick(int);
	void setclr(cv::Scalar);
	int getthick()const;
	cv::Scalar getclr()const;
	void setstart(cv::Point s);
	void setend(cv::Point e);
	cv::Point getstart()const;
	cv::Point getend()const;
	virtual int getcount() = 0;
	virtual ~shape() {};
};

#endif SHAPE


