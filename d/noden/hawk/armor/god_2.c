#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Zeus Amulet","��˹�������" );
        add( "id", ({ "amulet","zeus amulet" }) );
        set_short( "��˹�������" );
        set_long(
                "ϣ������֮����˹�Ļ��������Ө���ŵĴ��񷴶����Գ�����"+
                "��������\n"
        );
        set( "unit", "��" );
        set("material","scholar");
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 2510, "silver" }) );
}
