#include "../../story.h"

inherit WMOB"warmob";

void create()
{
	::create();
	set_level(14);
	set_name( "special ghost", "�ȹ�" );
	add( "id", ({ "ghost" }) );
	set_short( "�ȹ�" );
	set_long(@LONG
һ�������˵�����Ұ�޵�������Ӱ�ӣ������������˿����������������ʲ�ᡣ��
���������ǰС����ֻ������ҡ���ź��Ĳ��ϡ�
LONG
	);
	set( "unit", "��" );
	set( "race","��");
	set( "alignment", -300 );
	set_natural_armor(40,25);
        set( "special_defense", ([ "all":10 ]) );
        set( "aim_difficulty",
           ([ "critical":10, "vascular":10, "weakest":20 ]));
	set( "wealth/silver", 110 );
	set( "killer", 1 );
        set( "unbleeding",1);
        set( "war_points", 60 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 16 );
	set_natural_weapon(5,4,5);
	set_skill( "longblade", 80 );
	set_skill( "parry", 70 );
	set( "chat_chance", 5 );
	set( "att_chat_output", ({
		"�ȹ�˵������������ǿ�ĵֿ��ˣ�û�˵���ס��ȴ���ģ�\n"
	}) );
        set("tactic_func","my_tactic");
        wield_weapon(WWEA"scythe1");
}
