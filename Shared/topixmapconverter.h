#ifndef TOQPIXMAPCONVERTER_H
#define TOQPIXMAPCONVERTER_H

#include <QObject>
#include <QPixmap>

#include <opencv2/opencv.hpp>


/**
 * @brief The ToQPixmapConverter abstract class
 */
class ToQPixmapConverter : public QObject
{
    Q_OBJECT

   public:
      ToQPixmapConverter(
              QPixmap *pPixMapDest,
              QObject *parent = 0) :
          QObject(parent),  pixMapDest(pPixMapDest) {}

      ~ToQPixmapConverter(){}

      virtual void convertFromPath(cv::String const path) =0;

public slots:
      virtual void convert() =0;

    protected:
      QPixmap *pixMapDest;
};

//******************************************************************************

/**
 * @brief The FromCVMatToQPixmapConverter class
 */
class CvMat2QPixmapConverter : public ToQPixmapConverter
{
    Q_OBJECT

   public:
      CvMat2QPixmapConverter(
              QPixmap *pPixMapDest,
              cv::Mat *prawPic,
              QObject *parent = nullptr) :
          ToQPixmapConverter(pPixMapDest, parent), rawPic(prawPic) {}

      ~CvMat2QPixmapConverter(){}

      virtual void convertFromPath(cv::String const path);

public slots:
      virtual void convert();

   private:
      cv::Mat* rawPic;
};


#endif // TOQPIXMAPCONVERTER_H

