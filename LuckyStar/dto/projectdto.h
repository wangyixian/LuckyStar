#include "basedto.h"

#include <QBitArray>

#ifndef PROJECTDTO_H
#define PROJECTDTO_H

class ProjectDto : public BaseDto
{
public:
    ProjectDto();

private:
    //Project ID
    int projectID;

    //Project's Name
    QString projectName;

    //Project's Main Title.
    //Will display on the bingo window
    QString mainTitle;

    //Project's Sub Title.
    //Will display on the bingo window
    QString subTitle;

    //Project's roll display information
    QString rollTitle;

    //Project's Background image bytes
    QByteArray backgroundImage;

public:
    //The default prefix of project name
    static const QString DEFAULT_PREFIX_PROJECT_NAME;

    //The default suffix of main title
    static const QString DEFAULT_SUFFIX_MAIN_TITLE;

    //The default suffix of sub title
    static const QString DEFAULT_SUFFIX_SUB_TITLE;

    //The default suffix of roll title
    static const QString DEFAULT_SUFFIX_ROLL_TITLE;

    //Set the Project ID with value
    void setProjectID(int value);
    //Get the Project ID
    int getProjectID();

    //Set the Project Name with value
    void setProjectName(QString value);
    //Get the Project Name
    QString getProjectName();

    //Set the Main title with value
    void setMainTitle(QString value);
    //Get the Main title
    QString getMainTitle();

    //Set the Sub titile with value
    void setSubTitle(QString value);
    //Get the Sub title
    QString getSubTitle();

    //Set the Roll title with value
    void setRollTitle(QString value);
    //Get the Roll title
    QString getRollTitle();

    //Set the background image with value
    void setBackgroundImage(QByteArray value);
    //Get the background image
    QByteArray getBackgroundImage();
    
};

#endif // PROJECTDTO_H
