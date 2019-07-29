var Constructor = function()
{
    this.init = function (building)
    {
        building.setHp(100);
        building.setAlwaysVisble(true);
    };
    // called for loading the main sprite
    this.loadSprites = function(building)
    {
        building.loadSprite("minicannon+N", false);
        building.loadSprite("minicannon+N+mask", true);
    };
    this.getBaseIncome = function()
    {
        return 0;
    };
    this.getActions = function()
    {
        // returns a string id list of the actions this building can perform
        return "ACTION_CANNON_FIRE";
    };
    this.startOfTurn = function(building)
    {
        building.setFireCount(1);
    };
    this.getActionTargetFields = function(building)
    {
        return globals.getShotFields(1, 4, 0, -1);
    };
    this.getMiniMapIcon = function()
    {
        return "minimap_blackholebuilding";
    };
    this.getName = function()
    {
        return qsTr("Mini Cannon");
    };
    this.getDamage = function(building, unit)
    {
        return 3;
    };
    this.getBuildingTargets = function()
    {
        return GameEnums.BuildingTarget_Enemy;
    };
    this.onDestroyed = function(building)
    {
        // called when the terrain is destroyed and replacing of this terrain starts
        var x = building.getX();
        var y = building.getY();
        map.replaceTerrain("PLAINS_DESTROYED", x, y);
        map.getTerrain(x, y).loadSprites();
        var animation = GameAnimationFactory.createAnimation(x, y);
        animation.addSprite("explosion+land", -map.getImageSize() / 2, -map.getImageSize(), 0, 1.5);
        audio.playSound("explosion+land.wav");
    };
    this.getShotAnimation = function(building)
    {
        var animation = GameAnimationFactory.createAnimation(building.getX(), building.getY(), 70);
        animation.addSprite("minicanon_north", -map.getImageSize() * 0.5, -map.getImageSize() * 1.5, 0, 1.5);
        return animation;
    };
}

Constructor.prototype = BUILDING;
var ZMINICANNON_N = new Constructor();
