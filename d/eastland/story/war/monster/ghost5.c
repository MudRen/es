#include "../../story.h"
inherit WMOB"warmob";

void create()
{
	::create();
	set_level(16);
	set_name( "large ghost", "����" );
	add( "id", ({ "ghost" }) );
	set_short( "����" );
	set_long(@LONG
���ͳ����˵�����Ұ�޵����ӣ�ȴֻ��һֻ��һֻ�š�
LONG
	);
	set( "unit", "��" );
        set( "race","��");
	set( "alignment", -300 );
	set_natural_armor(50,25);
	set_natural_weapon(40,18,30);
        set( "special_defense", ([ "all":20,"none":10 ]) );
        set( "aim_difficulty",
           ([ "critical":20, "vascular":20, "weakest":20 ]));
	set( "wealth/silver", 200 );
	set( "killer", 1 );
        set( "unbleeding",1);
        set( "war_points", 150 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 20 );
	set_skill( "unarmed", 100 );
	set_skill( "unarm-parry",75 );
	set_skill( "dodge", 75 );
        set("tactic_func","my_tactic");
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(5) > 1 ) return 0;
    tell_room(environment(),"�����͵����������ɫ��Һ�壡\n");
    hurt_all("poison",60);
    return 1;    
}
