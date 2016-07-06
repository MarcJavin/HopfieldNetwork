#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <glob.h>
#include "Hopfield.hpp"

using namespace std;




int main (int argc, char *argv[]){

	cout << "Hello World !" << endl;

	Hopfield network = Hopfield(50, 50);

	//~ cv::Mat example(90,120, CV_8UC1, cv::Scalar(0));

	cv::Mat example = cv::imread("images/index.png", 0);
	cv::imwrite("example.jpg", example);

	cv::Mat example2 = cv::imread("images/index2.png", 0);
	cv::imwrite("example2.jpg", example2);

	cv::Mat example3 = cv::imread("images/index3.jpg", 0);
	cv::imwrite("example3.jpg", example3);

	// cv::Mat example4 = cv::imread("/home/markus/Documents/ReconnaissanceEmotions/images/sorties/40:0.jpg", 0);
	// cv::imwrite("example4.jpg", example4);

	cv::Mat test = cv::imread("images/test.jpg", 0);
	cv::imwrite("test.jpg", test);

	network.addPattern(example);
	network.addPattern(example2);
	network.addPattern(example3);
	//~ network.addPattern(example4);

	// network.calculateWeightsStorkey();
	network.calculateWeightsHebbian();

	network.serialize("network.jpg");

	//~ Hopfield network2 = Hopfield(60,80);
	//~ network2.deserialize("network.jpg");

	network.compare(test);



	//~ glob_t glob_result;
	//~ glob("/home/markus/Documents/ReconnaissanceEmotions/images/entrees/*",GLOB_TILDE,NULL,&glob_result);
	//~ for(unsigned int i=0; i<glob_result.gl_pathc; ++i){
		//~ cout << "toto" << endl;
	  //~ cout << glob_result.gl_pathv[i] << endl;
	//~ }










	return 0;

}
