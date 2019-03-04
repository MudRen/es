#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Lay Chou-Tan", "�׾���" );
	add ("id", ({ "master", "lay", }) );
	set_short( "�������ɶ������� �׾���");
	set_long( @LONG
�׾���������������ʦ�������˵Ĺ��ŵ��ӣ���������λʦ��һ����
����һ���¶���������������������������������������ѧ�յ�ʱ��ܶ�
���󲿷ֵ��书�ķ��������Ĵ�ʦ�ַ��������������������书����λʦ
�����в�ͬ�����Գ�һ����������λʦ�ַ�ʦ�������е�֮�ᣬ������
ִ�������ɣ�����Ϊ�������ɵĶ������š�
LONG
	);
	set_perm_stat("str", 30 );
	set_perm_stat("con", 25 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set( "alignment", 1500 );

	set( "race", "human" );
	set( "gender", "male" );

	set( "hit_points", 2000 );
	set( "max_hp", 2000 );
	set( "aim_difficulty",
	    ([ "critical":70,"vascular":80,"weakest":70,"ganglion":60 ]) );
	set_natural_weapon( 50, 15, 30 );
	set_natural_armor( 90, 60 );
	set ("special_defense", ([
		"all": 40 , "none" : 50]) );

	wield_weapon( "/d/swordman/guild/weapons/anti-god" );
	equip_armor( "/d/swordman/guild/armors/lay_plate" );
	equip_armor( "/d/swordman/guild/armorsblue/lay_pants" );
	equip_armor( "/d/swordman/guild/armors/lay_gloves" );
	equip_armor( "/d/swordman/guild/armors/lay_boots" );
	equip_armor( "/d/swordman/guild/armors/lay_amulet" );
}
