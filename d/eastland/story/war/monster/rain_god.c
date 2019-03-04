#include "../../story.h"
inherit WMOB"warmob";

void create()
{
	::create();
	set_level(18);
	set_name( "rain god", "��ʦ" );
	add( "id", ({ "god","rain" }) );
	set_short( "��ʦ" );
	set_long(@LONG
��ʦ�����ݳ����������ĵ���ף�����Ӫ�����������ӡ���������ȴ����������
��Ӧ���ģ�ƽʱ�����ˣ�����������ˮʹ�����ǲ�����࣬��������Ǹ�����
����Ĵ󻵵���  
LONG
	);
	set( "unit", "��" );
	set( "alignment", -800 );
	set( "gender","male");
	set( "weight",1500);
	set_natural_armor(65,21);
	set_natural_weapon(10,10,3);
        set( "special_defense", ([ "all":40,"none":30 ]) );
        set( "aim_difficulty",
           ([ "critical":40, "vascular":40, "weakest":40 ]));
	set( "wealth/silver", 800 );
	set( "killer", 1 );
        set( "moving",1);
        set( "speed",30);
        set( "pursuing",1);
        set( "wimpy",100);
        set( "war_points", 250 );
	set( "max_hp",550);
	set( "hit_points",550);
	set_perm_stat( "str", 27 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 25 );
	set_skill( "whip", 100 );
        set_skill( "parry", 90 );
	set_skill( "dodge", 90 );
        set("tactic_func","my_tactic");
        wield_weapon(WWEA"whip1");
        equip_armor(WARM"rain_cloth");
        equip_armor(WARM"rain_amulet");
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(8) > 1 ) return 0;
    tell_room(environment(),"��ʦ�������һ�У���Ȼ���������һ����ɫ����������\n\n");
    hurt_all("poison",55);
    return 1;    
}
