#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "carter", "����" );
	set_short( "����" );
	set_long(
		"������һЩ�ŷ�泵��ר�Ű��ھָϳ���������������Χ��һ��\n"+
		 "���Ŀ�����һ������������š�\n"
	);
	set( "unit", "��" );
	set_perm_stat( "str", 6 );
	set_perm_stat( "dex", 6 );
	set_skill( "dodge", 20 );
	set( "gender", "male" );
	set( "alignment", 100 );
	set_natural_armor( 10, 4 );
	set_natural_weapon( 1, 2, 5 );
	set( "wealth/gold", 2 );
#include <replace_mob.h>
}
