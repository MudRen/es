
#include <../goomay.h>

inherit MONSTER;

void create ()
{
        ::create();
        set_name( "daoist", "��ʿ" );
        set_short( "��ʿ");
        set_long(
@C_LONG
    ����һ������ͨͨ�ĵ�ʿ�����˿��������ϳ����˾��֣���Ϊ��������
һ�����䵹���С͵��
C_LONG
);
        set_level(9);
        set ("gender", "male");
        set ("race", "human");
		set("killer",1);
        set( "alignment", 400 );
        set_natural_armor( 40, 15 );
		set_natural_weapon( -7,1,4);
        set_perm_stat( "str", 15 );
        set_perm_stat( "kar", 18 );
        set_perm_stat( "int", 15 );
        set_perm_stat( "dex", 15 );
        set_skill( "dodge", 100 );
		set_skill( "shortblade",60);
		set( "max_fp",500);
		set( "force_points",500);
		set( "force_effect",2);
        set( "hit_points", 200 );
        set( "max_hp", 200 );
        set( "special_defense", ([ "all": 20 ]) );
        set( "wealth/silver", 200 );

	wield_weapon( Obj"shortsword01" );
	equip_armor( Obj"doshu_robe" );

        set( "chat_chance", 15 );
        set( "att_chat_output", ({
                "�ǵ�ʿ��������󺰣������˰� !! ��С͵�� !!����\n",
                "��ʿ�е�������ʦ����Ҫ���ˣ�������Ī���� !!����\n"
	}) );
}
void die()
{
	if (!present("The master daoist",environment())) {
                tell_room( environment(this_object()), 
		set_color("\n\nͻȻ��һ��͸���Ľ�������ʺ����������һ�������ἱ�ݣ�һ�������ʿ��\n"+
		"ŭ�����㣬���е��������� !! ������ !!������һ�����������\n\n","HIY") ,
			this_object() );
                set( "alt_corpse", Mob"master_doshu" );
	}
                ::die();
}
