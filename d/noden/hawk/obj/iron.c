
#include <mudlib.h>

inherit OBJECT;
void create()
{
        set_name("iron", "�ٶ�");
        add( "id", ({ "iron" }) );
        set_short( "�ٶ�" );
        set("long","����һ�������ٶ���������������Ǭ(dry)ʪ�����·���\n");
        set( "weight", 40 );
        set( "unit", "��" );
}
