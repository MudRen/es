#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid( getuid() );
	set_name( "Sword of Markara", "玛卡拉之剑" );
	add( "id", ({ "markara","sword" }) );
	set_short( "玛卡拉之剑" );
	set_long(
        "这把玛卡拉之剑是国王送给精锐骑士长戴利佛的武器，上面刻著许多\n"
		"美丽的花纹，这把美丽的剑是戴利佛最重视的武器。\n"
	);
	set( "unit", "把" );
	set( "weapon_class", 35 );
	set( "type", "longblade" );
	set( "min_damage", 19 );
	set( "max_damage", 36 );
	set( "weight", 120 );
	set( "value", ({ 230, "gold" }) );
}
