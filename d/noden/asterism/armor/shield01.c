#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name( "shield of Alaits", "������˹֮��");
        add( "id", ({ "shield" }) );
        set_short( "������˹֮��");
        set_long(
           "���˻��Ұ���˹�ؼ��崫�ҵĶ���,���ϻ�������ֻ��׳��ʨ���ޡ�\n"
        );
        set( "unit", "��"); 
        set( "type", "shield" );
        set( "material", "light_metal" );
        set( "armor_class", 10 );
        set( "defense_bonus", 5 );
        set( "weight", 100 );
        set("special_defense",
              (["evil":10,"fire":10,"cold":10]) );
        set( "value", ({ 250, "gold" }) );
        
}






