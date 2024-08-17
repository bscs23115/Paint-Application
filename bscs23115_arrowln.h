#ifndef ARROWLN
#define ARROWLN
#include"bscs23115_shape.h"


class arrowln :public shape
{
	static int count;
public:
	arrowln(cv::Point s, cv::Point e, int t, cv::Scalar c);
	void draw(cv::Mat& wname);
	int getcount();
	~arrowln();
};

#endif ARROWLN