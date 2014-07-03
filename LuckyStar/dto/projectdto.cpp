#include "projectdto.h"

#include <QObject>

ProjectDto::ProjectDto()
{
}

//The default prefix of project name
const QString ProjectDto::DEFAULT_PREFIX_PROJECT_NAME = QString::fromLocal8Bit("幸运星抽奖活动");

//The default suffix of main title
const QString ProjectDto::DEFAULT_SUFFIX_MAIN_TITLE = QString::fromLocal8Bit("主标题");

//The default suffix of sub title
const QString ProjectDto::DEFAULT_SUFFIX_SUB_TITLE = QString::fromLocal8Bit("副标题");

//The default suffix of roll title
const QString ProjectDto::DEFAULT_SUFFIX_ROLL_TITLE = QString::fromLocal8Bit("滚动字幕");

//Set the Project ID with value
void ProjectDto::setProjectID(int value)
{
    this->projectID = value;
}

//Get the Project ID
int ProjectDto::getProjectID()
{
    return this->projectID;
}

//Set the Project Name with value
void ProjectDto::setProjectName(QString value)
{
    this->projectName = value;
}

//Get the Project Name
QString ProjectDto::getProjectName()
{
    return this->projectName;
}

//Set the Main title with value
void ProjectDto::setMainTitle(QString value)
{
    this->mainTitle = value;
}

//Get the Main title
QString ProjectDto::getMainTitle()
{
    return this->mainTitle;
}

//Set the Sub titile with value
void ProjectDto::setSubTitle(QString value)
{
    this->subTitle = value;
}

//Get the Sub title
QString ProjectDto::getSubTitle()
{
    return this->subTitle;
}

//Set the Roll title with value
void ProjectDto::setRollTitle(QString value)
{
    this->rollTitle = value;
}

//Get the Roll title
QString ProjectDto::getRollTitle()
{
    return this->rollTitle;
}

//Set the background image with value
void ProjectDto::setBackgroundImage(QByteArray value)
{
    this->backgroundImage = value;
}

//Get the background image
QByteArray ProjectDto::getBackgroundImage()
{
    return this->backgroundImage;
}
