#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "ebony robe", "��ɫ����" );
	add( "id", ({ "robe" }) );
	set_short( "��ɫ����" );
	set_long(
	"�����ɫ�����ֿ��ֺ��أ���������ϴ��������ںڰ���һ�����ѱ����֡�\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "leather" );
	set( "armor_class", 18 );
	set( "defense_bonus", 2 );
	set( "special_defense", ([ "magic":3, "fire":-5 ]) );
	set( "weight", 100 );
	set( "value", ({ 740, "silver" }) );
}
