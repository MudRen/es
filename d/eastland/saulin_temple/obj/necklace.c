#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("stone beads","�ھ�ʯ����");
    add("id",({"bead","beads",}) );
    set_short("�ھ�ʯ����");
	set_long(@C_LONG
����һ�����Ϻ��ھ�ʯ���ɵ�����, ��������������,
��һ��������ڲ�����, ɢ����һ�ɺ��س�������Ϣ��
C_LONG
	);
	set( "unit", "��" );
	set( "weight", 30 );
	set( "type", "misc" );
        set("material","stone");
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
	set( "value", ({ 110, "gold" }) );
}
