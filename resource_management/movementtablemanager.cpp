#include <QFileInfo>
#include <QDirIterator>

#include "resource_management/movementtablemanager.h"

#include "coreengine/mainapp.h"

#include "modding/csvtableimporter.h"

#include "game/unit.h"
#include "game/terrain.h"
#include "game/gamemap.h"

MovementTableManager::MovementTableManager()
    : RessourceManagement<MovementTableManager>("",
                                                "/scripts/movementtables")
{
    setObjectName("MovementTableManager");
}

void MovementTableManager::loadAll()
{
    RessourceManagement<MovementTableManager>::loadAll();
    // import csv tables
    // clean up temp folder
    Interpreter* pInterpreter = Interpreter::getInstance();
    QDir dir("temp/");
    dir.removeRecursively();
    dir.mkpath(".");
    QStringList data;
    QFile file("resources/scripts/movementtables/movement_csv_import.txt");
    if (!file.exists())
    {
        file.setFileName(QString(oxygine::Resource::RCC_PREFIX_PATH) + "resources/scripts/movementtables/movement_csv_import.txt");
    }
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString jsHeader = stream.readAll();
    QStringList searchPaths = getSearchPaths();
    for (qint32 i = 0; i < searchPaths.size(); i++)
    {
        QString jsData = CsvTableImporter::ImportCsvTable(searchPaths[i] + "/movementtables.csv", jsHeader, "movementpointsTable", data);
        if (!jsData.isEmpty())
        {
            m_loadedRessources.append(data);
            pInterpreter->loadScript(jsData, "temp/movementtable.js");
        }
    }
    m_loadedRessources.sort();
}
qint32 MovementTableManager::getBaseMovementPoints(const QString & movementID, Terrain* pTerrain, Terrain* pCurrentTerrain, Unit* pUnit, bool trapChecking)
{
    Interpreter* pInterpreter = Interpreter::getInstance();
    QString function1 = "getMovementpoints";
    QJSValueList args1;
    QJSValue obj3 = pInterpreter->newQObject(pTerrain);
    args1 << obj3;
    QJSValue obj2 = pInterpreter->newQObject(pUnit);
    args1 << obj2;
    QJSValue obj4 = pInterpreter->newQObject(pCurrentTerrain);
    args1 << obj4;
    args1 << trapChecking;
    QJSValue obj5 = pInterpreter->newQObject(pCurrentTerrain->getMap());
    args1 << obj5;
    QJSValue ret = pInterpreter->doFunction(movementID, function1, args1);
    if (ret.isNumber())
    {
        return ret.toInt();
    }
    else
    {
        return -1;
    }
}

bool MovementTableManager::getSupportsFastPfs(const QString & movementID)
{
    Interpreter* pInterpreter = Interpreter::getInstance();
    QString function1 = "getSupportsFastPfs";
    QJSValue ret = pInterpreter->doFunction(movementID, function1);
    if (ret.isBool())
    {
        return ret.toBool();
    }
    else
    {
        return true;
    }
}
