var COABILITY_TRUEDAMAGE =
{

    getAbilityName : function()
    {
        return qsTr("All true damage bonus");
    },

    getFunctionNameContext : function(coAbility, coGeneratorMenu)
    {
        return "getTrueDamage";
    },

    writeCoAbilityContent : function(coAbility, coGeneratorMenu)
    {
        var variables = coAbility.getVariables();
        var bonus = variables.createVariable("bonus");
        return COGENERATORMENU.getActiveConditionPrologue(coAbility) +
               "                result = result + " + bonus.readDataInt32().toString() + ";\n" +
               "            }\n"
    }
};
