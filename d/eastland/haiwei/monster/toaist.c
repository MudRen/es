#include <mudlib.h>
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "old toaist", "�ϵ�ʿ" );
	add( "id", ({ "toaist" }) );
	set_short( "�ϵ�ʿ" );
	set_long(
		"��λ��ʿ�������۵����֣���˵������ǿ�Ѿ��������������֡�\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_natural_weapon( 20, 11, 15 );
	set_natural_armor( 40, 10 );
	set_perm_stat( "dex", 15 );
	set_perm_stat( "kar", 15 );
	set_skill( "dodge", 20 );
	set( "wealth/gold", 20 );
	set( "inquiry", ([
		"paper" : 
	"��Ҫ����!ֻҪ���(put coins)���;Ϳ��Եõ�һ����������"
	]) );
#include <replace_mob.h>
}

