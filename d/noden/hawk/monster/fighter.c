
#include <mudlib.h>
#include "../hawk.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name("crazy fighter", "鸟人族狂斗士");
	add( "id", ({"hawkman", "fighter"}) );
	set_short("鸟人族狂斗士");
	set_long(@LONG
    这是鸟人族中专司守卫天界之城的斗士，基於职务所需，
他会格杀一切外来的陌生人，你看到他手中拿了一把异乎寻常
的巨剑，看来好像不太好惹。
LONG
	);
	set( "gender", "male" );
	set( "race", "hawkman" );
	set( "alignment", 300 );
	set_natural_armor( 25, 5 );
	set_perm_stat( "str", 24 );
	set_perm_stat( "dex", 20 );
	set( "max_hp",250 );
        set( "hit_points",250 );
	set_skill( "longblade", 70 );
	set_skill( "parry", 90 );
	set_skill( "block", 40 );
	set_skill( "dodge", 50 );
	set( "wealth/silver", 200 );
	
	wield_weapon ( WEAPON"stsword");
	equip_armor( ARMOR"stone_shield" );
	equip_armor( ARMOR"leather_hauberk" );
}
