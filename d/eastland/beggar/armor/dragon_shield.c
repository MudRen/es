#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "dragon shield", "������" );
        add( "id", ({ "shield" }) );
        set_short( "������" );
        set_long(@C_LONG
һ���е��������ºۼ��Ķ���,����������˵����˲�֪���ٴεĹ������ڶ���
�ϻ���һֻ������צ������,��������ò,��춵��˻�����Щ��Ķ������á�  
C_LONG       
        );
        set("unit","��");
        set( "type", "shield" );
        set( "material", "cloth" );
        set( "armor_class",7 );
        set( "defense_bonus", 1 );
        set( "weight", 100 );
        set( "value", ({ 1360, "silver" }) );
}
