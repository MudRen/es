#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name( "king-kong-po-lo lun", "��ղ��޷���");
    add( "id", ({ "shield","lun" }) );
    set_short("��ղ��޷���");
    set_long(@C_LONG
������һ�ַ𷨵ľ���,���з���������˫�ص�Ч��... 
��ղ��޷��������ּ������µķ���,ƽʱ�ɵ�������ʹ
��,��������ǿ��
C_LONG
	);
    set( "unit", "��"); 
    set( "type", "shield" );
    set( "armor_class", 10 );
	set("material","monk");
    set( "defense_bonus", 6 );
    set( "weight", 110 );
    set( "value", ({ 150, "gold" }) );
    set( "no_sale", 1 );
}
