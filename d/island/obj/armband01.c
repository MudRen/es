#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("life armband", "����֮��");
        add( "id", ({"armband" }) );
        set_short("����֮��");
        set_long(@C_LONG
����Ǯ�δ���ÿ������ʱר�Ű��ڱ��ϵ��ֽ���һ����������ʵ����Ǯ�δ��ɵ�д�ա�        
C_LONG
        );
        set( "unit", "��");
        set( "type", "arms" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "material","cloth" );
        set( "weight", 20 );
        set( "value", ({ 500 , "silver" }) );
}
