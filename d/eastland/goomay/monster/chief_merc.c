#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "Tong the vice-chieftain", "�Ƹ�����ͷ" );
	set_short( "�Ƹ�����ͷ" );
	set_long(
		 "�Ƹ�����ͷ�˳������ƣ�����Զ�ھֵĵڶ���������������ڴ���\n"
		 "�������������������ֱ��������\n"
	);
        add ("id",({ "tong","chieftain"}));
	set( "unit", "��" );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "int", 20 );
	set_skill( "dodge", 80 );
	set_skill( "unarmed", 90 );
	set_skill( "two-weapon", 100 );
	set("max_fp", 1800);
	set("force_points", 1800);
	set( "special_defense", ([ "all": 30 ]) );
	set( "gender", "male" );
	set( "alignment", 1000 );
	set_natural_armor( 75, 30 );
	set_natural_weapon( 31, 16, 28 );
	set( "natural_weapon_class2", 28 );
	set( "natural_min_damage2", 17 );
	set( "natural_max_damage2", 26 );
	set( "wealth/gold", 60 );
	set_c_verbs( ({ "%s̤����ǰ��һ��ֱȭ����%s", "%s������%sһ��",
		"%sʹһ�С�ɳɮ�ݷ𡹣���ȭ����%s", "%s��ǰһ�ݣ�������%s��ȥ",
		"%sһ�ǡ����ҷ�Դ����˫ȭֱȡ%s", "%sʹһ�С��ӹ���������˫ȭ��%s��ȥ",
		"%sһ�С��������������������%s", "%sһ�С��ͻ���բ������ȭ��磬ֱȡ%s",
		"%sʹһ�ǡ��ڻ�͵�ġ�����ȭֱ��%s" }) );

#include <replace_mob.h>
}
