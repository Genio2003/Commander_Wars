#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QObject>
#include <QVector>

#include "oxygine/core/ref_counter.h"
#include "oxygine-framework.h"
#include "game/smartpointers.h"

#include "memory"

#include "game/terrain.h"
#include "objects/cursor.h"
#include "coreengine/fileserializable.h"

class GameMap : public QObject, public oxygine::Actor, public FileSerializable
{
    Q_OBJECT

    Q_PROPERTY(qint32 width READ getWidth WRITE setWidth)
public:
    static const qint32 frameTime;
    static const qint32 Imagesize = 24;
    enum Directions
    {
        None = -1,
        North,
        NorthEast,
        East,
        SouthEast,
        South,
        SouthWest,
        West,
        NorthWest,
        All,
        Direct,
        Diagnonal
    };
    /**
     * @brief GameMap creates an empty ma (filled with plains) with two players and the given size
     * @param width
     * @param heigth
     */
    explicit GameMap(qint32 width, qint32 heigth);
    /**
     * @brief GameMap
     * @param map path to the map which should be loaded
     */
    explicit GameMap(QString map);
    virtual ~GameMap();
    /**
     * @brief getMapWidth
     * @return width of the map
     */
    qint32 getMapWidth() const;
    /**
     * @brief getMapHeight
     * @return height of the map
     */
    qint32 getMapHeight() const;

    inline static GameMap* getInstance()
    {
        return m_pInstance;
    }
    /**
     * @brief getTerrain smart pointer
     * @param x
     * @param y
     * @return the smart pointer
     */
    spTerrain getSpTerrain(qint32 x, qint32 y);
    /**
     * @brief getspPlayer
     * @param player index of the player
     * @return smart pointer to the selected player
     */
    spPlayer getspPlayer(qint32 player);
    /**
     * @brief serialize stores the object
     * @param pStream
     */
    virtual void serialize(QDataStream& pStream) override;
    /**
     * @brief deserialize restores the object
     * @param pStream
     */
    virtual void deserialize(QDataStream& pStream) override;
    /**
     * @brief getVersion stream version for serialization
     * @return
     */
    inline virtual qint32 getVersion() override
    {
        return 1;
    }


signals:

public slots:
    /**
     * @brief updateTerrainSprites updates the terrain sprites refreshes them to fit the current map
     * @param xInput around given coordinates -1 whole map
     * @param yInput around given coordinates -1 whole map
     */
    void updateTerrainSprites(qint32 xInput = -1, qint32 yInput = -1);
    /**
     * @brief getField changes the coordinates into the given direction
     * @param x x-coordinates
     * @param y y-coordinates
     * @param direction the suitable direction
     */
    static void getField(qint32& x, qint32& y, Directions direction);
    /**
     * @brief onMap returns if the given coordinates are on the map
     * @param x
     * @param y
     * @return true if it's still on the map
     */
    bool onMap(qint32 x, qint32 y);
    /**
     * @brief centerMap centers the view point to the given location
     * @param x
     * @param y
     */
    void centerMap(qint32 x, qint32 y);
    /**
     * @brief zoom zooms into or out of the map :)
     * @param zoom
     */
    void zoom(float zoom);
    inline float getZoom() const
    {
        return m_zoom;
    }
    void moveMap(qint32 x, qint32 y);
    /**
     * @brief getTerrain only use this for js scripts
     * @param x
     * @param y
     * @return the real pointer to the given terrain
     */
    Terrain* getTerrain(qint32 x, qint32 y);

    /**
     * @brief canBePlaced
     * @param terrainID the terrain id you want to place
     * @param x position
     * @param y position
     * @return true if this terrain can be placed
     */
    bool canBePlaced(const QString& terrainID, qint32 x, qint32 y);
    /**
     * @brief updateTerrain updates the given fields around. So all terrains are placeable.
     * @param x
     * @param y
     */
    void updateTerrain(qint32 x, qint32 y);
    /**
     * @brief replaceTerrain
     * @param terrainID
     * @param x
     * @param y
     */
    void replaceTerrain(const QString& terrainID, qint32 x, qint32 y, bool useTerrainAsBaseTerrain = false, bool updateSprites = false);
    /**
     * @brief getPlayerCount
     * @return number of players on the map
     */
    qint32 getPlayerCount()
    {
        return players.size();
    }
    /**
     * @brief getPlayer
     * @param player player index in the vector
     * @return pointer to the player
     */
    Player* getPlayer(qint32 player);
private:
    static GameMap* m_pInstance;

    qint32 width{0};
    qint32 heigth{0};
    QVector<QVector<spTerrain>*> fields;
    QVector<spPlayer> players;

    static const QString m_JavascriptName;
    float m_zoom{1.0f};

    void loadMapData();
};

#endif // GAMEMAP_H
