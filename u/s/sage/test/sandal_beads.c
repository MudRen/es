#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("red sandal beads","��̴����");
    add("id",({"bead","beads","sandal"}) );
    set_short( "red sandal beads","��̴����");
	set_long(
"This is a holy-ball necklace \n"
"����һ����������ɫ̴��ľ���ɵ�����, �ഫ�Ƿ����ù�������, ���ʹ�úܾ�,\n"
"�������ܾ���, ������Ʈɢ��һ�����ص���ζ, �������ʹ�������ܰ��ġ�\n"
	);
	set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 17 );
	set( "type", "misc" );
    set( "material", "wood");
	set( "armor_class", 0 );
	set( "defense_bonus", 10 );
	set( "value", ({ 100, "gold" }) );
}
