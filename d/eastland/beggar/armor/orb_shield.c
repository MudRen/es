#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name( "orb shield", "������" );
        add( "id", ({ "shield" }) );
        set_short( "������" );
        set_long(@C_LONG
һ���������Ķ��ơ� ����½��������ǰ��·��ʰ���һ��ǧ��������ƶ��ɵġ���
��Ϊ��������������,½������������������ҹ,�پ���������,��ʮ������ҹ��˳
���Ƴɵ�,��ν��Ѫ�ƴ�
C_LONG        
        );
        set("unit","��");
        set( "type", "shield" );
        set( "material", "element" );
        set( "armor_class", 7 );
        set( "defense_bonus", 7 );
        set( "weight", 100 );
        set( "value", ({ 4000, "silver" }) );
        set( "light",1);   
}

