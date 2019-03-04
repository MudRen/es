#include <mudlib.h>
#include <races.h>

inherit RACE_DRAGON;
inherit MOUNT;

void create()
{
	::create();
	set_level(17);
	set_name( "Fire Dragon","����" );
	add( "id", ({ "dragon" }) );
	set_short( "����" );
	set_long(@LONG
����һͷ����������˵ֻҪ��ѱ��������Խ���������
LONG
		);
	set( "unit","ͷ" );
	set( "race","dragon" );
	set_perm_stat( "str",30 );
	set_perm_stat( "dex",20 );
	set_perm_stat( "int",15 );
	set_natural_weapon( 45,40,60 );
	set_natural_armor( 80,40 );
	set( "alignment",300 );
	set( "extra_look","$N������һͷ�޴�Ļ�������������������һ�㡣\n" );
//	set( "mountable",1 );
	set( "max_load", 2600 );
}

void init()
{
	mount::init();
}
