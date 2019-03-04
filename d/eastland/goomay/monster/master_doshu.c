
#include <../goomay.h>

inherit MONSTER;

void create ()
{
        ::create();
        set_name( "The master daoist", "��������" );
        add ("id",({ "daoist","master"}));
        set_short( "��������");
        set_long(
@C_LONG
    �������������������ˣ�һ���ó������������书\��ǿ���޵�ʿ
���˿���������縳�������ϳ�����ŭ����Ϊ��������һ�����䵹��
��С͵��
C_LONG
);
        set_level(15);
        set ("gender", "male");
        set ("race", "gnome");
		set("killer",1);
        set( "alignment", 1000 );
        set_natural_armor( 70, 25 );
        set_natural_weapon( 0, 4, 6 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "kar", 18 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 25 );
        set_skill( "dodge", 100 );
	set_skill( "shortblade",100);
//	set( "tactic_func", "my_tactic" );
//	set( "gonfus/unknow",1);
	set( "max_fp",500);
	set( "force_points",500);
	set( "force_effect",4);
        set( "hit_points", 400 );
        set( "max_hp", 400 );
        set( "special_defense", ([ "all": 30 ]) );
        set( "wealth/silver", 500 );
	wield_weapon( Obj"icy_sword" );
	equip_armor( Obj"doshu_robe" );

        set( "chat_chance", 15 );
        set( "att_chat_output", ({
                "��������ŭ������������ !! �޳ܵ�С͵ !!����\n",
                "��������Ц����������С�������ҵı����������𣿡���\n"
	}) );
}
/*
int my_tactic()
{
        object victim;
        if( random(20)>6 || !(victim= query_attacker()) ) return 0;
	if( (string)this_object()->query_temp("gonfu_now") == "unknow" )
		return 0;
	if( (int)this_player()->query("force_points") < 100 )
		set( "force_points",500);
	command("enhant unknow");
}
*/
