#include "../../story.h"
inherit WMOB"warmob";

void create()
{
	::create();
	set_level(18);
	set_name( "wind god", "�粮" );
	add( "id", ({ "god","wind" }) );
	set_short( "�粮" );
	set_long(@LONG
�粮���ð�С���ֲ�����ȫ��һɫ���´���������һ������ӣ�����·��һ�ڰڵ�
��������Χ���ƻ����硣�粮����ȴ���������Ը�Ӧ���ģ�ƽ�����ǽ���������
һ����  
LONG
	);
	set( "unit", "��" );
	set( "alignment", -300 );
	set( "weight",1500);
	set( "gender","male");
	set_natural_armor(50,20);
	set_natural_weapon(17,16,18);
        set( "special_defense", ([ "all":40,"none":30 ]) );
        set( "aim_difficulty",
           ([ "critical":40, "vascular":40, "weakest":40 ]));
	set( "wealth/silver", 800 );
	set( "killer", 1 );
	set( "pursuing",1);
        set( "moving",1);
        set( "speed",30);
        set( "war_points", 400 );
	set( "max_hp",700);
        set( "hit_points",700);
	set_perm_stat( "str", 27 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "kar", 28 );
	set_skill( "wand", 100 );
        set_skill( "parry", 90 );
	set_skill( "dodge", 90 );
        set("wimpy",100);
        set("tactic_func","my_tactic");
        wield_weapon(WWEA"staff1");
        equip_armor(WARM"cloth2");
        equip_armor(WARM"gloves1");
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(7) > 1 ) return 0;
    tell_room(environment(),"\n�ӷ粮����Ĵ����ﴵ��һ���硫��\n\n");
    hurt_all("evil",70);
    return 1;    
}
