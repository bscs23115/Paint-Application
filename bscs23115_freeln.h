#ifndef FREELN
#define FREELN
#include"bscs23115_shape.h"

class freeln :public shape
{
private:
	vector<cv::Point> mvc;
	static int count;
public:
	freeln(cv::Point s, cv::Point e, int t, cv::Scalar c);
	void draw(cv::Mat& wname);
	int getcount();
	~freeln();
};
#endif FREELN