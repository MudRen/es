#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("round shield","��Բ��");
        add("id",({"shield"}) );
        set_short("��Բ��");
        set_long(
"����һ��Բ�εĶܣ�������һȦһȦ���㿴�˷��ε�Բ��\n"
        );
        set( "unit", "��" );
        set( "weight", 150 );
        set( "type", "shield" );
        set( "material", "element" );
        set( "armor_class", 4 );
        set( "defense_bonus", 6 );
        set( "value", ({ 1500 , "silver" }) );
}
