#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "wolf", "����" );
	set_short( "��˹��ĳ���--����" );
	set_long(
		"�㿴��һֻ�ǳ��޴����׶�ı��ǣ�������������צ��\n"
	);
	set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );
	set_skill( "dodge", 70 );

	set( "unit", "ֻ" );
        set_natural_armor(60,25);
	set_natural_weapon( 15, 10, 20 );

	set_c_verbs( ({ "%s��ǰצ����%s", "%s�ſ��������ݵ��죬��%sҧȥ" }) );
	set_c_limbs( ({ "ͷ��", "����", "β��", "�Ȳ�" }) );
#include <../replace_mob.h>
}
