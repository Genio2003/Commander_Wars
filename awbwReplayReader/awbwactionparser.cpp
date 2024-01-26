#include <QJsonArray>

#include "awbwReplayReader/awbwactionparser.h"
#include "awbwReplayReader/awbwdatatypes.h"
#include "coreengine/memorymanagement.h"
#include "game/gameaction.h"
#include "game/gamemap.h"
#include "ai/coreai.h"

const char* const AwbwActionParser::JSONKEY_ACTION = "action";
const char* const AwbwActionParser::JSONKEY_UNIT = "unit";
const char* const AwbwActionParser::JSONKEY_UNITNAME = "units_name";
const char* const AwbwActionParser::JSONKEY_NEWUNIT = "newUnit";
const char* const AwbwActionParser::JSONKEY_UNITS_FUEL = "units_fuel";
const char* const AwbwActionParser::JSONKEY_PATH = "paths";
const char* const AwbwActionParser::JSONKEY_GLOBAL = "global";
const char* const AwbwActionParser::JSONKEY_X = "x";
const char* const AwbwActionParser::JSONKEY_Y = "y";
const char* const AwbwActionParser::JSONKEY_UNITS_X = "units_x";
const char* const AwbwActionParser::JSONKEY_UNITS_Y = "units_y";
const char* const AwbwActionParser::JSONKEY_UNITS_COST = "units_cost";
const char* const AwbwActionParser::JSONKEY_UNITS_NAME = "units_name";
const char* const AwbwActionParser::JSONKEY_COPVALUES = "copValues";
const char* const AwbwActionParser::JSONKEY_COPVALUE = "copValue";
const char* const AwbwActionParser::JSONKEY_TAGVALUE = "tagValue";
const char* const AwbwActionParser::JSONKEY_ATTACKER = "attacker";
const char* const AwbwActionParser::JSONKEY_DEFENDER = "defender";
const char* const AwbwActionParser::JSONKEY_UNITS_HIT_POINTS = "units_hit_points";
const char* const AwbwActionParser::JSONKEY_COMBATINFOVISION = "combatInfoVision";
const char* const AwbwActionParser::JSONKEY_COMBATINFO = "combatInfo";
const char* const AwbwActionParser::JSONKEY_FIRE = "Fire";
const char* const AwbwActionParser::JSONKEY_MOVE = "Move";

AwbwActionParser::AwbwActionParser(GameMap* pMap)
    : m_pMap(pMap)
{
}

spGameAction AwbwActionParser::getAction(const QJsonObject & object)
{
    spGameAction action = MemoryManagement::create<GameAction>(m_pMap);
    QString actionType = object.value(JSONKEY_ACTION).toString().toLower();
    if (actionType == "move")
    {
        action->setActionID(CoreAI::ACTION_WAIT);
        addMovepath(object, action);
    }
    else if (actionType == "capt")
    {
        action->setActionID(CoreAI::ACTION_CAPTURE);
        addMovepath(object, action);
    }
    else if (actionType == "fire")
    {
        action->setActionID(CoreAI::ACTION_FIRE);
        addMovepath(object.value(JSONKEY_MOVE).toObject(), action);
        addActionFireInfo(object, action);
    }
    else if (actionType == "build")
    {
        action->setActionID(CoreAI::ACTION_BUILD_UNITS);
        addBuildInfo(object, action);
    }
    else if (actionType == "delete")
    {
        action->setActionID("ACTION_DELETE_UNIT");
    }
    else if (actionType == "eliminated")
    {

    }
    else if (actionType == "unload")
    {
        action->setActionID(CoreAI::ACTION_UNLOAD);

    }
    else if (actionType == "unhide")
    {
        action->setActionID(CoreAI::ACTION_UNSTEALTH);
        addMovepath(object, action);
    }
    else if (actionType == "tag")
    {
        action->setActionID(CoreAI::ACTION_ACTIVATE_TAGPOWER);

    }
    else if (actionType == "supply")
    {
        action->setActionID(CoreAI::ACTION_SUPPORTALL_RATION);
        addMovepath(object, action);
    }
    else if (actionType == "resign")
    {

    }
    else if (actionType == "repair")
    {
        action->setActionID(CoreAI::ACTION_SUPPORTSINGLE_REPAIR);
        addMovepath(object, action);
    }
    else if (actionType == "power")
    {

    }
    else if (actionType == "load")
    {
        action->setActionID(CoreAI::ACTION_LOAD);
        addMovepath(object, action);
    }
    else if (actionType == "launch")
    {
        action->setActionID(CoreAI::ACTION_MISSILE);
    }
    else if (actionType == "join")
    {
        action->setActionID(CoreAI::ACTION_JOIN);
        addMovepath(object, action);
    }
    else if (actionType == "hide")
    {
        action->setActionID(CoreAI::ACTION_STEALTH);
        addMovepath(object, action);
    }
    else if (actionType == "gameover")
    {
    }
    else if (actionType == "explode")
    {
        action->setActionID(CoreAI::ACTION_EXPLODE);
    }
    else if (actionType == "end")
    {
        action->setActionID(CoreAI::ACTION_NEXT_PLAYER);
    }

    action->setMapHash(m_pMap->getMapHash());

    return action;
}

void AwbwActionParser::addMovepath(const QJsonObject & object, spGameAction & action)
{
    QJsonArray jsonPath = object.value(JSONKEY_PATH).toObject().value(JSONKEY_GLOBAL).toArray();
    QJsonObject unitObj = object.value(JSONKEY_UNIT).toObject().value(JSONKEY_GLOBAL).toObject();
    if (jsonPath.size() > 0)
    {
        QJsonObject startPoint = jsonPath[0].toObject();
        action->setTarget(QPoint(startPoint[JSONKEY_X].toInt(), startPoint[JSONKEY_Y].toInt()));
        auto* pUnit = action->getTargetUnit();
        if (pUnit != nullptr)
        {
            QVector<QPoint> path;
            for (qint32 i = jsonPath.size() - 1; i >= 0; --i)
            {
                QJsonObject point = jsonPath[i].toObject();
                path.append(QPoint(point[JSONKEY_X].toInt(), point[JSONKEY_Y].toInt()));
            }
            action->setMovepath(path, pUnit->getFuel() - unitObj[JSONKEY_UNITS_FUEL].toInt());
        }
    }
}

void AwbwActionParser::addBuildInfo(const QJsonObject & object, spGameAction & action)
{
    QJsonObject unitObj = object.value(JSONKEY_NEWUNIT).toObject().value(JSONKEY_GLOBAL).toObject();
    action->setTarget(QPoint(unitObj[JSONKEY_UNITS_X].toInt(), unitObj[JSONKEY_UNITS_Y].toInt()));
    action->setCosts(action->getCosts() + unitObj[JSONKEY_UNITS_COST].toInt());
    action->writeDataString(AwbwDataTypes::UNIT_ID_ID_MAP[unitObj[JSONKEY_UNITS_NAME].toString()]);
    action->setInputStep(action->getInputStep() + 1);
}

void AwbwActionParser::addActionFireInfo(const QJsonObject & object, spGameAction & action)
{
    QJsonObject fireInfo = object.value(JSONKEY_FIRE).toObject();
    QJsonObject copValues = fireInfo.value(JSONKEY_COPVALUES).toObject();
    QJsonObject combatInfo = fireInfo.value(JSONKEY_COMBATINFOVISION).toObject().value(JSONKEY_GLOBAL).toObject().value(JSONKEY_COMBATINFO).toObject();
    QJsonObject attackerData = combatInfo.value(JSONKEY_ATTACKER).toObject();
    QJsonObject defenderData = combatInfo.value(JSONKEY_DEFENDER).toObject();
    Unit* pAttacker = action->getPerformingUnit();
    Unit* pDefender = m_pMap->getTerrain(defenderData[JSONKEY_UNITS_X].toInt(), defenderData[JSONKEY_UNITS_Y].toInt())->getUnit();


}
