#include "debugmacros.h"
#include "glpicviewerwithcommands.h"
#include "histowitheditboxes.h"
#include "histogramcalculator.h"
#include "pichistogrammanager.h"
#include "Shared/openglpicviewer.h"
#include "singlehistogram.h"

#include <QApplication>
#include <QtWidgets>
#include <opencv2/opencv.hpp>


int openCVbasicDemo(QApplication *app);
int graphicSceneDemo(QApplication *app);

int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    PicHistogramManager histmgr;
    SingleHistogram hist;
    HistoWithEditboxes histBoxed;
    OpenGLPicViewer * openGLPic;
    OpenGLPicViewer * openGLPicIgnoreAR;
    OpenGLPicViewer * openGLPicKeepAR;
    OpenGLPicViewer * openGLPicKeepARExpand;
    GLPicViewerWithCommands * picViewCmds;
    HistogramCalculator * histCalc;
    cv::Mat * mat;

    int demoSelect = 9;

    switch (demoSelect)
    {
    case 0:
        // All histogram widgets
//        histmgr.show();
        hist.show();
//        histBoxed.show();
        return app.exec();
        break;

    case 1:
        // Histogram manager only
        histmgr.show();
        return app.exec();
        break;

    case 2:
        // OpenCV basic demo
        return openCVbasicDemo(&app);
        break;

    case 3:
        // Basic QGraphicScene demo
        return graphicSceneDemo(&app);
        break;

    case 4:
        // Basic QOpenGLWidget demo
        openGLPic = new OpenGLPicViewer();
        openGLPic->show();
        return app.exec();
        break;

    case 5:
        // 3 QOpenGLWidgets with 3 aspect ratios
        openGLPicIgnoreAR = new OpenGLPicViewer();
        openGLPicKeepAR = new OpenGLPicViewer();
        openGLPicKeepARExpand = new OpenGLPicViewer();

        openGLPicIgnoreAR->setPixmapWithPath("D:/temp/Uluru.jpg");
        openGLPicKeepAR->setPixmapWithPath("D:/temp/Uluru.jpg");
        openGLPicKeepARExpand->setPixmapWithPath("D:/temp/Uluru.jpg");

        openGLPicIgnoreAR->setAspectRatioMode(Qt::IgnoreAspectRatio);
        openGLPicKeepAR->setAspectRatioMode(Qt::KeepAspectRatio);
        openGLPicKeepARExpand->setAspectRatioMode(Qt::KeepAspectRatioByExpanding);

        openGLPicIgnoreAR->show();
        openGLPicKeepAR->show();
        openGLPicKeepARExpand->show();

        return app.exec();
        break;

    case 6:
        // GL pic viewer with commands demo
        picViewCmds = new GLPicViewerWithCommands(0, Qt::KeepAspectRatio);
        picViewCmds->setPixmapWithPath("D:/temp/Uluru.jpg");
        picViewCmds->show();
        picViewCmds->setPixmapWithPath("D:/temp/lena.png");
        return app.exec();
        break;

    case 7:
        // cv::Mat convertion in GL pic viewer with commands demo
        picViewCmds = new GLPicViewerWithCommands(
                    0, Qt::KeepAspectRatioByExpanding);
        mat = new cv::Mat();
        *mat = cv::imread("D:/temp/Uluru.jpg");
        picViewCmds->setCvMat(*mat);
        picViewCmds->show();
        picViewCmds->setPixmapWithPath("D:/temp/lena.png");
        return app.exec();
        break;

    case 8:
        // Histogram computing
        mat = new cv::Mat();
        *mat = cv::imread("D:/temp/Uluru.jpg");
        histCalc = new HistogramCalculator(mat);
        histCalc->configure();
        histCalc->computeHist();

        hist.setHist(histCalc->blueX, histCalc->blueY);
        hist.show();
        return app.exec();
        break;

    case 9:
        // Histogram computing
        mat = new cv::Mat();
        *mat = cv::imread("D:/temp/P1070216.JPG");
        histCalc = new HistogramCalculator(mat);
        histCalc->configure();
        histCalc->computeHist();

        // Histogram manager only
        histmgr.setHist(histCalc);
        histmgr.show();

        return app.exec();
        break;
    }
    return 0;
}

