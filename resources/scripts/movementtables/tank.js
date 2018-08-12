var Constructor = function()
{
    this.getName = function()
    {
        return qsTr("Tank");
    };
    this.getMovementpoints = function(terrainID)
    {
        switch (terrainID)
        {
            case "PLAINS":
            case "BEACH":
            case "BRIDGE":
            case "DESTROYEDWELD":            
            case "RUIN":
            case "STREET":
            case "AIRPORT":
            case "FACTORY":
            case "HARBOUR":
            case "HQ":
            case "MINE":
            case "PIPESTATION":
            case "RADAR":
            case "TOWER":
            case "TOWN":
                return 1;
			case "FOREST":
			case "WASTELAND":
				return 2;
        }
    };
};
Constructor.prototype = MOVEMENTTABLE;
var TANK = new Constructor();
