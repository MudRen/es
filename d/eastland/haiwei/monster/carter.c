#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "carter", "����" );
	set_short( "����" );
	set_long("���������������Ǹ��˺ܳ���·���������ڿ�ջǰ��̨������Ϣ��\n");
	set( "unit", "��" );
	set( "gender", "male" );
	set( "race", "human" );
	set_perm_stat( "str", 3 );
	set_natural_weapon( 3, 3, 3 );
	set( "alignment", 200 );
	set( "wealth/gold", 1 );
#include <replace_mob.h>
}
