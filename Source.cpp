#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	VideoCapture capture("rtsp://admin:admin12345@192.168.1.64"); //ประกาศ link ของ ip camera ใส่ videoCapture
	Mat frame; //ประกาศ frame เพื่อใช้แสดงภาพ 
	bool OK = capture.grab(); //ประกาศตัวตัดสินการเข้าถึงกล้อง

	if (OK == false) {				
		cout << "cannot grab" << endl; //ถ้าไม่สามารถเข้าถึงกล้อง จะแสดงข้อความ cannot grab ใน console
		return -1;
	}
	else {
		while (1) {
			if(!capture.read(frame)){ //ถ้าไม่สามารถ-->การอ่านข้อมูล จาก ip camera ผ่าน frame 
				cout << "NO FRAME" << std::endl; //ถ้าไม่สามารถอ่านภาพได้ ให้แสดงคำว่า NO FRAME ใน console
				waitKey();
			}

			if (!frame.empty())
			{
				imshow("w", frame); // ถ้า frame มีข้อมูล ให้แสดงหน้าต่างแสดงภาพจากกล้อง
			}
			if (waitKey(1) >= 0)// กดปุ่มใดๆ แล้วปิดหน้าต่าง
			{
				break;
			}
		}
	}
}
