#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_level(11);
	ob->set_name( "hunter", "����" );
	ob->set_short( "����" );
	ob->set_long(@C_LONG
�����������Ũü���ۣ�һ����ļ���ͽ�ʵ�ļ����ʾ�������ա�
������������ڴ˵أ��Ⱥ�һֻ��˵�Ѿ��ڸ���������˲����˵��ϻ���
C_LONG
	);
	ob->set( "race", "human" );
	ob->set( "gender", "male" );
	ob->set( "alignment", 800 );
	ob->set_perm_stat( "str", 20 );
	ob->set_perm_stat( "dex", 20 );
	ob->set_perm_stat( "kar", 16 );
	ob->set_skill( "thrusting", 70 );
	ob->set_skill( "parry", 60 );
	ob->set_skill( "dodge", 60 );
	ob->set_skill( "anatomlogy", 60 );
	ob->set( "aiming_loc", "ganglion" );
	ob->set( "hit_points", 300 );
	ob->set( "max_hp", 300 );
	ob->set( "wealth/gold", 55 );
	ob->set( "special_defense", (["all": 25 ]) );
	ob->set_natural_weapon( 6, 6, 6 );
	ob->set_natural_armor( 35, 10 );

	ob->wield_weapon( "/d/eastland/obj/tiger_fork" );
}
