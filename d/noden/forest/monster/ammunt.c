#include <mudlib.h>

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(7);
	set_name( "ammunt", "��������" );
	add ("id", ({ "ammunt", "beast" }) );
	set_short( "���͵���������" );
	set("aggressive", 1);
	set("killer", 1);
	set("pursuing", 1);
	set_long(@CLONG
    ����һֻ�н�����㡢����ʨ��֮������Ұ�ޡ���춱��˻�С��
����, ���������°Ͷ����ض�����һ�����¡�
CLONG
	);
	
	set( "alignment", -500 );
	set( "unit", "ֻ" );
	set_perm_stat( "dex", 9 );
	set_perm_stat( "str", 12 );
	set_perm_stat( "int", 3 );
	set_perm_stat( "piety", 3 );
	set("special_defense", ([ "all":20 ]) );
	set("aim_difficulty", ([ "critical":10, "vascular":30, ]) );
	set_natural_weapon( 9, 6, 10);
	set_natural_armor( 35, 7);
	
	set_c_limbs( ({ "������", "��ͷ", "�Ľ�", "��β��"}) );
	set_c_verbs( ({ "%s�ݺݵ���%sһ��ҧ��", "%s��%s����һ��",
		 "%s��β�����صغ�ɨ%s",}) ); 
}
