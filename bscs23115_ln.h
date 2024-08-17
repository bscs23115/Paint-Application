#ifndef LN
#define LN
#include"bscs23115_shape.h"

class ln :public shape
{
	static int count;
public:
	ln(cv::Point s, cv::Point e, int t, cv::Scalar c);
	void draw(cv::Mat& wname);
	int getcount();
	~ln();
};
#endif LN