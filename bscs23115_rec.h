#ifndef REC
#define REC
#include"bscs23115_shape.h"
class rec :public shape
{
private:
	static int count;
public:
	rec(cv::Point s, cv::Point e, int t, cv::Scalar c);
	void draw(cv::Mat& wname);
	int getcount();
	~rec();
};
#endif REC