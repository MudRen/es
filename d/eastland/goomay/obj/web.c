#include "../goomay.h"
inherit ARMOR;

void create()
{
        set_name("Love web","��˿����");
        add( "id", ({ "cloak","web" }) );
        set_short("a Love web", "��˿����");
        set_long(
 "����һ��ɢ������Ө��â�����磬������һ������������������Ů�԰���
������������֯�ɵ����� \n"
        );
        set("no_sell",1);
        set("unit","��");
        set( "type", "cloak" );
        set("material","element");
        set( "armor_class", 2 );
        set( "defense_bonus", 9 );
        set( "weight", 70 );
        
        set( "value", ({ 1400, "silver" }) );
}
