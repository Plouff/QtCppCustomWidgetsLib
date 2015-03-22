#include "pichistogrammanager.h"
#include "singlehistogram.h"
#include "histowitheditboxes.h"
#include <QApplication>
#include <QtWidgets>
#include <opencv2/opencv.hpp>
#include <string>


int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    PicHistogramManager histmgr;
    SingleHistogram hist;
    HistoWithEditboxes histBoxed;


//    histmgr.show();
//    hist.show();
//    histBoxed.show();
//    cv::Mat image= cv::imread("IMG_9786.jpg", 1);
    cv::Mat image= cv::imread("D:/IMG_9786.jpg", 1);
    cv::namedWindow("Tulips");
    cv::imshow("Tulips", image);
    cv::waitKey(1000);

    return app.exec();
}

