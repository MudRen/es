#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "sparrow", "��ȸ" );
	set_short( "��ȸ" );
	set_long(
		"�㿴��һֻСС����ȸ�ڵ�����Ծ�����ƺ��������˽ӽ���\n"
	);
	set_perm_stat( "dex", 4 );

	set( "unit", "ֻ" );
	set( "natural_weapon_class1", 2 );
	set( "natural_min_damage1", 2 );
	set( "natural_max_damage1", 2 );
	set( "alignment", -100 );
	set_c_verbs( ({ "%s���¸��壬�������%s", "%s��צ����%sץ��" }) );
	set_c_limbs( ({ "ͷ��", "����", "���" }) );
#include <replace_mob.h>
}
