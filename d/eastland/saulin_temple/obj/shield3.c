#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name( "sky lun", "���취��");
        add( "id", ({ "shield", "lun" }) );
        set_short("���취��");
        set_long(@C_LONG
������һ�ַ𷨵ľ���, ���з���������˫�ص�Ч�ܡ�
��Ҫ����������Ľ��, ���취���Ƿǳ�������ķ��ߡ�
C_LONG
		);
        set( "unit", "��"); 
        set( "type", "shield" );
        set( "armor_class", 8 );
	set("material","monk");
        set( "defense_bonus", 4 );
        set( "weight", 50 );
        set( "value", ({90, "gold" }) );
}
