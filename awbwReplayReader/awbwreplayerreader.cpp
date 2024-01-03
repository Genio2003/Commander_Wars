#include "awbwReplayReader/awbwreplayerreader.h"
#include "zipSupport/qzipreader.h"

#include <QBuffer>

#include "awbwReplayReader/awbwdataparser.h"

static const char* const JSON_TURNSTART = "O:8:\"awbwGame\":";
static const char* const JSON_PLAYERSTART = "O:10:\"awbwPlayer\":";
static const char* const JSON_BUILDINGSTART = "O:12:\"awbwBuilding\":";
static const char* const JSON_UNITSSTART = "O:8:\"awbwUnit\":";
static const char* const JSON_ACTIONSTART = "a:a:3:{";
static const char* const JSON_REPLAYSTART = "p:";

AwbwReplayerReader::AwbwReplayerReader(const QString & awbwReplayZip)
{

    QByteArray gameStateContent;
    QByteArray replayFileContent;
    QZipReader reader(awbwReplayZip);
    auto files = reader.fileInfoList();
    for (auto file : files)
    {
        auto zipContent = reader.fileData(file.filePath);
        QBuffer contentBuffer(&zipContent);
        contentBuffer.open(QIODevice::ReadOnly);
        QZipReader unzipReader(&contentBuffer);
        auto unzipContent = unzipReader.unzipContent(true);
        if (unzipContent.startsWith(JSON_TURNSTART))
        {
            gameStateContent = unzipContent;
        }
        else if (unzipContent.startsWith(JSON_REPLAYSTART))
        {
            replayFileContent = unzipContent;
        }
    }
    auto playerTurns = gameStateContent.split('\n');
//    for (const auto & turn : playerTurns)
//    {
//        auto turnData = AwbwDataParser::readList(turn);
//        qint32 a = 0;
//    }
}
