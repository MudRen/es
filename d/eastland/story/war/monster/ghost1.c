#include "../../story.h"

inherit WMOB"warmob";

void create()
{
	::create();
	set_level(14);
	set_name( "special ghost", "�ι�" );
	add( "id", ({ "ghost" }) );
	set_short( "�ι�" );
	set_long(@LONG
һ�������˵�����Ұ��������Ӱ�ӣ������������˿�������������ʲ�ᡣ���ƺ���
����������צ����ס�������˵�������
LONG
	);
        set( "race", "��");
	set( "unit", "��" );
	set( "alignment", -300 );
	set_natural_armor(70,15);
        set( "special_defense", ([ "all":10 ]) );
        set( "aim_difficulty",
           ([ "critical":10, "vascular":10, "weakest":20 ]));
	set( "wealth/silver", 110 );
	set( "killer", 1 );
        set( "unbleeding",1);
        set( "war_points", 60 );
	set_perm_stat( "str", 17 );
	set_perm_stat( "dex", 16 );
	set_skill( "longblade", 80 );
	set_skill( "parry", 70 );
	set( "chat_chance", 5 );
	set( "att_chat_output", ({
		"�ι�˵������������ǿ�ĵֿ��ˣ�û�˵���ס��ȴ���ģ�\n"
	}) );
        set("tactic_func","my_tactic");
        wield_weapon(WWEA"scythe1");
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(10) > 1 ) return 0;
    tell_room(environment(),"�ι���������ɫ�����壡!\n");
    hurt_all("evil",30);
    return 1;    
}
