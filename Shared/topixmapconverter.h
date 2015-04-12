#ifndef TOQPIXMAPCONVERTER_H
#define TOQPIXMAPCONVERTER_H

#include <QObject>
#include <QPixmap>

#include <opencv2/opencv.hpp>


//******************************************************************************
//******************************************************************************
// Converter class template
//******************************************************************************
//******************************************************************************
class ToQPixmapConverter : public QObject
{
    Q_OBJECT

   public:
      ToQPixmapConverter(QObject *parent = 0) : QObject(parent) {}
      ~ToQPixmapConverter(){}

      virtual QPixmap *convert() =0;
      virtual QPixmap *convertFromPath(cv::String const path) =0;

    protected:
      QPixmap localPixMap;

};

//******************************************************************************

//******************************************************************************
//******************************************************************************
// cv::Mat converter
//******************************************************************************
//******************************************************************************

class FromCVMatToQPixmapConverter : public ToQPixmapConverter
{
   public:
      FromCVMatToQPixmapConverter(QObject *parent = nullptr,
                                  cv::Mat* prawPic = nullptr) :
          ToQPixmapConverter(parent), rawPic(prawPic) {}
      ~FromCVMatToQPixmapConverter(){delete rawPic;}

      virtual QPixmap *convert();
      virtual QPixmap *convertFromPath(cv::String const path);
   private:
      cv::Mat* rawPic;
};


#endif // TOQPIXMAPCONVERTER_H

