#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name("ant knight", "��ʿ��");
	add( "id", ({ "ant" }) );
	set_short("��ʿ��");
	set_long(
		"��ʿ���Ǳȱ��ϸ���ս���ľ��ϣ��⿴����Ƭ�޴�����ݾ������ĺ���\n"
	);
	set( "max_hp",250);
	set( "hit_points",250);
	set( "unit", "ֻ" );
   set( "race", "insect" );
	set( "alignment", 200 );
	set_natural_weapon( 26, 11, 22 );
	set_natural_armor( 49, 20 );
	set_perm_stat("str",24);
	set_perm_stat("dex",21);
	set_perm_stat("con",24);
	set( "weight", 100);
	set( "c_death_msg", "%s���һ�������˼��²����� ....\n" );
	set_c_limbs( ({ "ͷ��", "����", "��" }) );
	set_c_verbs( ({ "%s�ݺݵ���%sҧ��ȥ" }) );
	set( "alt_corpse", MOYADA"obj/ant_corpse1" );
}
