#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("red sandal beads","��̴����");
    add("id",({"bead","beads","sandal"}) );
    set_short("��̴����");
	set_long(@C_LONG
����һ����������ɫ̴��ľ���ɵ�����, �ഫ�Ƿ����ù�������, ���ʹ�úܾ�,
�������ܾ���, ������Ʈɢ��һ�����ص���ζ, �������ʹ�������ܰ��ġ�
C_LONG
	);
	set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 17 );
	set( "type", "misc" );
    set( "material", "wood");
	set( "armor_class", 2 );
	set( "defense_bonus", 8 );
	set( "value", ({ 100, "gold" }) );
}
