
#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("ice demon's cloak", "��������");
        add( "id", ({ "cloak" }) );
        set_short("��������");
        set_long(@C_LONG
���Ǵ�˵�е�а���������������磬��˵���������а��ħ����
���������������ü���а��ľ��ӹ�ĸ�����ͷ�������������
�к���ʮ�����и������ǵ�С��������������������������ʿ��
����׷���¹���һ��
C_LONG
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 5 );
        set( "defense_bonus", 4 );
        set( "special_denfese", ([ "ice":6, "fire":-10 ]) );
        set( "weight", 50 );
        set( "value", ({ 1600, "silver" }) );
}
