#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	VideoCapture capture("rtsp://admin:admin12345@192.168.1.64"); //��С�� link �ͧ ip camera ��� videoCapture
	Mat frame; //��С�� frame �������ʴ��Ҿ 
	bool OK = capture.grab(); //��С�ȵ�ǵѴ�Թ�����Ҷ֧���ͧ

	if (OK == false) {				
		cout << "cannot grab" << endl; //����������ö��Ҷ֧���ͧ ���ʴ���ͤ��� cannot grab � console
		return -1;
	}
	else {
		while (1) {
			if(!capture.read(frame)){ //����������ö-->�����ҹ������ �ҡ ip camera ��ҹ frame 
				cout << "NO FRAME" << std::endl; //����������ö��ҹ�Ҿ�� ����ʴ������ NO FRAME � console
				waitKey();
			}

			if (!frame.empty())
			{
				imshow("w", frame); // ��� frame �բ����� ����ʴ�˹�ҵ�ҧ�ʴ��Ҿ�ҡ���ͧ
			}
			if (waitKey(1) >= 0)// �������� ���ǻԴ˹�ҵ�ҧ
			{
				break;
			}
		}
	}
}
