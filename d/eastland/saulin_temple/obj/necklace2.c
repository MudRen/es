#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("puty beads ","��������");
    add("id",({"bead","beads",}) );
    set_short("��������");
	set_long(@C_LONG
����һ����ǧ�����������ɵ�����, ���ʹ�úܾ�, �������ܾ��ˡ�
��һ������ɢ����һ����������Ϣ, �����������ƽ����
C_LONG
	);
	set( "unit", "��" );
	set( "weight", 15 );
        set("material","wood");
	set( "type", "misc" );
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
	set( "value", ({ 180, "gold" }) );
}
