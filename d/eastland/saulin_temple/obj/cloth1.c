#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("damo pallium","��Ħ����");
    add("id",({"cloth","pallium"}) );
    set_short("��Ħ����");
	set_long(@C_LONG
����һ���������ƾɵļ���,�ഫ�ǵ����Ħ��������������,ֻ��
��λ�൱�ߵĺ������ʸ���,�ഫ�����д�Ħ����ķ�,�ܰ���
���ħ����
C_LONG
	);
    set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 90 );
	set( "type", "body" );
	set( "armor_class", 34 );
        set("material","monk");
	set( "defense_bonus", 6 );
	set( "value", ({ 200, "gold" }) );
}
