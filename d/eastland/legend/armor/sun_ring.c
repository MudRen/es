#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "sun ring","�ս�");
        add( "id", ({"ring"}) );
        set_short("�ս�");
        set_long(@C_LONG
һֻ��ħ���챦ʯ���Ƶ�С�ɽ�ָ����ָ�ϲ�ʱ��˸�������հ�Ĺ��������ǿ��
��ħ������������������춷�ӡ�ڱ�ʯ�ϵ��������ǿ�󣬷���ʹ�ñ�ʯ�������
�������������κܶ��أ��ƺ���Ϊ��ĳ����ƣ���������������ʲ���·���Ҳ˵
������
C_LONG
        );
        set( "unit", "ֻ" );
        set( "type", "finger" );
        set( "material", "element" );
        set( "weight",1);
        set( "defense_bonus", 2 );
        set( "value", ({ 1000, "silver" }) );
        set("special_defense",(["magic":30, "evil":30]));
        set( "equip_func","equip_ring");
        set( "unequip_func","unequip_ring" );
}
int equip_ring()
{
    set("light",1 ); 
    return 1;
}
int unequip_ring()
{
    set("light",0);
    return 1;
}    
