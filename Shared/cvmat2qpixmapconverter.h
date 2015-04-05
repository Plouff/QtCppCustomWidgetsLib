#ifndef CVMAT2QPIXMAPCONVERTER_H
#define CVMAT2QPIXMAPCONVERTER_H

#include <QObject>
#include <QPixmap>

#include <opencv2/opencv.hpp>

class cvMat2QPixmapConverter : public QObject
{
    Q_OBJECT
public:
    explicit cvMat2QPixmapConverter(QObject *parent = 0);
    ~cvMat2QPixmapConverter();

    QPixmap *convert(cv::Mat &pMat);
    QPixmap* convertFromPath(cv::String const path);

    cv::Mat *getMatPic() const;
    void setMatPic(cv::Mat *value);

private:
    cv::Mat* matPic;
    QPixmap localPixMap;
};

#endif // CVMAT2QPIXMAPCONVERTER_H
