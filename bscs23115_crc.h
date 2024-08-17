#ifndef CRC
#define CRC
#include"bscs23115_shape.h"
class crc :public shape
{
private:
	static int count;
public:
	crc(cv::Point, cv::Point, int t, cv::Scalar c);
	void draw(cv::Mat& wname);
	int getcount();

	~crc();


};
#endif CRC