#include"bscs23115_shape.h"
#include"bscs23115_paint.h"
#include<exception>

int main()
{
	try
	{
		paint p(1, 500, 500, cv::Scalar(0, 0, 0));
		p.run();
	}
	catch (...)
	{
		cout << "UNKNOWN ERROR OCCURED!!!" << endl;
	}
	return 0;
}


