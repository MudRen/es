#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("red sandal beads ","��̴����");
        add("id",({"bead","beads","sandal"}) );
         set_short("��̴����");
	set_long(@C_LONG
����һ����������ɫ̴��ľ���ɵ�����,�ഫ�Ƿ����ù�������,���ʹ�úܾ�,������
�ܾ��� ������Ʈɢ��һ�����ص���ζ �������ʹ�������ܰ���... 
C_LONG
	          );
	set( "unit", "��" );
	set( "weight", 17 );
	set( "type", "misc" );
        set("material","wood");
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
	set( "value", ({ 200, "gold" }) );
}
