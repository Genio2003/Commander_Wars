#ifndef EDITORSELECTION_H
#define EDITORSELECTION_H

#include "oxygine-framework.h"
#include <QObject>
#include <QVector>
#include <QVector3D>
#include "game/terrain.h"
#include "game/building.h"
#include "game/gamemap.h"
#include "game/player.h"
#include "game/unit.h"

class EditorSelection;
typedef oxygine::intrusive_ptr<EditorSelection> spEditorSelection;

class EditorSelection : public QObject, public oxygine::Actor
{
    Q_OBJECT
public:
    /**
     * @brief The EditorMode enum describes what we want to place at the moment
     */
    enum class EditorMode
    {
        All = -1,
        Terrain = 0,
        Building,
        Unit,
    };
    /**
     * @brief The PlacementSize enum describes how terrain is placed
     */
    enum class PlacementSize
    {
        Small = 0,
        Medium,
        Big,
        Fill
    };

    explicit EditorSelection();


    inline EditorMode getCurrentMode() const
    {
        return m_Mode;
    }
    inline QString getCurrentTerrainID()
    {
        return m_Terrains.at(m_selectedItem)->getTerrainID();
    }
    inline QString getCurrentBuildingID()
    {
        return m_Buildings.at(m_selectedItem)->getBuildingID();
    }
    /**
     * @brief getCurrentSpBuilding the current selected unit
     * @return
     */
    spBuilding getCurrentSpBuilding();
    /**
     * @brief getCurrentSpUnit the current selected unit
     * @return
     */
    spUnit getCurrentSpUnit();


    PlacementSize getSizeMode() const;
    /**
     * @brief createPlayerSelection
     */
    void createPlayerSelection();

signals:
   void sigUpdateSelectedPlayer();
   void sigSelectionChanged();
   void sigChangeSelectedPlayer(qint32 player);
   void sigUpdateTerrainView();
   void sigUpdateBuildingView();
   void sigUpdateUnitView();
public slots:
    void selectTerrain(QString terrainID);
    void selectBuilding(QString buildingID);
    void selectUnit(QString unitID);
    void updateSelectedPlayer();
    void changeSelectedPlayer(qint32 player);

    void updateTerrainView();
    void updateBuildingView();
    void updateUnitView();
private:
    /**
     * @brief selectBuilding
     * @param building
     */
    void selectBuilding(qint32 building);
    /**
     * @brief selectUnit
     * @param unit
     */
    void selectUnit(qint32 unit);
    /**
     * @brief selectTerrain
     * @param terrain
     */
    void selectTerrain(qint32 terrain);
    /**
     * @brief getPosX
     * @param xCounter
     * @return
     */
    qint32 getPosX(qint32 xCounter);
private:
    // small hints for the ui
    static const qint32 frameSize = 30;
    static const qint32 selectionHeight = 80;
    static const qint32 startHPlacementSize = 0;
    static const qint32 startHSelectionType = startHPlacementSize + selectionHeight;
    static const qint32 startHSelectedPlayer = startHSelectionType + startHPlacementSize + selectionHeight;
    static const qint32 startHTerrain = startHSelectedPlayer + selectionHeight;
    static const qint32 startH = GameMap::Imagesize * 2;
    static const float xFactor;
    static const float yFactor;
    EditorMode m_Mode{EditorMode::Terrain};
    PlacementSize m_SizeMode{PlacementSize::Small};
    qint32 m_StartIndex{0};
    qint32 m_xCount{0};

    oxygine::spSlidingActor m_PlacementSelectionSlider;
    oxygine::spActor m_PlacementActor;
    QVector<spTerrain> m_Terrains;
    QVector<spBuilding> m_Buildings;
    QVector<spUnit> m_Units;

    oxygine::spSprite m_BoxPlacementSize;
    oxygine::spSprite m_BoxSelectionType;
    oxygine::spSprite m_BoxSelectedPlayer;
    oxygine::spSprite m_BoxPlacementSelection;

    oxygine::spSprite m_CurrentSelector;
    oxygine::spSprite m_CurrentSelectorSize;
    oxygine::spSprite m_CurrentSelectorMode;

    oxygine::spSprite m_pSpriteTerrainMode;
    oxygine::spSprite m_pSpriteBuildingMode;
    oxygine::spSprite m_pSpriteUnitMode;

    qint32 m_selectedItem{0};
    /**
     * @brief current selected player
     */
    spPlayer m_currentPlayer{nullptr};
    qint32 m_playerStartIndex{0};
    QVector<spBuilding> m_Players;

    oxygine::spSprite createV9Box(qint32 x, qint32 y, qint32 width, qint32 heigth);
    void createBoxPlacementSize();
    void createBoxSelectionMode();
    void initSelection();

    /**
     * @brief calcMaxPlayerSelection the amount of player hq's shown in the select player part
     * @return
     */
    qint32 calcMaxPlayerSelection();

};

#endif // EDITORSELECTION_H


