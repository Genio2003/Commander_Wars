var Constructor = function()
{
    this.getName = function()
    {
        return qsTr("Air");
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
			case "FOREST":
			case "WASTELAND":
            case "SEA":
			case "ROUGH_SEA":
            case "REAF":
				return 1;
        }
    };
};
Constructor.prototype = MOVEMENTTABLE;
var AIR = new Constructor();
