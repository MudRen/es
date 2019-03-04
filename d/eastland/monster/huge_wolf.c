// /u/m/mad/special/wolf.c

#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(8);
   set_name( "huge hyaena", "������" );
   add( "id", ({ "wolf" }) );
   set_short("������");
	set_long(
           "�㿴��һֻ�׶�����ǣ������㷢�������ء��ĵͺ�\n"
	);
   set( "race", "beast" );
   set( "unit", "ֻ" );
   set_perm_stat( "str", 10 );
   set_skill( "dodge", 50 );
   set_natural_weapon( 20, 8, 20 );
   set_c_verbs( ({ "%s��ǰצ����%s", "%s�ſ��������ݵ��죬��%sҧȥ" }) );
   set_c_limbs( ({ "ͷ��", "����", "β��", "�Ȳ�" }) );
}

void die()
{
   object killer;

   killer=query("last_attacker");
   killer->set_temp("killed_wolf",1);
   ::die();
}
