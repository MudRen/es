#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "snake ring","����ʯ֮��");
        add( "id", ({"ring"}) );
   set_short("����ʯ֮��");
        set_long(
@C_LONG
����һö������֮ʯ������Ľ�ָ������ʱ����˸��һ����ɫ�Ĺ�
â������ҫ���ܣ����㿴������λ�á���
C_LONG
        );
        set( "unit", "ֻ" );
        set( "type", "finger" );
        set( "material", "element" );
        set( "weight",10);
        set( "light",0);
   set( "defense_bonus", 1 );
        set( "value", ({ 500, "silver" }) );
        set( "no_sale",1);
        set( "equip_func","equip_ring");
        set( "unequip_func","unequip_ring" );
}
int equip_ring()
{
object holder; 
    set("light",1 ); 
    holder=this_player();   
    tell_object(holder,
    "һ����ů�Ĺ�â��ҫ���ܣ���о���������\n");
    return 1;
}
int unequip_ring()
{
    set("light",0);
    return 1;
}    
