#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "gem necklace","���������" );
        add( "id", ({ "necklace" }) );
        set_short( "���������");
        set_long(@long
��һ�ſŷ������ƶ��ɵ������������ɵ�������ǳ��������⴮�������˸��һ
�����Ĺ�â����ȫ������ͨ����
long    );
        set( "unit", "��" );
        set( "weight", 30 );
        set( "type", "misc" );
        set( "material", "element");
        set( "defense_bonus", 5);
        set( "value", ({ 2000, "silver" }) );
        set( "equip_func","equip_cloth");
        set( "unequip_func","unequip_cloth" );
        set("extra_stats",(["str":-1]));
                 
}
int equip_cloth()
{
    set("light",1);
    return 1;
}
int unequip_cloth()
{
    set("light",0);
    return 1;
}
