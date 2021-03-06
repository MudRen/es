#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "king robe", "孔雀王袍" );
	add( "id", ({ "robe", }) );
	set_short( "孔雀王袍");
	set_long(@C_LONG
此袍乃是孔雀王朝的传国之宝，历届国君皆需身著此袍，在登基大典时
祭拜天地四方，深深地受著神灵们的祝福，可是在孔雀王朝灭亡後，早
以不知此袍的去向．		
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 120 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 35 );
	set( "defense_bonus", 5 );
	set( "value", ({ 2000, "silver" }) );
}