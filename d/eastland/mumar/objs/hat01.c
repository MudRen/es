#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("silken threads","�ڽ�");
        add("id",({"threads","hat"}) );
        set_short("�ڽ�");
        set_long(
"����һ���ڽ��Ƕ�����½�ľ�ʦ�����ʸ����װ����\n"
        );
        set( "unit", "��" );
        set( "weight", 50 );
        set( "type", "head" );
        set( "material", "cloth" );
        set( "armor_class", 7 );
        set( "defense_bonus", 1 );
        set( "value", ({ 1200, "silver" }) );
        set( "no_sale",1);
}
