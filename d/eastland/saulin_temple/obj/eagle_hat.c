#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name("eagle helmet", "��ӥ֮��");
        add( "id", ({ "helmet" }) );
        set_short("��ӥ֮��");
        set_long(@C_LONG
����һ����ѩӥƤ���ɵ�ͷ�����ഫ�������õķ��������� 
����һ�����׵�Ƥ������������һֻСС����ӥ�� 
C_LONG
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "fire":8, "cold":-3, "electric":-5 ]) );
        set( "weight", 100 );
        set( "value", ({ 240, "gold" }) );
}